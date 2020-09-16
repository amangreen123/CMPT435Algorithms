#include <cstdlib>
#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include<fstream>
using namespace std;

int main(int argc, char** argv) {
	
	ifstream letterFile("magicitems.txt");

	List MagicItems;

	MagicItems.AddNode("a");
	MagicItems.AddNode("b");
	MagicItems.AddNode("c");
	MagicItems.PrintList();

	MagicItems.RemoveNode("d");
	MagicItems.PrintList();

    Stack stack;
        stack.Push("a", 1);
        stack.Push("b", 2);
        stack.Push("c", 3);
        stack.PrintStack();
        cout << "pop\n";
        stack.Pop();
        cout << "pop\n";
        stack.Pop();
        cout << "pop\n";
        stack.Pop();
        cout << "pop\n";
        stack.Pop();
        cout << "pop\n";
        stack.Pop();

    Queue q(5);
        q.enquene(1);
        q.enquene(2);
        q.enquene(3);
        cout << "Queue size is" << q.size() << endl;
        q.dequene();
        q.dequene();
        q.dequene();

        if (q.empty())
            cout << "Queue is Empty\n";
        else
            cout << "Queue is not Empty\n";



        return 0;

	return 0;
}
