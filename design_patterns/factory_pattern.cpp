/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Shape{
    public: virtual void draw()=0;
};
class Rectangle: public Shape{
    public : void draw(){
        cout<<"Rectangle called";
    }
};
class Circle: public Shape{
    public : void draw(){
        cout<<"Circle called";
    }
};
class ShapeFactory{
    public : 
    Shape* getShape(int shapeName){
        switch(shapeName){
            case 1:  return new Rectangle();  break;
            case 2: return new Circle(); break;
            default: return nullptr; break;
        }
    }
};
int main()
{
    cout<<"Hello World\n";
    // Shape *shapeObject = new Rectangle();
    // shapeObject->draw();
    
    ShapeFactory* shapeFactory = new ShapeFactory();
    Shape* shapeObject = shapeFactory->getShape(2);
    shapeObject->draw();
    
    return 0;
}
