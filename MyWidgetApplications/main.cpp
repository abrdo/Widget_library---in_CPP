#include "applications/widgettesterapp.hpp"
#include "applications/craftapp.hpp"

#include "applications/calculator.hpp"

using namespace std;
using namespace genv;


int main(){
    WidgetTesterApp myapp;
    myapp.run();
    Calculator mycalculator;
    mycalculator.run();

    return 0;
}

