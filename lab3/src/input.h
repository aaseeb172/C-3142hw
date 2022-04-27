#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "struct.h"
#include "func.h"

#ifndef INPUT_HEADER
#define INPUT_HEADER


vector<entry> inputEntry(vector<string> files) {
    vector<entry> vect;

    for(auto file : files) {
    string iD, courseno, instructorID, termID, sectionID, grade; 
    ifstream i;
    i.open(file);



    if(!i.fail()) {
        string line;
        getline(i, line);

        while(!i.eof()) {
            entry entry;

            getline(i, iD, ',');
            entry.emplid = iD;

            getline(i, courseno, ',');
            int newcourseno = stoi(courseno);
            entry.courseno = newcourseno;

            getline(i, instructorID, ',');
            entry.instructorID = instructorID;

            getline(i, termID, ',');
            entry.termID = termID;

            getline(i, sectionID, ',');
            entry.sectionID = sectionID;

            getline(i, grade);
            entry.grade = grade;

            vect.push_back(entry);
            
            
        };

      vect.pop_back();


       
    }
    }


    return vect;

}
#endif