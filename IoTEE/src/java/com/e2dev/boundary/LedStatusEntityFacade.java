/*
 * 
 * Copyright Paul Fetet 2018
 * These demo applications are not to be used
 * in production. I Cannot be liable of anything
 * and will never guarantee this code works,
 * or serves a particular purpose
 */
package com.e2dev.boundary;

import com.e2dev.entities.LedStatusEntity;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

/**
 *
 * @author paul
 */
@Stateless
public class LedStatusEntityFacade extends AbstractFacade<LedStatusEntity> {

    @PersistenceContext(unitName = "IoTEEPU")
    private EntityManager em;

    @Override
    protected EntityManager getEntityManager() {
        return em;
    }

    public LedStatusEntityFacade() {
        super(LedStatusEntity.class);
    }
    
}
