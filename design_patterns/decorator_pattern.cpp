/******************************************************************************

Points to remember
1. since ToppingsDecorator class is not implementing the findCost method, it has become a abstract class
2. we can give the implementation of ToppingsDecorator class like , but it will be redundant and not be using it
    int findCost(){
        return this->basePizza()->findCost();
    }
3. Leaving it unimplemented allows ToppingsDecorator to remain an abstract class, enforcing that all derived classes must provide a findCost() implementation.
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class BasePizza{
    public:
        virtual int findCost() = 0; 
};
class MargheritaPizza: public BasePizza{
    public:
        int findCost(){
            return 10;
        }

};
class FarmhousePizza: public BasePizza{
    public:
        int findCost(){
            return 20;
        }

};

class ToppingsDecorator : public BasePizza{};
class ExtraCheeseToping: public ToppingsDecorator{
    BasePizza *basePizza;
    public:
    ExtraCheeseToping(BasePizza *basePizza){
      this->basePizza = basePizza;
    }
    int findCost(){
        return this->basePizza->findCost() + 1;
    }
    
};
class MushroomToping: public ToppingsDecorator{
    BasePizza *basePizza;
    public:
    MushroomToping(BasePizza *basePizza){
      this->basePizza = basePizza;
    }
    int findCost(){
        return this->basePizza->findCost() + 2;
    }
    
};
class OnionTopping: public ToppingsDecorator {
    BasePizza *basePizza;
    public:
    OnionTopping(BasePizza *basePizza){
      this->basePizza = basePizza;
    }
    int findCost(){
        return this->basePizza->findCost() + 3;
    }
    
};
int main()
{
    ExtraCheeseToping* mar = new ExtraCheeseToping(new MushroomToping(new OnionTopping(new MargheritaPizza())));
    cout<<mar->findCost();
    return 0;
}
