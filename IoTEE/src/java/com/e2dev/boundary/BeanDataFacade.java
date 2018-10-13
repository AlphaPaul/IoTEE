/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.e2dev.boundary;

import com.e2dev.entities.BeanData;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

/**
 *
 * @author paul
 */
@Stateless
public class BeanDataFacade extends AbstractFacade<BeanData> {

    @PersistenceContext(unitName = "IoTEEPU")
    private EntityManager em;

    @Override
    protected EntityManager getEntityManager() {
        return em;
    }

    public BeanDataFacade() {
        super(BeanData.class);
    }
    
}
