#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    bool loadImages();
    bool checkDirectory();
    void drawImage(int index, int alpha);

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
		
    ofDirectory dir;
    deque<ofImage> images;
    vector<string> imagePaths;
    
    int currentImage, nextImage;
    bool hasMedia;
    
    float beginImageTime; // store when we start time timer
    float nextImageTime; // when do want to stop the timer
    
    float fadeTime;
    
    int framesCounter;
    int imageDuration;
    
    int fadeDuration;
    
};
