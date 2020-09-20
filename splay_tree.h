//
// Created by roma on 19.09.2020.
//
#include "node.h"
#include <vector>

#ifndef SPLAY_TREE_SPLAY_TREE_H
#define SPLAY_TREE_SPLAY_TREE_H

struct splay_tree {
    size_t tree_size = 0;
    node *root = nullptr;
    std::vector <node*> nodes;

    node *new_node(int x);

    int get_sz(node *v);

    int size();

    void upd_sz(node *&v);

    void set_parent(node *&v, node *p);

    void keep_parent(node *&v);

    void rotate(node *&v, node *&p);

    node* splay(node *&v);

    void dfs(node *v);

    node *find(node *v, int x);

    bool find(int x);

    std::pair <node*, node*> split(node *&v, int k);

    void add(int x);

    node *merge(node *&vl, node *&vr);

    void remove(int x);

    int next(int x);

    int prev(int x);

    int kth_max(int k);

    int kth_min(int k);
private:
    int kth(node *v, int k);
};

#endif //SPLAY_TREE_SPLAY_TREE_H
