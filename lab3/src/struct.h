#include <string>
using namespace std;

#ifndef STRUCT_HEADER
#define STRUCT_HEADER

struct entry {
    string emplid;
    int courseno;
    string instructorID;
    string termID;
    string sectionID;
    string grade;

    bool isEqual (entry j) {
        if(this->emplid == j.emplid && this->sectionID == j.sectionID) {
           return true;
        }
        else {
           return false;
       }

    }
    };

struct student {
    string iD;
    int course;
    string grade;
};

struct instructor {
    string iD;
    int course;
    string term;

    bool isEqual(instructor j) {
        if(this->iD == j.iD) {
            return true;

        } 
        else {
            return false;
        }
    }
};
struct term {
    string iD;
    string name;

    bool isEqual(term j) {
        if(this->iD == j.iD) {
             return true;
        }
        else {
            return false;
        }
    };
};

struct course {
    string iD;
    string instructor;
    int courseno;
    string sectionID;
    string termID;

    bool isEqual(course j) {
        if(this->courseno == j.courseno && this->iD == j.iD) {
            return true;
        }
        else {
            return false;
        }
    };
};
#endif
