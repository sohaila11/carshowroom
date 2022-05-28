#include <iostream>
#include <fstream>
#include <cstring>
#include <string >
#include <conio.h>
#include "adminn.h"
#include  <vector>



using namespace std;

void admin() {
	char l;
	int num = 1;
	char letter;


	while (num != 0) {
		cout << "to add press 1 " << endl;
		cout << "to update press 2 " << endl;
		cout << "to delete press 3 " << endl;
		cout << "to logout press 0" << endl;
		cin >> num;
		switch (num) {
		case 1:
			cout << "to add car press a" << endl;
			cout << "to add showroom press b" << endl;
			cout << "to add garage press c" << endl;
			cout << "to add service press d" << endl;
			cin >> letter;
			if (letter == 'a')
			{
				Car c;
				c.AddCar();
			}
			else if (letter == 'b')
			{
				Showrooms s;
				s.addShowRooms();

			}
			else if (letter == 'c')
			{
				Garages g;
				g.addGarage();

			}
			else if (letter == 'd')
			{
				Service s;
				s.addService();

			}
			break;

		case 2:
			cout << "to update in cars press a " << endl;
			cout << "to update in showroom press b " << endl;
			cout << "to update in garages press c" << endl;
			cout << "to update in service press d " << endl;
			cin >> letter;
			if (letter == 'a') {
				Car a;
				a.updateCarData();
			}
			else if (letter == 'b') {
				Showrooms sh;
				sh.updateShowRooms();

			}
			else if (letter == 'c') {
				Garages g;
				g.updateGarage();
			}
			else if (letter == 'd')
			{
				Service s;
				s.updateService();
			}
			break;
		case 3:
			cout << "to delete in cars press a" << endl;
			cout << "to delete in showroom press b" << endl;
			cout << "to delete in Garage  press c" << endl;
			cout << "to delete in Service press d" << endl;
			cin >> letter;
			if (letter == 'a') {
				Car a;
				a.deleteCar();
			}
			else if (letter == 'b')
			{
				Showrooms sh;
				sh.deleteShowRooms();
			}
			else if (letter == 'c') {
				Garages g;
				g.deleteGarage();
			}
			else if (letter == 'd') {
				Service s;
				s.deleteService();
			}

			break;




		}
	}

}
void customers(int cu_id) {
	char l;
	int num = 1;
	char letter;
	while (num != 0) {
		cout << endl;
		cout << "to search press 1 " << endl;
		cout << "to view data press 2 " << endl;
		cout << "to buy/rent car press 3 " << endl;
		cout << "to book garage press 4 " << endl;
		cout << "to get services press 5 " << endl;
		cout << "to show the historical service data press 6" << endl;
		cout << "to logout press 0" << endl;
		cin >> num;
		switch (num) {
		case 1:
		{
			cout << "to search car press a" << endl;
			cout << "to search showroom press b" << endl;
			cout << "to search garage press c" << endl;
			cout << "to search service press d" << endl;
			cin >> letter;
			if (letter == 'a')
			{
				Car c;
				c.searchCar();
			}
			else if (letter == 'b')
			{
				Showrooms s;
				s.searchShowRooms();

			}
			else if (letter == 'c')
			{
				Garages g;
				g.searchGarage();

			}
			else if (letter == 'd')
			{
				Service s;
				s.searchService();

			}
			break;
		}
		case 2:
		{
			cout << "to display in showroom press b " << endl;
			cout << "to display in garages press c" << endl;
			cin >> letter;

			if (letter == 'b') {
				Showrooms sh;
				sh.displayShowRooms();

			}
			else if (letter == 'c') {
				Garages g;
				g.displayGarage();
			}
			break;
		}
		case 3:
		{

			BR_process b;
			b.buy_process(cu_id);

			break;
		}
		case 4: {
			Garages g;
			g.bookGarage();
			break;
		}
		case 5: {
			ServiceProcess sv;
			sv.getservice(cu_id);
			break;
		}
		case 6: {
			ServiceProcess sv;
			sv.displayhistory();
			break;
		}
		case 0: {
			break;
		}
		}

	}
	
}





int main()
{

	vector <customer> ccu;
	customer cu;
	string command;
	bool flag = true;



	while (flag) {
		cout << "\t\t ~~~~~~ WELCOME IN CARSHOWROOM APP ~~~~~~~~ \t\t\t" << endl;
		cout << "(register/ login /exit)" << endl;
		cin >> command;
		if (command == "register") {

			ifstream reg("registration.txt");
			fstream REG("registration.txt", ios::app);


			bool found = false;
			int id;
			string u_n, password;
			if (reg.is_open()) {

				while (reg >> id >> u_n >> password) {
					cu.ID_C = id;
					cu.Username = u_n;
					cu.Password = password;
					ccu.push_back(cu);

				}

			}
			else {
				cout << "file not opened" << endl;
			}
			std::cout << "Enter your ID" << endl;
			cin >> cu.ID_C;
			for (int i = 0; i < ccu.size(); i++) {
				if (ccu[i].ID_C == cu.ID_C) {
					found = true;
				}
			}if (found) {
				cout << " id already used , please change your id " << endl;
				cin >> cu.ID_C;
			}
			std::cout << "Enter your username" << endl;
			cin >> cu.Username;
			std::cout << "Enter your password" << endl;
			cin >> cu.Password;


			cout << "done" << endl;
			ccu.push_back(cu);
			ofstream regs("registration.txt");
			for (int i = 0; i < ccu.size(); i++) {

				REG << ccu[i].ID_C << endl;
				REG << ccu[i].Username << endl;
				REG << ccu[i].Password << endl;

			}
			cout << "Data added to our system" << endl;
			
			ccu.clear();
			reg.close();
			REG.close();
			regs.close();

		}
		else if (command == "login") {
			ifstream reg("registration.txt");
			fstream REG("registration.txt", ios::app);
			bool logged = false;
			char ch = ' ';
			bool found = false;
			int id;
			string u_n, pass;
			string username, password;
			if (reg.is_open()) {

				while (reg >> id >> u_n >> pass) {
					cu.ID_C = id;
					cu.Username = u_n;
					cu.Password = pass;
					ccu.push_back(cu);

				}

			}
			else {
				cout << "file not opened" << endl;
			}

			while (!logged) {
				int id_cu;
				cout << "ENTER YOUR USERNAME : " << endl;
				cin >> username;
				cout << "Enter YOUR PASSWORD : " << endl;
				getline(cin, password);
				ch = _getch();
				while (ch != 13) {
					password.push_back(ch);
					cout << '*';
					ch = _getch();
				}
				for (int i = 0; i < ccu.size(); i++) {
					if (ccu[i].Username == username && ccu[i].Password == password) {
						id_cu = ccu[i].ID_C;
						found = true;
					}
				}
				if (found && username == "admin" && password == "1111") {
					cout << "\t\t\t ~~~~ welcome to admin~~~~~~~\t\t\t" << endl;
					admin();

					logged = true;
					

				}
				else if (found) {
					cout << "\t\t\t~~~~~~~~ CARSHOWROOM ~~~~~~~~\t\t\t" << endl;

					customers(id_cu);
					logged = true;
					

				}
				else {
					cout << endl;
					cout << "incorrect name or password" << endl;
				}

			}
			reg.close();
			REG.close();

		}
		else {
			flag = false;
		}
	}
	system("pause");
	return 0;
}