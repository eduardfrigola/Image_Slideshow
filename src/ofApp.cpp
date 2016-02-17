#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //load images to vector;
    hasMedia = loadImages();
    if(hasMedia){
        currentImage=0;
        nextImage = currentImage+1;
        nextImage %= imagePaths.size();
        images.push_back(ofImage(imagePaths[currentImage]));
        images.push_back(ofImage(imagePaths[nextImage]));
    }
    
    //to use with time
//    beginImageTime = ofGetElapsedTimef();  // get the start time
//    nextImageTime = 3; // in seconds
//    fadeTime = 0.7;
    
    //use frames
    framesCounter = 0;
    imageDuration = 3; //in seconds, later to fps.
    imageDuration *= ofGetFrameRate();
    fadeDuration = 0.7 * ofGetFrameRate();
}

//--------------------------------------------------------------
void ofApp::update(){
//    if(ofGetElapsedTimef()-beginImageTime > nextImageTime){
//        currentImage++;
//        currentImage %= dir.size();
//        cout<<currentImage<<endl;
//        beginImageTime = ofGetElapsedTimef();
//    }
//    if(!hasMedia){
//        if(checkDirectory()){
//            loadImages();
//            hasMedia=true;
//            framesCounter=0;
//            currentImage=0;
//            nextImage = currentImage+1;
//            nextImage %= imagePaths.size();
//            images.push_back(ofImage(imagePaths[currentImage]));
//            images.push_back(ofImage(imagePaths[nextImage]));
//        }
//    }
    
    framesCounter++;
    if (framesCounter >= imageDuration){
        if(!checkDirectory()){
            hasMedia=false;
            images.clear();
            images.push_back(ofImage("wallpaper.jpg"));
        }
        if(hasMedia){
            currentImage++;
            currentImage %= imagePaths.size();
            nextImage = currentImage+1;
            nextImage %= imagePaths.size();
            images.pop_front();
            images.push_back(ofImage(imagePaths[nextImage]));
        }else if(checkDirectory()){
            loadImages();
            hasMedia=true;
            currentImage=0;
            nextImage = currentImage+1;
            nextImage %= imagePaths.size();
            images.clear();
            images.push_back(ofImage(imagePaths[currentImage]));
            images.push_back(ofImage(imagePaths[nextImage]));
        }
        framesCounter = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(hasMedia){
        ofHideCursor();
        int alphaValue = 255;
        //    if(ofGetElapsedTimef()-beginImageTime > nextImageTime-(fadeTime)){
        //        alphaValue = 255 - ((ofGetElapsedTimef()-beginImageTime)-(nextImageTime-(fadeTime)))/(fadeTime)*255;  //(ofGetElapsedTimef()-beginImageTime) * 255;
        //    }
        if(framesCounter > imageDuration-fadeDuration)
            alphaValue = 255 - float(framesCounter-(imageDuration-fadeDuration))/float(fadeDuration)*255;
        
        //draw current image
        drawImage(0, alphaValue);
        
        //draw next image
        if(alphaValue != 255){
            drawImage(1, (255-alphaValue));
        }
    }else
        drawImage(0, 255);
}

bool ofApp::loadImages(){
#if defined(TARGET_OSX)
        dir.listDir("/Volumes/USB");
#else
        dir.listDir("/media/usb");
#endif
    if(dir.size() == 0)
        return false;
        
    dir.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order
    
    // you can now iterate through the files and load them into the ofImage vector
    for(int i = 0; i < (int)dir.size(); i++){
        imagePaths.push_back(dir.getPath(i));
    }
    return true;
}

//--------------------------------------------------------------
bool ofApp::checkDirectory(){
#if defined(TARGET_OSX)
    dir.listDir("/Volumes/USB");
#else
    dir.listDir("/media/usb");
#endif
    return (dir.size() != 0);
}

void ofApp::drawImage(int index, int alpha){
    ofPushStyle();
    ofSetColor(255, 255, 255, alpha);
    images[index].draw(0,0);
    ofPopStyle();
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
