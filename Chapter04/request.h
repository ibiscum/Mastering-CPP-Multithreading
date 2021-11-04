/*
	request.h - header file for the Request class.
	
	Revision 0
	
	Notes:
			- 
			
	2016/11/19, Maya Posch
	(c) Nyanko.ws
*/


#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "abstract_request.h"


#include <string>

using namespace std;


typedef void (*logFunction)(string text);


class Request : public AbstractRequest {
	int value{};
	logFunction outFnc{};
	
public:
	void setValue(int Value) override { this->value = Value; }
	void setOutput(logFunction fnc) { outFnc = fnc; }
	void process() override;
	void finish() override;
};

#endif
