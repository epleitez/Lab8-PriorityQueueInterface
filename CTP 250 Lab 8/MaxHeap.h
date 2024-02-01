//
// Created by Emely Pleitez on 11/22/22.
//

#ifndef CTP_250_LAB_8_MAXHEAP_H
#define CTP_250_LAB_8_MAXHEAP_H
#include "PriorityQueueInterface.h"
#include "Packet.h"
#include <vector>

template <class T>

class MaxHeap {
public:
    MaxHeap();
    ~MaxHeap();

    //interface methods
    bool isEmpty() const;
    int getNumberOfItems();
    T peek() const;
    bool add(const T& newData);
    void heapify(int i);
    T remove();
    void clear();

    //methods
    void printHeap();
    double calculateTransferTime(int location); //of each packet



private:

    int numItems = 0;
    int indexFront;
    //int indexRear;

    T heapArray[250];


    int parent(int i) {return (i-1) /2; }
    int leftChild(int i) {return (2 * i) + 1; }
    int rightChild(int i) {return (2 * i) + 2; }

};



template <typename T>
MaxHeap<T>::MaxHeap() {
    numItems = 0;
    indexFront = 0;
}
template <typename T>
MaxHeap<T>::~MaxHeap() {

}


template <typename T>
bool MaxHeap<T>::isEmpty() const {
    return numItems == 0;
}

template <typename T>
int MaxHeap<T>::getNumberOfItems() {
    return numItems;
}

template <typename T>
T MaxHeap<T>::peek() const {
    assert(!isEmpty());
    return heapArray[0];

}

template <typename T>
bool MaxHeap<T>::add(const T &newData) {

    if(numItems >= 250){
        cout << "heap full..." << endl;
    }//end if


    heapArray[numItems] = newData;
    numItems++;


    int i = numItems - 1;
    while((i != 0) && ( (heapArray[parent(i)].getPriorityNum()) < (heapArray[i]).getPriorityNum()) ){
        T temp;
        temp = heapArray[parent(i)];
        heapArray[parent(i)] = heapArray[i];
        heapArray[i] = temp;
        i = parent(i);
    }

}

template <typename T>
void MaxHeap<T>::heapify(int i){

    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;

    if ( (left <= numItems) && (heapArray[left].getPriorityNum() ) > (heapArray[largest].getPriorityNum()) )
        largest = left;

    if ( (right <= numItems) && (heapArray[right].getPriorityNum()) > (heapArray[largest].getPriorityNum()) )
        largest  = right;

    //swapping
    if (largest != i){
        T temp = heapArray[i];
        heapArray[i] = heapArray[largest];
        heapArray[largest] = temp;
        heapify(largest);
    }//end if
}

//track priority num here
template <typename T>
T MaxHeap<T>::remove() {
    T max = heapArray[0];

    heapArray[0] = heapArray[numItems - 1];
    numItems--;

    heapify(0);

    return max;

}

template <typename T>
void MaxHeap<T>::clear() {
    //todo
}

template <typename T>
void MaxHeap<T>::printHeap() {
    //cout << numItems << endl;
    for (int i = 0; i < numItems; i++)
        cout << heapArray[i].toString() << endl;

}//end printHeap()

template <typename T>
double MaxHeap<T>::calculateTransferTime(int location) {

    /* Math for transfer time
     * There are 8 bits in one byte
     * transfer time = file size * ( 8 bits )
     *  90 Mb/s (megabits per second).
     */
    double fileSize = heapArray[location].getFileSize();
    double transferTime = 0.0;

    transferTime = (fileSize * 8) * ((1.0) / 90)  ;

    return transferTime;

}//end calculateTransferTime()





#endif //CTP_250_LAB_8_MAXHEAP_H
