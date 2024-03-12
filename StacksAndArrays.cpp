#include <iostream>
#include <limits>
using namespace std;

#define MAX_SIZE 5

struct Stack {
    int items[MAX_SIZE];
    int top;
};   

void initializeStack(Stack&);
void push(Stack&, int);
int pop(Stack&);
int top(Stack&);
void display(Stack&);
void purge(Stack&);
bool isEmpty(Stack&);
bool isFull(Stack&);
bool isValidInput(int);

int main() {
    char choice;
    do {
        Stack stack;
        initializeStack(stack);
        int option, element;

        do {
            cout << "\nStack Operations:" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Top" << endl;
            cout << "4. Display" << endl;
            cout << "5. Purge" << endl; 
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> option;

            switch (option) {
                case 1:
                    if (!isFull(stack)) {
                        cout << "Enter element to push (0-99): ";
                        cin >> element;
                        if (isValidInput(element)) {
                            push(stack, element);
                            cout << "Stack after push operation:" << endl;
                            display(stack);
                        } else {
                            cout << "Invalid input. Please enter a number between 0 and 99." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } else {
                        cout << "Stack is full. Cannot push." << endl;
                    }
                    break;
                case 2:
                    if (!isEmpty(stack)) {
                        cout << "Popped element: " << pop(stack) << endl;
                        cout << "Stack after pop operation:" << endl;
                        display(stack);
                    } else {
                        cout << "Stack is empty. Cannot pop." << endl;
                    }
                    break;
                case 3:
                    if (!isEmpty(stack)) {
                        cout << "Top element: " << top(stack) << endl;
                    } else {
                        cout << "Stack is empty." << endl;
                    }
                    break;
                case 4:
                    if (!isEmpty(stack)) {
                        display(stack);
                    } else {
                        cout << "Stack is empty." << endl;
                    }
                    break;
                case 5:
                    purge(stack); 
                    cout << "Stack purged." << endl;
                    break;
                case 6:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        } while (option != 6);

        cout << "Do you want to continue? (yes/no): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void initializeStack(Stack& stack) {
    stack.top = -1;
}

void push(Stack& stack, int element) {
    stack.items[++stack.top] = element;
}

int pop(Stack& stack) {
    return stack.items[stack.top--];
}

int top(Stack& stack) {
    return stack.items[stack.top];
}

void display(Stack& stack) {
    cout << "Stack: ";
    for (int i = stack.top; i >= 0; i--) {
        cout << stack.items[i] << " ";
    }
    cout << endl;
}

void purge(Stack& stack) {
    initializeStack(stack);
}

bool isEmpty(Stack& stack) {
    return stack.top == -1;
}

bool isFull(Stack& stack) {
    return stack.top == MAX_SIZE - 1;
}

bool isValidInput(int num) {
    return num >= 0 && num <= 99;
}
