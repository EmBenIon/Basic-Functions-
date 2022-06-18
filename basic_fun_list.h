#include "global.h"



typedef struct sll{

    void *data;
    struct sll *next;

}SLL; //single linked list

typedef struct dll{
    
    void *data;
    struct dll *next, *prev;

}DLL; //double linked list


typedef struct basic_node{

    void *data;
    struct basic_node **link;
    FLOATING_POINT *link_weight;
    INTEGER number_of_links;

}Node; //multipurpose node type

//___________________________________________________________________________//
//Single Linked List functions                                               //
//___________________________________________________________________________//

SLL *CreateSLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output);

SLL *GetElement_byindexSLL(SLL *List, INTEGER index);

void DeleteElement_byindexSLL(SLL *List, INTEGER index); // !!It modifies "List" head pointer if is deleted the first element

void DeleteSLL(SLL *List);

//___________________________________________________________________________//
//Double Linked List functions                                               //
//___________________________________________________________________________//

DLL **CreateDLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output);

DLL *GetElement_byindexDLL(DLL *List, INTEGER index, short search_direction);

void DeleteElement_byindexDLL(DLL *List, INTEGER index, short search_direction); // !!It modifies "List" head pointer if is deleted the first element

void DeleteDLL(DLL *List);

//___________________________________________________________________________//
//Graph type data functions                                                  //
//___________________________________________________________________________//

Node* CreateGraph(FLOATING_POINT **adjacency_matrix, INTEGER number_of_nodes, INTEGER size_of_data_type, short fail_output);
