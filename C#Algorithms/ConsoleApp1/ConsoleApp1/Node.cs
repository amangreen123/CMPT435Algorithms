using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Node
    {
       internal char data;
       internal Node next;


        // Constructor to create a new node. Next is by default initialized as null
        public Node(char d)
        {
           this.data = d;
           this.next = null;
        }

    }
}
