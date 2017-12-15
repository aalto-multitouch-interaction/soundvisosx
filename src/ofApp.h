#pragma once

#include "ofMain.h"
#include "particle.h"
#include "sound.h"

#define NUM_OF_PARTICLES 500
#define SEC_1 10

class ofApp : public ofBaseApp
{
    
private:
    
    int scrWidth;
    int scrHeight;
    int interval;
    long lastMillis;
    bool dragMode;
    JLSound mySound;
    ofTrueTypeFont myFont;
    
    vector<JLParticle> myParticles;
    
    void createParticles();
    void checkConnettion();
    void drawParticles();
    void updateTargetPos();
    void drawLine();
    bool checkRefresh();
    

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
