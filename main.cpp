#include <iostream>
#include <string>
#include <fstream>
#include "students.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
bool isDelims(char c, string delim);

int main(){
    int resp;
    StudentList list1;
    vector<Student*> list2;
    bool system = true;
    cout<<"Welcome to the Student Record Management System"<<endl;
    while(system){

        cout<<"Please choose from one of the following: "<<endl;
        cout<<"1. Add New Student"<<endl;
        cout<<"2. Delete a student"<<endl;
        cout<<"3. Search for student"<<endl;
        cout<<"4. Import student record from file"<<endl;
        cout<<"5. Export student record to a file"<<endl;
        cout<<"6. Print the student list"<<endl;
        cout<<"7. Quit program"<<endl;
        cin>>resp;

        string first;
        string last;
        int ID;
        string major;
        string classStand;
        int gradYear;
        string cont;

        if(resp == 1){
            cout<<"You are adding a student"<<endl;

            cout<<"Enter the student first name: ";
            cin >> first;

            cout<<"Enter the student last name: ";
            cin >> last;

            cout<<"Enter the student ID: ";
            cin>>ID;

            cout<<"Enter the student's major: ";
            cin>>major;

            cout<<"Enter the student's class standing: ";
            cin>>classStand;

            cout<<"Enter the student's graduation year: ";
            cin>>gradYear;

            list1.addStudent(first, last, ID, major, classStand, gradYear);
            
            cout<<"Student "<<first<<" "<<last<<" added."<<endl;

            cout<<"Do you wish to continue? (y/n): ";
            cin>>cont;

            if(cont == "n"){
                system = false;
            }
        }

        else if(resp == 2){
            
            cout<<"You are deleting a student"<<endl;

            cout<<"Enter student last name: ";
            cin>>last;

            cout<<"Enter student first name: ";
            cin>>first;

            list1.deleteStudent(last, first);
            cout<<"Removing student "<<first<<" "<<last<<" from the system"<<endl;

            cout<<"Do you wish to continue? (y/n): ";
            cin>>cont;

            if(cont == "n"){
                system = false;
            }
        }
        else if(resp == 3){
            bool search = true;
            int searchType;
            string searchCont;
            while(search){
                cout<<"You are searching for a student"<<endl;
                cout<<"Please select how you would like to search for the Student"<<endl;
                cout<<"1. Name"<<endl;
                cout<<"2. Student ID"<<endl;
                cout<<"3. Major"<<endl;
                cout<<"4. Graduation Year"<<endl;
                cout<<"5. Class standing"<<endl;
                cin>>searchType;

                if(searchType == 1){
                    cout<<"You are searching for student by name"<<endl;
                    cout<<"Enter the first name: ";
                    cin>>first;
                    cout<<"Enter the last name: ";
                    cin>>last;
                    cout<<endl;

                    list2 = list1.searchStudentName(last, first);

                    cout<<"Printing search results:"<<endl;
                    cout<<endl;
                    if(list2.size() == 0){
                        cout<<"No student with name "<<first<<" "<<last<<" was found"<<endl;
                    }
                    else{
                        for(int i = 0; i < list2.size(); i++){
                            Student *s1 = list2[i];
                            cout<<s1->firstName<<","<<s1->lastName<<" ID-"<<s1->ID<<", Major: "
                                <<s1->major<<", Year: "<<s1->year<<", Graduation: "<<s1->grad<<endl;
                        }

                    }

                    cout<<endl;
                    cout<<"Would you like to search again? (y/n): ";
                    cin>>searchCont;
                    
                    if(searchCont == "n"){
                        search = false;
                    }

                }
                else if(searchType == 2){
                    cout<<"You are searching by ID"<<endl;
                    cout<<"Enter the ID: ";
                    cin>>ID;

                    list2 = list1.searchStudentID(ID);

                    if(list2.size() == 0){
                        cout<<"No students with ID "<<ID<<" were found"<<endl;
                    }
                    else{
                        for(int i = 0; i < list2.size(); i++){
                            Student *s1 = list2[i];
                            cout<<s1->firstName<<","<<s1->lastName<<" ID-"<<s1->ID<<", Major: "
                                <<s1->major<<", Year: "<<s1->year<<", Graduation: "<<s1->grad<<endl;
                        }
                    }  
                    cout<<"Would you like to search again? (y/n): ";
                    cin>>searchCont;
                    
                    if(searchCont == "n"){
                        search = false;
                    }

                }
                else if(searchType == 3){ //major
                    cout<<"You are searching by major"<<endl;
                    cout<<"Enter the major: ";
                    cin>>major;

                    list2 = list1.searchStudentMajor(major);
                    cout<<"Printing search results: "<<endl;
                    cout<<endl;
                    if(list2.size() == 0){
                        cout<<"No students majoring in "<<major<<" were found"<<endl;
                    }
                    else{
                        for(int i = 0; i < list2.size(); i++){
                            Student *s1 = list2[i];
                            cout<<s1->firstName<<","<<s1->lastName<<" ID-"<<s1->ID<<", Major: "
                                <<s1->major<<", Year: "<<s1->year<<", Graduation: "<<s1->grad<<endl;
                        }
                    }  

                    cout<<"Would you like to search again? (y/n): ";
                    cin>>searchCont;
                    
                    if(searchCont == "n"){
                        search = false;
                    }


                }
                else if(searchType == 4){ //grad year
                    cout<<"You are searching by graduation year"<<endl;
                    cout<<"Enter the grad year: ";
                    cin>>gradYear;

                    list2 = list1.searchStudentGrad(gradYear);

                    cout<<"Printing search results: "<<endl;
                    cout<<endl;
                    if(list2.size() == 0){
                        cout<<"No students graduating in "<<gradYear<<" were found"<<endl;
                    }
                    else{
                        for(int i = 0; i < list2.size(); i++){
                            Student *s1 = list2[i];
                            cout<<s1->firstName<<","<<s1->lastName<<" ID-"<<s1->ID<<", Major: "
                                <<s1->major<<", Year: "<<s1->year<<", Graduation: "<<s1->grad<<endl;
                        }
                    }  

                    cout<<"Would you like to search again? (y/n): ";
                    cin>>searchCont;
                    
                    if(searchCont == "n"){
                        search = false;
                    }


                }
                else if(searchType == 5){//class standing
                    cout<<"You are searching by class standing"<<endl;
                    cout<<"Enter class standing: ";
                    cin>>classStand;

                    list2 = list1.searchStudentClass(classStand);

                    cout<<"Printing search results: "<<endl;
                    cout<<endl;
                    if(list2.size() == 0){
                        cout<<"No students with a class standing of "<<classStand<<" were found"<<endl;
                    }
                    else{
                        for(int i = 0; i < list2.size(); i++){
                            Student *s1 = list2[i];
                            cout<<s1->firstName<<","<<s1->lastName<<" ID-"<<s1->ID<<", Major: "
                                <<s1->major<<", Year: "<<s1->year<<", Graduation: "<<s1->grad<<endl;
                        }
                    }  
                    cout<<"Would you like to search again? (y/n): ";
                    cin>>searchCont;
                    
                    if(searchCont == "n"){
                        search = false;
                    }


                }
                else{
                    cout<<"Response not recognized"<<endl;

                }

            } 

        }
        else if(resp == 4){
            ifstream newStus;
            string infile;
            string line;
            cout<<"You are importing a student record from a file"<<endl;
            cout<<"Enter file name: ";
            cin>>infile;

            newStus.open(infile);
            if(newStus.fail()){
                cerr<<"File could not be opened"<<endl;
                exit(1);
            }
            
            //char delims = ': \n';
            char c;
            int fields = 0;
            while(getline(newStus, line)){
                std::stringstream ss(line);
                while(getline(ss, line, ':')){
                    if(fields == 0){
                        last = line;
                    }
                    else if(fields == 1){
                        first = line;
                    }
                    else if(fields == 2){
                        ID = stoi(line);
                    }
                    else if(fields == 3){
                        major = line;
                    }
                    else if(fields == 4){
                        classStand = line;
                    }
                    else if(fields == 5){
                        gradYear = stoi(line);

                        list1.addStudent(first, last, ID, major, classStand, gradYear);
                    }
                    fields++;
                    if(fields == 6){
                        fields = 0;
                    }
                    
                }

            }

            cout<<"File imported"<<endl;
            cout<<endl;
            cout<<"Do you wish to continue? (y/n): ";
            cin>>cont;

            if(cont == "n"){
                system = false;
            }


            
        }
        else if(resp == 5){
            ofstream students;
            string outfile;
            string line;
            cout<<"You are exporting a student record to a file"<<endl;
            cout<<"Enter file name: ";
            cin>>outfile;

            students.open(outfile);
            if(students.fail()){
                cerr<<"File could not be opened"<<endl;
                exit(1);
            }
            
            list1.outFile(students);

            cout<<"File exported"<<endl;

            cout<<"Do you wish to continue? (y/n): ";
            cin>>cont;

            if(cont == "n"){
                system = false;
            }

            

        }
        else if(resp ==6){
            cout<<"Printing students"<<endl;
            cout<<endl;
            list1.print();
            cout<<endl;

            cout<<"Do you wish to continue? (y/n): ";
            cin>>cont;

            if(cont == "n"){
                system = false;
            }

        }
        else if(resp == 7){
            system = false;
        }
        else{
            cout<<"Response not recognized"<<endl;
        }


    }
    cout<<"Thank you for using the Student Managment System"<<endl;
    cout<<endl;

}

bool isDelims(char c, string delim){
    for(int i = 0; i < delim.size(); i++){
        if(delim[i] == c){
            return true;
        }
    }
    return false;
}