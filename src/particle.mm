//
//  particle.m
//  soundvis
//
//  Created by jlsy012 on 2017. 12. 13..
//

#include "particle.h"




//--------- private member method area ----------------//


void JLParticle::move()
{
    ofPoint temp;
    
    temp = (targetPos - curPos)/7;//.normalize();
    
    //temp = (curPos - orgPos);//.normalize();
    
    curPos += temp;
    
    ofSetColor(255,70);
    
    //ofDrawRectangle(curPos,5,5);
    //ofDrawEllipse(curPos,2,2);
}



//--------- public member method area -----------------//


void JLParticle::setup()
{
    
    ofSetColor(255);
    
}

void JLParticle::setOrgPos(ofPoint pos)
{
    orgPos.set(pos);
    curPos.set(pos);
    targetPos.set(pos);
}

void JLParticle::setTargetPos(ofPoint pos)
{
    pos = (orgPos + pos);
 
    targetPos.set(pos);
}

void JLParticle::setTargetPos2(ofPoint pos)
{
    targetPos.set(pos);
}

void JLParticle::setAcc(ofPoint acc)
{
    curAcc.set(acc);
}

ofPoint& JLParticle::getcurPos()
{
    return curPos;
}

bool JLParticle::isConnected(ofPoint &destPos)
{
    float dist;
    bool connected;
  
    connected = false;
    
    dist = curPos.distance(destPos);
    
    if (dist <= APPROX_DIST)
    {
        connected = true;
    }

    return connected;
}

void JLParticle::update()
{
    
    ;
    
}

void JLParticle::draw()
{
    move();
}
