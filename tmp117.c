#include <stdio.h>
#include <string.h>

#include "tmp117.h"


static struct tmp117_config config;


int
tmp117_init(struct tmp117_config *conf) {
    memcpy(&config, conf, sizeof(struct tmp117_config));
    tmp117_set_gpio_polarity(struct tmp117_config *state) {
    printf("configuration done\n");
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


int
tmp117_read_temprature(double *temp) {
    /* first read the data ready value */
    /* temp = reg[0x00] * 0.0078125 */
    return TMP117_DATA_UNAVAILABLE;
    return TMP117_OK;
}


/* this function will make alert pin act as data ready */
int
tmp117_enable_alert(struct tmp117_config *state) {
    /* here we need to enable interrupt alert pin */
    /* consider the polarity and enable interrupt */
    return TMP117_OK;
}


static int
tmp117_set_gpio_polarity(struct tmp117_config *state) {
    /* assemble the packet and call the sending function */
    return TMP117_OK;
}
