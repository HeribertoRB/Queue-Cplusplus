
//=========================================================
//HW#: HW1P1 queue
//Your name: Heriberto Bernal
//Complier:  g++ compiler
//File type: queue implementation file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

//PURPOSE: Constructor must initialize count and front to be 0 and rear to be -1 to begin wtih
queue::queue()
{ count = -1;
  front = 0;
  rear = -1;}

//PURPOSE: Destructor does not have to do anything since this is a static array
queue::~queue()
{}

// PURPOSE: returns true if queue is empty, otherwise false
//If the count is equal 0 them the queue is empty
bool queue::isEmpty()
{ if(count == 0) return true; else return false; }

// PURPOSE: returns true if queue is full, otherwise false
//If the count is equal MAX_SIZE then the queue is full
bool queue::isFull()
{ if( count == MAX_SIZE) return true; else return false; }

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{ if (isFull()) throw Overflow{};
  else { rear = (rear+1)% MAX_SIZE; el[rear] = newElem; count++; }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{ if(isEmpty()) throw Underflow{};
  else{removedElem = el[front]; front = (front+1)% MAX_SIZE; count--; }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{ if(isEmpty()) throw Underflow{};
  else{theElem = el[front]; }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{ int size = count; return size; }

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{ if(isEmpty()) cout << "[ empty ]" << endl;
  else{ int e = front; //e will substitute the front element of the queue
  for(int i=count; i>=1; i--)
  {cout << el[e] << endl; e = (e+1)%MAX_SIZE;}
  cout << "--------------" << endl; }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{if(isEmpty()) throw Underflow{};
  else if(count == 1); //if there is just one element on the queue then do nothing
  else{ el_t eleme; //removed element will go in this variable
  remove(eleme);
  add(eleme); }
}





