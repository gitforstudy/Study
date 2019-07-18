Circular doubly linked list:
============================
Method 1:
---------
	- Use head as starting node, which doesn't have any data.
	- Head node is used to keep reference of starting node and last node.
	- For printing the nodes, traverse from starting node not from head node.
	- Always traverse from start node i.e "head->next or head.next".


		 	   Head                     a                       b
         _________________       _________________       _________________
        |    |      |     |     |    |      |     |     |    |      |     |
    --->| b  |   x  |  a  |<--->|Head|  1   |  b  |<--->| a  |  2   |Head |<--
    |   |____|______|_____|     |____|______|_____|     |____|______|_____|  |
    |________________________________________________________________________|
