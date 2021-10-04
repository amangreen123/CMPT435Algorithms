using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class StackList
    {
        Node top;

        public void LinkedListStack()
        {
            this.top = null;
          
        }



        // adds element to the stack
        internal void Push(char value)
        {
            Node newNode = new Node(value);

            //checks if top is null 
            if (top == null)
            { 
              newNode.next = null;

            }
            else
            {
                newNode.next = top;
            }

            top = newNode;

            //top.data = value;
            //top.next = top;

            //top = newNode;

        }

        // removes element from the stack
        internal char Pop()
        {
            //default equivalent of null for a char

            char popC = '\u0000'; 

            if (top != null)
            {
                popC = top.data;
                top = top.next;
            }
            
            return popC;
           
        }


    }
}
