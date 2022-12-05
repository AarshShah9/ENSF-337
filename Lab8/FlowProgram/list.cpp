/*
 *  File Name: list.cpp
 *  Assignment: ENSF 337 Lab 8 Exercise  C
 *  Lab section: B01
 *  Completed by: Aarsh Shah
 *  Submission Date: Friday Nov. 25
 */

// FlowList.cpp
// ENSF 337 Fall 2021 Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList()
    : headM(0)
{
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::print() const
{
    if (headM != 0)
    {
        cout << "\nYear:\tFlow (in billions of cubic meters):\n";
        cout << headM->item.year << '\t' << headM->item.flow;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << '\n'
                 << p->item.year << '\t' << p->item.flow;
    }
    else
        cout << "\nList is empty.\n";
}

void FlowList::insert(const ListItem &itemA)
{

    Node *new_node = new Node;
    new_node->item.year = itemA.year;
    new_node->item.flow = itemA.flow;

    if (headM == 0 || itemA.year <= headM->item.year)
    {
        new_node->next = headM;
        headM = new_node;
    }
    else
    {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while (after != 0 && itemA.year > after->item.year)
        {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void FlowList::remove(const int &itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item.year)
        return;

    Node *doomed_node = 0;

    if (itemA == headM->item.year)
    {
        doomed_node = headM;
        headM = headM->next;
        delete doomed_node;
        return;
    }
    else
    {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while (maybe_doomed != 0 && itemA > maybe_doomed->item.year)
        {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed->item.year == itemA)
        {
            before->next = maybe_doomed->next;
            delete maybe_doomed;
            return;
        }
    }
}

void FlowList::destroy()
{
    if (headM == 0)
        return;

    Node *current = headM;
    Node *after;

    while (headM != nullptr)
    {
        after = current->next;
        delete current;
        current = after;
        headM = after;
    }
    headM = nullptr;
}