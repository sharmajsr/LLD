// splitwise app
// can add users
// can edit users
// can add Expense
// can edit Expense
// expense can be split into 3 type ( equal exact percent ) 
// enhancement : how to maintain balance for each user ? like how much each owe to other ? use a map<int,map<int,double>>debtMatrix; where debtMatrix[x][y] tells how much x has to be pay/collect from y.
#include<bits/stdc++.h>
using namespace std;
enum class SplitType{
    EXACT,
    EQUAL,
    PERCENT
};
class User{
    string name;
    int id;
    public: 
    User(){};
        User(string name,int id){
            this->name = name;
            this->id = id;
        }
        int getId(){
            return id;
        }
    
};
class Split{
    
    User user;
    double amount;
    public: 
    Split(User user,double amount){
        this->user = user;
        this->amount = amount;
    }
    double getAmount(){
        return amount;
    }
    void setAmount(double new_amount){
        amount = new_amount;
    }
    User getUser(){
        return user;
    }
    
};
class EqualSplit : public Split{
    public:
        EqualSplit(User user, double amount):Split(user,amount){}
};
class ExactSplit : public Split{
    public:
        ExactSplit(User user, double amount):Split(user,amount){}
};
class PercentSplit : public Split{
    public:
        PercentSplit(User user, double amount):Split(user,amount){}
};

class Expense{
  int id;
  double total_amount;
  User paid_by;
  SplitType split_type;
  vector<Split*>splits;
  public:
    Expense(int id,double total_amount,User paid_by,vector<Split*>splits): id(id),total_amount(total_amount),paid_by(paid_by),split_type(split_type),splits(splits){}
    
};
class ExpenseManager{
  vector<User>users;
  unordered_map<int,double>netBalance;
  vector<Expense*> expenses;
  public:
    void addUser(User user){
        users.push_back(user);
        netBalance[user.getId()]=0.0;
    }
    void showBalance(){
        cout << "\n--- Net Balances ---\n";
        for(auto user_balance : netBalance){
            cout<<"userID : " <<user_balance.first<<" "<<user_balance.second<<endl;
        }
        cout << "--------------------\n";
    }
    
    void addExpense(int id,double totalAmount, User paidBy, vector<User>owes,SplitType split_type,vector<int>values){
        vector<Split*>localSplit;
        switch(split_type){
            case SplitType::EQUAL: {
                int equalShare = totalAmount/owes.size();
                for(auto user : owes){
                    EqualSplit* equalSplit = new EqualSplit(user,equalShare);
                    localSplit.push_back(equalSplit);
                }
                break;
            }
            
            case SplitType::EXACT: {
                for(int i=0;i<owes.size();i++){
                    ExactSplit* exactSplit = new ExactSplit(owes[i],values[i]);
                    localSplit.push_back(exactSplit);
                }
                break;
            }
            
            case SplitType::PERCENT:{
                for(int i=0;i<owes.size();i++){
                    int percentSplitValue = values[i] * 0.01 * totalAmount;
                    PercentSplit* percentSplit = new PercentSplit(owes[i],percentSplitValue);
                    localSplit.push_back(percentSplit);
                }
                break;
            }
        }
        Expense* expense = new Expense(id,totalAmount,paidBy,localSplit);
        expenses.push_back(expense);
        netBalance[paidBy.getId()]+= totalAmount;
        for(auto spl : localSplit){
            netBalance[spl->getUser().getId()]-=spl->getAmount();
        }
    }
  
  
    
};
int main(){
    
    User u1("shubham",1);
    User u2("surya",2);
    User u3("saket",3);
    User u4("surbhi",4);
    
    ExpenseManager em;
    em.addUser(u1);
    em.addUser(u2);
    em.addUser(u3);
    
    // em.addExpense(
    //     101,
    //     90,
    //     u1,
    //     {u1,u3},
    //     SplitType::EQUAL,
    //     {}
    //     );
    // em.showBalance();
    
    em.addExpense(
        101,
        90,
        u1,
        {u1,u2,u3},
        SplitType::PERCENT,
        {33,33,34}
        );
    em.showBalance();
    
    // em.addExpense(
    //     101,
    //     90,
    //     u1,
    //     {u1,u2,u3},
    //     SplitType::EXACT,
    //     {40,20,30}
    //     );
    // em.showBalance();
    
    // vector<User>groupAUsers;
    // vector<User>groupBUsers;
    // groupAUsers.push_back(u1);
    // groupAUsers.push_back(u2);
    // groupAUsers.push_back(u3);
    // groupBUsers.push_back(u1);
    // groupBUsers.push_back(u2);
    // groupBUsers.push_back(u4);
    
    
    return 0;
}
