#ifndef TMP117_H_
#define TMP117_H_

#define ENO_TMP117_NORESPONSE   -1
#define ENO_TMP117_INVALID      -2

#define TMP117_OK                0
#define TMP117_DATA_UNAVAILABLE  1

#define TMP117_READ              0
#define TMP117_WRITE             1

#define TMP117_REG_LEN           2

#define EVENT_TMP117_LOWALERT    0
#define EVENT_TMP117_HIGHALERT   1

#define TMP117_ENABLE_ALERT      0x10
#define TMP117_ALERT_POLARITY    0x08
#define TMP117_ALERT_ACTIVE_LOW  0x00
#define TMP117_ALERT_ACTIVE_HIGH 0x01

#define TMP117_ID_REG            0x0F
#define TMP117_ID                0x0117
#define TMP117_ID_MASK           0x0FFF

#define TMP117_TEMPRATURE_REG    0x00
#define TMP117_CONFIG_REG        0x01

#define TMP117_RESOLUTION      0.0078125

#define TMP117_DATA_READY_POS  13
#define TMP117_DATA_READY_BIT  (0x01 << TMP117_DATA_READY_POS)

#define TMP117_SET_REG(r, f)   r |= f
#define TMP117_CLEAR_REG(r, f) r &= ~f

#define TMP117_RD_CONCAT(msb, lsb)  (msb << 8) | lsb


struct tmp117_cmd {
    int type;
    int device_address;
    int reg_address;
    unsigned char wr_data[TMP117_REG_LEN];
    unsigned char rd_data[TMP117_REG_LEN];
};


typedef int (*tmp117_communicate) (struct tmp117_cmd *cmd);


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


int
tmp117_check(struct tmp117_config *conf);


/* we need to pass opaque pointers to function */
int
tmp117_get_alert(struct tmp117_config *state);


int
tmp117_read_temprature(struct tmp117_config *conf, float *temp);


/* this function will make alert pin act as data ready */
int
tmp117_enable_alert(struct tmp117_config *state);
#endif
