/***************************************************
* Mika Peer Shalem, mpeersha
* 2023 Winter CSE101, PA6
* ListTest.cpp
* Contains a main function and implements tests to ensure that the List.cpp functions work.
****************************************************/

#include "List.h"
#include<iostream>
#include<string>
using namespace std;
int main() {
    List A; List B;
    A.insertBefore(34);
    A.insertBefore(77);
    A.insertBefore(77);
    A.insertBefore(1);
    A.insertBefore(34);
    A.insertBefore(1);
    A.insertBefore(55);
    A.insertBefore(77);
    if (A.findPrev(99) != -1)
      printf("1\n");
    if (A.position() != 0)
      printf("2\n");

    A.moveBack();
    if (A.findPrev(1) != 5)
      printf("3\n");
    if (A.findPrev(1) != 3)
      printf("4\n");
    if (A.findPrev(1) != -1)
      printf("5\n");

    A.moveBack();
    cout << "\nA = " << A.to_string();
    printf("pos is %d\n", A.position());
    A.cleanup();
    cout << "\nA = " << A.to_string();
    printf("pos is %d %d \n", A.position(), A.findPrev(1));
    if (A.findPrev(1) != 2)
      printf("6\n");
    if (A.findPrev(1) != -1)
      printf("7\n");
    return 0;
  


    List L; List L1; List L2;
    printf("length of a new list is %d\n", L.length());
    printf("A new list without changes, a new list that moved to the front, and a new list that moved to the back: \n");
    L1.moveFront(); L2.moveBack();
    for (int i=1; i<=10; i+=1) {
        L.insertAfter(i);
        L1.insertAfter(i);
        L2.insertAfter(i);
    }
    cout << "L = " << L.to_string();
    cout << "\nL1 = " << L1.to_string();
    cout << "\nL2 = " << L2.to_string();
    printf("\nCheck setAfter function: \n");
    L1.moveFront(); L2.moveBack();
    L.setAfter(-1); L.moveNext(); L.moveNext(); L.moveNext(); L.moveNext(); L.moveNext(); L.moveNext(); L.moveNext();
    L1.setAfter(-1); L1.moveNext(); L1.setAfter(-2); L1.moveNext(); L1.setAfter(-3);
    L2.movePrev(); L2.setAfter(-1); L2.movePrev(); L2.setAfter(-2); L2.movePrev(); L2.setAfter(-3);
    cout << "L = " << L.to_string();
    cout << "\nL1 = " << L1.to_string();
    cout << "\nL2 = " << L2.to_string();
    printf("\nErase after: \n");
    L2.eraseAfter(); L2.eraseAfter();
    cout << "L2 = " << L2.to_string();
    L2.movePrev(); L2.movePrev(); L2.movePrev();
    L2.eraseAfter();
    cout << "\nL2 = " << L2.to_string();
    printf("Find next: \n");
    int f1 = L1.findNext(5);
    printf("Found the number 5 at L1 at index %d\n", f1);
    int f2 = L1.findNext(-24);
    L1.moveFront();
    printf("Found the number -24 at L1 at index %d\n", f2);
    L1.moveFront();
    int f3 = L1.findNext(2);
    printf("Found the number 2 at L1 at index %d\n", f3);
    
    printf("Find prev: \n");
    int f4 = L.findPrev(5);
    printf("Found the number 5 at L at index %d\n", f4);
    L.moveBack();
    int f5 = L.findPrev(-24);
    printf("Found the number -24 at L at index %d\n", f5);
    L.moveBack();
    int f6 = L.findPrev(2);
    printf("Found the number 2 at L at index %d\n", f6);

    List L3; List L4; List L5;
    printf("\n\nA new list without changes, a new list that moved to the front, and a new list that moved to the back: \n");
    L4.moveFront(); L5.moveBack();
    for (int i=1; i<=10; i+=1) {
        L3.insertBefore(i);
        L4.insertBefore(i);
        L5.insertBefore(i);
    }
    cout << "L3 = " << L3.to_string();
    cout << "\nL4 = " << L4.to_string();
    cout << "\nL5 = " << L5.to_string();
    printf("\nCheck setBefore function: \n");
    L4.moveFront(); L5.moveBack();
    L4.moveNext(); L4.setBefore(-1); L4.moveNext(); L4.setBefore(-2); L4.moveNext(); L4.setBefore(-3);
    L5.setBefore(-1); L5.movePrev(); L5.setBefore(-2); L5.movePrev(); L5.setBefore(-3);
    cout << "L3 = " << L3.to_string();
    cout << "\nL4 = " << L4.to_string();
    cout << "\nL5 = " << L5.to_string();
    printf("\nErase before: \n");
    L4.eraseBefore(); L4.eraseBefore();
    cout << "L4 = " << L4.to_string();
    L4.moveNext(); L4.moveNext(); L4.moveNext();
    L4.eraseBefore();
    cout << "\nL4 = " << L4.to_string();

    printf("\nTesting clean up");
    List L6;
    L6.insertAfter(1); L6.insertAfter(1); L6.insertAfter(2); L6.insertAfter(1); L6.insertAfter(2);
    L6.insertAfter(3); L6.insertAfter(1); L6.insertAfter(3);
    cout << "\nL6 = " << L6.to_string();
    L6.cleanup();
    cout << "\nL6 = " << L6.to_string();

    printf("\n\nPeek prev:\n");
    List L7;
    L7.insertAfter(1); L7.insertAfter(2); L7.insertAfter(3);
    cout << "L7 = " << L7.to_string();
    L7.moveFront(); L7.moveNext();  printf("\nPeek at front: %d\n", L7.peekPrev());
    L7.moveNext();                  printf("Peek at mid: %d\n", L7.peekPrev());
    L7.moveNext();                  printf("Peek at back: %d\n", L7.peekPrev());
    printf("\nPeek next:");
    L7.moveFront();  printf("\nPeek at front: %d\n", L7.peekNext());
    L7.moveNext();   printf("Peek at mid: %d\n", L7.peekNext());
    L7.moveNext();   printf("Peek at back: %d\n", L7.peekNext());
    printf("Clearing\n");
    L7.clear();
    cout << "L7 = " << L7.to_string();
    printf("\nClearing an empty list\n");
    List L8;
    L8.clear();
    cout << "L8 = " << L8.to_string();
	return 0;
}