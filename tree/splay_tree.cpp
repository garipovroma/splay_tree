//
// Created by roma on 19.09.2020.
//

#include <iostream>
#include "splay_tree.h"

node* splay_tree::new_node(int x) {
    nodes.push_back(new node(x));
    return nodes[nodes.size() - 1];
}

int splay_tree::size() {
    return tree_size;
}

int splay_tree::get_sz(node *v) {
    return (v == nullptr ? 0 : v->sz);
}

void splay_tree::upd_sz(node *&v) {
    if (v == nullptr) {
        return;
    }
    v->sz = get_sz(v->l) + 1 + get_sz(v->r);
}

void splay_tree::set_parent(node *&v, node *p) {
    if (v != nullptr) {
        v->p = p;
    }
    upd_sz(v);
}

void splay_tree::keep_parent(node *&v) {
    set_parent(v->l, v);
    set_parent(v->r, v);
    upd_sz(v);
}

void splay_tree::rotate(node *&v, node *&p) {
    node *g = p->p;
    if (g != nullptr) {
        if (g->l == p) {
            g->l = v;
        } else {
            g->r = v;
        }
    }
    if (p->l == v) {
        p->l = v->r;
        v->r = p;
    } else {
        p->r = v->l;
        v->l = p;
    }
    keep_parent(v);
    keep_parent(p);
    v->p = g;
}

node* splay_tree::splay(node *&v) {
    if (v->p == nullptr) {
        return v;
    }
    node *p = v->p;
    node *g = p->p;
    if (g == nullptr) {    //    zig
        rotate(v, p);
        return v;
    } else {
        bool f = (p->l == v) == (g->l== p);
        if (f) {   //   zig-zig
            rotate(p, g);
            rotate(v, p);
        } else {   //   zig-zag
            rotate(v, p);
            rotate(v, g);
        }
        return splay(v);
    }
}

void splay_tree::dfs(node *v) {
    if (v == nullptr) {
        return;
    }
    std::cout << v->x << ' ';
    dfs(v->l);
    dfs(v->r);
}

node* splay_tree::find(node *v, int x) {
    if (v == nullptr) {
        return nullptr;
    }
    if (v->x == x) {
        return splay(v);
    } else if (v->x < x && v->r != nullptr) {
        return find(v->r, x);
    } else if (v->x > x && v->l != nullptr) {
        return find(v->l, x);
    }
    return splay(v);
}

bool splay_tree::find(int x) {
    root = find(root, x);
    return (root != nullptr && root->x == x);
}

std::pair <node*, node*> splay_tree::split(node *&v, int k) {
    if (v == nullptr) {
        return {nullptr, nullptr};
    }
    node *root = find(v, k);
    if (root->x == k) {
        set_parent(root->l, nullptr);
        set_parent(root->r, nullptr);
        upd_sz(root->l);
        upd_sz(root->r);
        return {root->l, root->r};
    } else if (root->x < k) {
        node *cur = root->r;
        set_parent(cur, nullptr);
        root->r = nullptr;
        upd_sz(root);
        upd_sz(cur);
        return {root, cur};
    } else {
        node *cur = root->l;
        set_parent(cur, nullptr);
        root->l = nullptr;
        upd_sz(cur);
        upd_sz(root);
        return {cur, root};
    }
}

void splay_tree::add(int x) {
    tree_size++;
    if (root == nullptr) {
        root = new_node(x);
        return;
    }
    std::pair <node*, node*> t = split(root, x);
    root = new_node(x);
    root->l = t.first;
    root->r = t.second;
    keep_parent(root);
}

node* splay_tree::merge(node *&vl, node *&vr) {
    if (vl == nullptr) {
        return vr;
    }
    if (vr == nullptr) {
        return vl;
    }
    vr = find(vr, vl->x);
    vr->l = vl;
    keep_parent(vr);
    return vr;
}

void splay_tree::remove(int x) {
    tree_size--;
    root = find(root, x);
    set_parent(root->l, nullptr);
    set_parent(root->r, nullptr);
    root = merge(root->l, root->r);
}


int splay_tree::next(int x) {
    root = find(root, x);
    if (root == nullptr) {
        return 1e9 + 1;
    }
    if (root->x > x) {
        return root->x;
    }
    if (root->r == nullptr) {
        return 1e9 + 1;
    }
    node *cur = root->r;
    int val = (root->x > x ? root->x : (int)1e9 + 1);
    node *was;
    while (cur != nullptr) {
        val = std::min(cur->x, val);
        was = cur;
        cur = cur->l;
    }
    root = splay(was);
    return val;
}

int splay_tree::prev(int x) {
    root = find(root, x);
    if (root == nullptr) {
        return 1e9 + 1;
    }
    if (root->x < x) {
        return root->x;
    }
    if (root->l == nullptr) {
        return 1e9 + 1;
    }
    node *cur = root->l;
    int val = (root->x < x ? root->x : (int)-1e9 - 1);
    node *was;
    while (cur != nullptr) {
        val = std::max(val, cur->x);
        was = cur;
        cur = cur->r;
    }
    root = splay(was);
    return val;
}

int splay_tree::kth(node *v, int k) {
    int x = get_sz(v->r);
    if (x + 1 == k) {
        return v->x;
    } else if (k <= x) {
        return kth(v->r, k);
    } else {
        return kth(v->l, k - x - 1);
    }
}

int splay_tree::kth_max(int k) {
    return kth(root, k);
}

int splay_tree::kth_min(int k) {
    return kth(root, tree_size - k + 1);
}