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
    return 0;
}

int LibUSBDemoControl::turnLedOn(int ledIndex){
    return 0;
}

int LibUSBDemoControl::turnLedOff(int ledIndex){
    return 0;
}

//
// Private Methods
//

//
// Getters and Setters
//



