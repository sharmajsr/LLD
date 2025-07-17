/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class Observer{
    public:
    virtual void notify(string ) = 0 ;  
};
class Observable{
    vector<Observer*>observers;
    public:
        void add(Observer* obs){
            this->observers.push_back(obs);
        }
        void notifyObservers(string message){
            for(auto obs : observers){
                obs->notify(message);
            }
        }
};
class Book : public Observable {
    int state = 0;
    public:
        void changeState(int newState){
            if( state == 0 and newState >1 ){
                state = newState;
                notifyObservers("book available ");
            }
            else if(state > 0 and newState == 0 ){
                state = newState;
                notifyObservers("book unavailable ");
            }else{
                state = newState;
            }
        }
};
class ConcreteObserver : public Observer{
  
    public:
        void notify(string message){
            cout<<"New message : " <<message<<endl;
        }
};
int main(){
   
    ConcreteObserver* c1 = new ConcreteObserver();
    ConcreteObserver* c2 = new ConcreteObserver();
    ConcreteObserver* c3 = new ConcreteObserver();
    
    Book* book = new Book();
    book->add(c1);
    book->add(c2);
    book->add(c3);
    
    book->changeState(2);
    book->changeState(1);
    book->changeState(0);
    
    
    return 0;
}
