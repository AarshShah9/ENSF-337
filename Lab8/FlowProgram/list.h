/*
 *  File Name: list.h
 *  Assignment: ENSF 337 Lab 8 Exercise  C
 *  Lab section: B01
 *  Completed by: Aarsh Shah
 *  Submission Date: Friday Nov. 25
 */

#ifndef LIST_H
#define LIST_H

struct ListItem
{
    int year;
    double flow;
};

struct Node
{
    ListItem item;
    Node *next;
};

class FlowList
{
public:
    FlowList(); // PROMISES: Creates empty list.
    FlowList(const FlowList &source);
    FlowList &operator=(const FlowList &rhs);
    ~FlowList();

    void insert(const ListItem &itemA);
    // PROMISES:
    //    A node with a copy of itemA is added in
    //    a way that preserves the nondecreasing
    //    order of items in nodes.

    void remove(const int &itemA);
    //  PROMISES:
    //    If no node has an item matching itemA,
    //    list is unchanged.
    //    Otherwise exactly one node with
    //    its item == itemA is removed.

    void print() const;
    // PROMISES:
    //   Prints items in list on a single line, with commas separating
    //   the items and square brackets marking the ends of the list.
    // NOTE:
    //   This is different from the print function presented in lectures.

    Node *getHead() const { return headM; }

private:
    Node *headM;

    void destroy();
    // Deallocate all nodes, set headM to zero.

    void copy(const FlowList &source);
    // List becomes copy of source.
};

#endif