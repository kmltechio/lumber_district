.PHONY: all compile setup \
	compile_cs_ex setup_cs_ex upload_cs_ex \
	compile_io_ex setup_io_ex upload_io_ex

all: compile

setup: setup_cs_ex setup_io_ex

compile: compile_cs_ex compile_io_ex


CS_EX := CommandStation-EX
CS_EX_BRANCH := master
CS_EX_CONFIGS := $(CS_EX)/config.h $(CS_EX)/myAutomation.h \
	$(CS_EX)/myPassengerLoop.h $(CS_EX)/myPins.h $(CS_EX)/myRoster.h \
	$(CS_EX)/myTrolley.h $(CS_EX)/myTurnouts.h
CS_EX_BOARD := arduino:avr:mega

$(CS_EX):
	git clone https://github.com/DCC-EX/$@.git

setup_cs_ex: $(CS_EX)
	@cd $(CS_EX) && \
	git fetch origin && \
	git checkout -B $(CS_EX_BRANCH) origin/$(CS_EX_BRANCH)

$(CS_EX_CONFIGS): $(CS_EX)/%: %
	cp $< $@

# Injects the wifi ssid and pwd from 1Password into the compile process
compile_cs_ex: $(CS_EX_CONFIGS)
	@echo Compiling $(CS_EX); \
	WIFI_SSID="$$(op read 'op://Family/WiFi - Home/network name')"; \
	WIFI_PASSWORD="$$(op read 'op://Family/WiFi - Home/wireless network password')"; \
	arduino-cli compile --build-property compiler.cpp.extra_flags="-DWIFI_SSID=\"$$WIFI_SSID\" -DWIFI_PASSWORD=\"$$WIFI_PASSWORD\"" -b $(CS_EX_BOARD) $(CS_EX); \

upload_cs_ex: compile_cs_ex
	@echo ; \
	./upload.sh $(CS_EX_BOARD) $(CS_EX)


IO_EX=EX-IOExpander
IO_EX_BRANCH := kml-add-nano-every-support
IO_EX_CONFIGS := $(IO_EX)/myConfig.h
IO_EX_BOARD := arduino:megaavr:nona4809

$(IO_EX):
	git clone https://github.com/kmltechio/$@.git
#	git clone https://github.com/DCC-EX/$@.git

setup_io_ex: $(IO_EX)
	@cd $(IO_EX) && \
	git fetch origin && \
	git checkout -B $(IO_EX_BRANCH) origin/$(IO_EX_BRANCH)

$(IO_EX_CONFIGS): $(IO_EX)/%: %
	cp $< $@

compile_io_ex: $(IO_EX_CONFIGS)
	@echo Compiling $(IO_EX); \
	I2C_ADDRESS="${I2C_ADDRESS}"; \
	[ -z "$$I2C_ADDRESS" ] && I2C_ADDRESS=0x65; \
	echo "\tI2C_ADDRESS=$$I2C_ADDRESS"; \
	arduino-cli compile --build-property compiler.cpp.extra_flags="-DI2C_ADDRESS=$$I2C_ADDRESS" -b $(IO_EX_BOARD) $(IO_EX)

upload_io_ex: compile_io_ex
	@echo ; \
	./upload.sh $(IO_EX_BOARD) $(IO_EX)
