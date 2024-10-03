#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
    int value;
    struct node* next;
}node;


node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void push_front(node **array, int value)
{
    node *temp;
    temp = createNode(value);

    if(*array == NULL)
    {
        *array = temp;
    }
    else
    {
        temp->next = *array;
    }
    (*array) = temp;
}

void outputList(node **array)
{
    node *temp = *array;
    while(temp != NULL)
    {
        printf("Xuat: %d \n", temp->value);
        temp = temp->next;
    }

}



void pop_back(node** array)
{
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);

}

void pop_front(node **array)
{
    node *temp = (*array)->next;
    node *temp2 = (*array);
    *array = temp;
    free(temp2);

}

int front(node *array)
{
    return array->value;
}

int back(node *array)
{
    node *temp = array;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp->value;
}

void insert(node **array, int value, int pos)
{
    int i=0;
    node *temp = *array;
    node *nodeAdd = createNode(value);
    while(temp->next != NULL && (pos-1) != i)
    {
        temp = temp->next;
        i++;
    }

    if((pos-1) != i)
    {
        printf("Khong du phan tu \n");
    }

    nodeAdd->next = temp->next;
    temp->next = nodeAdd;

}

int size(node **array)
{
    int i=0;
    while((*array)->next != NULL)
    {
        i++;
    }

    return i;
}


void delete_list(node **array, int pos)
{
    int i=0;
    node *temp = *array;
    node *temp2;

    while(temp->next != NULL && (pos-1) != i)
    {
        temp = temp->next;
        i++;
    }

    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);

}

int sizeOfList(node *array)
{
    node *temp = array;
    int i=1;

    if(array == NULL)
    {
        return 0;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    return i;

}


uint8_t empty(node *array)
{
    if(array == NULL)
        return 1;
    else
        return 0;
}



int get(node* array, int pos)
{
    int i = 0;
 
    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}





int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_front(&arr, 10);
    outputList(&arr);
    // pop_back(&arr);
    // outputList(&arr);
    pop_front(&arr);
    outputList(&arr);
    printf("Front: %d \n",front(arr));
    printf("Back: %d \n", back(arr));
    insert(&arr, 8, 1);
    outputList(&arr);
    delete_list(&arr, 1);
    outputList(&arr);
    printf("Size: %d \n", sizeOfList(arr));
    printf("Is empty: %d \n", empty(arr));
    // push_back(&arr, 4);
    // push_back(&arr, 5);
    // push_back(&arr, 3);
    // push_back(&arr, 10);

    // printf("Value test: %d\n", get(arr, 2));
    // printf("Value test: %d\n", get(arr, 0));
    // printf("Value test: %d\n", get(arr, 5));


	return 0;
}



