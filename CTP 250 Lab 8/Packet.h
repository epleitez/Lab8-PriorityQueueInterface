//
// Created by Emely Pleitez on 11/22/22.
//

#ifndef CTP_250_LAB_8_PACKET_H
#define CTP_250_LAB_8_PACKET_H
#include <string>

using namespace std;

class Packet {

private:
    string idNum;
    int fileSize;
    int priorityNum;

public:
    Packet();
    Packet(string idNum, int fileSize, int priorityNum);

    //setters
    void setIdNum(string);
    void setFileSize(int);
    void setPriorityNum(int);

    //getters
    string getIdNum();
    int getFileSize();
    int getPriorityNum();


    const string toString() const;
    //
};


#endif //CTP_250_LAB_8_PACKET_H
