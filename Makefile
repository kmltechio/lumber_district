DEST=CommandStation-EX
BRANCH=PORTX_HAL_cursense2_HIGHMEM
FILES=$(DEST)/myAutomation.h
FILES_W_SECRETS=$(DEST)/config.h

all: $(DEST) update $(FILES) $(FILES_W_SECRETS)

$(DEST):
	git clone https://github.com/DCC-EX/CommandStation-EX.git

update:
	cd $(DEST); \
	git switch $(BRANCH); \
	git pull

$(FILES): $(DEST)/%: %
	cp $< $@

$(FILES_W_SECRETS): $(DEST)/%: %
	eval $$(op signin); \
	op inject -f -i $< -o $@

.PHONY: all update
