#include <cstdlib>
#include "List.h"
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

	return 0;
}