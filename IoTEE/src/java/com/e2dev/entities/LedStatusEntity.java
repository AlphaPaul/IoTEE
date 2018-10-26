/*
 * 
 * Copyright Paul Fetet 2018
 * These demo applications are not to be used
 * in production. I Cannot be liable of anything
 * and will never guarantee this code works,
 * or serves a particular purpose
 */
package com.e2dev.entities;

import com.e2dev.jni.JNILinker;
import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.validation.constraints.NotNull;

/**
 *
 * @author paul
 */
@Entity
public class LedStatusEntity implements Serializable {

    private static final long serialVersionUID = 1L;
    
    // JNI Link
    private transient JNILinker jniLink;
    
    // Variables accessed by the webpage
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private String className;
    private String jniStatus;
    
    //
    // Constructor
    //
    public LedStatusEntity(){
        jniLink = JNILinker.getInstance();
        className = new String("LedStatusEntity");
        jniStatus = new String("Status Not Updated");
    }
    
    // 
    // Public Methods
    //
    public void loadjniLibrary(){
        jniLink.loadLibrary();
    }
    
    
    public void updateJNIStatus(){
        
        jniStatus = "Last received Status: " + jniLink.geJNIStatus();
        
    }

    //
    // Private Methods
    //
    
    //
    // Getters and Setters
    //

    public String getJniStatus() {
        return jniStatus;
    }

    public void setJniStatus(String jniStatus) {
        this.jniStatus = jniStatus;
    }
    
    
    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }
    
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }
    
    //
    // Overrides
    //
    
    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof LedStatusEntity)) {
            return false;
        }
        LedStatusEntity other = (LedStatusEntity) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "com.e2dev.entities.LedStatusEntity[ id=" + id + " ]";
    }
    
}
