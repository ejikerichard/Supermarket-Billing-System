
#include<iostream>
#include<fstream>

#pragma once
using namespace std;
class Shopping
{
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

void Shopping::menu() {
	m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\t*****************************\n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t    Supermarket Main Menu    \n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t*****************************\n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t|  1) Administrator    |\n";
	cout << "\t\t\t\t|                      |\n";
	cout << "\t\t\t\t|  2) Buyer			|\n";
	cout << "\t\t\t\t|                      |\n";
	cout << "\t\t\t\t|  3) Exit				|\n";
	cout << "\t\t\t\t|                      |\n";
	cout << "\n\t\t\t Please select!";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\t\t\t Please login \n";
		cout << "\t\t\t Enter your email \n";
		cin >> email;
		cout << "\t\t\t Enter your password \n";
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

void Shopping::admistrator() {

	m:

	int choice =0;

	cout << "\n\n\n\t\t\tAdministrator Menu";
	cout << "\n\t\t\t|_____1) Add the product_____";
	cout << "\n\t\t\t|                            ";
	cout << "\n\t\t\t|____2) Modify the product__|";
	cout << "\n\t\t\t|                            ";
	cout << "\n\t\t\t|____3) Delete the product__|";
	cout << "\n\t\t\t|                            ";
	cout << "\n\t\t\t|____4) Back to main menu___|";

	cout << "\n\n\t Please enter your choice";
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
		cout << "Invalid choice!";
		break;
	}
	goto m;
}

void Shopping::buyer() {
	m:
	int choice;
	cout << "\t\t\t Buyer \n";
	cout << "\t\t\t_______________\n";
	cout << "                  \n";
	cout << "\t\t\t1) Buy prodect \n";
	cout << "                  \n";
	cout << "\t\t\t2) Go back     \n";
	cout << "\t\t\t Enter  your choice :";

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

void Shopping::add() {
	m:
	fstream data;
	int c = 0;
	int token = 0;
	float p;
	float d;
	string n;

	cout << "\n\n\t\t Add new product";
	cout << "\n\n\t\t Product code of the product ";
	cin >> pcode;
	cout << "\n\n\t\t Name of the product ";
	cin >> pname;
	cout << "\n\n\t Price of the product";
	cin >> price;
	cout << "\n\n\t Discount on product";
	cin >> dis;

	data.open("database.txt", ios::in);

	if (!data) {
		data.open("database.txt", ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else 
	{
		data >>c>>n>>p>>d;

		while (!data.eof()) {
			if (c == pcode) {
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	if (token == 1){
		goto m;
	}

	else {
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	cout << "\n\n\t\t Record inserted !";
}

void Shopping::edit() {
	fstream data, data1;
	int pkey, token = 0, c;
	float p, d;
	string n;

	cout << "\n\t\t\t Modify the record" << endl;
	cout << "\n\t\t\t Product code: ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data) {
		cout << "\n\nFile doesn't exist!" << endl;
	}
	else {
		data1.open("database1.txt", ios::app | ios::out);

		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if (pkey == pcode) 
			{
				cout << "\n\t\t New product code: ";
				cin >> c;
				cout << "\n\t\t New name of the product: ";
				cin >> n;
				cout << "\n\t\t New price: ";
				cin >> p;
				cout << "\n\t\t New discount: ";
				cin >> d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<< "\n";
				cout << "\n\n\t\t Record edited" << endl;
				token++;
			}
			else 
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");
		if (token == 0) {
			cout << "\n\n Record not found. Sorry!" << endl;
		}
	}
}
void Shopping::rem() {
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\n\n\t Delete product";
	cout << "\n\n\t Product code :";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if (!data) {
		cout << "File doesnt exist";

	}
	else {
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (!data.eof()) {
			if (pcode == pkey) {
				cout << "\n\n\t Product deleted successfully";
				token++;
			}
			else 
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0) {
			cout << "\n\n Record not be found";
		}
	}
}

void Shopping::list() {
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n|_____________________________________\n";
	cout << "ProNo\t\tName\t\tPrice \n";
	cout << "\n\n|_____________________________________\n";
	data >> pcode >> pname >> price >> dis;
	while (!data.eof()) {
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void Shopping::receipt() {
	fstream data;

	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);
	if (!data) {

		cout << "\n\n Empty database";

	}

	else {
		data.close();

		list();
		cout << "\n_________________________________\n";
		cout << "\n                                 \n";
		cout << "\n     Please place the order      \n";
		cout << "\n                                 \n";
		cout << "\n_________________________________\n";
		do {
			m:
			cout << "\n\nEnter Product code: ";
			cin >> arrc[c];
			cout << "\n\nEnter the product quantity :";
			cin >> arrq[c];
			for (int i = 0; i < c; i++) {
				if (arrc[c] == arrc[i]) {
					cout << "\n\n Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? if yes then press y else no ";
			cin >> choice;

		} while (choice == 'y');

		cout << "\n\n\t\t\t__________________RECEIPT______________________\n";
		cout << "\nProduct No\t product Name\t product quantity\tprice\tAmount\tAmount with discount\n";

		for (int i = 0; i < c; i++) {
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof()) {
				if (pcode == arrc[i]) {
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total = total + dis;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrc[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
		}
		data.close();
	}
	cout << "\n\n_________________________________________";
	cout << "\n Total Amount : " << total;
}

