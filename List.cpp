//-----------------------------------------------------------------------------
// Mika Peer Shalem, mpeersha
// 2023 Winter CSE101, PA6
// List.cpp
// Implements a List ADT that includes access and manipulation functions. List is a double ended queue with a vertical
// cursor standing between elements. The cursor position is always defined
// to be an int in the range 0 (at front) to length of List (at back).
// An empty list consists of the vertical cursor only, with no elements.
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include "List.h"

using namespace std;

// Private Constructor
// Node constructor
List::Node::Node(ListElement x) {
    data = x;
    next = nullptr;
    prev = nullptr;
}

// Class Constructors & Destructors ----------------------------------------
// Creates new List in the empty state.
List::List() {
    frontDummy = new Node(-1);
    backDummy = new Node(-1);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

// Copy constructor.
List::List(const List& L) {
    // Make an empty list
    frontDummy = new Node(-1);
    backDummy = new Node(-1);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
    // Load elements of L into the List
    Node * N = L.frontDummy->next;
    while (N != L.backDummy) {
        this->insertBefore(N->data);
        N = N->next;
    }
}

// Destructor
List::~List() {
    moveFront();
    while (length()>0) {
        eraseAfter();
    }
    delete frontDummy;
    delete backDummy;
}

// Access functions --------------------------------------------------------
// length()
// Returns the length of this List.
int List::length() const {
    return(num_elements);
}

// front()
// Returns the front element in this List.
// pre: length()>0
ListElement List::front() const {
    if (num_elements<=0) {
        throw std::length_error("List: front(): empty list");
    }
    return(frontDummy->next->data);
}

// back()
// Returns the back element in this List.
// pre: length()>0
ListElement List::back() const {
    if (num_elements==0) {
        throw std::length_error("List: back(): empty list");
    }
    return(backDummy->prev->data);
}

// position()
// Returns the position of cursor in this List: 0 <= position() <= length().
int List::position() const {
    if (pos_cursor<0 || pos_cursor>length()) {
         throw std::range_error("List: position(): invalid cursor position");
    }
    return(pos_cursor);
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<length()
ListElement List::peekNext() const {
    if (pos_cursor>=length()) {
        throw std::range_error("List: peekNext(): cursor at back");
    }
    return(afterCursor->data);
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
ListElement List::peekPrev() const {
    if (pos_cursor<=0) {
        throw std::range_error("List: peekPrev(): cursor at front");
    }
    return(beforeCursor->data);
}


// Manipulation procedures -------------------------------------------------

// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear() {
    moveFront();
    while (length()>0) {
        eraseAfter();
    }
}

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
    pos_cursor = 0;
}

// moveBack()
// Moves cursor to position length() in this List.
void List::moveBack() {
    pos_cursor = length();
    afterCursor = backDummy;
    beforeCursor = backDummy->prev;
}

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<length() 
ListElement List::moveNext() {
    if (pos_cursor>=length()) {
        throw std::range_error("List: moveNext(): cursor at back");
    }
    pos_cursor += 1;
    beforeCursor = beforeCursor->next;
    afterCursor = afterCursor->next;
    return (beforeCursor->data);
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
ListElement List::movePrev() {
    if (pos_cursor<=0) {
        throw std::range_error("List: movePrev(): cursor at front");
    }
    pos_cursor -= 1;
    beforeCursor = beforeCursor->prev;
    afterCursor = afterCursor->prev;
    return (afterCursor->data);
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(ListElement x) {
    Node * N = new Node(x);
    afterCursor->prev->next = N;
    N->next = afterCursor;
    N->prev = afterCursor->prev;
    afterCursor->prev = N;
    afterCursor = N;
    num_elements += 1;
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x) {
    Node * N = new Node(x);
    beforeCursor->next->prev = N;
    N->next = beforeCursor->next;
    N->prev = beforeCursor;
    beforeCursor->next = N;
    beforeCursor = N;
    pos_cursor += 1;
    num_elements += 1;
}

// setAfter()
// Overwrites the List element after the cursor with x.
// pre: position()<length()
void List::setAfter(ListElement x) {
    if (pos_cursor>=length()) {
        throw std::range_error("List: setAfter(): cursor at back");
    }
    afterCursor->data = x;
}

// setBefore()
// Overwrites the List element before the cursor with x.
// pre: position()>0
void List::setBefore(ListElement x) {
    if (pos_cursor<=0) {
        throw std::range_error("List: setBefore(): cursor at front");
    }
    beforeCursor->data = x;
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<length()
void List::eraseAfter() {
    if (pos_cursor>=length()) {
        throw std::range_error("List: eraseAfter(): cursor at back");
    }
    afterCursor->next->prev = afterCursor->prev;
    afterCursor->prev->next = afterCursor->next;
    Node * temp = afterCursor->next;
    num_elements -= 1;
    delete afterCursor;
    afterCursor = temp;
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore() {
    if (pos_cursor<=0) {
        throw std::range_error("List: eraseBefore(): cursor at front");
    }
    beforeCursor->next->prev = beforeCursor->prev;
    beforeCursor->prev->next = beforeCursor->next;
    num_elements -= 1;
    pos_cursor -= 1;
    Node * temp = beforeCursor->prev;
    delete beforeCursor;
    beforeCursor = temp;
}


// Other Functions ---------------------------------------------------------

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of element x. If x
// is found, places the cursor immediately after the found element, then 
// returns the final cursor position. If x is not found, places the cursor 
// at position length(), and returns -1. 
int List::findNext(ListElement x) {
    while (pos_cursor >= 0 && pos_cursor < length()) {
        if (afterCursor->data == x) {
            moveNext();
            return pos_cursor;
        }
        moveNext();
    }
    moveBack();
    return -1;
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of element x. If x
// is found, places the cursor immediately before the found element, then
// returns the final cursor position. If x is not found, places the cursor 
// at position 0, and returns -1. 
int List::findPrev(ListElement x) {
    while (pos_cursor > 0 && pos_cursor <= length()) {
        // printf("before cursor is %d\n", beforeCursor->data);
        if (beforeCursor->data == x) {
            movePrev();
            return pos_cursor;
        }
        movePrev();
    }
    moveFront();
    return -1;
}

// cleanup()
// Removes any repeated elements in this List, leaving only unique elements.
// The order of the remaining elements is obtained by retaining the frontmost 
// occurrance of each element, and removing all other occurances. The cursor 
// is not moved with respect to the retained elements, i.e. it lies between 
// the same two retained elements that it did before cleanup() was called.
void List::cleanup() {
    // int before = beforeCursor->data;
    // int after = afterCursor->data;
    // moveFront();
    //  printf("before is %d after %d\n", before, after);
    // printf("pos %d\n", pos_cursor);
    // printf("beg\n");
    Node * N = frontDummy->next;
    int pos = 0;
    int og_cursor = pos_cursor;
    int erase = 0;
    while (N != backDummy && N->next != backDummy) {
        int x = N->data;
        // printf("x is %d\n", x);
        int count = 0;
        pos += 1;
        
        N = N->next;
        while (N != backDummy) {
            int y = N->data;
            // printf("    y is %d pos %d\n", y, pos);
            if (x==y) {
                if (N == beforeCursor) {
                    Node * temp = beforeCursor->prev;
                    beforeCursor->next->prev = beforeCursor->prev;
                    beforeCursor->prev->next = beforeCursor->next;
                    beforeCursor = temp;
                } else if (N == afterCursor) {
                    Node * temp = afterCursor->next;
                    afterCursor->next->prev = afterCursor->prev;
                    afterCursor->prev->next = afterCursor->next;
                    afterCursor = temp;
                }
                N->next->prev = N->prev;
                N->prev->next = N->next;
                Node * temp = N->next;
                num_elements -= 1;
                delete N;
                // printf("        x==y, value is %d\n", x);
                // printf("        pos %d pos cursor is %d erase %d\n", pos, pos_cursor, erase);
                N = temp;
                if (pos+erase < og_cursor) {
                    erase+=1;
                    // printf("        delete: pos %d pos cursor is %d erase %d\n", pos, pos_cursor, erase);
                    pos_cursor -= 1;
                }
                continue;
            }
            pos += 1;
            if (N->next != backDummy || N!=backDummy) { N = N->next; }
            else { break; }
            count += 1;
        }
        for (int j=0; j<count; j+=1) {
            N = N->prev;
            pos -= 1;
        }
    }
}

// concat()
// Returns a new List consisting of the elements of this List, followed by
// the elements of L. The cursor in the returned List will be at postion 0.
List List::concat(const List& L) const {
    List P;
    Node * N = this->frontDummy->next;
    Node * M = L.frontDummy->next;
    while (N!=backDummy) {
        P.insertBefore(N->data);
        N = N->next;
    }
    while (M!=L.backDummy) {
        P.insertBefore(M->data);
        M = M->next;
    }
    while (P.pos_cursor > 0) {
        P.movePrev();
    }
    return P;
}

// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
std::string List::to_string() const {
    Node * N = nullptr;
    std::string s = "";
    for (N=frontDummy->next; N!=backDummy; N=N->next) {
        if (N->next == backDummy) {
            s += std::to_string(N->data)+"";
        } else {
            s += std::to_string(N->data)+", ";
        }
    }
    s+=")";
    return s;
}

// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R) const {
    if (this->length() != R.length()) {
        return false;
    }
    Node * N = this->frontDummy;
    Node * M = R.frontDummy;
    while (N!=backDummy) {
        if (N->data != M->data) { return false; }
        N = N->next;
        M = M->next;
    }
    return true;
}


//    // Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ) {
    return stream << L.List::to_string();
}

// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged.
bool operator==( const List& A, const List& B ) {
    return A.List::equals(B);
}

// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L ) {
    if (this != &L) {
        // Make a copy of L
        List temp = L;
        // Swap the copy's fields with fields of this
        std::swap(frontDummy, temp.frontDummy);
        std::swap(backDummy, temp.backDummy);
        std::swap(beforeCursor, temp.beforeCursor);
        std::swap(afterCursor, temp.afterCursor);
        std::swap(pos_cursor, temp.pos_cursor);
        std::swap(num_elements, temp.num_elements);
    }
    // return this with the new data installed
    return *this;
}

