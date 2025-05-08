.PHONY: .board-info.mk all check_op clean compile_cs_ex update_cs_ex upload_cs_ex

all: compile_cs_ex compile_io_ex


CS_EX := CommandStation-EX
CS_EX_BRANCH := master
CS_EX_CONFIGS := $(CS_EX)/config.h $(CS_EX)/myAutomation.h $(CS_EX)/myRoster.h \
	$(CS_EX)/myTrolley.h $(CS_EX)/myPassengerLoop.h
CS_EX_BOARD := arduino:avr:mega

$(CS_EX):
	git clone https://github.com/DCC-EX/$@.git

update_cs_ex: $(CS_EX)
	@cd $(CS_EX) && \
	git fetch origin && \
	git checkout -B $(CS_EX_BRANCH) origin/$(CS_EX_BRANCH)

$(CS_EX_CONFIGS): $(CS_EX)/%: %
	cp $< $@

# Injects the wifi ssid and pwd from 1Password into the compile process
compile_cs_ex: $(CS_EX_CONFIGS)
	@WIFI_SSID="$$(op read 'op://Family/WiFi - Home/network name')"; \
	WIFI_PASSWORD="$$(op read 'op://Family/WiFi - Home/wireless network password')"; \
	arduino-cli compile --build-property compiler.cpp.extra_flags="-DWIFI_SSID=\"$$WIFI_SSID\" -DWIFI_PASSWORD=\"$$WIFI_PASSWORD\"" -b $(CS_EX_BOARD) $(CS_EX); \

upload_cs_ex: compile_cs_ex .board-info.mk
	@if [ "$(BOARD)" = "$(CS_EX_BOARD)" ]; then \
		arduino-cli upload -b $(CS_EX_BOARD) -p $(DEVICE) $(CS_EX); \
	else \
		echo "⚠️ Won't compile: expected $(CS_EX_BOARD), found $(BOARD)"; \
	fi


IO_EX=EX-IOExpander
IO_EX_BRANCH := master
IO_EX_CONFIGS :=
IO_EX_BOARD := arduino:megaavr:nona4809

$(IO_EX):
	git clone https://github.com/DCC-EX/$@.git

update_io_ex: $(IO_EX)
	@cd $(IO_EX) && \
	git fetch origin && \
	git checkout -B $(IO_EX_BRANCH) origin/$(IO_EX_BRANCH)

$(IO_EX_CONFIGS): $(IO_EX)/%: %
	cp $< $@

compile_io_ex:
	arduino-cli compile $$BUILD_FLAGS -b $(IO_EX_BOARD) $(IO_EX)

upload_io_ex: compile_io_ex .board-info.mk
	@if [ "$(BOARD)" = "$(IO_EX_BOARD)" ]; then \
		arduino-cli upload -b $(IO_EX_BOARD) -p $(DEVICE) $(IO_EX); \
	else \
		echo "⚠️ Won't compile: expected $(IO_EX_BOARD), found $(BOARD)"; \
	fi


clean:
	@rm -f .board-info.mk

# Get the currently connected usb device and arduino board
.board-info.mk:
	@echo "🔍 Detecting connected Arduino board..."; \
	output="$$(arduino-cli board list | grep Arduino)"; \
	if [ -z "$$output" ]; then \
		echo "❌ ERROR: No Arduino board connected." >&2; exit 1; \
	fi; \
	device="$$(echo $$output | awk '{print $$1}')"; \
	board="$$(echo $$output | awk '{print $$(NF-1)}')"; \
	echo "✅ Found device: $$device"; \
	echo "✅ Found board: $$board"; \
	echo "DEVICE=$$device" > $@; \
	echo "BOARD=$$board" >> $@

# Include the file (auto includes once re-generated!) to load DEVICE and BOARD
-include .board-info.mk

