/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paul
 *
 * Created on October 28, 2018, 7:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

#include "LibUSBDemoControl.h"

using namespace std;

/*
 * 
 */

// Command Definitions
//
#define LED_OFF_PREFIX  0
#define LED_ON_PREFIX   10
#define MAX_LED_ID      8

#define CONNECT_COMMAND     20
#define DISCONNECT_COMMAND  21
#define EXIT_COMMAND        42


int main(int argc, char** argv) {

    int input;
    LibUSBDemoControl *usbDemo = new LibUSBDemoControl();
    
    while(1){
        cout << "Input the Command:\nTurn OFF: 0--7; Turn ON 10--17\n Connect 20; Disconnect 21\nExit with 42" << endl;
        cin >> input;
        
        if(input >= LED_OFF_PREFIX && input < MAX_LED_ID + LED_OFF_PREFIX){
            // Turn off
            cout << "Turning led off: " << input - LED_OFF_PREFIX << endl;
        }
        else if(input >= LED_ON_PREFIX && input < MAX_LED_ID + LED_ON_PREFIX){
            cout << "Turning led on: " << input - LED_ON_PREFIX << endl;
        }
        else if(input == CONNECT_COMMAND){
            cout << "Connecting" << endl;
            int ret = usbDemo->connect();
            cout << "Connected with return code (0 is success): " << ret << endl;
            
        }
        else if (input == DISCONNECT_COMMAND){
            cout << "Disconnecting" << endl;
        }
        else if (input == EXIT_COMMAND){
            cout << "Good Bye!" << endl;
            break;
        }
        else{
            cout << "invalid command: " << input << endl;
        }
        
    }
    return 0;
}

