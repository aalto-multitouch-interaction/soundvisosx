#include "ofApp.h"

void ofApp::createParticles()
{
    JLParticle *temp;
    ofPoint pos;
    
    for (int i=0;i<NUM_OF_PARTICLES;i++)
    {
        temp = new JLParticle();
        
        pos.set(ofRandom(scrWidth) , ofRandom(scrHeight));
        
        temp->setup();
        temp->setOrgPos(pos);
        
        myParticles.push_back(*temp);
    }
}


bool ofApp::checkRefresh()
{
    long diff;
    bool result;
    float *fftSmooth;
    
    result = false;
    
    diff = (ofGetElapsedTimeMillis() - lastMillis);
    
    if (diff >= SEC_1)
    {
        interval = ofRandom(0,3);
        
        lastMillis = ofGetElapsedTimeMillis();
        
        result = true;
    }
    
    return result;
}

void ofApp::checkConnettion()
{
    int tempCount;
    bool connected;
    
    ofSetColor(255,30);
    
    tempCount = myParticles.size();
    
    for (int i=0;i<tempCount;i++)
    {
        for (int j=i;j<tempCount;j++)
        {
            connected = myParticles[i].isConnected(myParticles[j].getcurPos());
            
            if (connected == true)
            {
                ofDrawLine(myParticles[i].getcurPos(),myParticles[j].getcurPos());
            }
        }
    }
}

void ofApp::updateTargetPos()
{
    float indexOffset;
    float scale;
    int index;
    int directionX;
    int directionY;
    ofPoint pos;
    float *fftSmooth;
    
    fftSmooth = mySound.getFFT();
        
    index = 1;
    
    indexOffset = 10;
    
    for (int i=0;i<myParticles.size();i++)
    {
        //pos.set(ofRandom(scrWidth) , ofRandom(scrHeight));
        
        indexOffset += 0.06;
        
        scale = fftSmooth[0] * 0.2;
        
        index  = round(indexOffset);
    
        directionX = ofRandom(-fftSmooth[index] , fftSmooth[index]) * scale;
        directionY = ofRandom(-fftSmooth[index] , fftSmooth[index]) * scale;
        
        if (directionX == 0)
        {
            directionX = 1;
        }
        
        if (directionY == 0)
        {
            directionY = 1;
        }
        
        pos.set(directionX , directionY);
        
        myParticles[i].setTargetPos(pos);
        
        //ofDrawLine(i*2,500,i*2,500-fftSmooth[index]);
    }
    
}

void ofApp::drawParticles()
{
    for (int i=0;i<myParticles.size();i++)
    {
        myParticles[i].draw();
    }
}

void ofApp::drawLine()
{
    float *fftSmooth;
    
    fftSmooth = mySound.getFFT();
    
    for (int i=0;i<512;i++)
    {
        if (i == 10)
        {
            ofSetColor(255,0,0);
        }
        else
        {
            ofSetColor(255);
        }
        
        ofDrawLine(i*2,500,i*2,500-fftSmooth[i]);
    }
}


//--------------------------------------------------------------


void ofApp::setup()
{
    interval = 0;
    
    lastMillis = ofGetElapsedTimeMillis();
    
    scrWidth = ofGetScreenWidth();
    scrHeight = ofGetScreenHeight();
    
    myFont.load("ITCAvantGardePro-Bk.otf", 20 , true , true , true);
    
    mySound.setup();
    
    ofBackground(0);
    
    createParticles();
    
    ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update()
{
    mySound.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    checkConnettion();
    
    drawParticles();
    
    if(checkRefresh() == true && dragMode == false)
    {
      updateTargetPos();
    }
    
    ofSetColor(255);
    
    //ofDrawLine(scrWidth-200,scrHeight-70 , scrWidth-180,scrHeight-70);
    
    myFont.drawString("Daft Funk", scrWidth-200,scrHeight-50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    ofPoint pos;
    
    dragMode = true;
    
    pos.set(x, y);
    
    for (int i=0;i<myParticles.size();i++)
    {
        myParticles[i].setTargetPos2(pos);
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
   

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    dragMode = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
