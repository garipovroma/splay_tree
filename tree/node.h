//
// Created by roma on 19.09.2020.
//

#ifndef SPLAY_TREE_NODE_H
#define SPLAY_TREE_NODE_H

struct node {
    node *l, *r, *p;
    int x, sz;
    node() {
        l = r = p = nullptr;
        sz = 0;
    }
    node(int a) {
        x = a;
        l = r = p = nullptr;
        sz = 1;
    }
    node(int a, node* parent) {
        x = a;
        l = r = nullptr;
        p = parent;
        sz = 1;
    }
};

#endif //SPLAY_TREE_NODE_H
