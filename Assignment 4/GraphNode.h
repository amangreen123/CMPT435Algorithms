//
// Created by aaron on 11/17/2020.
//

#ifndef MAIN_CPP_GRAPHNODE_H
#define MAIN_CPP_GRAPHNODE_H

#endif //MAIN_CPP_GRAPHNODE_H

struct GNode{
    int dest;
    struct GNode* next;
};

struct undirectedG{
    undirectedG* next;
    GNode* data;
};


