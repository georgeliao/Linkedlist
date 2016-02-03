//*****************************************************************
//  LinkedList.cpp
//
//  Written by George Liao on Jan 25, 2016.
//
//*****************************************************************


#include <iostream>
#include <assert.h>

//one node in the linked list
struct List_node {
    int m_key;
    List_node *p_next;
};


class LinkedList
{
    List_node *p_head;

public:
    //construct a linked list based on an given array
    LinkedList(int a_array[] = NULL, int n = 0);

    //return the middle and last 3rd nodes of the linked list
    void Get_mid_r3rd_node(List_node **p_mid, List_node **p_r3rd) const;

    //de-allocate all memory used by linked list
    ~LinkedList();
};



void LinkedList::Get_mid_r3rd_node(List_node **p_mid, List_node **p_r3rd) const {
    //p_mid and p_r3rd are output
    //r3rd means the last 3rd

    if(p_head == NULL || p_head->p_next == NULL){// 0 or 1 nodes case
        *p_r3rd = NULL;
        *p_mid = p_head;
        return ;
    }

    if(p_head->p_next->p_next == NULL){// 2 nodes case
        *p_r3rd = NULL;
        *p_mid = p_head->p_next;
        return ;
    }

    // case where there are more than 2 nodes
    List_node *p_ahead = p_head->p_next->p_next;
    List_node *p_behind_r3rd = p_head;//the pointer to find last 3rd node
    List_node *p_behind_mid = p_head->p_next;//the pointer to find the middle node


    while (p_ahead->p_next != NULL){
        p_ahead = p_ahead->p_next;
        p_behind_r3rd = p_behind_r3rd->p_next;
        p_behind_mid = p_behind_mid->p_next;

        if(p_ahead->p_next != NULL){
            //p_ahead moves two steps but p_behind_mid only moves one
            //when p_ahead reaches the end, p_behind_mid is in the middle
            p_ahead = p_ahead->p_next;
            p_behind_r3rd = p_behind_r3rd->p_next;
        }
    }

    *p_r3rd = p_behind_r3rd;
    *p_mid = p_behind_mid;

    return ;
}

LinkedList::LinkedList(int a_array[], int n){

    assert(n>=0);

    if (n == 0 || a_array == NULL) {
        p_head = NULL;
        return ;
    }

    p_head = new List_node;
    List_node *p_move = p_head;

    for (int i = 0; i < n; i++) {
        p_move->m_key = a_array[i];

        if (i == n-1){
            p_move->p_next = NULL;
            break;
        }
        else
        {
            p_move->p_next = new List_node;
            p_move = p_move->p_next;
        }
    }
}

LinkedList::~LinkedList(){

    if (p_head == NULL)
        return ;

    List_node *p_next = NULL;
    while (p_head != NULL){
        p_next = p_head->p_next;
        delete p_head;
        p_head = p_next;
    }
    return ;
}
