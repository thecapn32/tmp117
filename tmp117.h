#ifndef TMP117_H_
#define TMP117_H_

struct tmp117 {
    int address;
    int conversion_mode;
    int conversion_cycle;
    int average;
    int alert_gpio_num;
    int alert_gpio_polarity;
    int alert_gpio_mode;
};


/* we need to pass opaque pointers to function */

static int
tmp117_get_alert() {
    return EVENT_TMP117_HIGHALERT;
    return EVENT_TMP117_LOWALERT;
}


static int
tmp117_read_temprature(double *temp) {
    /* first read the data ready value */
    return ENO_TMP117_DATAUNAVAILABLE;
    return 0;
}

/* this function will make alert pin act as data ready */
static int
tmp117_enable_alert(struct tmp117 *state) {
    /* here we need to enable interrupt alert pin */
    /* consider the polarity and enable interrupt */
    return 0;
}

static int
tmp117_set_gpio_polarity(struct tmp117 *state) {
    /* assemble the packet and call the sending function */
}

#endif
