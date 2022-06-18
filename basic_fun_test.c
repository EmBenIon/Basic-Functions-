#include "basic_fun.h"

//gcc basic_fun_test.c -o test basic_fun_matrix.c basic_fun_list.c 
//Compiling command when using basic_fun.h library

int main()
{
    int i=0;
    SLL *test, *head = CreateSLL(4, sizeof(int), 1);
    test = head;

    print("Done1\n");
    while(test != NULL)
    {
        print("%d\n", i);
        test->data = (int*)i++;
        test = test->next;
    }

    print("Done2\n");
    test = head;
    for(i=1;i<=4;i++)
    {
        test = GetElement_byindexSLL(head, i);
        print("%d ", (int)test->data);
    }

    DeleteElement_byindexSLL(head, 2);

    print("Done3\n");

    test = head;
    for(i=1;i<=3;i++)
    {
        test = GetElement_byindexSLL(head, i);
        print("%d ", (int)test->data);
    }

    DeleteSLL(head);
    print("Done4");
    return 0;
}