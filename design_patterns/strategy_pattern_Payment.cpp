#include <bits/stdc++.h>
using namespace std;
class PaymentStrategy{
    public:
        virtual void pay(int amount) = 0;
};
class CCStrategy : public PaymentStrategy{
    public:
        void pay(int amount){
            cout<<"Amount " << amount<<" paid by CC CCStrategy\n";
        }
};
class UPIStrategy : public PaymentStrategy{
    public:
        void pay(int amount){
            cout<<"Amount "<<amount<<" paid by upi \n";
        }
};
class PaymentContext{
    PaymentStrategy* paymentStrategy;
    public:
        PaymentContext(PaymentStrategy* strategy){
            paymentStrategy = strategy;
        }
        void setStrategy(PaymentStrategy* strategy){
            paymentStrategy = strategy;
            
        }
        void makePayment(int amt){
            paymentStrategy->pay(amt);
        }
};
int main()
{
    // printf("Hello World");
    UPIStrategy* upi = new UPIStrategy();
    CCStrategy* cc =  new CCStrategy();
    PaymentContext pc(cc);
    pc.makePayment(300);
    return 0;
}
