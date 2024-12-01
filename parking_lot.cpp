#include<bits/stdc++.h>
using namespace std;

enum VehicleType{
	BIKE,
	CAR
};
class Vehicle{
	protected:
		string id;
	public:
		Vehicle(string id){
			this->id= id;
		}
		virtual int getPrice(int hours)=0;
		string getId(){
			return this->id;
		}
};
class Car: public Vehicle{
	public:
		Car(string id):Vehicle(id){}
		int getPrice(int hours){
			return hours*20;
		}
};
class Bike:public Vehicle{
	public:
		Bike(string id):Vehicle(id){}
		int getPrice(int hours){
			return hours*10;
		}
};
class ParkingLot{
	protected:	
		struct SpaceDetails{
			bool isOccupied = false;
			string allowedType;
			Vehicle* vehicle;
		};
		static unordered_map<int,SpaceDetails>parkingSpaces;
		int totalParkingSpace;
		int noOfAvailableParkingSpace;
		int floors;
	public:
		ParkingLot(){
			vector<vector<int>>parkingLot(1000,vector<int>(1000,false));
		}
		virtual int getNumberOfParkingSpace()=0;
		virtual void addParkingSpace(int number)=0;
		virtual void parkVehicle(Vehicle* vehicle)=0;
		virtual void unparkVehicle(int id)=0;
};
class TwoWheelerParkingLot: public ParkingLot{

	public:
		TwoWheelerParkingLot(){}
		int getNumberOfParkingSpace(){
			int freeParkingSpace = 0;
			for(int i=0;i<parkingSpaces.size();i++){
				if(ParkingLot::parkingSpaces[i].allowedType == "BIKE" and ParkingLot::parkingSpaces[i].isOccupied == false){
					++freeParkingSpace;
				}
			}
			return freeParkingSpace;
		}
		void addParkingSpace(int numberOfParkingSpace){
			int currentParkingSpaceSize = ParkingLot::parkingSpaces.size();
			for(int i=currentParkingSpaceSize;i<currentParkingSpaceSize+ numberOfParkingSpace;i++){
				SpaceDetails spaceDetails;
				spaceDetails.isOccupied = false;
				spaceDetails.allowedType = "BIKE";
				spaceDetails.vehicle = NULL;
				ParkingLot::parkingSpaces[i]=spaceDetails;
			}
			cout<<"New Parking Size : "<<ParkingLot::parkingSpaces.size()<<endl;
		}
		void parkVehicle(Vehicle* vehicle){
			bool parkingSpaceFound = false ;
			for(int i=0;i<ParkingLot::parkingSpaces.size();i++){
				if(ParkingLot::parkingSpaces[i].allowedType == "BIKE" and ParkingLot::parkingSpaces[i].isOccupied == false){
					parkingSpaceFound = true;
					ParkingLot::parkingSpaces[i].isOccupied = true;
					ParkingLot::parkingSpaces[i].vehicle = vehicle;
					cout<<"Vehicle "<<vehicle->getId()<<" parked at parking spot "<<i<<endl;
					break;
				}
			}
			if(!parkingSpaceFound){
				cout<<"Parking Full\n";
			}
		}
		void unparkVehicle(int id){
			Vehicle* vehicle = ParkingLot::parkingSpaces[id].vehicle;
			cout<<"Price is " <<vehicle->getPrice(1)<<endl;
			cout<<"going to unpark vehicle with vehcle id : "<<ParkingLot::parkingSpaces[id].vehicle->getId()<<endl;
			ParkingLot::parkingSpaces[id].isOccupied = false;
			ParkingLot::parkingSpaces[id].vehicle = NULL;
		}
};
class FourWheelerParkingLot: public ParkingLot{
	public:
		FourWheelerParkingLot(){};
		int getNumberOfParkingSpace(){
			int freeParkingSpace = 0;
			for(int i=0;i<ParkingLot::parkingSpaces.size();i++){
				if(ParkingLot::parkingSpaces[i].allowedType == "CAR" and ParkingLot::parkingSpaces[i].isOccupied == false){
					++freeParkingSpace;
				}
			}
			return freeParkingSpace;
		}
		void addParkingSpace(int numberOfParkingSpace){
			int currentParkingSpaceSize = ParkingLot::parkingSpaces.size();
			for(int i=currentParkingSpaceSize;i<currentParkingSpaceSize+ numberOfParkingSpace;i++){
				SpaceDetails spaceDetails;
				spaceDetails.isOccupied = false;
				spaceDetails.allowedType = "CAR";
				spaceDetails.vehicle = NULL;
				ParkingLot::parkingSpaces[i]=spaceDetails;
			}
			cout<<"New Parking Size : "<<ParkingLot::parkingSpaces.size()<<endl;
		}
		void parkVehicle(Vehicle* vehicle){
			bool parkingSpaceFound = false ;
			for(int i=0;i<parkingSpaces.size();i++){
				if(ParkingLot::parkingSpaces[i].allowedType == "CAR" and ParkingLot::parkingSpaces[i].isOccupied == false){
					parkingSpaceFound = true;
					ParkingLot::parkingSpaces[i].isOccupied = true;
					ParkingLot::parkingSpaces[i].vehicle = vehicle;
					cout<<"Vehicle "<<vehicle->getId()<<" parked at parking spot "<<i<<endl;
					break;
				}
			}
			if(!parkingSpaceFound){
				cout<<"Parking Full\n";
			}
		}
		void unparkVehicle(int id){

			Vehicle* vehicle = ParkingLot::parkingSpaces[id].vehicle;
			cout<<"Price is " <<vehicle->getPrice(1)<<endl;
			cout<<"going to unpark vehicle with vehcle id : "<<parkingSpaces[id].vehicle->getId()<<endl;
			ParkingLot::parkingSpaces[id].isOccupied = false;
			ParkingLot::parkingSpaces[id].vehicle = NULL;
		}

};
class ParkingLotManager{
	private:
		unordered_map<string,ParkingLot*>parkingLots;
	public:
		void addParkingLot(string type,ParkingLot* parkingLot){
			this->parkingLots[type]=parkingLot;
			// cout<<this->parkingLots.size()<<endl;
		}
		void getNumberOfParkingSpace(string type){
			if(this->parkingLots.find(type)!=parkingLots.end()){
				ParkingLot* parkingLot = this->parkingLots[type];
				cout<<"FREE parking space for "<<type<<" is "<<parkingLot->getNumberOfParkingSpace()<<endl;
			}else{
				cout<<"Parking Lot not found";
			}
		}
		// void getNumberOfParkingSpace(string type){
		// 	if(parkingLots.find(type)!=parkingLots.end()){
		// 		parkingLots[type]->getNumberOfParkingSpace();
		// 	}else{
		// 		cout<<"Parking Lot not found";
		// 	}
		// }
		void addParkingSpace(string type,int numberOfParkingSpaceToBeAdded){
			if(parkingLots.find(type)!=parkingLots.end()){
				parkingLots[type]->addParkingSpace(numberOfParkingSpaceToBeAdded);
			}else{
				cout<<"Added Parking Space";
			}
		}
		void parkVehicle(string type,Vehicle* vehicle){
			if(parkingLots.find(type)!=parkingLots.end()){
				parkingLots[type]->parkVehicle(vehicle);
			}else{
				cout<<"Parked "<<vehicle->getId();
			}
		}
		void unparkVehicle(string type,int id){
			if(parkingLots.find(type)!=parkingLots.end()){
				parkingLots[type]->unparkVehicle(id);
			}else{
				cout<<"UnParked vehicle"<<id;
			}
		}
		
};
unordered_map<int,ParkingLot::SpaceDetails>ParkingLot::parkingSpaces;
int main()
{
	cout<<"Welcome to Parking Lot\n";
	ParkingLotManager parkingLotManager;
    TwoWheelerParkingLot* twoWheelerParkingLot = new TwoWheelerParkingLot();
    FourWheelerParkingLot* fourWheelerParkingLot = new FourWheelerParkingLot();
    parkingLotManager.addParkingLot("BIKE",twoWheelerParkingLot);
    parkingLotManager.addParkingLot("CAR",fourWheelerParkingLot);
    parkingLotManager.getNumberOfParkingSpace("BIKE");
    parkingLotManager.addParkingSpace("BIKE",2);
    parkingLotManager.getNumberOfParkingSpace("BIKE");
    
	Bike b1("KA01");
	parkingLotManager.parkVehicle("BIKE",&b1);
	parkingLotManager.getNumberOfParkingSpace("BIKE");
	parkingLotManager.parkVehicle("BIKE",&b1);
	parkingLotManager.getNumberOfParkingSpace("BIKE");
	parkingLotManager.parkVehicle("BIKE",&b1);
	parkingLotManager.getNumberOfParkingSpace("BIKE");

	parkingLotManager.getNumberOfParkingSpace("CAR");
 	parkingLotManager.addParkingSpace("CAR",2);
    parkingLotManager.getNumberOfParkingSpace("CAR");
    Car c1("KA51");
    parkingLotManager.parkVehicle("CAR",&c1);
	parkingLotManager.getNumberOfParkingSpace("CAR");
	parkingLotManager.parkVehicle("CAR",&c1);
	parkingLotManager.getNumberOfParkingSpace("CAR");

}
// }
