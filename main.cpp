#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  ~DoublyLinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList() {
    Node *temp = head;
    if (temp == nullptr) {
      cout << "empty" << endl;
      return;
    }
    while (temp->next != nullptr) {
      cout << temp->value << " <-> ";
      temp = temp->next;
    }
    cout << temp->value << endl;
  }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  int getLength() { return length; }

  void append(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - The swapPairs function swaps adjacent pairs       |
  //   |   of nodes in a doubly linked list.                 |
  //   | - Return type: void                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Utilizes a dummyNode to simplify edge cases.      |
  //   | - Uses pointers to navigate and swap nodes.         |
  //   | - Pay close attention to the 'next' and 'prev'      |
  //   |   pointers of the nodes.                            |
  //   | - Works in-place; doesn't create new nodes.         |
  //   | - Always checks if the list is empty or has only    |
  //   |   one node.                                         |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+
  void swapPairs() {
    // Check if the list is empty or has only one node.
    if (head == nullptr || head->next == nullptr) {
      return; // No pairs to swap, just return.
    }

    // Initialize a dummy node that points to the original head to simplify edge
    // cases.
    Node dummyNode(0);
    dummyNode.next = head;
    head->prev = &dummyNode;

    Node *current = &dummyNode;

    while (current->next != nullptr && current->next->next != nullptr) {
      Node *first = current->next;
      Node *second = current->next->next;

      // Swapping the pairs by adjusting the next and prev pointers.
      first->next = second->next;
      if (second->next != nullptr) {
        second->next->prev = first;
      }
      second->prev = current;
      second->next = first;
      first->prev = second;
      current->next = second;

      // Moving to the next pair to swap.
      current = first;
    }

    // Updating the head and tail of the list after swapping.
    head = dummyNode.next;
    head->prev = nullptr;
    if (current->next == nullptr) {
      tail = current;
    } else {
      tail = current->next;
    }
  }
};
