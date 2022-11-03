CS_EX=CommandStation-EX
BRANCH=PORTX_HAL_cursense2_HIGHMEM

CONFIGS=$(CS_EX)/myAutomation.h
CONFIGS_W_SECRETS=$(CS_EX)/config.h

all: update_cs_ex config

$(CS_EX):
	git clone https://github.com/DCC-EX/$@.git

update_cs_ex: $(CS_EX)
	cd $(CS_EX); \
	git pull; \
	git switch $(BRANCH)

config: check_op $(CONFIGS) $(CONFIGS_W_SECRETS)

check_op:
	@op account get > /dev/null 2>&1 || echo 'Please log in to op: eval $$(op signin)'

$(CONFIGS): $(CS_EX)/%: %
	cp $< $@

$(CONFIGS_W_SECRETS): $(CS_EX)/%: %
	op inject -f -i $< -o $@

clean:
	rm -rf $(CS_EX)

.PHONY: all check_op clean config update_cs_ex
