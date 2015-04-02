#include "ofApp.h"

/* Joni's Seaweed
This code creates a simulated strand of seaweed for your screen.*/

//--------------------------------------------------------------
void ofApp::setup(){

	multi = -100; //This is for the last point and control point of the Polyline, because I was tired of changing the same number twice.
	ofSetFrameRate(80);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	angle3 = ofGetElapsedTimef(); //Angle for top movement
	angle2 = ofGetElapsedTimef()*.5; //Angle for middle movement
	angle1 = ofGetElapsedTimef()*.25; //Angle for (almost) bottom movement
	
	curvedSegmentPolyline.curveTo(512, 750);  //Base, doesn't move.
	curvedSegmentPolyline.curveTo(512, 750);  // Necessary Duplicate for Control Point
	curvedSegmentPolyline.curveTo((-100*cos(angle1))+500, 400); //Almost bottom. Cos gives a curvy movement. 
	curvedSegmentPolyline.curveTo((-100*cos(angle2))+500, 200);  //Middle. Adding 500 (after the () for the multiplication!) keeps it centered, else it goes off the screen.
	curvedSegmentPolyline.curveTo((multi*cos(angle3))+500, 50); //Top. The multipliers let us determine how far out the points move. Bigger absolute value = wider movement.
	curvedSegmentPolyline.curveTo((multi*cos(angle3))+500, 50);  // Necessary Duplicate for Control Point

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetLineWidth(2.0);  //For all the lines

	float numPoints = curvedSegmentPolyline.size();
	for (int p=0; p<800; p+=10) {
		
		chloroform = ofColor(10, 220, 100); //This is so we can have live, healthy seaweed :)
		chloroform.setBrightness(p/2);
		ofSetColor(chloroform);

		ofVec3f point = curvedSegmentPolyline.getPointAtPercent(p/800.0); //This is how we tell it how many strands the seaweed should have. Bigger=More
		float length = (point.y/8); //This determines the length of the strands, so that they become smaller as they move up.
		float floatIndex = p/50.0 * (numPoints-1); //Keeping this number low makes sure the strands don't glitch.
		ofVec3f normal = curvedSegmentPolyline.getNormalAtIndexInterpolated(floatIndex) * length; //This will store the numbers that determine the end points of the strands 
		ofLine (point-normal/2, point+normal/2); //This finally gives us the strands
		
	}
	curvedSegmentPolyline.draw();  //After all that work, we can finally draw our seaweed.
	curvedSegmentPolyline.clear(); //This makes sure we don't have past seaweeds filling up the screen.
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
