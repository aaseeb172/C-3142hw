#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "struct.h"

#ifndef FUNC_HEADER
#define FUNC_HEADER

bool fallTerm (string termID) {
    vector<string> fall= {"T04", "T08", "T12", "T16", "T20", "T23"}; 
    for(auto j : fall) {
        if(termID == j) {
            return true;
        }
    }
    return false;
}

bool springTerm(string termID) {
    vector<string> spring = {"T02", "T06", "T10", "T14", "T18", "T21"};
    for(auto j : spring) {
        if(termID == j) {
            return true;
        }
    }
    return false;
}
bool failCheck(string grade) {
    if(grade.compare("F")== 0) {
        return true;
    }
    else {
        return false;
    }
}

bool checkForW(string grade) {
    if(grade.compare("W") == 0) {
        return true;
    }
    else {
        return false;
    }
}


void findPassRateSpring(vector<entry> e, string t) {
    int count = 0;
    int rate = 0;
    int p = 0;
     for(auto i : e) {
         if(i.courseno == stoi(t) == 0 && springTerm(i.termID)) {
                count++;
             if(!failCheck(i.grade)) {
                 p++;
                 

             }

         }
     }
     rate = p / count * 100;
     printf("the pass rate by spring is  %d", rate);

}

void findPassRateFall(vector<entry> e, string t) {
    int count = 0;
    int rate = 0;
    int p = 0;
     for(auto i : e) {
         if(i.courseno == stoi(t) && !springTerm(i.termID)) {
                count++;
             if(!failCheck(i.grade)) {
                 p++;
                 

             }

         }
     }
     rate = p / count * 100;
     printf("the pass rate by fall is  %d", rate);

}


#endif