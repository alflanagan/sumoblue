#if !defined(__SUMOBLUEFRUIT_H)
#define __SUMOBLUEFRUIT_H

#include "Adafruit_BluefruitLE_SPI.h"
#include "SumoBluefruitConfig.h"

/**
 * SumoBluefruit
 * 
 * Higher-level interface for the things we use the Bluefruit for.
 */
class SumoBluefruit {
    private:
        Adafruit_BluefruitLE_SPI ble = Adafruit_BluefruitLE_SPI(BLUEFRUIT_SPI_CS, 
                                                                BLUEFRUIT_SPI_IRQ,
                                                                BLUEFRUIT_SPI_RST);
        // avoiding exceptions, so remember failure (any value > 0)
        unsigned int status = 1;  // uninitialized
        // and store last error message
        const __FlashStringHelper *last_error = NULL;
        void signal_error(const unsigned err_code, const __FlashStringHelper *err_msg);
    public:
        SumoBluefruit ();
        // normally would set up in constructor, but that's not working (?)
        // think I understand why but not sure
        void setup();
        const inline unsigned get_status() { return status; }
        const inline __FlashStringHelper *get_error() { return last_error; }
        inline int available(void) { return ble.available(); }
        inline int read(void) { return ble.read(); }
        char read_uart(void);
};

#endif