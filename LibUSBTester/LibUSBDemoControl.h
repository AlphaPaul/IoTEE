/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LibUSBDemoControl.h
 * Author: paul
 *
 * Created on October 28, 2018, 6:21 PM
 */

#ifndef LIBUSBDEMOCONTROL_H
#define LIBUSBDEMOCONTROL_H

#include <libusb-1.0/libusb.h>

#define MAX_ENDPOINT_SIZE   64
#define DATA_ENDPOINT_ID    1
// vendor ID and Product ID are defined in the device descriptor
#define DEMO_VENDOR_ID      0x04D8
#define DEMO_PRODUCT_ID     0x0204


class LibUSBDemoControl {
public:
    LibUSBDemoControl();
    LibUSBDemoControl(const LibUSBDemoControl& orig);
    virtual ~LibUSBDemoControl();
    
    int connect();
    int disconnect();
    int turnLedOn(int ledIndex);
    int turnLedOff(int ledIndex);
    
    
private:
    libusb_device* demoDevice;
    libusb_device_handle * deviceHandle;
    // keeping devList because it needs to be freed on exit
    libusb_device ** devList;

};

#endif /* LIBUSBDEMOCONTROL_H */

