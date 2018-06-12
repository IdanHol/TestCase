
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class TestCase {
    private :
    int passTest,failedTest,totalTest;
    string nameTest,msgTest;
    public :
      TestCase(string name,ostream &out):
         passTest(0),failedTest(0), totalTest(0),nameTest(name),msgTest(name +": Faild in test num "){}

        template <typename T> TestCase& check_equal (T first, T second) {
        totalTest++;
        if (first == second) {
            passTest++;
        } else {
            cout << msgTest << totalTest<<" check_equal " << ": " << first<<"  Not equal to  "  << second<< "!\n";
            failedTest++;
        }
        return *this;
        }
        template <typename T> TestCase& check_different (T first, T second) {
        totalTest++;
        if (first != second) {
            passTest++;
        } else {
            cout << msgTest << totalTest <<" check_different "<< ": " << first<<"  Equal to  "  << second<< "!\n";
            failedTest++;
        }
        return *this;
        }
        template <typename T,typename A,typename B> TestCase& check_function (T foo,A first, B second) {
        totalTest++;
        if (foo(first)== second) {
            passTest++;
        } else {
            cout << msgTest << totalTest <<" check_function " << ": " << first<<" Not  Equal to  "  << second<< "!\n";
            failedTest++;
        }
        return *this;
        }
                template <typename T> TestCase& check_output (const T first,const string other) {
        stringstream s;
        s<<first;
        totalTest++;
        if (s.str()== other) {
            passTest++;
        } else {
            cout << msgTest << totalTest  <<" check_output " << ": " << first<<" Not Equal to  "  << other<< "!\n";
            failedTest++;
        }
        return *this;
        }
        void print(){
            cout<<"Total of Test  for "<<nameTest<<"  is :  "<<totalTest<<endl<<
            "Num of Test pass :  "<<passTest<<endl<<
            "Num of Test failed:  "<<failedTest<<endl;
        }

};