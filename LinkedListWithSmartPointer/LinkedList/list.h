#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   ~List();     // destructor
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const ;
   void print() const;

private:
	smart_pointer<ListNode<NODETYPE>> firstPtr;  // pointer to first node
	smart_pointer<ListNode<NODETYPE>> lastPtr;   // pointer to last node

   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );

}; // end class List



// default constructor
template< class NODETYPE >
List< NODETYPE >::List() 
: firstPtr(nullptr),
lastPtr(nullptr)
{ 
   // empty body

} // end List constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   cout << "All nodes destroyed\n\n";
} // end List destructor



// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
	smart_pointer<ListNode<NODETYPE>> newPtr(getNewNode(value));

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;

   } // end else

} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
	smart_pointer<ListNode<NODETYPE>> newPtr(getNewNode(value));

	if (isEmpty()) // List is empty
		firstPtr = lastPtr = newPtr;
	else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else

} // end function insertAtBack

// remove functions /////////////////////////////////////////////////////////////////////////////////////////////


// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {  
	   smart_pointer<ListNode<NODETYPE>> tempPtr(firstPtr);

	   if (firstPtr == lastPtr){
		   firstPtr = smart_pointer<ListNode<NODETYPE>>(nullptr);
		   lastPtr = smart_pointer<ListNode<NODETYPE>>(nullptr);
	   }
	   else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed

      return true;  // delete successful

   } // end else

} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
	   smart_pointer<ListNode<NODETYPE>> tempPtr(lastPtr);

	   if (firstPtr == lastPtr){
		   firstPtr = smart_pointer<ListNode<NODETYPE>>(nullptr);
		   lastPtr = smart_pointer<ListNode<NODETYPE>>(nullptr);
	   }
      else {
		  smart_pointer<ListNode<NODETYPE>> currentPtr(firstPtr);

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = smart_pointer<ListNode<NODETYPE>>(nullptr);

      } // end else

      value = tempPtr->data;
      //delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromBack




// until here ///////////////////////////////////////////////////////////////////////////////////////////////////

// is List empty?
template< class NODETYPE > 
bool List< NODETYPE >::isEmpty() const
{ 
	if (firstPtr == smart_pointer<ListNode<NODETYPE>>(nullptr))
		return true;
	
	return false; 
   
} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( 
   const NODETYPE &value )
{
	return new ListNode< NODETYPE >(value);

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if
   smart_pointer<ListNode< NODETYPE >> currentPtr;
   currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != smart_pointer<ListNode<NODETYPE>>(nullptr)) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print





#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
