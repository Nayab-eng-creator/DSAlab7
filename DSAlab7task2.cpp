#include <iostream>
using namespace std;

struct Node {
    string item;
    Node* next;
};

class GroceryList {
public:
    Node* head;

    GroceryList() {
        head = NULL;
    }

    void addItem(string item) {
        Node* newNode = new Node();
        newNode->item = item;
        newNode->next = head;
        head = newNode;
        cout << "Added: " << item << "\n";
    }

    bool isEmpty() {
        return head == NULL;
    }

    void removeItem(string item) {
        if (isEmpty()) {
            cout << "List is empty. No item to remove.\n";
            return;
        }

        if (head->item == item) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Removed: " << item << "\n";
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->item != item) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Item not found in the list.\n";
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Removed: " << item << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "The list is empty.\n";
            return;
        }

        cout << "Current grocery list: ";
        Node* current = head;
        while (current != NULL) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    GroceryList list;

    list.addItem("Milk");
    list.addItem("Bread");
    list.addItem("Eggs");

    list.display();

    list.removeItem("Bread");
    list.display();

    list.removeItem("Butter");
    list.display();

    list.addItem("Butter");
    list.display();

    return 0;
}

