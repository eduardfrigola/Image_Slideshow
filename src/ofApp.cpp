#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //load images to vector;
    loadImages();
    currentImage=0;
    
    beginImageTime = ofGetElapsedTimef();  // get the start time
    nextImageTime = 1; // in seconds
    
    fadeTime = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetElapsedTimef()-beginImageTime > nextImageTime){
        currentImage++;
        currentImage %= dir.size();
        beginImageTime = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int alphaValue = (ofGetElapsedTimef()-beginImageTime) * 255;
    
    //draw current image
    ofPushStyle();
    ofSetColor(255, 255, 255, 255-alphaValue);
    images[currentImage].draw(0,0);
    ofPopStyle();
    
    //draw next image
    ofPushStyle();
    ofSetColor(255, 255, 255, alphaValue);
    int nextImage = currentImage+1;
    nextImage %= dir.size();
    images[nextImage].draw(0,0);
}

bool ofApp::loadImages(){
#if defined(TARGET_OSX)
        dir.listDir("/Volumes/USB");
#else
        dir.listDir("/media/usb");
#endif
    if(dir.size() == 0)
        OF_EXIT_APP(0);
        
    dir.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order
    
    //allocate the vector to have as many ofImages as files
    if( dir.size() ){
        images.assign(dir.size(), ofImage());
    }
    
    // you can now iterate through the files and load them into the ofImage vector
    for(int i = 0; i < (int)dir.size(); i++){
        images[i].load(dir.getPath(i));
    }
    return true;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentImage++;
    currentImage %= dir.size();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
