/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.e2dev.presentation;

import com.e2dev.boundary.BeanDataFacade;
import com.e2dev.entities.BeanData;
import java.util.List;
import javax.ejb.EJB;
import javax.inject.Named;
import javax.enterprise.context.RequestScoped;

/**
 *
 * @author paul
 */
@Named(value = "MessageView")
@RequestScoped
public class MessageView {

    @EJB
    private BeanDataFacade beanDataFacade;

    
    // Creates a new field
    private BeanData message;


    // Calls getMessage to retrieve the message
    public BeanData getMessage() {
       return message;
    }

    // Returns the total number of messages
    public int getNumberOfMessages(){
       return beanDataFacade.findAll().size();
    }
    
    public String getAllMessages(){
        List<BeanData> beanList = beanDataFacade.findAll();
        StringBuffer resStr = new StringBuffer();
        
        for(int i = 0; i < beanList.size(); i++){
            resStr.append(beanList.get(i).getMessage());
            resStr.append(" || ");
        }
        
        return new String(resStr);
        
    }

    // Saves the message and then returns the string "theend"
    public String postMessage(){
       this.beanDataFacade.create(message);
       return "theend";
    }
    
    /** Creates a new instance of MessageView */
    public MessageView() {
       this.message = new BeanData();
    }
    
}
