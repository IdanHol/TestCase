
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
         passTest(0),failedTest(0), totalTest(0),nameTest(name),msgTest(name +": Failure in test #"){}

        template <typename T> TestCase& check_equal (T first, T second) {
        totalTest++;
        if (first == second) {
            passTest++;
        } else {
            cout << msgTest << totalTest << ": " << first<<" should equal "  << second<< "!\n";
            failedTest++;
        }
        return *this;
        }
        template <typename T> TestCase& check_different (T first, T second) {
        totalTest++;
        if (first != second) {
            passTest++;
        } else {
            cout << msgTest << totalTest << ": " << first<<" should not equal "  << second<< "!\n";
            failedTest++;
        }
        return *this;
        }
        template <typename T,typename A,typename B> TestCase& check_function (T foo,A first, B second) {
        totalTest++;
        if (foo(first)== second) {
            passTest++;
        } else {
            cout << msgTest << totalTest<<":"<<" Function should return " << second<<"  but returned "  << foo(first)<< "!\n";
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
            cout << msgTest << totalTest<<":"  <<" string value should be "<< other<<" but is "  << s.str()<< "!\n";
            failedTest++;
        }
        return *this;
        }
        void print(){
            cout<<failedTest<<" failed, "<<passTest<<" passed "<<totalTest<<" total."<<endl<<"---"<<endl;
        }

};