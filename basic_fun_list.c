#include "basic_fun_list.h"

SLL *CreateSLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output)
{
    INTEGER i;
    SLL *List = (SLL*)malloc(sizeof(SLL));
    if(List == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    List->data = malloc(size_of_data_type);
    List->next = (SLL*)malloc(sizeof(SLL));
    
    if(List->data == NULL || List->next == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    SLL *First_Element = List;

    for(i = 2; i < number_of_elements; i++)
    {
        List = List->next;

        List->data = malloc(size_of_data_type);
        List->next = (SLL*)malloc(sizeof(SLL));
    
        if(List->data == NULL || List->next == NULL)
        {
            if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
            return NULL;
        }
    }

    List = List->next;

    List->data = malloc(size_of_data_type);
    List->next = NULL;

    if(List->data == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    return First_Element;
}

SLL *GetElement_byindexSLL(SLL *List, INTEGER index)
{
    SLL *res = List;
    
    while (index > 1 && res->next != NULL)
    {
        index--;
        res = res->next;
    }

    return res;
}

void DeleteElement_byindexSLL(SLL *List, INTEGER index)
{
    if(index <= 1)
    {
        SLL *node = List;
        
        List = List->next;
        free(node);

        return;
    }

    SLL *parent = GetElement_byindexSLL(List, index - 1);
    SLL *child = (parent->next)->next;

    if(parent->next != NULL)
        free(parent->next);

    parent->next = child;
}

void DeleteSLL(SLL *List)
{
    SLL *node = List;

    while(node != NULL)
    {
        List = node;
        node = node->next;

        free(List);
    }

    List = NULL;
}

//____________

//____________

DLL **CreateDLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output)
{
    INTEGER i;
    DLL *First_Element, *AUX, *List = (DLL*)malloc(sizeof(DLL));
    DLL **Result = (DLL**)malloc(2 * sizeof(*DLL));

    if(List == NULL || Result == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    List->data = malloc(size_of_data_type);
    List->next = (DLL*)malloc(sizeof(DLL));
    List->prev = NULL;
    
    if(List->data == NULL || List->next == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    First_Element = List;

    for(i = 2; i < number_of_elements; i++)
    {
        AUX = List;
        List = List->next;

        List->data = malloc(size_of_data_type);
        List->next = (SLL*)malloc(sizeof(SLL));
        List->prev = AUX;
    
        if(List->data == NULL || List->next == NULL)
        {
            if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
            return NULL;
        }
    }

    AUX = List;
    List = List->next;

    List->data = malloc(size_of_data_type);
    List->next = NULL;
    List->prev = AUX;

    if(List->data == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    Result[0] = First_Element;
    Result[1] = List;

    return Result;
}

DLL *GetElement_byindexDLL(DLL *List, INTEGER index, short search_direction)
{
    DLL *res = List;

    if(search_direction == 1)
    {   
        while (index > 1 && res->next != NULL)
        {
            index--;
            res = res->next;
        }
    }
    else if(search_direction == 0)
    {
        while(index > 1 && res->prev != NULL)
        {
            index--;
            res = res->prev;
        }
    }

    return res;
}

void DeleteElement_byindexDLL(DLL *List, INTEGER index, short search_direction)
{
    DLL *node = GetElement_byindexDLL(List, index, search_direction);
    
    if(node->prev == NULL) //first node
    {
        (node->next)->prev = NULL;
        free(node);

        if(search_direction == 1) //List is the root
            List = List->next;

        return;
    }

    if(node->next == NULL) //last node
    {
        (node->prev)->next = NULL;
        free(node);

        if(search_direction == 0) //List is the tail
            List = List->prev;
    
        return;
    }

    (node->prev)->next = node->next;
    (node->next)->prev = node->prev;

    free(node);
}

void DeleteDLL(DLL *List)
{
    DLL *Node = List;

    while(List->next != NULL)
    {
        List = List->next;
        free(List->prev);
    }
    free(List);

    while(Node->prev != NULL)
    {
        Node = Node->prev;
        free(Node->next);
    }
    free(Node);
}

//____________

//____________

Node* CreateGraph(FLOATING_POINT **adjacency_matrix, INTEGER number_of_nodes, INTEGER size_of_data_type, short fail_output)
{
    Node **Nodes = (Node**)malloc(number_of_nodes * sizeof(Node*));
    if(Nodes == NULL)
    {
        if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
        return NULL;
    }

    INTEGER i, e, k;
    
    for(i=0; i<number_of_nodes; i++)
    {
        Nodes[i] = (Node*)malloc(sizeof(Node));
        Nodes[i]->link = (Node**)malloc(number_of_nodes * sizeof(Node*));
        Nodes[i]->link_weight = (FLOATING_POINT*)malloc(number_of_nodes * sizeof(FLOATING_POINT));
    
        if(Nodes[i] == NULL || Nodes[i]->link == NULL || Nodes[i]->link_weight == NULL)
        {
            if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
            return NULL;
        }

    }

    for(i=0; i<number_of_nodes; i++)
    {
        k=0;

        for(e=0; e<number_of_nodes; e++)
        {
            if(adjacency_matrix[i][e] != 0)
            {
                Nodes[i]->link[k] = Nodes[e];
                Nodes[i]->link_weight[k++] = adjacency_matrix[i][e];
            }
        }

        Nodes[i]->number_of_links = k;
        Nodes[i]->link = (Node**)realloc(Nodes[i]->link, k * sizeof(Node*));
        Nodes[i]->link_weight = (FLOATING_POINT*)realloc(Nodes[i]->link_weight, k * sizeof(FLOATING_POINT));

        if(Nodes[i]->link == NULL || Nodes[i]->link_weight == NULL)
        {
            if(fail_output != 0) { SET_COLOR_RED print("Allocation error!\n"); SET_COLOR_WHITE}
            return NULL;
        }
    }

    Node* root = Nodes[0];
    free(Nodes);

    return root;
}
