// OLList2.h
// ENSF 337 Lab 10 Exercise F

#ifndef OLLIST_H
#define OLLIST_H

typedef int ListItem;

struct Node
{
  ListItem item;
  Node *next;
};

class OLList
{
public:
  OLList(); // PROMISES: Creates empty list.
  OLList(const OLList &source);
  OLList &operator=(const OLList &rhs);
  ~OLList();

  void insert(const ListItem &itemA);
  // PROMISES:
  //    A node with a copy of itemA is added in
  //    a way that preserves the nondecreasing
  //    order of items in nodes.

  void remove(const ListItem &itemA);
  //  PROMISES:
  //    If no node has an item matching itemA,
  //    list is unchanged.
  //    Otherwise exactly one node with
  //    its item == itemA is removed.

  void print() const;
  // PROMISES:
  //   If list is empty, LIST IS EMPTY
  //   is printed on cout.
  //   Otherwise items are printed,
  //   one per line, on cout.

private:
  Node *headM;
  void destroy();
  // Deallocate all nodes, set headM to zero.

  void destroy_sublist(Node *sublist_head);
  // Recursive helper for destroy.

  void copy(const OLList &source);
  // List becomes copy of source.

  Node *copy_sublist(const Node *source_sublist);
  // Recursive helper for copy.
};

#endif
