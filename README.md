<br />Documentation
<br />
<br />SLL Documentation
<br />|_____________________________________________________________
<br />|   CreateSLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output)
<br />|        *parameters descripion:*
<br />|            number_of_elements = Number of elements in list
<br />|            size_of_data_type  = It is used for multiple purpose data types in list and it is equal at call with sizeof(my_data_type)
<br />|            fail_output        = For any integer non zero it display errors messages if necessary
<br />|
<br />|        *returns: the head pointer of the list*
<br />|
<br />|        *note:* This functions creates memory trash if allocation fails. Is highly recommended to stop the program if the function returns NULL (may be patched up in the future)
<br />|
<br />|
<br />|_____________________________________________________________
<br />|    GetElement_byindexSLL(SLL *List, INTEGER index)
<br />|        *parameters description:*
<br />|            *List = The pointer of the head of the list in which the search is made
<br />|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers lower than 1 it returns the first element and for integers bigger than the number of elements returns the last element)
<br />|
<br />|        *returns: element at index*
<br />|
<br />|
<br />|_____________________________________________________________
<br />|    DeleteElement_byindexSLL(SLL *List, INTEGER index)
<br />|        *parameters description:*
<br />|            *List = The pointer of the head of the list in which the deletion is made
<br />|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers lower than 1  it deletes the first element and for integers bigger than the number of elements doesn't deletes anything)
<br />|
<br />|        *returns: -*
<br />|
<br />|
<br />|_____________________________________________________________
<br />|    DeleteSLL(SLL *List)
<br />|        *parameters description:*
<br />|            *List = The pointer of the head of the list in which is deleted
<br />|            
<br />|        *returns: -*
<br />|        
<br />|
<br />|_____________________________________________________________
<br />
<br />
<br />
<br />
<br />
<br />
<br />DLL Documentation
<br />|_____________________________________________________________
<br />|   CreateDLL(INTEGER number_of_elements, INTEGER size_of_data_type, short fail_output)
<br />|        *parameters descripion:*
<br />|            number_of_elements = Number of elements in list
<br />|            size_of_data_type  = It is used for multiple purpose data types in list and it is equal at call with sizeof(my_data_type)
<br />|            fail_output        = For any integer non zero it display errors messages if necessary
<br />|
<br />|        *returns: the head and the tail pointers of the list as a vector*
<br />|
<br />|        *note:* This functions creates memory trash if allocation fails. Is highly recommended to stop the program if the function returns NULL (may be patched up in the future)
<br />|
<br />|
<br />|_____________________________________________________________
<br />|    GetElement_byindexDLL(DLL *List, INTEGER index, short search_direction)
<br />|        *parameters description:*
<br />|            *List = The pointer of the head/tail of the list in which the search is made
<br />|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers lower than 1 it returns the first element and for integers bigger than the number of elements returns the last element)
<br />|            search_direction = 1 for indexing and searching from the begining and 0 for reverse
<br />|
<br />|        *returns: element at index*
<br />|
<br />|
<br />|_____________________________________________________________
<br />|    DeleteElement_byindexDLL(DLL *List, INTEGER index, short search_direction)
<br />|        *parameters description:*
<br />|            *List = The pointer of the head/tail of the list in which the deletion is made
<br />|            index = The order number of the element wanted **(1 FOR THE FIRST, 2 FOR THE SECOND, ...)** (for integers lower than 1 it returns the first element and for integers bigger than the number of elements returns the last element)
<br />|            search_direction = 1 for indexing and searching from the begining and 0 for reverse
<br />|
<br />|        *returns: element at index*
<br />|
<br />|
<br />|_____________________________________________________________
<br />|    DeleteDLL(DLL *List, INTEGER index, short search_direction)
<br />|        *parameters description:*
<br />|            *List = The pointer of any element of the list in which is deleted
<br />|
<br />|        *returns: -*
<br />|
<br />|
<br />|_____________________________________________________________
<br />
<br />
<br />