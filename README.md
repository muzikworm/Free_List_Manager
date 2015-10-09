# Free_List_Manager
1. To implement a free list manager which keeps track of calls of malloc() and free().  
2. The user interface should allow to issue a malloc() call for x bytes. 
e.g  $:> malloc 10  would result in a malloc call for 10 bytes.  
3. The user interface should allow to issue a free call for any past malloc() call by index 
e.g $:> free 2  will result in the free operation for the 2nd malloc call  
4. The user interface should allow to print the free list 
e.g.:  $:>  print  will result in printing the past malloc calls (which are still allocated) in the order with size 
and pointer address information
