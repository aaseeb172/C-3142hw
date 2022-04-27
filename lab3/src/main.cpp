#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "struct.h"
#include "func.h"
#include "input.h"

int main() {
    string t;
    vector<string> files = {"/lab3/data/1115.csv", "/lab3/data/3115.csv", "/lab3/data/3130.csv"};
    vector<entry> ent = inputEntry(files);

    cout << "what term would you like to get info on?" << endl;
    cin >> t;
    if(!fallTerm(t)) {
      findPassRateSpring(ent, t);
    }
    else {
      findPassRateFall(ent, t);
    }


    
   for (auto i : ent) {
             cout << i.emplid << endl;
      }
        cout << endl;
  

}



