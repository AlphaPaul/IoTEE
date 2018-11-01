/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LibUSBDemoControl.cpp
 * Author: paul
 * 
 * Created on October 28, 2018, 6:21 PM
 */

#include <iostream>

#include "LibUSBDemoControl.h"

//
// Constructors and Destructors
//

LibUSBDemoControl::LibUSBDemoControl() {
    demoDevice = NULL;
    ledData[1] = 0;
}

LibUSBDemoControl::LibUSBDemoControl(const LibUSBDemoControl& orig) {
}

LibUSBDemoControl::~LibUSBDemoControl() {
}

//
// Public Methods
//

// Objective here is to connect to the device as defined in the h file.
int LibUSBDemoControl::connect(){
    
    int res = 0;
    bool success = false;
    
    res = libusb_init(NULL);
    if(res != 0)
        return res;
    
    res = libusb_get_device_list(NULL, &devList);
    if(res < 0){
        return res;
    }
    
    for (int i = 0; i < res; i++){
        // Checking in the device list for the right device
        demoDevice = devList[i];
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(demoDevice, &desc);
        if(r < 0){
            std::cout << "error getting device descriptor: " << r << std::endl;
            continue;
        }
        if (desc.idProduct == DEMO_PRODUCT_ID){
            if (desc.idVendor == DEMO_VENDOR_ID){
                // we have found our device
                std::cout << "Device Found!" << std::endl;
                success = true;
                break;
            }
        }
    }
    if(!success){
        std::cout << "No Device Found" << std::endl;
        return 1;
    }
    
    res = libusb_open(demoDevice, &deviceHandle);
    if(res != 0){
        return res;
    }
    
    return res;
}

int LibUSBDemoControl::disconnect(){
    
    libusb_close(deviceHandle);
    libusb_free_device_list(devList, 0);
    
    
    return 0;
}

int LibUSBDemoControl::turnLedOn(int ledIndex){
    ledData[0] = DEMO_SET_LED_COMMAND;

    ledData[1] |= 0x01 << ledIndex;

    std::cout << "LedData: " << (unsigned int)ledData[0] << ":" << (unsigned int)ledData[1] << " || " << (0x01 << ledIndex) << " || " << ledIndex << std::endl;
    
    int ret = libusb_bulk_transfer(deviceHandle, DEMO_OUT_ENDPOINT_NUMBER, ledData,DEMO_OUT_ENDPOINT_LENGTH, NULL, DEMO_TIMEOUT_MS);
    
    return ret;
}

int LibUSBDemoControl::turnLedOff(int ledIndex){
    ledData[0] = DEMO_SET_LED_COMMAND; 
    ledData[1] &= ~(0x01 << ledIndex);
    std::cout << "LedData: " << (unsigned int)ledData[0] << ":" << (unsigned int)ledData[1] << std::endl;
    
    int ret = libusb_bulk_transfer(deviceHandle, DEMO_OUT_ENDPOINT_NUMBER, ledData,DEMO_OUT_ENDPOINT_LENGTH, NULL, DEMO_TIMEOUT_MS);
    
    return ret;
}

//
// Private Methods
//

//
// Getters and Setters
//



