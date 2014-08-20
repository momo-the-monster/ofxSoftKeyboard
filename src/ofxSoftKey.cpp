/*
 *  ofxSoftKey.cpp
 *  softKeyboardExample
 *
 *  Created by Jeffrey Crouse on 11/9/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofxSoftKey.h"

#pragma mark CONSTRUCTORS

//--------------------------------------------------------------
ofxSoftKey::ofxSoftKey(int _code) {
	
	code = _code;
	roundness = 0;
	
	textColor = ofColor(0);
	textBGColor = ofColor(204);
	borderColor = ofColor(0);
	hoverColor = ofColor(153);
	clickColor = ofColor(255, 0, 0);
	isLastInRow = false;
	useCustomFont = false;
	
	disableAppEvents();
	enableMouseEvents();
	
	padding = new int[4];
	setPadding(5, 5, 5, 5);

	switch(_code) {
		case OFXSK_KEY_SHIFT:
			label = "shift";
			setSize(115, 40);
			break;
		case OFXSK_KEY_TAB: 
			label = "tab";
			setSize(70, 40);
			break;
		case OFXSK_KEY_CAPS: 
			label = "caps";
			setSize(85, 40);
			break;
		case OFXSK_KEY_DELETE: 
			label = "del";
			setSize(85, 40);
			break;
		case OFXSK_KEY_RETURN: 
			label = "return";
			setSize(85, 40);
			break;
		case OFXSK_KEY_AT:
			label = "@";
			setSize(40, 40);
			break;
		case OFXSK_KEY_DOTCOM:
			label = ".COM";
			setSize(40, 40);
			break;
		case OFXSK_KEY_DOTNET:
			label = ".NET";
			setSize(40, 40);
			break;
		case OFXSK_KEY_DOTORG:
			label = ".ORG";
			setSize(40, 40);
			break;
		default:
			label = string(1, code);
			setSize(40, 40);
			break;
	}
}


#pragma mark PADDING

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setPadding(int top, int right, int bottom, int left) {
	padding[OFXSK_PADDING_TOP] = top;
	padding[OFXSK_PADDING_RIGHT] = right;
	padding[OFXSK_PADDING_BOTTOM] = bottom;
	padding[OFXSK_PADDING_LEFT] = left;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padLeft(int left) {
	padding[OFXSK_PADDING_LEFT] += left;
	return *this;
}
	
//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::padRight(int right) {
	padding[OFXSK_PADDING_RIGHT] += right;
	return *this;
}

void ofxSoftKey::setCustomFont(ofTrueTypeFont &font){
	customFont = &font;
	useCustomFont = true;
}



#pragma mark APP EVENTS



//--------------------------------------------------------------
void ofxSoftKey::draw() {
	
	// Draw the background
	ofFill();
	if(isMouseOver()) ofSetColor(hoverColor);
	else ofSetColor(textBGColor);
	ofRectRounded(x, y, width, height, roundness);
	
	// Draw the outline.
	ofNoFill();
	ofSetColor(borderColor);
	ofRectRounded(x, y, width, height, roundness);
	
	// Draw the actual letter
	ofSetColor(textColor);
	if(useCustomFont){
		customFont->drawString(label, x+10, y+height-10);
	} else {
		ofDrawBitmapString(label, x+10, y+height-10);
	}

}


#pragma mark SETTERS

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setCode(char c) {
	this->code = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setTextColor(ofColor c) {
	this->textColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setTextBGColor(ofColor c) {
	this->textBGColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setBorderColor(ofColor c) {
	this->borderColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setHoverColor(ofColor c) {
	this->hoverColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setClickColor(ofColor c) {
	this->clickColor = c;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setRoundness(float r) {
	this->roundness = r;
	return *this;
}

//--------------------------------------------------------------
ofxSoftKey& ofxSoftKey::setLabel(string l) {
	this->label = l;
	return *this;
}


#pragma mark MOUSE INTERACTION


//--------------------------------------------------------------
void ofxSoftKey::onPress(int x, int y, int button) {
	sendKeyEvent(ofKeyEventArgs::Type::Pressed);
}

//--------------------------------------------------------------
void ofxSoftKey::onRelease(int x, int y, int button) {
	sendKeyEvent(ofKeyEventArgs::Type::Released);
}

void ofxSoftKey::sendKeyEvent(ofKeyEventArgs::Type type){
	
	ofEvent<ofKeyEventArgs>&event = (type == ofKeyEventArgs::Type::Pressed) ?  ofEvents().keyPressed : ofEvents().keyReleased;
	ofKeyEventArgs args;
	args.type = type;

	switch(code) {
		case OFXSK_KEY_SHIFT:
			
			break;
		case OFXSK_KEY_TAB: 
			args.key = '\t';
			ofNotifyEvent(event, args, this);
			break;
		case OFXSK_KEY_CAPS: 
			
			break;
		case OFXSK_KEY_DELETE: 
			args.key = OF_KEY_BACKSPACE;
			ofNotifyEvent(event, args, this);
			break;
		case OFXSK_KEY_RETURN: 
			args.key = '\n';
			ofNotifyEvent(event, args, this);
			break;
		case OFXSK_KEY_AT:
			args.key = '@';
			ofNotifyEvent(event, args, this);
			break;
		case OFXSK_KEY_DOTCOM:
			args.key = '.';
			ofNotifyEvent(event, args, this);
			args.key = 'c';
			ofNotifyEvent(event, args, this);
			args.key = 'o';
			ofNotifyEvent(event, args, this);
			args.key = 'm';
			ofNotifyEvent(event, args, this);
			break;
		case OFXSK_KEY_DOTNET:
			args.key = '.';
			ofNotifyEvent(event, args, this);
			args.key = 'n';
			ofNotifyEvent(event, args, this);
			args.key = 'e';
			ofNotifyEvent(event, args, this);
			args.key = 't';
			ofNotifyEvent(event, args, this);
			break;
		case OFXSK_KEY_DOTORG:
			args.key = '.';
			ofNotifyEvent(event, args, this);
			args.key = 'o';
			ofNotifyEvent(event, args, this);
			args.key = 'r';
			ofNotifyEvent(event, args, this);
			args.key = 'g';
			ofNotifyEvent(event, args, this);
			break;
		default:
			args.key = code;
			ofNotifyEvent(event, args, this);
			break;
	}

}

//--------------------------------------------------------------
void ofxSoftKey::onReleaseOutside(int x, int y, int button) {

}
