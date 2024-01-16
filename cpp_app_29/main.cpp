#include "LinkedList.h"

int main() {
    LinkedList<int> myList;

    myList.AddToHead(3);
    myList.AddToTail(5);
    myList.AddToTail(7);
    myList.AddToHead(1);

    myList.Show();

    myList.DeleteFromHead();
    myList.DeleteFromTail();

    myList.Show();

    myList.DeleteAll();

    return 0;
}
