Circular doubly linked list:
============================
Method 2:
---------
	- Use head as starting node, which contains data.
	- Head node is used to keep reference of starting node and last node and
	  data as well as it is 1st node.
	- For printing the nodes, traverse from starting node means head node.
	- Always traverse from start node i.e "head".

				Head					a						b
	     _________________ 	     _________________	     _________________
	    |    |      |     |     |    |      |     |     |    |      |     |
	--->| b  |  1   |  a  |<--->|Head|  2   |  b  |<--->| a  |  3   |Head |<--
	|   |____|______|_____|     |____|______|_____|     |____|______|_____|  |
	|________________________________________________________________________|
