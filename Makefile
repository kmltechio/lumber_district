CS_EX=CommandStation-EX
# Edit this to build a specific branch of CommandStation-EX
CS_EX_BRANCH=master
# Files that need to have 1Password values interpolated into them and then
# copied into the CS_EX directory
CS_EX_CONFIGS_W_SECRETS=$(CS_EX)/config.h
# Files that need to be copied into the CS_EX directory
CS_EX_CONFIGS=$(CS_EX)/myAutomation.h $(CS_EX)/myRoster.h $(CS_EX)/myTrolley.h \
    $(CS_EX)/myPassengerLoop.h

IO_EX=EX-IOExpander

all: update_cs_ex $(IO_EX) config_cs_ex

$(CS_EX):
	git clone https://github.com/DCC-EX/$@.git

$(IO_EX):
	git clone https://github.com/DCC-EX/$@.git

update_cs_ex: $(CS_EX)
	cd $(CS_EX); \
	git pull; \
	git switch $(CS_EX_BRANCH)

config_cs_ex: check_op $(CS_EX_CONFIGS) $(CS_EX_CONFIGS_W_SECRETS)

check_op:
	@op account get > /dev/null 2>&1 || echo 'Please log in to op: eval $$(op signin)'

$(CS_EX_CONFIGS): $(CS_EX)/%: %
	cp $< $@

$(CS_EX_CONFIGS_W_SECRETS): $(CS_EX)/%: %
	op inject -f -i $< -o $@

# TODO check for local modifications before removing
clean:
	rm -rf $(CS_EX)

.PHONY: all check_op clean config_cs_ex update_cs_ex
