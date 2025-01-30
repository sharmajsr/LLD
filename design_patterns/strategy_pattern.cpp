/******************************************************************************

Points to remember
1. use virtual keyword when creating a abstract class
2. a class containing a single abstract function will be considered as abstract class.
3. virtual void driveStrategy() = 0 ; dont miss the "()"and " = 0 " part
4. we have used "is a relationship' while inheriting from Drive Strategy and vehicle class
5. we have used "has a relationship " while using DriveStrategy *ds object in Vehicle class
6. we are then instantiating it using constructor
7. we have to call the driveStrategy function from the pointer of DriveStrategy class, hence we are using "->" to call the driveStrategy() method and not the "." operator.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
class DriveStrategy{
    public:
    virtual string driveStrategy() = 0 ;
};
class NormalDriveStrategy : public DriveStrategy{
    public: string driveStrategy(){
        return "Normal DriveStrategy\n";
    }
};
class AdvancedDriveStrategy: public DriveStrategy{
    public :
    string driveStrategy(){
         return "Advanced DriveStrategy\n";
    }
};
class Vehicle{
  string vno;  
  protected:
  DriveStrategy* ds;
  public:
  Vehicle(DriveStrategy* drive_strategy ){
    this->ds = drive_strategy;
  }
  virtual void drive() = 0 ;
};

class PassengerVehicle: public Vehicle{
    public:
    PassengerVehicle(DriveStrategy* drive_strategy):Vehicle(drive_strategy){}
    void drive(){
        cout<<this->ds->driveStrategy();
    }
};
class SportsVehicle : public Vehicle{
    public:
    SportsVehicle(DriveStrategy* drive_strategy):Vehicle(drive_strategy){}
    void drive(){
        cout<<this->ds->driveStrategy();
    }
};
class OffRoadVehicle: public Vehicle{
    public:
    OffRoadVehicle(DriveStrategy* drive_strategy):Vehicle(drive_strategy){}
    void drive(){
        cout<<this->ds->driveStrategy();
    }
};

int main()
{
    NormalDriveStrategy* ns = new NormalDriveStrategy();
    AdvancedDriveStrategy* as = new  AdvancedDriveStrategy();
    PassengerVehicle pv(ns);
    SportsVehicle sv(as);
    OffRoadVehicle ov(as);
    pv.drive();
    sv.drive();
    ov.drive();
    delete ns;
    delete as;
    return 0;
}
