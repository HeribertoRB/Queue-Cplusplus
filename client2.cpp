//=========================================================
//HW#: HW1P1 queue
//Your name: Heriberto Bernal
//Complier:  g++ compiler
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "queue.h"

//Purpose of the program: This program will generate all strings using A, B, and C as the letters
//Algorithm: The queue has A, B, and C. It will remove the front element, then it is going to be added to A, B, and C and the results will be added to the queue.
int main()
{ //A, B, C in the queue
  queue generatequeue; // character queue
  char choice; // user enter a choice
  string elem; // user enter an element for queue

  generatequeue.add("A");
  generatequeue.add("B");
  generatequeue.add("C");
  cout << "Enter any key to continue or enter Q to quit: ";
  cin >> choice;

  while((choice != 'Q') && (!generatequeue.isFull()) ) //if choice is Q or the queue is full, go out of the loop
    {
      try 
	{ 
	  generatequeue.remove(elem);
	  cout << elem << endl;

	  string elem1 = elem + "A";
	  //cout << "Sum A:" << elem << endl;
	  generatequeue.add(elem1); //add the elem to the queue
	  string elem2 = elem + "B";
          //cout << "Sum B:" << elem << endl;
          generatequeue.add(elem2);
	  string elem3 = elem + "C";
          //cout << "Sum C:" << elem << endl;
          generatequeue.add(elem3);

	  string elem;
	  cout << "Enter your choice or enter Q to quit: ";
	  cin >> choice;
	}
      
	  catch (queue::Overflow)
	    { cout << "Sorry, the queue is full." << endl; }
	  catch (queue::Underflow) // for too few operands
	    { cout << "Sorry, the queue is empty." << endl; }
    }
}
