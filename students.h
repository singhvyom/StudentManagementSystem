#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

class Student{   
    public:
        string firstName;
        string lastName;
        int ID;
        string major;
        string year;
        int grad;
        Student* next;
        Student* prev;
        Student(){
            firstName = " ";
            lastName = " ";
            ID = 0;
            major = " ";
            year = " ";
            grad = 0;
            next = NULL;
            prev = NULL;
        }
        Student(string first, string last, int ident, 
        string maj, string classStand, int gradYear){
            firstName = first;
            lastName = last;
            ID = ident;
            major = maj;
            year = classStand;
            grad = gradYear;
            next = NULL;
            prev = NULL;
        }
        friend ostream& operator<<(ostream& os, const Student &s1){
            os<<s1.firstName<<","<<s1.lastName<<" ID-"<<s1.ID<<", Major: "
                <<s1.major<<", Year "<<s1.year<<", Graduation: "<<s1.grad<<endl;

            return os;
        }
        void print();

};


class StudentList{
    public:
        StudentList(){
            head = NULL;
        }
        void print();
        vector<Student*> searchStudentName(string last, string first);
        vector<Student*> searchStudentID(int ID);
        vector<Student*> searchStudentMajor(string maj);
        vector<Student*> searchStudentGrad(int year);
        vector<Student*> searchStudentClass(string stand);
        void deleteStudent(string last, string first);
        void addStudent(string first, string last, int ident, string maj,
                        string classStand, int gradYear);
        void addStudent(Student *s);
        void outFile(ofstream &outfile);

    private:
        Student *head;


};


#endif