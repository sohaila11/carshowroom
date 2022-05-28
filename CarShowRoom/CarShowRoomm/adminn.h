#include <string>
using namespace std;
class adminn
{
public :
	int ID_A;
	string username, password;

};
class customer {
public :
	int ID_C;
	//mo2kt
	string Username, Password, Buy, Rent, Repair;
};

class Showrooms {
public :

	int id;
	string name;
	string location;
	int phoneNumber;



	Showrooms();
	void addShowRooms();
	void updateShowRooms();
	void deleteShowRooms();
	void displayShowRooms();
	void searchShowRooms();

};

class Garages {
public:
	int id;
	string name;
	string location;
	int phonenumber;
	string services;


	Garages();
	void searchGarage();
	void addGarage();
	void updateGarage();
	void deleteGarage();
	void displayGarage();
	void bookGarage();

};

class Service {
public:
	int IDS;
	string NameS;
	float price;


	Service();
	void addService();
	void updateService();
	void deleteService();
	void displayService();
	void dis_Ser_Names();
	void searchService();

};
class ServiceProcess {
 public :

	 int processID_S;
	 int CustomerID;
	 string Date;
	 float Amountofmoney;
	 string chosenService;
	 ServiceProcess();
	 void displayhistory();
	 void getservice(int);

};
class BR_process {
public :

	int processID_BR;
	int CustomerID;
	string Date;
	float Amountofmoney;
	string ChosenCar;

	void buy_process(int);
	BR_process();

};
class Car {
public:


	float id;
	string make;
	float model;
	float year;
	float price;
	float installment;

	Car();
	void searchCar();
	void AddCar();
	void updateCarData();
	void deleteCar();
	void displayCar();


};

