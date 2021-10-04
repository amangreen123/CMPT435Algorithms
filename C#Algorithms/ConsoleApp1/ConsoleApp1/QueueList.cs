using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class QueueList
    {
        Node head;
        Node tail;

        internal void LinkedListQueue()
        {
            this.head = this.tail = null;
        }

        internal void Enqueue(char item)
        {
            Node newNode = new Node(item);
            
            // If the queue is empty, then the new nod is front and rear both 
            if(head == null)
            {
                this.head = this.tail = newNode;
                return;

            }
            else
            {
                this.tail.next = newNode;
                tail = newNode;
                //this.head = this.tail = newNode;
                //this.tail = newNode;
            }
        }

        internal char Dequeue()
        {
           if(this.head == null)
            {
                return '\u0000';
            }

            Node temp = this.head;
            this.head = this.head.next;

           if (this.head == null) {

                this.tail = null;
            }


            return '\u0000';

        }

    }
}
