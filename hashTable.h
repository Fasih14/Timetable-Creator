#pragma once
#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
class Node {
public:
    string course;
    int day;
    string time;
    float duration;
    string location;
    Node* next;
    Node(int key, string course, string time, float duration, string location) {
        this->day = key;
        this->course = course;
        this->time = time;
        this->duration = duration;
        this->location = location;
        next = NULL;
        input();
    }
    void input() {
        cin.ignore();
    }
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};
class HashTable {
    Node** table;
    int cs; //total entries
    int ts; //size of table

    void gotoxy(int y, int x) {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
public:
    HashTable(int default_size = 5) {
        cs = 0;
        ts = default_size;
        table = new Node * [ts];
        for (int i = 0; i < ts; i++) {
            table[i] = NULL;
        }
    }
    void insert(int key, string course, string time, float duration, string location) {
        int idx = key;
        Node* n = new Node(key, course, time, duration, location);
        n->next = table[idx];
        table[idx] = n;
        cs++;
    }

    void print() {
        for (int i = 0; i < ts; i++) {
            cout << "Day " << i + 1 << " ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->course << "  ";
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

        int x =1, y =0;
        for (int i = 0; i < ts; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                gotoxy(x , y+=17);
                cout << temp->course ;
                temp = temp->next;
            }
            gotoxy(x +=1, y =17);
            cout << endl;
        }
    }
    int* search(int key) {
        for (int i = 0; i < ts; i++) {
            Node* temp = table[i];
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
        Node* head_ref = table[idx];
        int i = 0;
        while (head_ref != NULL) {
            if (head_ref->day == key) {
                // Store head node
                Node* temp = head_ref;
                Node* prev = NULL;

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