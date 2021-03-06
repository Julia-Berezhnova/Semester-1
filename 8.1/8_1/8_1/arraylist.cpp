#include "arraylist.h"
#include <iostream>

struct ArrayList
{
    int elementsNumber;
    int* array;
};

ArrayList* createList()
{
    ArrayList* result = new ArrayList();
    result->elementsNumber = 0;
    result->array = new int[maxNumberOfElements] {};
    return result;
}

void push(ArrayList* list, int value)
{
    list->array[list->elementsNumber] = value;
    ++list->elementsNumber;
}

int pop(ArrayList* list)
{
    --list->elementsNumber;
    int result = list->array[list->elementsNumber];
    list->array[list->elementsNumber] = {};
    return result;
}

int getElementsNumber(ArrayList* list)
{
    return list->elementsNumber;
}

int getHeadValue(ArrayList* list)
{
    return list->array[list->elementsNumber - 1];
}

void deleteList(ArrayList* list)
{
    delete[] list->array;
    delete list;
}

ArrayList* reverseList(ArrayList* list)
{
    ArrayList* result = createList();
    while (list->elementsNumber > 0)
    {
        push(result, pop(list));
    }
    deleteList(list);
    return result;
}

void printList(ArrayList* list)
{
    for (int i = list->elementsNumber - 1; i >= 0; --i)
    {
        std::cout << list->array[i] << " ";
    }
    std::cout << std::endl;
}
