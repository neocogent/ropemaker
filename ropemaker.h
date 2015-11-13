// ropemaker definitions

#ifndef ROPEMAKER_H
#define ROPEMAKER_H

#define BAUD_RATE           115200
#define HTTP_BUFFER_SIZE    256 // must be multiple of 4

#define TICK_RATE           100 // uS per tick 
#define TICKS_SCAN          500 // ticks per foot/btn scan
#define TICKS_SEC           10000 // ticks per second for speed calc
#define LOAD_SPEED          25 // run btn steps/sec feed, 0.5cm/sec
#define STEPS_METER         5013 // feed based on 1/2" roller, before calibrated for slip

typedef struct {
    
    int speed;      // steps/sec,  <0 max foot speed, >0 preset speed, =0 stopped
    
    unsigned int scan_count;
    unsigned int spin_count;
    unsigned int feed_count;
    
    unsigned int feed_total;
    unsigned int feed_stop;
    
    unsigned int foot_speed;
    
} runparms;

typedef struct {
    
    char ssid[32];
    char pwd[64];
    char hostname[32];
    
    int speed;      // steps/sec, <0 max foot speed, >0 preset speed, =0 stopped
    int twist16;    // twist ratio *16, <0 ccw, >0 cw  (feed steps *16 per spin step)
    
    // todo: foot adc map
    // todo: rope meter calibration 
    // todo: spin acceleration limits
} sysparms;
    
// GPIO pin mappings
#define RUN_BTN     0
#define SPIN_STEP   12
#define SPIN_DIR    14
#define FEED_STEP   13
#define STEP_ENABLE 4

void wifi_handler( System_Event_t *evt );

#endif
