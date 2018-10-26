/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <jni.h>
#include <stdio.h>
#include <math.h>



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
    return 42;
}


