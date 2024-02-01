//
// Created by Emely Pleitez on 11/22/22.
//

#include "Packet.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
Packet::Packet() {

    idNum = "";
    fileSize = 0;
    priorityNum = 0;

}

//overloaded constructor
Packet::Packet(string idNum, int fileSize, int priorityNum){

    this->idNum = idNum;
    this->fileSize = fileSize;
    this->priorityNum = priorityNum;

}

//Setters-----------------------------------------------------------
/* Sets the Identification number of the packet to idNum
 * @param idNum: the new Packet Identification number of this Packet
 */
void Packet::setIdNum(string idNum) {
    this->idNum = idNum;
}//end setIdNum()

void Packet::setFileSize(int fileSize) {
    this->fileSize = fileSize;
}//end setFileSize()

void Packet::setPriorityNum(int priorityNum) {
    this->priorityNum = priorityNum;
}//end setPriorityNum()

//Getters-----------------------------------------------------------
/* Returns the Identification number of this Packet
 * @return the Identification number of this Packet
 */
string Packet::getIdNum() {
    return idNum;
}//end getIdNum()

int Packet::getFileSize() {
    return fileSize;
}//end getFileSize()

int Packet::getPriorityNum() {
    return priorityNum;
}//end getPriorityNum()

//toString()-----------------------------------------------------------

const string Packet::toString() const {
    ostringstream s;

    s << "Identification Number: " << idNum << "\n"
      << "File size: " << fileSize << "\n"
      << "Priority Number: " << priorityNum << endl;
      //<< "------------------------------------" << endl;

    return s.str();
}

