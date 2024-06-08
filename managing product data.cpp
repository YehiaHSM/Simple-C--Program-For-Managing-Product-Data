#include<iostream>
using namespace std;

// Define a constant representing the number of days in a week
#define prod  7

// Define a struct to represent the expiration date of a product
struct expiredate {
	int day;
	int month;
	int year;
};

// Define a struct to represent a product
struct product {
	int serialnum;
	char name[50];
	expiredate EP;
	int quantity;
	char type[50];
	int salesperday[prod]; // Array to store daily sales for a week
};

int main() {
	// Define the number of products
	const int nop = 3;

	// Define variables to store user input
	int uq;
	int total[nop];

	// Define an array to store product data
	product products[nop];

	// Prompt the user to enter data for each product
	cout << "Please enter data for 3 products : " << endl;
	for (int t = 0; t < nop; t++) {
		// Initialize total sales for each product to 0
		total[t] = 0;

		// Prompt the user to input product details
		cout << "Enter values of product number #" << t+1 << "#" << endl;
		cout << "Serial Number : ";
		cin >> products[t].serialnum;
		cout << "Name : ";
		cin >> products[t].name;
		cout << "Expire date (Day,Month,Year) : ";
		cin >> products[t].EP.day >> products[t].EP.month >> products[t].EP.year;
		cout << "Quantity in store : ";
		cin >> products[t].quantity;
		cout << "Type : ";
		cin >> products[t].type;
		cout << "7 values that represents sales for week days : ";
		
		// Input sales data for each day of the week
		for (int p = 0; p < prod; p++) {
			cin >> products[t].salesperday[p];
			total[t] += products[t].salesperday[p]; // Update total sales
		}	
	}

	// Display products that will expire before 1/1/2020
	cout << "     ##############     " << endl;
	cout << "Display products that will expire before 1/1/2020"<<endl;
	cout << "The products that will expire are: "<< endl;
	for (int t = 0; t < nop; t++) {
		if (products[t].EP.year < 2020)
			cout << products[t].name << endl;
	}

	// Display products that have less quantity than the value entered by the user
	cout << "     ##############     " << endl;
	cout << "Products that have less quantity than the value entered by the user."<<endl;
	cout << "Please enter  a quantity : ";
	cin >> uq;
	cout << "Products that have less than this quantity : " << endl;
	for (int t = 0; t < nop; t++) {
		if (products[t].quantity < uq)
			cout << products[t].name << endl;
	}

	// Determine the product with the highest total sales per week
	if (total[0] > total[1] && total[0] > total[2])
		cout << products[0].name << endl;
	else if (total[1] > total[0] && total[1] > total[2])
		cout << products[1].name << endl;
	else if (total[2] > total[0] && total[2] > total[1])
		cout << products[2].name << endl;

	// Pause the program to keep the console window open
	// Note: Using system("pause") is not recommended for portability reasons
	system("pause");

	// Return 0 to indicate successful execution of the program
	return 0;
}
