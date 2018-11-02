/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "com_e2dev_jni_JNILinker.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "LibUSBDemoControl.h"


// Command Definitions
//
#define LED_OFF_PREFIX  0
#define LED_ON_PREFIX   10
#define MAX_LED_ID      8

#define CONNECT_COMMAND     20
#define DISCONNECT_COMMAND  21

static bool disconnected = true;
LibUSBDemoControl *usbDemo = NULL;


/*
 * Class:     com_e2dev_jni_JNILinker
 * Method:    getNativeStatus
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_e2dev_jni_JNILinker_getNativeStatus
  (JNIEnv * env, jobject obj){
    
    return rand();
}

/*
 * Class:     com_e2dev_jni_JNILinker
 * Method:    sendCommand
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_e2dev_jni_JNILinker_sendCommand
  (JNIEnv * env, jobject obj, jstring cmd){
    
    
    const char *nativeString = env->GetStringUTFChars(cmd, 0);
    long input = strtol(nativeString, NULL, 0);
    
    if(usbDemo == NULL){
        usbDemo = new LibUSBDemoControl();
    }
    
    int ret;
    
    if(input >= LED_OFF_PREFIX && input < MAX_LED_ID + LED_OFF_PREFIX){
            // Turn off
            std::cout << "Turning led off: " << input - LED_OFF_PREFIX << std::endl;
            ret = usbDemo->turnLedOff(input - LED_OFF_PREFIX);
            std::cout << "CCommand sent with return code (0 is success): " << ret << std::endl;
            std::cout << "Error Meaning: " << libusb_error_name(ret) << std::endl;
        }
        else if(input >= LED_ON_PREFIX && input < MAX_LED_ID + LED_ON_PREFIX){
            std::cout << "Turning led on: " << input - LED_ON_PREFIX << std::endl;
            ret = usbDemo->turnLedOn(input - LED_ON_PREFIX);
            std::cout << "CCommand sent with return code (0 is success): " << ret << std::endl;
            std::cout << "Error Meaning: " << libusb_error_name(ret) << std::endl;
        }
        else if(input == CONNECT_COMMAND){
            std::cout << "Connecting" << std::endl;
            ret = usbDemo->connect();
            std::cout << "Connected with return code (0 is success): " << ret << std::endl;
            std::cout << "Error Meaning: " << libusb_error_name(ret) << std::endl;
            if(ret == 0){
                disconnected = false;
            }
            
        }
        else if (input == DISCONNECT_COMMAND){
            std::cout << "Disconnecting" << std::endl;
            ret = usbDemo->disconnect();
            std::cout << "Connected with return code (0 is success): " << ret << std::endl;
            std::cout << "Error Meaning: " << libusb_error_name(ret) << std::endl;
            if(ret == 0){
                disconnected = true;
            }
        }
        else{
            std::cout << "invalid command: " << input << std::endl;
            ret = -42;
        }
    
    
    env->ReleaseStringUTFChars(cmd, nativeString);
    
    return ret;
}


