#include "UpdatedList.h"

int main() {
    LinkedList<int> myList;

    myList.AddToHead(3);
    myList.AddToTail(5);
    myList.AddToTail(7);
    myList.AddToHead(1);

    std::cout << "Original List: ";
    myList.Show();

    myList.InsertAt(4, 2);
    std::cout << "List after inserting 4 at position 2: ";
    myList.Show();

    myList.DeleteAt(3);
    std::cout << "List after deleting element at position 3: ";
    myList.Show();

    int searchResult = myList.Search(5);
    if (searchResult != -1) {
        std::cout << "Element 5 found at position " << searchResult << std::endl;
    }
    else {
        std::cout << "Element 5 not found" << std::endl;
    }

    int replaceCount = myList.Replace(3, 9);
    std::cout << "List after replacing 3 with 9: ";
    myList.Show();
    std::cout << "Number of replacements: " << replaceCount << std::endl;

    myList.Reverse();
    std::cout << "Reversed List: ";
    myList.Show();

    myList.DeleteAll();

    return 0;
}

