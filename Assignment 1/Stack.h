

class Stack { //constructor
   
    
    int numChar;//number of elements in struct

private:

    struct Node {
        char item;
        Node* tail;
    };
    Node* stackPt;

public:
    Stack();
    void Push(const char item);
    char Pop();
    bool emptyStack() const;



};



