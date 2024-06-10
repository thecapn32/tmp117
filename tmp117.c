#include <stdio.h>
#include <string.h>

#include "tmp117.h"


static struct tmp117_config config;
static struct tmp117_cmd cmd;


int
tmp117_init(struct tmp117_config *conf) {
    config.address = conf->address;
    cmd.device_address = conf->address;
    config.communicate = conf->communicate;
    // tmp117_set_gpio_polarity(conf);
    /* only need to configure 0x01 register once */
    return TMP117_OK;
}


int
tmp117_check(struct tmp117_config *conf) {
    cmd.type = TMP117_READ;
    cmd.reg_address = TMP117_ID_REG;
    conf->communicate(&cmd);
    unsigned int tmp117_id = TMP117_RD_CONCAT(cmd.rd_data[0], cmd.rd_data[1]);

    if ((tmp117_id & TMP117_ID_MASK) != TMP117_ID) {
        return ENO_TMP117_INVALID;
    }
    return TMP117_OK;
}


int
tmp117_get_alert(struct tmp117_config *tmp117) {
    return EVENT_TMP117_HIGHALERT;
    return EVENT_TMP117_LOWALERT;
}


int
tmp117_enable_continousconversion() {
    /* reg[0x01][11] = 0*/
    /* reg[0x01][10] = 0*/
    return TMP117_OK;
}


static int
tmp117_data_ready(struct tmp117_config *conf) {
    cmd.type = TMP117_READ;
    cmd.reg_address = TMP117_CONFIG_REG;
    conf->communicate(&cmd);
    unsigned int reg_value = (cmd.rd_data[0] << 8) | cmd.rd_data[1];

    if (reg_value & TMP117_DATA_READY_BIT) {
        return TMP117_OK;
    }
    return TMP117_DATA_UNAVAILABLE;
}


int
tmp117_read_temprature(struct tmp117_config *conf, float *temp) {
    int rc = tmp117_data_ready(conf);
    if (rc == TMP117_OK) {
        cmd.type = TMP117_READ;
        cmd.reg_address = TMP117_TEMPRATURE_REG;
        conf->communicate(&cmd);
        unsigned int reg_value = TMP117_RD_CONCAT(cmd.rd_data[0],
                cmd.rd_data[1]);
        *temp = reg_value * TMP117_RESOLUTION;
        return TMP117_OK;
    }
    return TMP117_DATA_UNAVAILABLE;
}


int
tmp117_enable_alert(struct tmp117_config *state) {
    return TMP117_OK;
}


static int
tmp117_set_gpio_polarity(struct tmp117_config *state) {
    char conf;
    if (state->alert_gpio_polarity == TMP117_ALERT_ACTIVE_LOW) {
        // TMP117_CLEAR_BIT(conf, TMP117_ALERT_POLARITY);
    }
    else if(state->alert_gpio_polarity == TMP117_ALERT_ACTIVE_HIGH) {
        // TMP117_SET_BIT(conf, TMP117_ALERT_POLARITY);
    }
    else {
        return ENO_TMP117_INVALID;
    }
    return TMP117_OK;
}
