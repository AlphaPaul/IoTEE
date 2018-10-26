/*
 * 
 * Copyright Paul Fetet 2018
 * These demo applications are not to be used
 * in production. I Cannot be liable of anything
 * and will never guarantee this code works,
 * or serves a particular purpose
 */
package com.e2dev.jni;

import java.util.StringTokenizer;

/**
 *
 * Singleton to initiate the JNI Communication
 * 
 * @author paul
 */
public class JNILinker {
    
    private static JNILinker singleton = null;
    
    
    // Native Calls
    private native int getNativeStatus();
    private native int sendCommand(String command);
    
    //
    // Constructor
    //
    private JNILinker(){
        
    }
    
    public static JNILinker getInstance(){
        if(singleton == null){
            singleton = new JNILinker();
        }
        return singleton;
    }
    
    // 
    // Public Methods
    //
    public void loadLibrary(){
        try {
            String property = System.getProperty("java.library.path");
            StringTokenizer parser = new StringTokenizer(property, ":");
            while (parser.hasMoreTokens()) {
                System.err.println(parser.nextToken());
            }
            System.loadLibrary("IoTEEJNI");
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
    
    public int geJNIStatus(){
        return this.getNativeStatus();
    }
    
    public int sendJNICommand(String command){
        return this.sendCommand(command);
    }
    
    //
    // Private Methods
    //
    
    //
    // Getters and Setters
    //
    
}
