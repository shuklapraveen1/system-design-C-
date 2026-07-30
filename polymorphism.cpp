#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void draw() {
        cout <<"Shape"<< endl;
    }
};
class Circle: public Shape{
    public:
    void draw() override{
        cout<< "circle"<< endl;
    }
};
class Rectangle : public Shape{
    public:
    void draw() override{
        cout << "Rectangel"<<endl;
    }
};
int main(){
    Rectangle* rect=new Rectangle();
    Circle* cir=new Circle();
    Shape* shap = new Shape();


    
}
