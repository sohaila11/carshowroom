#include <iostream>
#include "adminn.h"
#include <vector>
#include "assert.h"
#include <fstream>
#include <string>
#include<sstream>
#include<iomanip>
#include <ctime>

using namespace std;
vector <Car> cc;
Car c;

Car::Car() {
	id = 0;
	model = 0;
	year = 0;
	price = 0;
	installment = 0;
}

void Car::searchCar()
{
	ifstream car("cars.txt");
	string MA;
	float I, MO, Y, P, IN;
	
	if (car.is_open()) {
		
			while (car >> I >> MA >> MO >> Y >> P >> IN) {
				c.id = I;
				c.make = MA;
				c.model = MO;
				c.year = Y;
				c.price = P;
				c.installment = IN;
				cc.push_back(c);
			}
	}
	else {
		cout << "file not opened" << endl;
	}
	
	bool found = false;
	string temp_make;
	std::cout << "Enter the name of the car " << endl;
	cin >> temp_make;
	for (int i = 0; i < cc.size(); i++) {
		if (cc[i].make == temp_make) {
			found = true;
			std::cout << "Id of the car" << " " << cc[i].id << endl;
			std::cout << "Model of the car" << " " << cc[i].model << endl;
			std::cout << "Price of the car " << " " << cc[i].price<< endl;
			std::cout << "Installment of the car" << " " << cc[i].installment << endl;
			cout << "\t \t \t \t ----------\t \t \t \t" << endl;
			//std::cout << " the size of array = " << cc.size() << endl;
		}
		
		
	}
	if (found) {
		cout << "Done" << endl;
		cc.clear();
	}
	else {
		cout << "data not found" << endl;
		cc.clear();
	}
	
	car.close();
};
	



void Car::AddCar()
{
	ifstream car("cars.txt");
	fstream CARS("cars.txt",ios::app);
	
	//static int count=0;
	bool found = false;
	string MA;
	float I, MO, Y, P, IN;
	if (car.is_open()) {

		while (car >> I >> MA >> MO >> Y >> P >> IN) {
			c.id = I;
			c.make = MA;
			c.model = MO;
			c.year = Y;
			c.price = P;
			c.installment = IN;
			cc.push_back(c);
			
		}

	}
	else {
		cout << "file not opened" << endl;
	}
	std::cout << "Enter Id of the car" << endl;
	cin >> c.id;
	
	for (int i = 0; i < cc.size(); i++) {
		if (cc[i].id == c.id) {
			found = true;
		}
	}if (found) {
		cout << " id already used , please change your id " << endl;
		cin >> c.id;
	}
	std::cout << "Enter Make of the car" << endl;
	cin >> c.make;
	std::cout << "Enter Model of the car" << endl;
	cin >> c.model;
	std::cout << "Enter year of the car" << endl;
	cin >> c.year;
	std::cout << "Enter price of the car" << endl;
	cin >> c.price;
	std::cout << "Enter installment of the car" << endl;
	cin >> c.installment;
	cout << "done" << endl;
	cc.push_back(c);

	ofstream cars("cars.txt");
	for (int i = 0; i < cc.size(); i++) {

		CARS << cc[i].id << endl;
		CARS << cc[i].make << endl;
		CARS << cc[i].model << endl;
		CARS << cc[i].year << endl;
		CARS << cc[i].installment << endl;
		CARS << cc[i].price << endl;
	}
	car.close();
	CARS.close();
	cc.clear();
};

void Car::updateCarData() {

	ifstream car("cars.txt");
	fstream CARS("cars.txt", ios::app);
	string MA;
	float I, MO, Y, P, IN;
	if (car.is_open()) {

		while (car >> I >> MA >> MO >> Y >> P >> IN) {
			c.id = I;
			c.make = MA;
			c.model = MO;
			c.year = Y;
			c.price = P;
			c.installment = IN;
			cc.push_back(c);
		}

	}
	else {
		cout << "file not opened" << endl;
	}


	int idC;
	bool found = false;

	assert(!cc.empty());

	cout << "Enter your car Id " << endl;
	//cout << " the size of array = " << cc.size() << endl;
	cin >> idC;

	for (int i = 0; i < cc.size(); i++) {
		if (cc[i].id == idC) {
			found = true;
			cout << "Data found " << endl;
			cout << "please update your data" << endl;
			cout << "Enter Id of the car" << endl;
			cin >> c.id;
			cout << "Enter Make of the car" << endl;
			cin >> c.make;
			cout << "Enter Model of the car" << endl;
			cin >> c.model;
			cout << "Enter year of the car" << endl;
			cin >> c.year;
			cout << "Enter price of the car" << endl;
			cin >> c.price;
			cout << "Enter installment of the car" << endl;
			cin >> c.installment;
			cout << "update done";
			cc[i] = c;
			ofstream car("cars.txt");
			for (int i = 0; i < cc.size(); i++) {

				CARS << cc[i].id << endl;
				CARS << cc[i].make << endl;
				CARS << cc[i].model << endl;
				CARS << cc[i].year << endl;
				CARS << cc[i].installment << endl;
				CARS << cc[i].price << endl;
			}
			
		}
	}
	if (found) {
		cout << "Done" << endl;
		
		cc.clear();
	}
	else {
		cout << "data not found" << endl;
		cc.clear();
	}
	car.close();
	CARS.close();
};

void Car::deleteCar() {

	ifstream car("cars.txt");
	fstream CARS("cars.txt", ios::app);
	string MA;
	float I, MO, Y, P, IN;
	
	if (car.is_open()) {

		while (car >> I >> MA >> MO >> Y >> P >> IN) {
			c.id = I;
			c.make = MA;
			c.model = MO;
			c.year = Y;
			c.price = P;
			c.installment = IN;
			cc.push_back(c);
			
			
		}

	}
	else {
		cout << "file not opened" << endl;
	}


	int idC;
	bool found = false;
	assert(!cc.empty());

	cout << "Enter your car Id " << endl;
	//cout << " the size of array = " << cc.size() << endl;
	cin >> idC;

	for (int i = 0; i < cc.size() ; i++) {
		if (cc[i].id == idC) {
			cc.erase(cc.begin() + i);
			found = true;
			
		}
	}
	if (found){
		ofstream car("cars.txt");
		cout << "Data deleted" << endl;
		for (int i = 0; i < cc.size(); i++) {

			CARS << cc[i].id << endl;
			CARS << cc[i].make << endl;
			CARS << cc[i].model << endl;
			CARS << cc[i].year << endl;
			CARS << cc[i].installment << endl;
			CARS << cc[i].price << endl;
		}
		
	}
	else {
		cout << "Data not found" << endl;
	}


	cc.clear();
	car.close();
	CARS.close();
};
void Car::displayCar()
{
	ifstream car("cars.txt");
	string MA;
	float I, MO, Y, P, IN;
	string line;
	if (car.is_open()) {

		while (car >> I >> MA >> MO >> Y >> P >> IN) {
			c.id = I;
			c.make = MA;
			c.model = MO;
			c.year = Y;
			c.price = P;
			c.installment = IN;
			cc.push_back(c);

		}
	}
	assert(!cc.empty());
	for (int i = 0; i < cc.size(); i++) {
		cout << "data of car " << i + 1 << endl;
		cout << cc[i].id << endl;
		cout << cc[i].make << endl;
		cout << cc[i].model << endl;
		cout << cc[i].year << endl;
		cout << cc[i].installment << endl;
		cout << cc[i].price << endl;
	}
	cc.clear();
	car.close();
};

vector <Showrooms> shh;
Showrooms sh;

Showrooms::Showrooms()
{
	id = 0;
	phoneNumber = 0;


};
void Showrooms::addShowRooms() {
	ifstream Showroom("showrooms.txt");
	fstream SHOWROOM("showrooms.txt", ios::app);
	
	bool found = false;
	string n, Lo;
	float I, P;
	if (Showroom.is_open()) {
		while (Showroom >> I >> n >> Lo >> P) {
			sh.id = I;
			sh.name = n;
			sh.location = Lo;
			sh.phoneNumber = P;
			shh.push_back(sh);
			
		}
	}
	else {
		cout << "file not opened" << endl;
	}
	std::cout << "Enter Id of the Showroom" << endl;
	cin >> sh.id;
	for (int i = 0; i < shh.size(); i++) {
		if (shh[i].id == sh.id) {
			found = true;
		}
	}if (found) {
		cout << " id already used , please change your id " << endl;
		cin >> sh.id;
	}
	std::cout << "Enter Name of the Showroom" << endl;
	cin >> sh.name;
	std::cout << "Enter phone number of the Showroom" << endl;
	cin >> sh.phoneNumber;
	std::cout << "Enter location of the Showroom" << endl;
	cin >> sh.location;
	cout << "done" << endl;
	shh.push_back(sh);
	ofstream Showrooms("showrooms.txt");
	for (int i = 0; i < shh.size(); i++) {

		SHOWROOM << shh[i].id << endl;
		SHOWROOM << shh[i].name << endl;
		SHOWROOM << shh[i].location << endl;
		SHOWROOM << shh[i].phoneNumber << endl;

	}
	cout << "Data added to our system" << endl;
	cout << "the size of array = " << shh.size() << endl;
	Showrooms.close();
	Showroom.close();
	SHOWROOM.close();
	shh.clear();



};

void Showrooms::updateShowRooms()
{
	ifstream Showroom("showrooms.txt");
	fstream SHOWROOM("showrooms.txt", ios::app);
	string n, Lo;
	float I, P;
	if (Showroom.is_open()) {

		while (Showroom >> I >> n >> Lo >> P) {
			sh.id = I;
			sh.name = n;
			sh.location = Lo;
			sh.phoneNumber = P;
			shh.push_back(sh);
		}
	}
	else {
		cout << "file not opened" << endl;
	}

	int idC;
	bool found = false;

	assert(!shh.empty());

	cout << "Enter your Showroom Id " << endl;
	cout << " the size of array = " << shh.size() << endl;
	cin >> idC;

	for (int i = 0; i < shh.size(); i++) {
		if (shh[i].id == idC) {
			found = true;
			cout << "Data found " << endl;
			cout << "please update your data" << endl;
			cout << "Enter Id of the Showroom" << endl;
			cin >> sh.id;
			cout << "Enter name of the Showroom" << endl;
			cin >> sh.name;
			cout << "Enter location of Showroom" << endl;
			cin >> sh.location;
			cout << "Enter Phonenumber of the Showroom" << endl;
			cin >> sh.phoneNumber;
			cout << "update done";
			shh[i] = sh;
			ofstream Showroom("showrooms.txt");
			for (int i = 0; i < shh.size(); i++) {
				SHOWROOM << shh[i].id << endl;
				SHOWROOM << shh[i].name << endl;
				SHOWROOM << shh[i].location << endl;
				SHOWROOM << shh[i].phoneNumber << endl;
			}

		}
	}
	if (found) {
		cout << "Done" << endl;

		shh.clear();
	}
	else {
		cout << "data not found" << endl;
		shh.clear();
	}
	Showroom.close();
	SHOWROOM.close();
};

void Showrooms::deleteShowRooms()
{
	ifstream Showroom("showrooms.txt");
	fstream SHOWROOM("showrooms.txt", ios::app);
	string n, Lo;
	float I, P;
	if (Showroom.is_open()) {

		while (Showroom >> I >> n >> Lo >> P) {
			sh.id = I;
			sh.name = n;
			sh.location = Lo;
			sh.phoneNumber = P;
			shh.push_back(sh);
		}
	}
	else {
		cout << "file not opened" << endl;
	}
	int idC;
	bool found = false;
	
	assert(!shh.empty());

	cout << "Enter your Showroom Id " << endl;
	cout << " the size of array = " << shh.size() << endl;
	cin >> idC;

	for (int i = 0; i < shh.size(); i++) {
		if (shh[i].id == idC) {
			shh.erase(shh.begin() + 1);
			found = true;
		}
	}

	if (found) {
		
		ofstream Showroom("showrooms.txt");
		cout << "Data deleted" << endl;
		for (int i = 0; i < shh.size(); i++) {
			SHOWROOM << shh[i].id << endl;
			SHOWROOM << shh[i].name << endl;
			SHOWROOM << shh[i].location << endl;
			SHOWROOM << shh[i].phoneNumber << endl;
		}
		shh.clear();
	}
	else {
		cout << "Data not found " << endl;
		shh.clear();
	}
	Showroom.close();
	SHOWROOM.close();
};

void Showrooms::displayShowRooms()
{
	ifstream Showroom("showrooms.txt");
	string n, Lo;
	float I, P;
	if (Showroom.is_open()) {

		while (Showroom >> I >> n >> Lo >> P) {
			sh.id = I;
			sh.name = n;
			sh.location = Lo;
			sh.phoneNumber = P;
			shh.push_back(sh);
		}
	}
	assert(!shh.empty());
	for (int i = 0; i < shh.size(); i++) {
		cout << "data of Showroom " << i + 1 << endl;
		cout << shh[i].id << endl;
		cout << shh[i].location << endl;
		cout << shh[i].phoneNumber << endl;
		cout << shh[i].name << endl;

	}
	shh.clear();
	Showroom.close();
};

void Showrooms::searchShowRooms() {
	ifstream Showroom("showrooms.txt");
	float I, P;
	string Lo, n;
	if (Showroom.is_open()) {

		while (Showroom >> I >> P >> Lo >> n) {
			sh.id = I;
			sh.name = n;
			sh.location = Lo;
			sh.phoneNumber = P;
			shh.push_back(sh);
		}
	}
	else {
		cout << "file not opened" << endl;
	}

	bool found = false;
	int ID;
	cout << "Enter the Showroom ID" << endl;
	cin >> ID;
	for (int i = 0; i < shh.size(); i++) {
		if (shh[i].id == ID) {
			found = true;
			cout << "Name of the Showroom" << " " << shh[i].name << endl;
			cout << "Phonenumber of the Showroom" << " " << shh[i].phoneNumber << endl;
			cout << "Location of the Showroom " << " " << shh[i].location << endl;
			cout << " the size of array = " << shh.size() << endl;
		}
	}
	if (found) {
		cout << "Done" << endl;
		shh.clear();
	}
	else {
		cout << "data not found" << endl;
		shh.clear();
	}

	Showroom.close();
};

vector <Service> ss;
Service s;

Service::Service()
{
	IDS = 0;
	price = 0;
};

void Service::addService()
{
	ifstream service("services.txt");
	fstream SERVICES("services.txt", ios::app);

	
	bool found = false;
	string NAME;
	float PRICE;
	int ID;
	if (service.is_open()) {

		while (service >> ID >> NAME >> PRICE) {
			s.IDS = ID;
			s.NameS = NAME;
			s.price = PRICE;
			ss.push_back(s);
			
		}

	}
	else {
		cout << "file not opened" << endl;
	}
	std::cout << "Enter Id of the Service" << endl;
	cin >> s.IDS;
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i].IDS == s.IDS) {
			found = true;
		}
	}if (found) {
		cout << " id already used , please change your id " << endl;
		cin >> s.IDS;
	}
	std::cout << "Enter Name of the Service" << endl;
	cin >> s.NameS;
	std::cout << "Enter Price of the Service" << endl;
	cin >> s.price;

	cout << "done" << endl;
	ss.push_back(s);
	ofstream services("services.txt");
	for (int i = 0; i < ss.size(); i++) {

		SERVICES << ss[i].IDS << endl;
		SERVICES << ss[i].NameS << endl;
		SERVICES << ss[i].price << endl;
	}
	cout << "Data added to our system" << endl;
	cout << "the size of array = " << ss.size() << endl;
	services.close();
	service.close();
	SERVICES.close();
	ss.clear();

};

void Service::updateService()
{
	ifstream service("services.txt");
	fstream SERVICES("services.txt", ios::app);
	string NAME;
	float PRICE;
	int ID;
	if (service.is_open()) {

		while (service >> ID >> NAME >> PRICE) {
			s.IDS = ID;
			s.NameS = NAME;
			s.price = PRICE;

			ss.push_back(s);
		}

	}
	else {
		cout << "file not opened" << endl;
	}


	int idU;
	bool found = false;

	assert(!ss.empty());

	cout << "Enter your car Id " << endl;
	cout << " the size of array = " << ss.size() << endl;
	cin >> idU;

	for (int i = 0; i < ss.size(); i++) {
		if (ss[i].IDS == idU) {
			found = true;
			cout << "Data found " << endl;
			cout << "please update your data" << endl;
			cout << "Enter Id of the car" << endl;
			cin >> s.IDS;
			cout << "Enter Name of the car" << endl;
			cin >> s.NameS;
			cout << "Enter Price of the car" << endl;
			cin >> s.price;

			cout << "update done";
			ss[i] = s;
			ofstream service("services.txt");
			for (int i = 0; i < ss.size(); i++) {

				SERVICES << ss[i].IDS << endl;
				SERVICES << ss[i].NameS << endl;
				SERVICES << ss[i].price << endl;

			}

		}
	}
	if (found) {
		cout << "Done" << endl;

		ss.clear();
	}
	else {
		cout << "data not found" << endl;
		ss.clear();
	}
	service.close();
	SERVICES.close();
};

void Service::deleteService()
{
	ifstream service("services.txt");
	fstream SERVICES("services.txt", ios::app);
	string NAME;
	float PRICE;
	int ID;
	if (service.is_open()) {

		while (service >> ID >> NAME >> PRICE) {
			s.IDS = ID;
			s.NameS = NAME;
			s.price = PRICE;

			ss.push_back(s);
		}

	}
	else {
		cout << "file not opened" << endl;
	}


	int idC;
	bool found = false;
	

	assert(!ss.empty());

	cout << "Enter your service Id " << endl;
	cout << " the size of array = " << ss.size() << endl;
	cin >> idC;

	for (int i = 0; i < ss.size() ; i++) {
		if (ss[i].IDS == idC) {
			ss.erase(ss.begin() + i);
			found =true;
		}
	}


	if (found) {
		
		ofstream service("services.txt");
		cout << "Data deleted" << endl;
		for (int i = 0; i < ss.size(); i++) {

			SERVICES << ss[i].IDS << endl;
			SERVICES << ss[i].NameS << endl;
			SERVICES << ss[i].price << endl;
		}
		ss.clear();
	}


	else {
		cout << "Data not found " << endl;
		ss.clear();
	}
	service.close();
	SERVICES.close();
};

void Service::displayService()
{
	ifstream service("services.txt");
	string NAME;
	float PRICE;
	int ID;
	string line;
	if (service.is_open()) {

		while (service >> ID >> NAME >> PRICE) {
			s.IDS = ID;
			s.NameS = NAME;
			s.price = PRICE;

			ss.push_back(s);

		}
	}
	assert(!ss.empty());
	for (int i = 0; i < ss.size(); i++) {
		cout << "data of car " << i + 1 << endl;
		cout << ss[i].IDS << endl;
		cout << ss[i].NameS << endl;
		cout << ss[i].price << endl;

	}
	ss.clear();
	service.close();

};
void Service::searchService()
{
	ifstream service("services.txt");
	string NAME;
	float PRICE;
	int ID;

	if (service.is_open()) {

		while (service >> ID >> NAME >> PRICE) {
			s.IDS = ID;
			s.NameS = NAME;
			s.price = PRICE;

			ss.push_back(s);
		}
	}
	else {
		cout << "file not opened" << endl;
	}

	bool found = false;
	int IDX;
	std::cout << "Enter the service ID" << endl;
	cin >> IDX;
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i].IDS == IDX) {
			found = true;
			std::cout << "Name of the service" << " " << ss[i].NameS << endl;
			std::cout << "Price of the service" << " " << ss[i].price << endl;
			std::cout << " the size of array = " << ss.size() << endl;
		}
	}
	if (found) {
		cout << "Done" << endl;
		ss.clear();
	}
	else {
		cout << "data not found" << endl;
		ss.clear();
	}

	service.close();

}

void Service::dis_Ser_Names()
{
	assert(!ss.empty());
	for (int i = 0; i < ss.size(); i++) {
		cout << "data of service " << i + 1 << ss[i].NameS << endl;
	}
};
 
vector <Garages> gg;
Garages g;


Garages::Garages()
{
	id = 0;
	phonenumber = 0;


};
void Garages::searchGarage()
{
	ifstream garage("garages.txt");
	int i;
	string n;
	string loc;
	int phonenum;
	string serv;
	if (garage.is_open()) {

		while (garage >> i >> n >> loc >> phonenum >> serv) {
			g.id = i;
			g.name = n;
			g.location = loc;
			g.phonenumber = phonenum;
			g.services = serv;
			gg.push_back(g);

		}
	}
	else {
		cout << "file not opened" << endl;
	}

	bool found = false;
	string temGar;
	std::cout << "Enter the name of the garage" << endl;
	cin >> temGar;
	for (int i = 0; i < gg.size(); i++) {

		if (gg[i].name == temGar) {
			found = true;
			std::cout << "ID of the garage" << " " << gg[i].id<< endl;
			std::cout << "location of the garage" << " " << gg[i].location << endl;
			std::cout << "phone number of the garage " << " " << gg[i].phonenumber << endl;
			std::cout << "services of the garage" << " " << gg[i].services << endl;
			
		}
	}

	if (found) {
		cout << "Done" << endl;
		gg.clear();
	}
	else {
		cout << "data not found" << endl;
		gg.clear();
	}

	garage.close();
};


void Garages::addGarage()
{
	ifstream garage("garages.txt");
	fstream GARAGE("garages.txt", ios::app);

	
	bool found = false;
	int i;
	string n;
	string loc;
	int phonenum;
	string serv;
	if (garage.is_open()) {

		while (garage >> i >> n >> loc >> phonenum >> serv) {
			g.id = i;
			g.name = n;
			g.location = loc;
			g.phonenumber = phonenum;
			g.services = serv;
			gg.push_back(g);
			
		}

	}
	else {
		cout << "file not opened" << endl;
	}
	std::cout << "Enter Id of the garage" << endl;
	cin >> g.id;
	for (int i = 0; i < gg.size(); i++) {
		if (gg[i].id == g.id) {
			found = true;
		}
	}if (found) {
		cout << " id already used , please change your id " << endl;
		cin >> g.id;
	}
	std::cout << "Enter name of the garage" << endl;
	cin >> g.name;
	std::cout << "Enter location of the garage" << endl;
	cin >> g.location;
	std::cout << "Enter the phone number of the garage" << endl;
	cin >> g.phonenumber;
	std::cout << "Enter the service you need" << endl;
	cin >> g.services;
	cout << "done" << endl;
	gg.push_back(g);
	
	ofstream garages("garages.txt");
	for (int i = 0; i < gg.size(); i++) {

		GARAGE << gg[i].id << endl;
		GARAGE << gg[i].name << endl;
		GARAGE << gg[i].location << endl;
		GARAGE << gg[i].phonenumber << endl;
		GARAGE << gg[i].services << endl;
	}
	cout << "Data added to our system" << endl;
	cout << "the size of array = " << gg.size() << endl;
	garages.close();
	garage.close();
	GARAGE.close();
	gg.clear();
};


void Garages::updateGarage() {

	ifstream garage("garages.txt");
	fstream GARAGE("garages.txt", ios::app);
	int i;
	string n;
	string loc;
	int phonenum;
	string serv;
	if (garage.is_open()) {

		while (garage >> i >> n >> loc >> phonenum >> serv) {
			g.id = i;
			g.name = n;
			g.location = loc;
			g.phonenumber = phonenum;
			g.services = serv;
			gg.push_back(g);
		}

	}
	else {
		cout << "file not opened" << endl;
	}


	int idG;
	bool found = false;

	assert(!gg.empty());

	cout << "Enter your garage Id " << endl;
	cout << " the size of array = " << gg.size() << endl;
	cin >> idG;

	for (int i = 0; i < gg.size(); i++) {
		if (gg[i].id == idG) {
			found = true;
			cout << "Data found " << endl;
			cout << "please update your data" << endl;
			cout << "Enter Id of the garage" << endl;
			cin >> g.id;
			cout << "Enter name of the garage" << endl;
			cin >> g.name;
			cout << "Enter location of the garage" << endl;
			cin >> g.location;
			cout << "Enter the phone number of the garage" << endl;
			cin >> g.phonenumber;
			cout << "Enter the service you need" << endl;
			cin >> g.services;
			cout << "update done";
			gg[i] = g;
			ofstream garage("garages.txt");
			for (int i = 0; i < gg.size(); i++) {

				GARAGE << gg[i].id << endl;
				GARAGE << gg[i].name << endl;
				GARAGE << gg[i].location << endl;
				GARAGE << gg[i].phonenumber << endl;
				GARAGE << gg[i].services << endl;
			}

		}
	}
	if (found) {
		cout << "Done" << endl;

		gg.clear();
	}
	else {
		cout << "data not found" << endl;
		gg.clear();
	}
	garage.close();
	GARAGE.close();
};

void Garages::deleteGarage() {

	ifstream garage("garages.txt");
	fstream GARAGE("garages.txt", ios::app);
	int i;
	string n;
	string loc;
	int phonenum;
	string serv;
	if (garage.is_open()) {

		while (garage >> i >> n >> loc >> phonenum >> serv) {
			g.id = i;
			g.name = n;
			g.location = loc;
			g.phonenumber = phonenum;
			g.services = serv;
			gg.push_back(g);
		}

	}
	else {
		cout << "file not opened" << endl;
	}


	int idG;
	bool found = false;
	

	assert(!gg.empty());

	cout << "Enter your car Id " << endl;
	cout << " the size of array = " << gg.size() << endl;
	cin >> idG;

	for (int i = 0; i < gg.size(); i++) {
		if (gg[i].id == idG) {
			gg.erase(gg.begin() + 1);
			found = true;
		}
	}


	if (found) {
		
		ofstream garage("garages.txt");
		cout << "Data deleted" << endl;
		for (int i = 0; i < gg.size(); i++) {

			GARAGE << gg[i].id << endl;
			GARAGE << gg[i].name << endl;
			GARAGE << gg[i].location << endl;
			GARAGE << gg[i].phonenumber << endl;
			GARAGE << gg[i].services << endl;
		}
		gg.clear();
	}


	else {
		cout << "Data not found " << endl;
		gg.clear();
	}
	garage.close();
	GARAGE.close();
};

void Garages::displayGarage()
{
	ifstream garage("garages.txt");
	int i;
	string n;
	string loc;
	int phonenum;
	string serv;
	if (garage.is_open()) {

		while (garage >> i >> n >> loc >> phonenum >> serv) {
			g.id = i;
			g.name = n;
			g.location = loc;
			g.phonenumber = phonenum;
			g.services = serv;
			gg.push_back(g);

		}
	}
	assert(!gg.empty());
	for (int i = 0; i < gg.size(); i++) {
		cout << "data of garage " << i + 1 << endl;
		cout << gg[i].id << endl;
		cout << gg[i].name << endl;
		cout << gg[i].location << endl;
		cout << gg[i].phonenumber << endl;
		cout << gg[i].services << endl;
	}
	gg.clear();
	garage.close();
}
void Garages::bookGarage()
{
	
	char ans;
	bool found = false;
	g.searchGarage();
	cout << "Do you want to book garage ? y/n " << endl;
	cin >> ans;
	if (ans == 'y' || ans == 'Y') {
		while (!found) {

			fstream garage("garages.txt");
			
			int i;
			string n;
			string loc;
			int phonenum;
			string serv;
			if (garage.is_open()) {

				while (garage >> i >> n >> loc >> phonenum >> serv) {
					g.id = i;
					g.name = n;
					g.location = loc;
					g.phonenumber = phonenum;
					g.services = serv;
					gg.push_back(g);

				}
				garage.close();
			}
			else {
				cout << "file not opened" << endl;
			}
			
			cout << "enter the id of the garage you want to book " << endl;
			cin >> g.id;
			for (int i = 0; i < gg.size(); i++) {
				if (gg[i].id == g.id) {
					cout << "the details of the garage you booked : " << endl;
					cout << "id : " << gg[i].id << endl;
					cout << "location : " << gg[i].location << endl;
					cout << "name of the garage : " << gg[i].name << endl;
					cout << "phonenumber : " << gg[i].phonenumber << endl;
					cout << "list of services: " << gg[i].services << endl;
					gg.erase(gg.begin() + i);
					cout << endl;
					found = true;
					gg.clear();
				}
			}
			if (found) {
				cout << "you will have the garage for the next 24 hours our only and the key will delivered to your home " << endl;
				cout << "thank you for using us " << endl;
				
			}
			else {
				cout << "garage not found" << endl;
			}
		}
	}
	
};

vector <BR_process> brr;
BR_process br;

BR_process::BR_process()
{
	Amountofmoney = 0;
	processID_BR = 0;
	CustomerID = 0;
};

void BR_process::buy_process(int cu_id)
{
	
	ifstream buy("buyrentcar.txt");

	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	int day = now->tm_mday; int mon = now->tm_mon + 1; int year = now->tm_year + 1900;
	int hour = now->tm_hour; int min = now->tm_min;

	br.Date = (to_string(day) + "/" + to_string(mon) + "/" + to_string(year));

	int P_ID, idc;
	float MON;
	string chc, D;

	if (buy.is_open()) {
		while (buy >> idc >> P_ID >> chc >> MON >> D) {
			br.CustomerID = idc;
			br.processID_BR = P_ID;
			br.ChosenCar = chc;
			br.Amountofmoney = MON;
			br.Date = D;
			brr.push_back(br);
		}
	}
	else {
		cout << "file not opened" << endl;
	}
	//////////////////////////////////////////////////////
	buy.close();
	c.searchCar();
	ifstream car("cars.txt");
	fstream CARS("cars.txt", ios::app);
	bool found = false;
	string MA;
	float I, MO, Y, P, IN;
	if (car.is_open()) {

		while (car >> I >> MA >> MO >> Y >> P >> IN) {
			c.id = I;
			c.make = MA;
			c.model = MO;
			c.year = Y;
			c.price = P;
			c.installment = IN;
			cc.push_back(c);

		}

	}
	
	else
		cout << "file not opened" << endl;
	car.close();
	while (!found) {
		cout << "enter the id of the car" << endl;
		cin >> br.processID_BR;
		for (int i = 0; i < cc.size(); i++)
		{
			//cout << "customer number : " << i + 1 << endl;
			if (cc[i].id== br.processID_BR) {
				found = true;
				br.ChosenCar = cc[i].make;
				br.CustomerID = cu_id;
				br.Amountofmoney = cc[i].price;

				int ans;
				
				cout << "to buy press 1 \t\t to rent press 2" << endl;
				cin >> ans;
				if (ans == 1) {
					cc.erase(cc.begin() + i);
				}
				
			}
		}
		if (found) {
			cout << endl;
			cout << "you've got the service successfully!, and here's the data of the process" << endl;
			cout << "customer id :\t" << br.CustomerID << endl;
			cout << "process id :\t" << br.processID_BR << endl;
			cout << "chosen car name :" << br.ChosenCar << endl;
			cout << "process price :\t" << br.Amountofmoney << endl;
			cout << "process date :\t" << br.Date << endl;
			brr.push_back(br);
		}
	}
	fstream BUY("buyrentcar.txt", ios::app);
	ofstream buys("buyrentcar.txt");

	for (int i = 0; i < brr.size(); i++)
	{
		BUY << brr[i].CustomerID << endl;
		BUY << brr[i].processID_BR << endl;
		BUY << brr[i].ChosenCar << endl;
		BUY << brr[i].Amountofmoney << endl;
		BUY << brr[i].Date << endl;
	}
	brr.clear();
	ofstream cars("cars.txt");
	for (int i = 0; i < cc.size(); i++) {

		CARS << cc[i].id << endl;
		CARS << cc[i].make << endl;
		CARS << cc[i].model << endl;
		CARS << cc[i].year << endl;
		CARS << cc[i].installment << endl;
		CARS << cc[i].price << endl;
		
	}
	cc.clear();
	CARS.close();
	buy.close();
	BUY.close();
	

};

vector < ServiceProcess > SV;
ServiceProcess sv;

ServiceProcess::ServiceProcess()
{
	CustomerID = 0;
	processID_S = 0;
	chosenService;
	Amountofmoney = 0.0;
	Date;

}
void ServiceProcess::getservice(int cu_id) {


	ifstream history("history.txt");
	fstream HISTORY("history.txt", ios::app);

	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	int day = now->tm_mday; int mon = now->tm_mon + 1; int year = now->tm_year + 1900;
	int hour = now->tm_hour; int min = now->tm_min;

	sv.Date = (to_string(day) + "/" + to_string(mon) + "/" + to_string(year));

	int P_ID, idser;
	float MON;
	string SER, D;

	if (history.is_open()) {
		while (history >> idser >> P_ID >> MON >> SER >> D) {
			sv.CustomerID = idser;
			sv.processID_S = P_ID;
			sv.chosenService = SER;
			sv.Amountofmoney = MON;
			sv.Date = D;
			SV.push_back(sv);
		}
	}
	else {
		cout << "file not opened" << endl;
	}
	//////////////////////////////////////////////////////

	s.searchService();
	bool found = false;
	ifstream service("services.txt");
	string NAME;
	float PRICE;
	int ID;
	string line;
	if (service.is_open()) {

		while (service >> ID >> NAME >> PRICE) {
			s.IDS = ID;
			s.NameS = NAME;
			s.price = PRICE;
			ss.push_back(s);

		}
	}
	else
		cout << "file not opened" << endl;
	service.close();
	while (!found) {
		cout << "enter the id of the service" << endl;
		cin >> sv.processID_S;
		for (int i = 0; i < ss.size(); i++)
		{
			//cout << "customer number : " << i + 1 << endl;
			if (ss[i].IDS == sv.processID_S) {
				found = true;
				sv.chosenService = ss[i].NameS;
				sv.CustomerID = cu_id;
				sv.Amountofmoney = ss[i].price;

			}
		}
		if (found) {
			cout << endl;

			cout << "you've got the service successfully!, and here's the data of the process" << endl;
			cout << "customer id :\t" << sv.CustomerID << endl;
			cout << "service id :\t" << sv.processID_S << endl;
			cout << "service name :\t" << sv.chosenService << endl;
			cout << "service price :\t" << sv.Amountofmoney << endl;
			cout << "service date :\t" << sv.Date << endl;
			SV.push_back(sv);
		}
	}
	ofstream historic("history.txt", ios::app);
	for (int i = 0; i < SV.size(); i++)
	{
		HISTORY << SV[i].CustomerID << endl;
		HISTORY << SV[i].processID_S << endl;
		HISTORY << SV[i].chosenService << endl;
		HISTORY << SV[i].Amountofmoney << endl;
		HISTORY << SV[i].Date << endl;
		SV.clear();
	}

	history.close();
	HISTORY.close();

}
void ServiceProcess::displayhistory() {
	ifstream history("history.txt");
	int P_ID, idser;
	float MON;
	string SER, D;

	if (history.is_open()) {
		while (history >> idser >> P_ID >> SER >> MON >> D) {
			sv.CustomerID = idser;
			sv.processID_S = P_ID;
			sv.chosenService = SER;
			sv.Amountofmoney = MON;
			sv.Date = D;
			SV.push_back(sv);

		}
	}
	bool found = false;


	int ID = -1;
	std::cout << "Enter the customer ID" << endl;
	cin >> ID;
	for (int i = 0; i < SV.size(); i++) {
		if (SV[i].CustomerID == ID) {
			found = true;

			cout << "the historical service data of the customer who's id  " << SV[i].CustomerID << " are " << endl;
			cout << "id of the service" << " " << SV[i].processID_S << endl;
			cout << "name of the service" << " " << SV[i].chosenService << endl;
			cout << "price of the service " << " " << SV[i].Amountofmoney << endl;
			cout << "the date of the process " << " " << SV[i].Date << endl;

		}


	}
	if (found) {
		cout << "Done" << endl;

	}

	else {
		cout << "data not found" << endl;
	}
	SV.clear();
	history.close();
}
