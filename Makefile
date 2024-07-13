CS_EX=CommandStation-EX

# Edit this to build a specific branch of CommandStation-EX
CS_EX_BRANCH=master
# Add any files here that you need straight copied into the CS_EX directory
CONFIGS=$(CS_EX)/myAutomation.h
# Add any files here that you need 1Password values interpolated into then
# copied into the CS_EX directory
CONFIGS_W_SECRETS=$(CS_EX)/config.h

IO_EX=EX-IOExpander

all: update_cs_ex $(IO_EX) config

$(CS_EX):
	git clone https://github.com/DCC-EX/$@.git

$(IO_EX):
	git clone https://github.com/DCC-EX/$@.git

update_cs_ex: $(CS_EX)
	cd $(CS_EX); \
	git pull; \
	git switch $(CS_EX_BRANCH)

config: check_op $(CONFIGS) $(CONFIGS_W_SECRETS)

check_op:
	@op account get > /dev/null 2>&1 || echo 'Please log in to op: eval $$(op signin)'

$(CONFIGS): $(CS_EX)/%: %
	cp $< $@

$(CONFIGS_W_SECRETS): $(CS_EX)/%: %
	op inject -f -i $< -o $@

# TODO check for local modifications before removing
clean:
	rm -rf $(CS_EX)

.PHONY: all check_op clean config update_cs_ex
