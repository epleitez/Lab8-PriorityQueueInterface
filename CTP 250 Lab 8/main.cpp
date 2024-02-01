#include <iostream>
#include "Packet.cpp"
#include "MaxHeap.h"
#include <fstream>


using namespace std;


void buildHeapFromFile(MaxHeap<Packet> &packetHeap);
void displayTransferTimeOfEachPacket(MaxHeap<Packet> packetHeap);
void displayNumPacketsLevel(MaxHeap<Packet> packetHeap);
void displayAmountTimeForEachLevel(MaxHeap<Packet> packetHeap);
void displayTotalAmountTransferTime(MaxHeap<Packet> packetHeap);

int main() {

    MaxHeap<Packet> packetHeap;
    buildHeapFromFile(packetHeap);

    displayTransferTimeOfEachPacket(packetHeap); //NEED TO FIX: ONLY READING 100 NOT 200?
    displayNumPacketsLevel(packetHeap);
    displayAmountTimeForEachLevel(packetHeap);
    displayTotalAmountTransferTime(packetHeap);

    return 0;
}

/* Reads data from File "packets.csv"
 * lines read from data placed in MaxHeap<Packet> packetHeap
 * @param MaxHeap<Packet> packetHeap is the array of packets organized in priority queue
 */
void buildHeapFromFile(MaxHeap<Packet> &packetHeap){
    //opening file
    ifstream infile("packets.csv");

    //checking if file is open
    if(!infile.is_open()){
        cout << "file not open for input...program terminating" << endl;
        exit(0);
    }

    //variables
    string line = "";
    string idNumString = "";
    string fileSizeString = "";
    int fileSize = 0;
    string priorityNumString = "";
    int priorityNum = 0;

    //getting the data from file
    //enqueueing "packets" into max heap implementation
    while(getline(infile, line)){
        stringstream s (line);
        getline(s, idNumString, ',');
        getline(s, fileSizeString, ',');
        getline(s, priorityNumString, ',');
        fileSize = stoi(fileSizeString);
        priorityNum = stoi(priorityNumString);

        Packet packetObj(idNumString, fileSize, priorityNum);

        packetHeap.add(packetObj);
        //cout << packetObj.toString();
    }//end while



    //packetHeap.printHeap();

}//end buildHeapFromFile()

/* Dequeue the packets, display and determine the transfer time of each.
 * Transfer Time in seconds
 * @param MaxHeap<Packet> packetHeap is the array of packets organized in priority queue
 */
void displayTransferTimeOfEachPacket(MaxHeap<Packet> packetHeap){

    double transferTime = 0;
    int counter = 0;

    //cout << packetHeap.getNumberOfItems();

    cout << "\nPacket Information including Transfer Time: \n" << endl;
    for (int i = 0; i < packetHeap.getNumberOfItems(); i++){

        cout << packetHeap.peek().toString();

        transferTime = packetHeap.calculateTransferTime(i);

        cout << "Transfer Time: " <<  fixed << setprecision(0) << transferTime << " seconds" << endl;

        cout << "--------------------------" << endl;

        packetHeap.remove();

        counter++;

    }

    cout << "Counter: " << counter << endl;

}

/* Displays the number of packets in each priority level
 * @param MaxHeap<Packet> packetHeap is the array of packets organized in priority queue
 */
void displayNumPacketsLevel(MaxHeap<Packet> packetHeap){

    int levelZero = 0;
    int levelOne = 0;
    int levelTwo = 0;
    int levelThree = 0;
    int levelFour = 0;
    int levelFive = 0;
    int levelSix = 0;
    int levelSeven = 0;
    int current = 0;

    for (int i = 0; i < packetHeap.getNumberOfItems(); i++){

        current = packetHeap.peek().getPriorityNum();

        //cout << current << endl;

        if (current == 0){
            levelZero++;
        }
        if (current == 1){
            levelOne++;
        }
        if (current == 2){
            levelTwo++;
        }
        if (current == 3){
            levelThree++;
        }
        if (current == 4){
            levelFour++;
        }
        if (current == 5){
            levelFive++;
        }
        if (current == 6){
            levelSix++;
        }
        if (current == 7){
            levelSeven++;
        }

        packetHeap.remove();

    } // end for loop


    cout << "\nNumber of Packets at Each Priority Level... " << endl;
    cout << "Level 0: " << levelZero << endl;
    cout << "Level 1: " << levelOne << endl;
    cout << "Level 2: " << levelTwo << endl;
    cout << "Level 3: " << levelThree << endl;
    cout << "Level 4: " << levelFour << endl;
    cout << "Level 5: " << levelFive << endl;
    cout << "Level 6: " << levelSix << endl;
    cout << "Level 7: " << levelSeven << endl;



} // end displayNumPacketsLevel()

/* Displays the transfer time of the packets in each priority level
 * @param MaxHeap<Packet> packetHeap is the array of packets organized in priority queue
 */
void displayAmountTimeForEachLevel(MaxHeap<Packet> packetHeap){

    int current = 0;
    double transferTimeZero = 0.0;
    double transferTimeOne = 0;
    double transferTimeTwo = 0;
    double transferTimeThree = 0;
    double transferTimeFour = 0;
    double transferTimeFive = 0;
    double transferTimeSix = 0;
    double transferTimeSeven = 0;

        for (int i = 0; i < packetHeap.getNumberOfItems(); i++){

            current = packetHeap.peek().getPriorityNum();

            //cout << current << endl;

            if (current == 0){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeZero = transferTimeZero + curr;
            }
            if (current == 1){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeOne = transferTimeOne + curr;
            }
            if (current == 2){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeTwo = transferTimeTwo + curr;
            }
            if (current == 3){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeThree = transferTimeThree + curr;
            }
            if (current == 4){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeFour = transferTimeFour + curr;
            }
            if (current == 5){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeFive = transferTimeFive + curr;
            }
            if (current == 6){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeSix = transferTimeSix + curr;
            }
            if (current == 7){
                double curr = packetHeap.calculateTransferTime(i);
                transferTimeSeven = transferTimeSeven + curr;
            }

            packetHeap.remove();

        } // end for loop

    cout << "\nTransfer Time at Each Priority Level... " << endl;
    cout << "Level 0: " <<  fixed << setprecision(0) << transferTimeZero << " seconds" << endl;
    cout << "Level 1: " <<  fixed << setprecision(0) << transferTimeOne << " seconds" << endl;
    cout << "Level 2: " <<  fixed << setprecision(0) << transferTimeTwo << " seconds" << endl;
    cout << "Level 3: " <<  fixed << setprecision(0) << transferTimeThree << " seconds" << endl;
    cout << "Level 4: " <<  fixed << setprecision(0) << transferTimeFour << " seconds" << endl;
    cout << "Level 5: " <<  fixed << setprecision(0) << transferTimeFive << " seconds" << endl;
    cout << "Level 6: " <<  fixed << setprecision(0) << transferTimeSix << " seconds" << endl;
    cout << "Level 7: " <<  fixed << setprecision(0) << transferTimeSeven << " seconds" << endl;

} // end displayAmountTimeForEachLevel()

/* Displays the total number of transfer time for all packets
 * @param MaxHeap<Packet> packetHeap is the array of packets organized in priority queue
 */
void displayTotalAmountTransferTime(MaxHeap<Packet> packetHeap){

    double totalTransferTime = 0.0;

    for (int i = 0; i < packetHeap.getNumberOfItems(); i++){
        packetHeap.peek();

        double curr = packetHeap.calculateTransferTime(i);
        totalTransferTime = totalTransferTime + curr;

        packetHeap.remove();

    }

    cout << "\nTotal Transfer Time for all Packets... " << endl;
    cout <<  fixed << setprecision(0) << totalTransferTime << " seconds" << endl;

} //end displayTotalAmountTransferTime()










/*

    //test statements

    //packetHeap.printHeap();

    //cout << packetHeap.peek().toString() << endl;

    //packetHeap.remove();

    //cout << packetHeap.peek().toString() << endl;

 */