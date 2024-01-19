#include "Stack.h"

int main() {

    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Stack size: " << myStack.getSize() << std::endl;
    std::cout << "Top element: " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << "Stack size after pop: " << myStack.getSize() << std::endl;

    return 0;
}