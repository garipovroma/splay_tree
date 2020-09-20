### Splay Tree

---

A **splay tree** is a [self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) with the additional property that recently accessed elements are quick to access again. It performs basic operations such as insertion, look-up and removal in O(log n) amortized time. For many sequences of non-random operations, splay trees perform better than other search trees, even when the specific pattern of the sequence is unknown. The splay tree was invented by [Daniel Sleator](https://en.wikipedia.org/wiki/Daniel_Sleator) and [Robert Tarjan](https://en.wikipedia.org/wiki/Robert_Tarjan) in 1985. [wiki-link](https://en.wikipedia.org/wiki/Splay_tree#:~:text=A%20splay%20tree%20is%20a,(log%20n)%20amortized%20time.)

---

**Available methods**

<u>*Methods for keep splay-tree structure :*</u>

- `new_node(int x)` - creates a new node with `key(field X at node) = x`
- `void rotate(node *&v, node *&p)` - rotates an edge `(p - v)`, like `(x - y)` on this pic ![img](https://habrastorage.org/getpro/habr/post_images/58b/97d/c8b/58b97dc8bf8293538e48a34716f4e1f5.png)
- `void set_parent(node *&v, node *p)` -sets parent of node `v` = `p`
- `void keep_parent(node *&v)` - sets parent for `v->l` and `v->r` nodes equal to `v`
- `node* splay(node *&v)` - returns node v to which the operation `splay` (which consists of few `zig`, `zig-zag`, `zig-zig` operations) was applied 
- `void upd_sz(node *&v)` - updates subtree size for node `v`

<u>*Basic Binary Search Tree operations :*</u>

- `std::pair <node*, node*> split(node *&v, int k)` - splits subtree of `v` node by key `k` 
- `node *merge(node *&vl, node *&vr)` - merges `vl` and `vr` subtrees, works only in case where any key from `vl` less then every key from `v2`
- `void add(int x)` adds a new node with `key = x` to the tree
- `void remove(int x)` - removes node with `key = x` from the tree
- `int next(int x)` - finds the least key in tree, which greater than x
- `int prev(int x)` - finds the greatest key in tree, which less than x
- `int kth_max(int k)` - finds the k-largest key in tree
- `int kth_min(int k)` - finds the k-smallest key in tree

---

