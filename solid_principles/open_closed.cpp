#include <bits/stdc++.h>
using namespace std;


class invoicedao{

    // Which one to choose?
    //   ✅ If only derived classes should access data, use Option 1 (protected).
    //   ✅ If external code should also be able to access data, use Option 2 (getter function).


    protected:
    int data;
    
    public:
        invoicedao(int temp){
            this->data = temp;
        }
        virtual void savedata() = 0 ;
};
class saveToDB : public invoicedao{
    public:
    saveToDB(int temp) : invoicedao(temp){};
    void savedata(){
        cout<<"save to db : "<<this->data<<endl;
    }
};

class saveToFile : public invoicedao{
    public:
    saveToFile(int temp):invoicedao(temp){};
    void savedata(){
        cout<<"save to file : "<<this->data<<endl;
    }
};
int main()
{
    saveToDB inv_dao(5);
    inv_dao.savedata();

    return 0;
}
