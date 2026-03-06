#include <iostream>
#include <stdexcept>

using namespace std;

/*
  The Node class represents a single node in the linked list, 
  containing an integer data and a pointer to the next node.

  The Node class has two constructors: a default constructor that initializes data to 0 and next to nullptr,
  and a parameterized constructor that initializes data to the provided value and next to nullptr.
*/
class Node{
  public:
    int data;
    Node *next;

    // Default constructor
    Node() {
        data = 0;
        next = nullptr;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
  The LinkedList class manages the linked list, providing methods to insert nodes at the head, tail, and specific positions,
  as well as methods to delete nodes by position and by value, and a method to display the contents of the list.
*/

class LinkedList{
  // ---

  // The head pointer of the linked list, which points to the first node in the list.
  Node* head;

  // The LinkedList class has a constructor that initializes the head pointer to nullptr, indicating an empty list.
  //public: is used to specify that the following members of the class are accessible from outside the class.
  public:
    LinkedList() {
      head = nullptr;
    }

    // The insertAtHead method creates a new node with the given data and inserts it at the beginning of the list.
    // If the list is empty, the new node becomes the head. Otherwise, the new node's next pointer is set to the current head, and then the head pointer is updated to point to the new node.
    void insertAtHead(int data){
      Node *newNode = new Node(data);

      if(head == nullptr){
        head = newNode;
        return;
      }

      newNode -> next = this->head;
      this->head = newNode;
      return;
    }

    /*
    The insertAtTail method creates a new node with the given data and inserts it at the end of the list. 
    If the list is empty, the new node becomes the head. Otherwise, the method traverses the list to find the last node (where next is nullptr) and sets its next pointer to the new node.
    */
    void insertAtTail(int data){
      Node *newNode = new Node(data);

      if(head == nullptr){
        head = newNode;
        return;
      }

      Node *temp = head;

      while (temp -> next != nullptr){
        temp = temp -> next;
      }
      temp->next = newNode;
      return;
    }

    /*
    The insertAtPosition method inserts a new node with the given data at a specified position in the list.
    The method first checks if the position is valid (greater than or equal to 1). 
    If the position is 1, it calls insertAtHead to insert the new node at the beginning of the list. Otherwise, it traverses the list to find the node currently at the position just before the desired position. 
    If the position is out of bounds (greater than the length of the list), it prints an error message. 
    If the position is valid, it creates a new node and adjusts the next pointers to insert the new node at the correct position in the list.
    */
    void insertAtPosition(int data, int position){

      if (position < 1) {
        cout << "Error: Position must be 1 or greater." << endl;
        return;
      }
    
      
      if(position == 1){
        insertAtHead(data);
        return;
      }

      Node *temp = head;

      for(int i=1;temp != nullptr && i<position-1; i++){
        temp = temp -> next;
      }

      if(temp == nullptr ){
        cout << "Error: Position " << position << " is out of bounds." << endl;

        return;
      }

      Node *newNode = new Node(data);

      newNode -> next = temp -> next;
      temp -> next = newNode;
      return;
    }

    /*
    The deleteAtPosition method deletes the node at a specified position in the list.
    The method first checks if the list is empty and throws a runtime error if it is. It also checks if the position is valid (greater than or equal to 1) and throws an out_of_range error if it is not. If the position is 1, it updates the head pointer to the next node and deletes the original head node. Otherwise, it traverses the list to find the node just before the desired position. If the position is out of bounds (greater than the length of the list), it throws an out_of_range error. If the position is valid, it adjusts the next pointers to bypass the node at the specified position and deletes that node from memory.
    */
    void deleteAtPosition(int position){

      if (head == nullptr) {
        throw runtime_error("List is empty");
      }

      if (position < 1) {
        throw out_of_range("Position must be positive");
      }

      if(position == 1){
        Node *temp = head;
        head = head -> next;
        delete temp;
        return;
      }

      Node *temp = head;

      for(int i=1; temp != nullptr && i<position-1; i++){
        temp = temp -> next;
      }

      if(temp == nullptr || temp -> next == nullptr){
        throw out_of_range("Position exceeds list length");
      }

      Node *nodeToDelete = temp -> next;
      temp -> next = nodeToDelete -> next;
      delete nodeToDelete;
      return;
    }

    /*
    The deleteByValue method deletes the first node in the list that contains the specified value.
    The method first checks if the list is empty and throws a runtime error if it is. If the head node contains the value, it updates the head pointer to the next node and deletes the original head node. Otherwise, it traverses the list to find the node just before the node that contains the specified value. If the value is not found in the list, it prints a message indicating that the value was not found. If the value is found, it adjusts the next pointers to bypass the node containing the value and deletes that node from memory.
    */
    void deleteByValue(int value) {
        if (head == nullptr) throw runtime_error("Cannot delete from an empty list");

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value " << value << " not found in list." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    /*
    The display method prints the contents of the linked list in a readable format.
    If the list is empty, it prints a message indicating that the list is empty. Otherwise, it traverses the list from the head to the end, printing the data of each node followed by an arrow (->) to indicate the link between nodes. After the last node, it prints "NULL" to indicate the end of the list.
    */
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    /*
    The destructor of the LinkedList class is responsible for freeing the memory allocated for the nodes in the linked list when an instance of the LinkedList class is destroyed. It traverses the list starting from the head, deleting each node one by one until it reaches the end of the list (where the next pointer is nullptr). This ensures that there are no memory leaks and that all dynamically allocated memory for the nodes is properly released when the linked list is no longer needed.
    */
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
  
};

int main(){
  LinkedList list;

  try{
    list.insertAtHead(10);   
    list.insertAtTail(30);    
    list.insertAtPosition(20, 2); 
    list.display();
    list.deleteAtPosition(2); 
    list.display();
    list.deleteByValue(30);  
    list.display();
    list.deleteAtPosition(10);

  }catch (const exception& e) {
    cerr << "Caught an error: " << e.what() << endl;
  } 
  cout << "Program continues safely..." << endl;
  return 0;
}