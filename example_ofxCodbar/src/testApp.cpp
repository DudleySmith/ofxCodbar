#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // STANDARD EAN13 : no prefix, no suffix, length : 13 caracters
    m_oCodbar = ofxCodbar("", "", 13);
 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    // We announce what we do
    ofDrawBitmapString("Example ofxCodbar : Addon for codbar scanners.", 0.5*ofGetWidth(), 25);
    ofDrawBitmapString("r/R to reset the code and wait a new one", 25, 50);
    
    ofPushStyle();
    // Orange : Code incomplete
    // Green : Code OK
    if(m_oCodbar.isFullyScanned()){
        ofSetColor(ofColor::green);
    }else{
        ofSetColor(ofColor::orangeRed);
    }
    ofDrawBitmapString("Code Scanned : " + m_oCodbar.get_codbar(), 50, 75);
    ofPopStyle();
    
    // Display
    list<string>::iterator oneKey;
    int idx = 0;

    for(oneKey=m_aMsgs.begin(); oneKey!=m_aMsgs.end(); oneKey++){
        ofDrawBitmapString((*oneKey), 50, 100 + 10*idx++);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    // Add the key entered
    m_oCodbar.addKeyToCode(key);
    
    // Display
    string msg = "";
    char keyChar = key;
    
    msg = ofGetTimestampString() + " : ";
    msg += "Int= " + ofToString(key, 3, '0') + " : ";
    msg += "Char= " + ofToString(keyChar);

    m_aMsgs.push_back(msg);
    // Resize the list to avois uselesse messages
    if(m_aMsgs.size()>=40){
        m_aMsgs.pop_front();
    }
    
    if(key == 'r' || key=='R'){
        m_oCodbar.openCode();
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}