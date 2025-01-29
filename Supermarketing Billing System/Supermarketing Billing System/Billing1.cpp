#include<iostream>
#include<fstream>

using namespace std;

class shopping {
private:
	int pcode;
	float price;
	float dis;
	string pname;

public:
	void menu();
	void admistrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
};

void shopping::menu() {
m:
	int choice;
	string email;
	string password;

	cout << "*************************************\n";
	cout << "******                               \n";
	cout << "******     Supermarket Main Menu     \n";
	cout << "******                               \n";
	cout << "*************************************\n";
	cout << "******                               \n";
	cout << "******|  1) Administrator       |\n";
	cout << "******|                         |\n";
	cout << "******|  2) Buyer				 |\n";
	cout << "******|                         |\n";
	cout << "******|  3) Exit				 |\n";
	cout << "******|                         |\n";
	cout << "\n*** Please select!";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "*** Please login \n";
		cout << "*** Enter your email \n";
		cin >> email;
		cout << "*** Enter your password \n";
		cin >> password;

		if (email == "ejikerichard366@yahoo.com" && password == "Ejikerichard234@") {

			admistrator();
		}
		else {
			cout << "Invalid email/password";
		}
		break;

	case 2:
	{
		buyer();
	}
	case 3:
	{
		exit(0);
	}

	default:
	{
		cout << "Please select from the given options";
	}

	}
	goto m;
}

void shopping::admistrator() {

	int choice;
	cout << "\n\n\n***Administrator Menu";
	cout << "\n***|_____1) Add the product_____";
	cout << "\n***|                            ";
	cout << "\n***|____2) Modify the product__|";
	cout << "\n***|                            ";
	cout << "\n***|____3) Delete the product__|";
	cout << "\n***|                            ";
	cout << "\n***|____4) Back to main menu___|";

	cout << "\n\n* Please enter your choice";
	cin >> choice;

	switch (choice)
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		rem();
		break;
	case 4:
		menu();
		break;
	default:
		break;
	}
}

void shopping::buyer() {
	m:
	int choice;
	cout << "*** Buyer \n";
	cout << "***_______________\n";
	cout << "                  \n";
	cout << "***1) Buy prodect \n";
	cout << "                  \n";
	cout << "***2) Go back     \n";
	cout << "*** Enter  your choice :";

	cin >> choice;

	switch (choice) {
	case 1:
		receipt();
		break;
	case 2:
		menu();
		break;
	default:
		cout << "Invalid choice";

	}
	goto m;
}

void shopping::add() {
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;

	cout << "\n\n*** Add new product";
	cout << "\n\n** Product code of the product ";
	cin >> pcode;
	cout << "\n\n** Name of the product ";
	cin >> pname;
	cout << "\n\n* Price of the product";
	cin >> price;
	cout << "\n\n* Discount on product";
	cin >> dis;

	data.open("database.txt", ios::in);

	if (!data) {
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else {
		data >> n >> p >> d;

		while (!data.eof()) {
			if (c == pcode) {
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();
	}
	if (token == 1)
		goto m;
	else {
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	cout << "\n\n** Record inserted !";
}

void shopping::edit() {
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;

	cout << "\n*** Modify the record";
	cout << "\n*** Product code :";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\nFile doesnt exist! ";
	}
	else {
		data1.open("database1.txt", ios::app | ios::out);

		data >> pcode >> pname >> price >> dis;
		while (!data.eof()) {
			if (pkey == pcode) {
				cout << "\n** Product new code :";
				cin >> c;
				cout << "\n** Name of the product :";
				cin >> p;
				cout << "\n** Price :";
				cout << "\n** Discount :";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n** Record edited ";
				token++;
			}
			else {
				data1 << " " << pcode << " " << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
	}
	data.close();
	data1.close();

	remove("database.txt");
	rename("database1.txt", "database.txt");

	if (token == 0) {
		cout << "\n\n Record not found sorry!";
	}
}
void shopping::rem() {

}