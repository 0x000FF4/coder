/*
 * MainServer.cpp
 *
 *  Created on: 24.02.2015 г.
 *      Author: x000ff4
 */

#include "MainServer.h"

MainServer::MainServer() {
	this->threadsClientRead = new std::thread(&ClientModule::readData,&MainServer::clientModule);
	this->threadsClientWrite= new std::thread(&ClientModule::writeData,&MainServer::clientModule);


}

MainServer::~MainServer() {

}


