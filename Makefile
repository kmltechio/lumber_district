CS_EX_DIR=CommandStation-EX

$(CS_EX_DIR)/config.h: config.h .env
	source .env && sed -e "s/Your network passwd/$$WIFI_PWD/" < config.h > $@
