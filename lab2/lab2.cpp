#include  <iostream>
#include <math.h>

using namespace std;
// enum class operation for each operation we need to perform
enum class Operation { Add= 1, Sub = 2 , Mult= 3, Div= 4,Sqrt= 5};
// struct calculator with a object of enum for the operations
struct Calculator {
    Operation op;
    // a constructor that accepts a Operation object to we know the operaiton to perform
    Calculator(Operation operation1) {
        op=operation1;
     }
     // method that will evaluate what we want and return the value needed
    int calc(int val1, int val2) {
        switch(op) {
            case Operation::Add: {
                return val1 + val2;
            } break;
            case Operation::Sub: {
                return val1-val2;
            } break;
            case Operation::Mult: {
                return val1 * val2;
            } break;
            case Operation::Div: {
                return val1 / val2;
            } break;
            default: {
                cout << "invalid operation detected\n";
                return 0;
            }

            }

        }
        // since it is only one input we have a seperate method for sqrt
       int sqr(int val1) {
          if(op == Operation::Sqrt) {
            return sqrt(val1);
        }
           return 0;
        }
    };
    int main() {
        int value1, value2;
        std::string operation;
        cout << "what type of operation would you like to do ( Add , Sub, Mult, Div, Sqrt)\n";
        cin >> operation;
        Operation op{};
        // checks to see what operation we are performing
        if(operation == "Add") {
             op=Operation::Add;
            cout << "Enter a integer.\n";
            cin >> value1;
            cout << "Enter another integer\n";
            cin >> value2;
            cout << "you chose to add so ";
            Calculator c(op);
            cout << "the answer is " << c.calc(value1, value2) << endl;
        }
        else if (operation == "Sub") {
            op=Operation::Sub;
            cout << "Enter a integer.\n";
            cin >> value1;
            cout << "Enter another integer\n";
            cin >> value2;
            cout << "you chose to subtract so ";
            Calculator c(op);
            cout << "the answer is " << c.calc(value1, value2) << endl;
        }
        else if (operation == "Mult") {
            op=Operation::Mult;
            cout << "Enter a integer.\n";
            cin >> value1;
            cout << "Enter another integer\n";
            cin >> value2;
            cout << "you chose to multiply so ";
            Calculator c(op);
            cout << "the answer is " << c.calc(value1, value2) << endl;
            
        }
        else if(operation == "Div") {
            op=Operation::Div;
            cout << "Enter a integer.\n";
            cin >> value1;
            cout << "Enter another integer\n";
            cin >> value2;
            cout << "you chose to divide so ";
            Calculator c(op);
            cout << "the answer is " << c.calc(value1, value2) << endl;
        }
         if(operation == "Sqrt") {
            op=Operation::Sqrt;
             cout << "Enter a integer.\n";
             cin >> value1;
            cout << "you chose to square root so ";
            Calculator c(op);
             cout << "the answer is " << c.sqr(value1) << endl;
          }
    
    }