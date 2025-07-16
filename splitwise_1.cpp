/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <bits/stdc++.h>
using namespace std;
class User{
    public:
    string name;
    int age;
    
};


class Group{
    private:
    string groupName;
    vector<User>users;
        unordered_map<string, int>balances;
    public: 
        
        unordered_map<string, int> getBalances(){
            return this->balances;
        }
        void setExpense(string user, int amount){
            this->balances[user] += amount;
        }
        void showBalances(){
            cout<<"Printing balances : \n";
            for(auto user_balance : balances){
                if(user_balance.second > 0 ){
                    cout<<user_balance.first<<" ko aayga "<<user_balance.second<<endl;
                }else if(user_balance.second == 0 ){
                    cout<<user_balance.first<<" owes nothing "<<endl;
                }else{
                    cout<<user_balance.first<<" ko dena h "<<user_balance.second<<endl;
                }
            }
        }
};
class Expense{
    public:
        string name;
        int amount;
        string paid_by;
        Expense(string Name, int amt,string paidBy): name(Name), amount(amt) , paid_by(paidBy){}
            
};

class Split{
  public: virtual void calculateSplit(Expense , Group* , User );  
};

class ExactSplit{
    unordered_map<string,int>exact_splits;
    public: 
    ExactSplit( unordered_map<string,int> splits): exact_splits(splits){};
    void calculateSplit(Expense expense, Group* g , string paid_by) {
        unordered_map<string, int> balances = g->getBalances();
        int total = 0 ;
        for(auto user : exact_splits ){
            
            string u = user.first;
            int amount = user.second;
            g->setExpense(u,amount);
        }
    } 
};

class EqualSplit{
    
    vector<string>participants;
    
    public:
    EqualSplit( vector<string> users):participants(users){};
    
    void calculateSplit(Expense expense, Group* g, string paid_by  ) {
        unordered_map<string, int>balances = g->getBalances();
        int total_participants = participants.size() + 1 ;
        int eachPersonAmount = expense.amount/(total_participants);
        int total = 0 ;
        for(auto user1 : participants){
            g->setExpense(user1,eachPersonAmount);
            total += eachPersonAmount;
        }
        g->setExpense(paid_by,total);
        
    } 
};

int main()
{
    cout<<"Welcome to splitwise\n";
    Group* goa_trip = new Group();
    goa_trip->showBalances();
    Expense e1("food",500,"shubham");
    vector<string>participants;
    
    participants.push_back("Surya");
    participants.push_back("Saket");
    
    EqualSplit esplit(participants);
    esplit.calculateSplit(e1,goa_trip,"shubham");
    goa_trip->showBalances();
    unordered_map<string,int>exact_split;
    
    exact_split["shubham"]=200;
    exact_split["surya"]=-100;
    exact_split["saket"]=-100;
    
    ExactSplit exactSplit(exact_split);
    exactSplit.calculateSplit(e1,goa_trip,"shubham");
    goa_trip->showBalances();
    
    return 0;
}
