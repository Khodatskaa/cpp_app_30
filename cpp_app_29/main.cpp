#include "List.h"

int main() {
    List<int> listA;
    listA.insert(1);
    listA.insert(2);
    listA.insert(3);

    List<int> listB;
    listB.insert(2);
    listB.insert(3);
    listB.insert(4);

    List<int>* clonedList = listA.clone();
    List<int>* combinedList = listA + listB;
    List<int>* intersectionList = listA * listB;

    std::cout << "List A: ";
    listA.display();
    std::cout << "List B: ";
    listB.display();

    std::cout << "Cloned List: ";
    clonedList->display();

    std::cout << "Combined List: ";
    combinedList->display();

    std::cout << "Intersection List: ";
    intersectionList->display();

    delete clonedList;
    delete combinedList;
    delete intersectionList;

    return 0;
}