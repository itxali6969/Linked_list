#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* nextNode;

public:
    Node(int value) : data(value), nextNode(NULL) {}

    void set(int value) {
        data = value;
    }

    int get() const {
        return data;
    }

    void setNext(Node* node) {
        nextNode = node;
    }

    Node* getNext() const {
        return nextNode;
    }
};

class List {
private:
    Node* headNode;
    Node* currentNode;
    Node* lastCurrentNode;

public:
    List() : headNode(NULL), currentNode(NULL), lastCurrentNode(NULL) {}

    Node* get() const {
        return currentNode;
    }

    void add(int value) {
        Node* newNode = new Node(value);

        if (headNode == NULL) {
            headNode = newNode;
            currentNode = newNode;
            lastCurrentNode = newNode;
        }
        else {
            lastCurrentNode->setNext(newNode);
            lastCurrentNode = newNode;
        }
    }

    void next() {
        if (currentNode != NULL) {
            currentNode = currentNode->getNext();
        }
    }
};

void traverse(const List& list) {
    Node* currentNode = list.get();
    int count = 1;

    while (currentNode != NULL) {
        cout << "List Element " << currentNode->get() << endl;
        currentNode = currentNode->getNext();
        count++;
    }
}


List addNodes() {
    List linkedList;
    int count = 0; // Initialize a count variable to keep track of the number of digits entered

    while (count < 9) {
        cout << "Enter Numeric characters of your vu id\n ";
        int digit;
        cin >> digit;

        if (digit == -1)
            break;

        linkedList.add(digit);
        count++;
    }

    return linkedList;
}


List mergeLists(const List& oddList, const List& evenList) {
    List mergedList;
    Node* oddNode = oddList.get();
    Node* evenNode = evenList.get();

    while (oddNode != NULL) {
        mergedList.add(oddNode->get());
        oddNode = oddNode->getNext();
    }

    while (evenNode != NULL) {
        mergedList.add(evenNode->get());
        evenNode = evenNode->getNext();
    }
    return mergedList;
}

int main() {
    List vuIdList = addNodes();

    List oddList;
    List evenList;

    Node* currentNode = vuIdList.get();
    while (currentNode != NULL) {
        if (currentNode->get() % 2 == 0)
            evenList.add(currentNode->get());
        else
            oddList.add(currentNode->get());

        currentNode = currentNode->getNext();
    }

    cout << "\n************* OUTPUT *************" << endl;
    cout << "Odd List\n" << endl;
    traverse(oddList);

    cout << "Even List\n" << endl;
    traverse(evenList);

    List mergedList = mergeLists(oddList, evenList);
    cout << "Merged List\n" << endl;
    traverse(mergedList);

    return 0;
}

