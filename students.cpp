#include "students.h"


void StudentList::print(){
    Student *s1 = head;
    if(s1 == NULL){
        cout<<"No students in this class"<<endl;
    }
    while(s1){
        cout<<"-"<<s1->firstName<<","<<s1->lastName<<", ID-"<<s1->ID<<", Major: "
            <<s1->major<<", Year: "<<s1->year<<", Graduation: "<<s1->grad<<endl;
        s1 = s1->next;
    }

}

void StudentList::outFile(ofstream &outfile){
    vector<Student*> stuList;
    Student *s = head;
    while(s){
        stuList.push_back(s);
        s = s->next;
    }

    for(int i = 0; i < stuList.size(); i++){
        Student *s = stuList[i];
        outfile<<s->lastName<<":"<<s->firstName<<":"<<s->ID<<":"<<s->major<<":"
               <<s->year<<":"<<s->grad<<endl;
    }
}
void StudentList::addStudent(Student *s){
    if(this->head == NULL){
        this->head  = new Student;
        this->head  = s;
        this->head ->next = NULL;
    }
    else{
        Student *h = head;
        while(h){
            h = h->next;
        }
        h->next = new Student;
        h->next = s;
        h->next->next = NULL;
        h->next->prev = h;
    }
}

void StudentList::addStudent(string first, string last, int ident, string maj,
                             string classStand, int gradYear){
            if(head == NULL){
                head = new Student;
                head->firstName = first;
                head->lastName = last;
                head->ID = ident;
                head->major = maj;
                head->year = classStand;
                head->grad = gradYear;
                head->next = NULL;
            }
            else{
                Student *s = head;
                while(s->next){
                    s = s->next;
                }
                s->next = new Student;
                s->next->firstName = first;
                s->next->lastName = last;
                s->next->ID = ident;
                s->next->major = maj;
                s->next->year = classStand;
                s->next->grad = gradYear;
                s->next->next = NULL;
                s->next->prev = s;
            }
        } 

void StudentList::deleteStudent(string last, string first){
    if((head->lastName == last) && (head->firstName == first)){
        Student *s = head;
        head = head->next;
    
        delete s;
        return;
    }
    else{
        Student *s = head;
        while(s){
            if(s->lastName == last && s->firstName == first){
                if(s->next == NULL){
                    s->prev->next = NULL;
                    delete s;
                    return;
                }
                else{
                    s->prev->next = s->next;
                    s->next->prev = s->prev;
                    delete s;
                    return;
                }
            }
            else{
                s = s->next;
            }
        }
        cout<<"Student not in system"<<endl;
    }
}
vector<Student*> StudentList::searchStudentName(string last, string first){
    vector<Student*> stuList;

    Student *s = this->head;
    while(s){
         if(last == s->lastName && first == s->firstName){
             stuList.push_back(s);
          
        }
         s = s->next;
    }
    return stuList;
    

}
vector<Student*> StudentList::searchStudentID(int ID){
    vector<Student*> stuList;
    Student *s = head;
    while(s){
        if(s->ID == ID){
            stuList.push_back(s);
        }
        s = s->next;
    }
    return stuList;


}
vector<Student*> StudentList::searchStudentMajor(string maj){
    vector<Student*> stuList;
    Student *s = head;
    while(s){
        if(s->major == maj){
            stuList.push_back(s);
        }
        s = s->next;
    }
    return stuList;
   
    
}
vector<Student*> StudentList::searchStudentGrad(int year){
    vector<Student*> stuList;
    Student *s = head;
    while(s){
        if(s->grad == year){
            stuList.push_back(s);
        }
        s = s->next;
    }
    return stuList;

}
vector<Student*> StudentList::searchStudentClass(string stand){
    vector<Student*> stuList;
    Student *s = head;
    while(s){
        if(s->year == stand){
            stuList.push_back(s);
        }
        s = s->next;
    }
    return stuList;
}