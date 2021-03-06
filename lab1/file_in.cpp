// This file shows basic functions of reading in a CSV file using C++98
//Aseeb Ahmad

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std; 

int main() {

  // define variables
  ofstream output;
  output.open("output.txt");
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;
  vector<int> sku2020, sku2000, sku2010; // vectors to hold the SKUS
  float avgpriceofABC=0; // place holder for avg price 
  float avgpriceofXYZ=0; // place holder for avg price
  int countABC=0; // count for abc
  int countXYZ=0; // count for XYZ
  int countA, countB,countC =0;
  float avgpriceofA, avgpriceofB, avgpriceofC= 0.0;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  if (!in_stream.fail()) { //if the file is open

    string line;

    while (getline(in_stream,line)) { //while the end of file is NOT reached
        stringstream in_stream(line); // fixes the input issue
    
        // Fields: sku,brand,category,year,price
     getline(in_stream, sku, ',');
     stringstream ssku(sku); 
     int iSKU = 1;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(in_stream, brand, ',');
     stringstream sbrand(brand);
     vBrand.push_back(brand);

     getline(in_stream, category, ',');
     stringstream pcategory(category);
     vCategory.push_back(category);

     getline(in_stream, year, ','); 
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(in_stream, price, '\n'); 
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;
  }

     else {
    cout << "Unable to open file"; 
   }
 
  //output values 
  output << "SKU " << " " << " Brand " << " " << " Category " << " " << "Year " << "\t" << "Price" << endl; 

  for (int j = 1; j < vSKU.size(); j++) {
    output << vSKU[j] << "   " << vBrand[j] << " \t \t" << vCategory[j] << " \t \t " << vYear[j] << " \t " << vPrice[j] << endl;
  }
  // loop for getting price of XYZ and also increments counter
  for(int i=0; i < vBrand.size(); i++) { 
    if(vBrand[i] == "XYZ") {
      avgpriceofXYZ += vPrice[i];
      countXYZ++;

    }
    // if statement for finding xyz and finding the avg price
    if (vBrand[i] == "ABC") {
      avgpriceofABC += vPrice[i];
      countABC++;

    }
    // if statement to find abc and finding the avg price of it 
  }
    for(int j=0; j < vCategory.size(); j++) {
      if (vCategory[j] == "A") {
        avgpriceofA +=vPrice[j];
        countA++;

      }
      // if it sees A we add the price that matches with it and increment counter
      if (vCategory[j] == "B") {
        avgpriceofB += vPrice[j];
        countB++;
      }
      // if it sees a B add price and increment
      if(vCategory[j] == "C") {
        avgpriceofC += vPrice[j];
        countC++;
      }
      // if it sees a C add price and increment 

    }
    //output << "2020 " <<sku2020.size() << " ";
    for(int i=0; i<vSKU.size(); i++) {
      if(vYear[i] == 2020) {
        sku2020.push_back(vSKU[i]);
        
      }
      // we see the year 2020 we push the sku into the vecotr
    }
     output << "2020 " << "(" << sku2020.size() << ")" << " ";
    for(int i=0; i<sku2020.size(); i++) {
      output << sku2020[i] << ", ";
    }
    // prints out 2020 with the size of the vector and SKUS
    output << endl;

    for(int i=0; i<vSKU.size(); i++) {
      if(vYear[i] == 2010) {
        sku2010.push_back(vSKU[i]);
        
      }
      // if it sees 2010 we add the SKU into the vector
    }
     output << "2010 " << "(" << sku2010.size() << ")" << " ";
    for(int i=0; i<sku2010.size(); i++) {
      output << sku2010[i] << ", ";
    }
    // outputs into the file the year, values of sku and sizr of vector
    output << endl;
     for(int i=0; i<vSKU.size(); i++) {
      if(vYear[i] == 2000) {
        sku2000.push_back(vSKU[i]);
        
      }
      // if it sees 2000 we add to the vector
    }
     output << "2000 " << "(" << sku2000.size() << ")" << " ";
    for(int i=0; i<sku2000.size(); i++) {
      output << sku2000[i] << ", ";
    }
    //outputs to file the year, values and vector size
    output << endl;

  
    
    // output << "2020 " << sku2020.size() << endl;
    //output to file for averages of price for brand and category
  output << "\n" << "Average price per brand for ABC is " << avgpriceofABC/countABC << endl;

  output << "\n" << "Average price per brand for XYZ is " << avgpriceofXYZ/countXYZ << endl;

  output << "\n" << "Average price per category for A is " << avgpriceofA/countA << endl;

  output << "\n" << "Average price per category for B is " << avgpriceofB/countB << endl;

  output << "\n" << "Average price per category for D is " << avgpriceofC/countC << endl; 

  output << endl;

}