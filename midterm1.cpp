#include <iostream> // lets us use cout and cin 
using namespace std;

// just seetting up some constants 
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
// Defines a class for the Doublylinkedlist
class DoublyLinkedList {
private:
//each node in the list will have a value and have two pointers
struct Node {
int data; // stores the value
Node* prev; // will point to the node before this 
Node* next; // points to the node after this one 

// This is a constructor that sets up a new node
Node(int val, Node* p = nullptr, Node* n = nullptr) {
data = val; // sets the data
prev = p;  //setting previous pointer 
next = n; // setting the next pointer
}
};
Node* head; // will point to the first node in the list 
Node* tail; // will point to the last node of the list
public:
// This is a contructor that will set up an empty list
DoublyLinkedList()
 { head = nullptr; 
tail = nullptr; }
//inserts a value after a certain position in the list
void insert_after(int value, int position) {
if (position < 0) {
cout << "Position must be >= 0." << endl;
return;
}
Node* newNode = new Node(value); // makes a new node

// if the list is empty just add to head and tail
if (!head) {
head = tail = newNode;
return;
}

//goes to the position 

Node* temp = head;
for (int i = 0; i < position && temp; ++i)
temp = temp->next;

//if position is too far then this displays
if (!temp) {
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode;
return;
}
// connects the new node between temp and the temp->next
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next)
temp->next->prev = newNode;
else
tail = newNode; //new node is the last one now
temp->next = newNode;
}

// deletes the first node with the given value
void delete_val(int value) {
if (!head) return;  // an empty list
Node* temp = head;

// finds the node with that value
while (temp && temp->data != value)
temp = temp->next;
if (!temp) return; // the value is not found

// connects around the node
if (temp->prev)
temp->prev->next = temp->next;
else
head = temp->next; // if deleting the first node 
if (temp->next)
temp->next->prev = temp->prev; 
else
tail = temp->prev; // deleting the last node
delete temp; // deletes the node
}

//deletes the node at a certain position
void delete_pos(int pos) {
if (!head) {
cout << "List is empty." << endl;
return;
}
//if deleting the first node 
if (pos == 1) {
pop_front();
return;
}
Node* temp = head;

// move it to the right position
for (int i = 1; i < pos; i++){
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
else
temp = temp->next;
}
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
// if deleting the last node
if (!temp->next) {
pop_back();
return;
}

// linking around it
Node* tempPrev = temp->prev;
tempPrev->next = temp->next;
temp->next->prev = tempPrev;
delete temp;
}

// adds a node to the end of the list
void push_back(int v) {
Node* newNode = new Node(v);
if (!tail)
head = tail = newNode;
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}

// adds a node to the front of the list 
void push_front(int v) {
Node* newNode = new Node(v);
if (!head)
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
// removes the first node
void pop_front() {
if (!head) {
cout << "List is empty." << endl;
return;
}
Node * temp = head;
if (head->next) {
head = head->next;
head->prev = nullptr;
}
else
head = tail = nullptr;
delete temp;
}

// removes the last node
void pop_back() {
if (!tail) {
cout << "List is empty." << endl;
return;
}
Node * temp = tail;
if (tail->prev) {
tail = tail->prev;
tail->next = nullptr;
}
else
head = tail = nullptr;
delete temp;
}

// a destructor that deletes all nodes when the list is gone
~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}

// prints the list from the start to the end
void print() {
Node* current = head;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}

//prints list backwards
void print_reverse() {
Node* current = tail;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->prev;
}
cout << endl;
}

 // ADDED THE NEW METHOD: prints every other element
    void every_other_element() {
        Node* current = head; // start at the first node
        bool skip = false;    // used to decide whether to print or skip

        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Every other element: ";
        while (current) {
            if (!skip) {
                cout << current->data << " "; // print this one
            }
            skip = !skip; // flip skip each time
            current = current->next; // move to next node
        }
        cout << endl;
    }
};

// main to test our list
int main() {
    DoublyLinkedList list; // make a new list

    // add some numbers to the list
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    // show the list
    cout << "Full list: ";
    list.print();

    // now call the new function
    list.every_other_element(); // should print 10, 30, 50

    return 0;
}


