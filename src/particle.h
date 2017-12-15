//
//  particle.h
//  soundvis
//
//  Created by jlsy012 on 2017. 12. 13..
//

#pragma once

#define APPROX_DIST 120

#include "ofMain.h"

class JLParticle
{
    
    //--------- private member property area---------------//
    
    
    
private:
    

    ofPoint orgPos;
    ofPoint curPos;
    ofPoint targetPos;
    ofPoint curAcc;
    
    
    
    //--------- public member property area ---------------//
    
    //--------- private member method area ----------------//
    
    void move();
    
    //--------- public member method area -----------------//
    
    
public:
    
    void setup();
    void setOrgPos(ofPoint pos);
    void setTargetPos(ofPoint pos);
    void setTargetPos2(ofPoint pos);
    void setAcc(ofPoint acc);
    void update();
    void draw();
    bool isConnected(ofPoint &destPos);
    ofPoint& getcurPos();
    
    
};
