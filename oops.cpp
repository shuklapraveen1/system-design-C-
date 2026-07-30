#include <iostream>
using namespace std;
class car {
    public:
    string model ="Tesla";
};
class engine: public car{
    bool is_engine_on;
    public:
    engine(bool e){
        is_engine_on = e;
    }
    void is_on(){
        if(is_engine_on)
        cout <<"Engine is running"<<endl;
        else 
        cout <<"Engine is off"<< endl;
    }
};
int main(){
    engine eng(true);
    cout << eng.model<<endl;
    eng.is_on();
}