#include "basicbuttonapp.hpp"

BasicButtonApp::BasicButtonApp(int XX, int YY) : Application(XX, YY){
    //ctor
}
BasicButtonApp::~BasicButtonApp(){
    for(auto w : _widgets)
        delete w;
}
