Documentation

SLL Documentation
|_____________________________________________________________
|   CreateSLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output)
|        *parameters descripion:*
|            number_of_elements = Number of elements in list
|            size_of_data_type  = It is used for multiple purpose data types in list and it is equal at call with sizeof(my_data_type)
|            fail_output        = For any integer non zero it display errors messages if necessary
|
|        *returns: the head pointer of the list*
|
|        *note:* This functions creates memory trash if allocation fails. Is highly recommended to stop the program if the function returns NULL (may be patched up in the future)
|
|
|_____________________________________________________________
|    GetElement_byindexSLL(SLL *List, INTEGER index)
|        *parameters description:*
|            *List = The pointer of the head of the list in which the search is made
|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers <1 it returns the first element and for integers bigger than the number of elements returns the last element)
|
|        *returns: element at index*
|
|
|_____________________________________________________________
|    DeleteElement_byindexSLL(SLL *List, INTEGER index)
|        *parameters description:*
|            *List = The pointer of the head of the list in which the deletion is made
|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers <1 it deletes the first element and for integers bigger than the number of elements doesn't deletes anything)
|
|        *returns: -*
|
|
|_____________________________________________________________
|    DeleteSLL(SLL *List)
|        *parameters description:*
|            *List = The pointer of the head of the list in which is deleted
|            
|        *returns: -*
|        
|
|_____________________________________________________________






DLL Documentation
|_____________________________________________________________
|   CreateDLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output)
|        *parameters descripion:*
|            number_of_elements = Number of elements in list
|            size_of_data_type  = It is used for multiple purpose data types in list and it is equal at call with sizeof(my_data_type)
|            fail_output        = For any integer non zero it display errors messages if necessary
|
|        *returns: the head and the tail pointers of the list as a vector*
|
|        *note:* This functions creates memory trash if allocation fails. Is highly recommended to stop the program if the function returns NULL (may be patched up in the future)
|
|
|_____________________________________________________________
|    GetElement_byindexDLL(DLL *List, INTEGER index, short search_direction)
|        *parameters description:*
|            *List = The pointer of the head/tail of the list in which the search is made
|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers <1 it returns the first element and for integers bigger than the number of elements returns the last element)
|            search_direction = 1 for indexing and searching from the begining and 0 for reverse
|
|        *returns: element at index*
|
|
|_____________________________________________________________
|    DeleteElement_byindexDLL(DLL *List, INTEGER index, short search_direction)
|        *parameters description:*
|            *List = The pointer of the head/tail of the list in which the deletion is made
|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers <1 it returns the first element and for integers bigger than the number of elements returns the last element)
|            search_direction = 1 for indexing and searching from the begining and 0 for reverse
|
|        *returns: element at index*
|
|
|_____________________________________________________________
|    DeleteDLL(DLL *List, INTEGER index, short search_direction)
|        *parameters description:*
|            *List = The pointer of any element of the list in which is deleted
|
|        *returns: -*
|
|
|_____________________________________________________________
