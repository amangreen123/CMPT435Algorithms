using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp1
{

  
    class StackandQueue
    {

        static void PalindromeCheck()
        {
            string magicItems = @"C:\Users\aaron\Desktop\magicitems.txt";
            StackList stackList = new StackList();
            QueueList queueList = new QueueList();

            if (File.Exists(magicItems))
            {
                
                int count = 0;
                int palindromeNum = 0;
                
                

                IEnumerable<string> lines = File.ReadAllLines(magicItems); // returns array of strings
                

                foreach (string line in lines)
                {
                    char[] itemArray = line.ToCharArray();
                           count++;
                    //Console.WriteLine("\t" + line);
                    

                    foreach(char c in itemArray) {

                        //Console.WriteLine(c + "\r" );
                            
                            stackList.Push(c);
                           queueList.Enqueue(c);
                 

                    }

                    for(int i = 0; i < count; i++)
                    {
                        char sta = stackList.Pop();
                        char que = queueList.Dequeue();
                       // string stack = sta.ToString();
                       // string queue = que.ToString();
                        

                        if (sta == que)
                        {
                            if(i == (count - 1))
                            {
                                palindromeNum++;
                                Console.WriteLine(++count + ":" + itemArray + ": is a palindrome.");
                                Console.WriteLine("Palindrome number is " + palindromeNum);
                            }
                            
                            

                        }
                    }
                  

                }

                

            }


            

            Console.ReadKey();
        }

        
        
        static void Main(string[] args)
        {

            PalindromeCheck();
           
        }
    }
    
}
