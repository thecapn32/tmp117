#ifndef TMP117_H_
#define TMP117_H_

#define ENO_TMP117_NORESPONSE      -1

#define EVENT_TMP117_LOWALERT  0
#define EVENT_TMP117_HIGHALERT 1

#define TMP117_OK 0
#define TMP117_DATA_UNAVAILABLE 1

typedef int (*tmp117_communicate) (unsigned char *data,
        unsigned char *response);


struct tmp117_config {
    int address;
    int conversion_mode;
    int conversion_cycle;
    int average;
    int alert_gpio_num;
    int alert_gpio_polarity;
    int alert_gpio_mode;
    tmp117_communicate communicate;
};


int
tmp117_init(struct tmp117_config *tmp117);


/* we need to pass opaque pointers to function */
int
tmp117_get_alert(struct tmp117_config *state);


int
tmp117_read_temprature(double *temp);


/* this function will make alert pin act as data ready */
int
tmp117_enable_alert(struct tmp117_config *state);
#endif
