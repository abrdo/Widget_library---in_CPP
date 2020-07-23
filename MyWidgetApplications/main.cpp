#include "applications/calculator.hpp"
#include "applications/accountingapp.hpp"
#include "applications/widgettesterapp.hpp"

#include "applications/puttingapp.hpp"
#include <iostream>

using namespace std;
using namespace dowi;


int main(){
    AccountingApp myapp2;
    myapp2.run();
    PuttingApp myapp;
    myapp.run();

    WidgetTesterApp myapp0;
    myapp0.run();
    Calculator myapp1;
    myapp1.run();

    return 0;
}

