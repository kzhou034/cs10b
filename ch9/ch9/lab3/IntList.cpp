#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   /*friend*/ 
   ostream & operator<<(ostream &out, const IntList &l) {
      IntNode *temp = l.head;
      if (temp == nullptr) {
         return out;
      }
      else {
         if (temp->next == nullptr) { //if temp is on the last node
            out << temp->value;
         }
         else {
            out << temp->value << " ";
            operator<<(out, temp->next);
         }
      }
      return out;
   }

   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
   bool IntList::exists(int i) const {
      bool z = false;
      IntNode *temp = head;
      if (temp == nullptr) {
         z = false;
      }
      else {
         if (temp->value == i) {
            z = true;
         }
         else if (exists(temp->next, i) == true) {
            z = true;
         }
         else {
            z = false;
         }
      }
      return z;
   }

 //private:
   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in.
      Otherwise returns false.
   */
   bool IntList::exists(IntNode *n, int i) const {
      bool z = false;
      if (n == nullptr) {
         z = false;
      }
      else {
         if (n->value == i) {
            z = true;
         }
         else if (exists(n->next, i)) {
            z = true;
         }
      }
      return z;
   }


/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *n) {
   if (n == nullptr) {
      return out;
   }
   else {
      if (n->next == nullptr) { //if n is on the last node
         out << n->value;
      }
      else {
         out << n->value << " ";
      }
      operator<<(out, n->next);
   }
   return out;
}
