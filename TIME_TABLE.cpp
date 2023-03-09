#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#include"hashTable.h"
#include"TeacherHash.h"

void gotoxy(int y, int x) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int x, y;
using namespace std;
HashTable table(5);
teacherHash t_table(5);

class University {
protected:
	string course;
	string lab;
	string batch;
	int semester;
	string teacher_name;
	string lab_teacher;
	string t_course_name;
	string class_room ;
	string lab_location;
	int credit_hours ;
public:
	University() {
		course = "xyz";
		lab = "efg";
		batch = "abc";
		semester = 0;
		teacher_name = "ijk";
		lab_teacher = "uvc";
		t_course_name = "mno";
		class_room = "0";
		lab_location = "jkl";
		credit_hours = 0;
	}
	void set_course(string course, string lab, string batch, int semester,string teacher_name,string lab_teacher,string t_course_name, string class_room, string lab_location, int credit_hours) {
		this->course = course;
		this->lab = lab;
		this->batch = batch;
		this->semester = semester;
		this->teacher_name = teacher_name;
		this->lab_teacher = lab_teacher;
		this->t_course_name = t_course_name;
		this->class_room = class_room;
		this->lab_location = lab_location;
		this->credit_hours = credit_hours;
	}
	string get_course() {
		return course;
	}
	string get_lab() {
		return lab;
	}
	string get_batch() {
		return batch;
	}
	int get_semester() {
		return semester;
	}
	string get_teacher_name() {
		return teacher_name;
	}
	string get_lab_teacher() {
		return lab_teacher;
	}
	string get_t_course_name() {
		return t_course_name;
	}
	string get_class_room() {
		return class_room;
	}
	int get_credit_hours() {
		return credit_hours;
	}
	void get_Detail() {
		cout << endl;
		cout << "Course: " << course << "LAB: " << lab << "Batch: " << batch << "Semester: " << semester << "Teacher Name: " << teacher_name <<"Lab Teacher Name: " <<lab_teacher<< "Teacher's Course Name: " << t_course_name << "Class Room : " << class_room << "Credit Hours : " << credit_hours << endl;
	}
};
class Time :public University {
protected:
	int day;
	string class_time;
	string lab_time;
	float class_duration;
	float lab_duration;

public:
	Time() {
		day = 0;
		class_time = "0";
		lab_time = "0";
		class_duration = 0;
		lab_duration = 0;
	}
	void inputStudent() {
		cin.ignore();
		cout << "Enter Batch: "; getline(cin, batch);
		cout << "Enter Semester: "; cin >> semester;
		cin.ignore();
		cout << "Enter No of Courses: ";
		int n;
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cout << endl;
			cout << "Write the Details of Course " << i + 1 << endl;
			cout << "Enter Course Name: ";  getline(cin, course);

			cout << "Enter Credit Hour: "; cin >> credit_hours;
			cin.ignore();
			if (credit_hours == 3) {
				int c;
				cout << "Enter '1' if You Want To Take One Class of '3' hours..." << endl << "Enter '2' if You Want to Take 2 Classes of 1.5 Hours.." << endl;
				cout << ">> "; cin >> c;
				cout << endl;
				cin.ignore();
				if (c == 1) {
					cout << "Enter Day No for its class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
						table.insert(day, course, class_time, class_duration, class_room);
					cin.ignore();
				}
				if (c == 2) {
					cout << "Enter Day No for its first class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					table.insert(day, course, class_time, class_duration, class_room);
					cin.ignore();
					cout << "Enter Day No for its second class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					table.insert(day, course, class_time, class_duration, class_room);
					cin.ignore();
				}
			}
			
			if (credit_hours > 3) {
				cout << "This Course Has Lab, So Enter Lab Details also... " << endl;
				cout << "Enter Day No: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
				cout << " 1.Monday ";
				cout << " 2.Tuesday ";
				cout << " 3.Wednesday ";
				cout << " 4.Thursday ";
				cout << " 5.Friday " << endl;
				cout << ">> "; cin >> day;
				day--;
				cin.ignore();
				string lab_course = course + "_lab";
				cout << "Enter Lab Time: "; getline(cin, lab_time);
				cout << "Enter Lab Duration: "; cin >> lab_duration;
				cin.ignore();
				cout << "Enter Lab Location: "; getline(cin, lab_location);
				table.insert(day, lab_course, lab_time, lab_duration, lab_location);
				cin.ignore();
				int c;
				cout << "Enter '1' if You Want To Take One Class of '3' hours..." << endl << "Enter '2' if You Want to Take 2 Classes of 1.5 Hours.." << endl;
				cout << ">> "; cin >> c;
				cout << endl;
				cin.ignore();
				if (c == 1) {
					cout << "Enter Day No for its class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					table.insert(day, course, class_time, class_duration, class_room);
					cin.ignore();
				}
				if (c == 2) {
					cout << "Enter Day No for its first class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					table.insert(day, course, class_time, class_duration, class_room);
					cin.ignore();
					cout << "Enter Day No for its second class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					table.insert(day, course, class_time, class_duration, class_room);
					cin.ignore();
				}
			}
			if (credit_hours < 3) {
				cout << "Enter Day No for its class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
				cout << " 1.Monday ";
				cout << " 2.Tuesday ";
				cout << " 3.Wednesday ";
				cout << " 4.Thursday ";
				cout << " 5.Friday " << endl;
				cout << ">> "; cin >> day;
				day--;
				cin.ignore();
				cout << "Enter Class Room: "; getline(cin, class_room);
				cout << "Enter Class Time: "; getline(cin, class_time);
				cout << "Enter Class Duration: "; cin >> class_duration;
				table.insert(day, course, class_time, class_duration, class_room);
				cin.ignore();
			}
			cout << "===========================================" << endl;
		}
		
	}
	void inputTeacher() {
		cin.ignore();
		cout << "Enter Batch: "; getline(cin, batch);
		cout << "Enter Semester: "; cin >> semester;
		cout << "Enter No of Courses: ";
		int n;
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cout << "Enter Teacher's Name: "; getline(cin, teacher_name);
			cout << "Enter Lab-Teacher-Name: "; getline(cin, lab_teacher);
			cout << "Enter Teacher's Course: "; getline(cin, t_course_name);
			cout << endl;
			cout << "Write the Details of Course " << i + 1 << endl;
			cout << "Enter Course Name: ";  getline(cin, course);
			cout << "Enter Credit Hour: "; cin >> credit_hours;
			cin.ignore();
			if (credit_hours == 3) {
				int c;
				cout << "Enter '1' if You Want To Take One Class of '3' hours..." << endl << "Enter '2' if You Want to Take 2 Classes of 1.5 Hours.." << endl;
				cout << ">> "; cin >> c;
				cout << endl;
				cin.ignore();
				if (c == 1) {
					cout << "Enter Day No for its class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
				}
				if (c == 2) {
					cout << "Enter Day No for its first class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
						t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
					cout << "Enter Day No for its second class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
				}
			}

			if (credit_hours > 3) {
				cout << "This Course Has Lab, So Enter Lab Details also... " << endl;
				cout << "Enter Day No: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
				cout << " 1.Monday ";
				cout << " 2.Tuesday ";
				cout << " 3.Wednesday ";
				cout << " 4.Thursday ";
				cout << " 5.Friday " << endl;
				cout << ">> "; cin >> day;
				day--;
				cin.ignore();
				string lab_course = course + "_lab";
				cout << "Enter Lab Time: "; getline(cin, lab_time);
				cout << "Enter Lab Duration: "; cin >> lab_duration;
				cout << endl;
				cin.ignore();
				cout << "Enter Lab Location: "; getline(cin, lab_location);
					t_table.insert(day, lab_teacher, course, class_time, class_duration, class_room);
					cin.ignore();
				cin.ignore();
				int c;
				cout << "Enter '1' if You Want To Take One Class of '3' hours..." << endl << "Enter '2' if You Want to Take 2 Classes of 1.5 Hours.." << endl;
				cout << ">> "; cin >> c;
				cout << endl;
				cin.ignore();
				if (c == 1) {
					cout << "Enter Day No for its class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
				}
				if (c == 2) {
					cout << "Enter Day No for its first class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
					cin.ignore();
					cout << "Enter Day No for its second class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
					cout << " 1.Monday ";
					cout << " 2.Tuesday ";
					cout << " 3.Wednesday ";
					cout << " 4.Thursday ";
					cout << " 5.Friday " << endl;
					cout << ">> "; cin >> day;
					day--;
					cin.ignore();
					cout << "Enter Class Room: "; getline(cin, class_room);
					cout << "Enter Class Time: "; getline(cin, class_time);
					cout << "Enter Class Duration: "; cin >> class_duration;
					t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
					cin.ignore();
				}
			}
			if (credit_hours < 3) {
				cout << "Enter Day No for its class: "; //--------- "1 For Monday" "2 For Tuesday" "3 For Wednesday" "4 For Thursday" "5 for Friday"--//
				cout << " 1.Monday ";
				cout << " 2.Tuesday ";
				cout << " 3.Wednesday ";
				cout << " 4.Thursday ";
				cout << " 5.Friday " << endl;
				cout << ">> "; cin >> day;
				day--;
				cin.ignore();
				cout << "Enter Class Room: "; getline(cin, class_room);
				cout << "Enter Class Time: "; getline(cin, class_time);
				cout << "Enter Class Duration: "; cin >> class_duration;
					t_table.insert(day, teacher_name, course, class_time, class_duration, class_room);
					cin.ignore();
				cin.ignore();
			}
			cout << "===========================================" << endl;
		}
	}
};

void insertmenu() {
	system("CLS");
	gotoxy(x=5, y=55);
	cout << "======================================================" << endl;
	gotoxy(++x, y=72);
	cout << "TIME TABLE PROJECT" << endl;
	gotoxy(++x, y=55);
	cout << "======================================================" << endl;
	cout << endl;
	gotoxy(x=9, y=70);
	cout << "[1] Make New Time Table " << endl;
	gotoxy(++x, y);
	cout << "[2] Show Time Table " << endl;
	gotoxy(++x, y);
	cout << "[3] Update Time Table " << endl;
	gotoxy(++x, y);
	cout << "[4] Exit " << endl;
}

int main() {
	int x;
	Time t;
	bool flag = true;
	while (flag) {
		insertmenu();
		gotoxy(x = 14, y = 60);
		cout << "Enter Your Choice: ";
		cin >> x;
		switch (x) {
		case 1: {
			system("cls");
			int n;
			bool flag1 = true;
			while (flag1) {
				gotoxy(++x, y);
				cout << "MAKING A NEW TIME TABLE..." << endl << endl << endl;
				cout << "[1] For Students " << endl;
				cout << "[2] For Teachers " << endl;
				cout << "[3] Return to Main Menu " << endl;
				cout << "Enter Your Choice: "; cin >> n;
				if (n == 1) {
					system("cls");
					t.inputStudent();
					flag1 = false;
				}
				else if (n == 2) {
					system("cls");
					t.inputTeacher();
					flag1 = false;
				}
				else if (n == 3) {
					flag1 = false;
				}
				else {
					cout << "Sorry! You Entered a wrong choice, Try Again..." << endl;
					system("pause");
					system("cls");
				}
			}
			cout << "\nPRESS ANY KEY TO CONTINUE...";
			cin.ignore();
			break;
		}
		case 2: {
			system("cls");
			gotoxy(15, 60);
			cout << "SHOWING A TIME TABLE..." << endl << endl << endl;
			int n;
			bool flag2 = true;
			while (flag2) {
				cout << "[1] For Students " << endl;
				cout << "[2] For Teachers " << endl;
				cout << "[3] Return to Main Menu " << endl;
				cout << "Enter Your Choice: "; cin >> n;
				if (n == 1) {
					system("cls");
					table.printSuper();
					//flag2 = false;
				}
				else if (n == 2) {
					system("cls");
					t_table.printSuper();
					//flag2 = false;
				}
				else if (n == 3) {
					flag2 = false;
				}
				else {
					cout << "Sorry! You Entered a wrong choice, Try Again..." << endl;
					system("pause");
					system("cls");
				}
			}
			cout << "\nPRESS ANY KEY TO CONTINUE...";
			cin.ignore();
			break;
		}
		case 3: {
			system("pause");
			cout << "\nPRESS ANY KEY TO CONTINUE...";
			cin.ignore();
			break;
		}
		case 4: {
			system("cls");
			gotoxy(x=10, y=65);
			cout << "=============================" << endl;
			gotoxy(++x, y=70);
			cout << "THANKYOU! FOR YOUR TIME" << endl << endl;
			gotoxy(++x, y=65);
			cout << "=============================" << endl;
			exit(0);
		}
		}
	}
}
