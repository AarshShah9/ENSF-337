/*
 *  File Name: hydro.h
 *  Assignment: ENSF 337 Lab 8 Exercise  C
 *  Lab section: B01
 *  Completed by: Aarsh Shah
 *  Submission Date: Friday Nov. 25
 */

#include "list.h"

#ifndef HYDRO_H
#define HYDRO_H

void displayHeader();
int readData(FlowList *list);
int menu();
void display(FlowList *list);
void addData(FlowList *list, int *numRecords);
void removeData(FlowList *list, int *numRecords);
double average(FlowList *list);
void saveData(FlowList *list);
void pressEnter();

#endif