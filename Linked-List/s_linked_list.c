#include "s_linked_list.h"

int main()
{
    sllist* sll = init_sllist( sizeof(int) );
    for (int i = 3; i < 10; i++)
    {
        sllist_push( sll, &i );
        sllist_printi(sll);
    }

    void* a = sllist_get( sll, 1 );
    printf("list[%d]: %d\n", 1, *((int*) a));

    a = sllist_get( sll, 10 );
    if (a) 
    {
        printf("list[%d]: %d\n", 1, *((int*) a));
    }

    sllist_remove( sll, 0 );
    sllist_printi( sll );

    sllist_remove( sll, 3 );
    sllist_printi( sll );

    sllist_remove( sll, 4 );
    sllist_printi( sll );

    int www = 123;
    sllist_push( sll, &www );
    sllist_printi(sll);
    
}

sllist* init_sllist( uint data_size )
{
    sllist* new_sll = (sllist*) calloc( 1, sizeof(sllist) );
    new_sll->head = init_sll_node( data_size );
    new_sll->tail = new_sll->head;
    new_sll->length = 0;
    new_sll->data_size = data_size;

    return new_sll;
}

sll_node* init_sll_node( uint data_size )
{
    sll_node* new_node = (sll_node*) calloc(1, sizeof(sll_node));
    new_node->next = NULL;
    new_node->val = (void*) calloc(1, data_size);

    return new_node;
}

void sllist_push( sllist* sll, void* val ) 
{
    // create new node
    sll->tail->next = init_sll_node( sll->data_size );
    // make new node the tail
    sll->tail = sll->tail->next;
    // make head if first element
    if (sll->length == 0) {
        sll->head = sll->tail;
    }

    // copy new value
    memcpy( sll->tail->val, val, sll->data_size );
    sll->length++;
}

void* sllist_remove( sllist* sll, uint index )
{
    if ( index >= sll->length ) // check if valid index
    {
        fprintf(stderr, "Removal Index Out of Bounds SLL: (%d) Max: (%d)\n", index, sll->length);
        return NULL;
    }

    sll_node* node = sll->head;
    for ( uint i = 1; i < index ; i++ ) 
    {
        node = node -> next;
    }
    // node = index - 1
    // want: index - 1 ---> index + 1
    sll_node* old;
    if ( index == 0 )
    {
        old = node;
    }
    else
    {
        old = node->next;
    }
    void* val = old->val;
    node->next = old->next;
    
    sll->length--;
    if ( index == 0 )
    {
        sll->head = node->next;

    }
    else if ( index == sll->length ) // check if removing tail
    {
        sll->tail = node;
    }

    free(old);
    return val;
}

void* sllist_get( sllist* sll, uint index )
{
    sll_node* node = sll->head;
    for ( uint i = 0; i < index; i++ ) 
    {
        node = node -> next;
        if (node == NULL)
        {
            fprintf(stderr, "Out of Bounds SLL: (%d) Max: (%d)\n", index, sll->length);
            return NULL;
        }
    }
    return node->val;
}

void sllist_printi( sllist* sll )
{
    printf("Singly Linked Int List (%d): ", sll->length );
    sll_node* node = sll->head;
    uint i = 0;
    while (i < sll->length )
    {
        // cast as int pointer, then de-ref
        printf("%d, ", *((int *) node->val));
        node = node->next;
        i++;
    }
    printf("\n");
}
