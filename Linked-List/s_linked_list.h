/**
 * Header file for a singly linked list data structure
 * 
 * Author: Bluedillydilly
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef S_LINKED_LIST_H
#define S_LINKED_LIST_H


typedef struct sll_node
{
    void* val;      // ptr to the value at current node 
    struct sll_node* next; // next entry in the list
} sll_node;

typedef struct sllist_t {

    sll_node* head; // first node in list
    sll_node* tail; // last node in list
    uint length;    // length of list
    uint data_size; // size of type values of list

} sllist;

/**
 * Creates and initializes an empty singly linked list.
 * @param data_size The size of the values being stored in the list 
 * 
 * @return An empty linked list
 */
sllist* init_sllist( uint data_size );

/**
 * Creates and initializes an empty singly linked list node.
 * @param data_size size of the data at the node
 * 
 */
sll_node* init_sll_node( uint data_size );

/**
 * Add a new value to a singly linked list
 * @param sll Head of list to add new value to.
 * @param val New value to add to list.
 * 
 */
void sllist_push( sllist* sll, void* val );

/**
 * Add a new value to a singly linked list
 * @param sll Head of list to add new value to.
 * @param val New value to add to list.
 * 
 */
void* sllist_pop( sllist* sll );

/**
 * Remove the nth element in the singly linked list.
 * @param sll Head of list to remove element from
 * @param index index of element to remove
 * 
 * @return The element removed 
 */
void* sllist_remove( sllist* sll, uint index );

/**
 * Access the singly linked list by an index.
 * @param sll Head of list to index
 * @param index index of element to get
 * 
 * @return The element indexed
 */
void* sllist_get( sllist* sll, uint index );

/**
 * Prints the singly linked list. Each node value treated as int
 * @param ssl Head of list to print
 */
void sllist_printi( sllist* sll );

#endif