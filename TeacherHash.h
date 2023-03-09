#pragma once
#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
class T_Node {
public:
    string T_name;
    string course;
    int day;
    string time;
    float duration;
    string location;
    T_Node* next;
    T_Node(int key,string T_name, string course, string time, float duration, string location) {
        this->day = key;
        this->T_name = T_name;
        this->course = course;
        this->time = time;
        this->duration = duration;
        this->location = location;
        next = NULL;
    }
        //cin.ignore();
    ~T_Node() {
        if (next != NULL) {
            delete next;
        }
    }
};
class teacherHash {
    T_Node** table;
    int cs; //total entries
    int ts; //size of table

    void gotoxy(int y, int x) {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
public:
    teacherHash(int default_size = 5) {
        cs = 0;
        ts = default_size;
        table = new T_Node * [ts];
        for (int i = 0; i < ts; i++) {
            table[i] = NULL;
        }
    }
    void insert(int key,string T_name, string course, string time, float duration, string location) {
        int idx = key;
        T_Node* n = new T_Node( key,T_name, course, time, duration, location);
        n->next = table[idx];
        table[idx] = n;
        cs++;
    }

    void print() {
        for (int i = 0; i < ts; i++) {
            cout << "Day " << i + 1 << " ";
            T_Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->T_name << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void printTemplate() {
        string arr[6][7] = { {"Days\t\t","8:00-9:30\t","9:30-11:00\t","11:00-12:30\t","12:30-1:00\t","1:00-2:30\t","2:30-4:00\t"},
        {"Monday\t\t","\t","\t","\t","\t","\t","\t"},
        {"Tuesday\t\t","\t","\t","\t","\t","\t","\t"},
        {"Wednesday\t\t","\t","\t","\t","\t","\t","\t"},
        {"Thursday\t\t","\t","\t","\t","\t","\t","\t"},
        {"Friday\t\t","\t","\t","\t","\t","\t","\t"} };
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printSuper() {
        //system("cls");
        printTemplate();

        int x = 1, y = 0;
        for (int i = 0; i < ts; i++) {
            T_Node* temp = table[i];
            while (temp != NULL) {
                gotoxy(x, y += 17);
                cout << temp->T_name;
                temp = temp->next;
            }
            gotoxy(x += 1, y = 17);
            cout << endl;
        }
    }
    int* search(int key) {
        for (int i = 0; i < ts; i++) {
            T_Node* temp = table[i];
            while (temp != NULL) {
                if (temp->day == key) {
                    return &temp->day;
                }
            }
            return NULL;
        }
    }

    bool empty(int key) {
        int idx = key;
        T_Node* head_ref = table[idx];
        int i = 0;
        while (head_ref != NULL) {
            if (head_ref->day == key) {
                // Store head node
                T_Node* temp = head_ref;
                T_Node* prev = NULL;

                // If head node itself holds
                // the key to be deleted
                if (temp != NULL && temp->day == key) {
                    head_ref = temp->next; // Changed head
                    delete temp;            // free old head
                    return 1;
                }
                else {
                    while (temp != NULL && temp->day != key) {
                        prev = temp;
                        temp = temp->next;
                    }

                    // If key was not present in linked list
                    if (temp == NULL)
                        return 0;

                    // Unlink the node from linked list
                    prev->next = temp->next;

                    // Free memory
                    delete temp;
                }
                return 1;
            }
            i++;
            head_ref = head_ref->next;
        }
        return 0;
    }
};