/*
 *  File Name: hydro.cpp
 *  Assignment: ENSF 337 Lab 8 Exercise  C
 *  Lab section: B01
 *  Completed by: Aarsh Shah
 *  Submission Date: Friday Nov. 25
 */

// cd Labs/lab8/Submission/lab8_EXC/

/*
Issues with the code:
- The pressEnter function doesn't get called after the call to the coressponding option function
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "list.h"
#include "hydro.h"

int main(void)
{
    FlowList x;
    int numRecords;
    displayHeader();
    numRecords = readData(&x);

    if (numRecords == 0)
    {
        cout << "No records in file. Program terminates.\n";
        return 0;
    }

    int option;

    while (1)
    {
        option = menu();

        if (option == 1)
        {
            // call display function;
            display(&x);
        }
        else if (option == 2)
        {
            // call addData function
            addData(&x, &numRecords);
        }
        else if (option == 3)
        {
            // call saveData function;
            saveData(&x);
        }
        else if (option == 4)
        {
            // call removeData
            removeData(&x, &numRecords);
        }
        else if (option == 5)
        {
            cout << "Program terminated succesfully.\n";
            break;
        }
        else
        {
            cout << "\nNot a valid input.\n";
        }
        pressEnter();
    }
}

void displayHeader()
{

    cout << "Program: Flow Studies - Fall 2022\n"
            "Version : 1.0\n"
            "Lab section : B01\n"
            "Produced by : Aarsh Shah\n";

    cout << "\n\n<<< Press Enter to Continue >>>\n";
    cin.get();
}

void pressEnter()
{
    cin.clear();
    cout << "\n\n<<< Press Enter to Continue >>>\n";
    cin.get();
    cin.get();
}

int readData(FlowList *list)
{

    ifstream fin;
    fin.open("flow.txt");
    if (!fin)
    {
        cout << "Error opening file. Program terminated.\n";
        exit(1);
    }
    int numRecords = 0;
    while (!fin.eof())
    {
        ListItem item;
        fin >> item.year;
        fin >> item.flow;

        list->insert(item);
        numRecords++;
    }
    fin.close();

    return numRecords;
}

int menu()
{
    int choice;
    cout << "\n1. Display flow list, and the average.\n"
            "2. Add data\n"
            "3. Save data into the file\n"
            "4. Remove data\n"
            "5. Quit the program\n"
            "Enter your choice (1, 2, 3, 4, of 5):\n";

    cin >> choice;
    if (!cin || (choice < 1 || choice > 5))
    {
        cin.clear();
        return 0;
    }
    else
    {
        return choice;
    }
}

void display(FlowList *list)
{
    cout << "\nDisplaying the data in the list:";
    list->print();
    cout << "\nThe average flow in this list is: " << average(list);
}

void addData(FlowList *list, int *numRecords)
{
    ListItem item;
    cout << "\nEnter the year:";
    cin >> item.year;
    cout << "\nEnter the flow:";
    cin >> item.flow;

    if (!cin || item.year < 0 || item.flow < 0)
    {
        cout << "\nInvalid input. Please try again.\n";
        return;
    }

    // Checks if year already exists in list
    for (const Node *p = list->getHead(); p != 0; p = p->next)
    {
        if (p->item.year == item.year)
        {
            cout << "\nError: Year already exists in list. Please try again.\n";
            return;
        }
    }

    list->insert(item);
    *numRecords++;
    cout << "\nData added successfully!";
}

void removeData(FlowList *list, int *numRecords)
{
    int year;
    cout << "Enter the year to be removed: ";

    if (!(cin >> year))
    {
        cout << "\nInvalid input. Please try again.\n";
        return;
    }

    // Checks if year actually exists in list
    for (const Node *p = list->getHead(); p != 0; p = p->next)
    {

        if (p->item.year == year)
        {
            list->remove(year);
            cout << "\nData removed successfully!";
            *numRecords--;
            return;
        }
    }
    cout << "\nError: Year does not exist in list. Please try again.\n";
}

double average(FlowList *list)
{
    double sum = 0;
    int n = 0;
    Node *p = list->getHead();

    while (p != 0)
    {
        sum += p->item.flow;
        n++;
        p = p->next;
    }

    return sum / n;
}

void saveData(FlowList *list)
{
    ofstream fout;
    fout.open("flow.txt");
    if (!fout)
    {
        cout << "Error opening file. Program terminated.\n";
        exit(1);
    }
    Node *p = list->getHead();
    while (p != 0)
    {
        fout << p->item.year;
        fout << "      ";
        fout << p->item.flow << endl;
        p = p->next;
    }
    fout.close();

    cout << "Data Saved Successfully.\n";
}