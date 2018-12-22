#include "SumoBluefruit.h"

SumoBluefruit::SumoBluefruit() {
}

void SumoBluefruit::setup() {
    if ( !ble.begin(VERBOSE_MODE) )
    {
        signal_error(2, F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
    } else {
        /* Perform a factory reset to make sure everything is in a known state */
        if ( ! ble.factoryReset() ){
            signal_error(3, F("Couldn't factory reset"));
        } else {
            ble.setMode(BLUEFRUIT_MODE_DATA);
            // enable callbacks (not too often)
            ble.update(200);
            status = 0;  // yay, it worked
        }
    }
}

void SumoBluefruit::signal_error(const unsigned err_code, 
                                 const __FlashStringHelper *err_msg) {
    // for now, just set error variables
    status = err_code;
    last_error = err_msg;
}

char SumoBluefruit::read_uart (void) {
    int value = read();
    return (char) value;
}