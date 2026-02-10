#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

// Structure for a company's business card
struct BusinessCard {
	// All the necessary information about the company is stored in this structure
	string name;
	string address;
	int phoneNumber;
	string workingHours;
	string representative;
	double quotedPrice;

	// Constructor for the BusinessCard structure
	BusinessCard(const string& n, const string& a, int p, const string& w, const string& r, double q)
		: name(n), address(a), phoneNumber(p), workingHours(w), representative(r), quotedPrice(q) {}

};

// Function that prints all the information about the companies
// This function takes 2 parameters:
// 1. An array of BusinessCard structures
// 2. The size of the array
void printCompanyInfo(BusinessCard cards[], int size) {
	// I use setw and left to format the output into a nice table
	// First I print the header for the table of company information
	cout << setw(20) << left << "Name"
		<< setw(20) << left << "Address"
		<< setw(15) << left << "Phone Number"
		<< setw(15) << left << "Working Hours"
		<< setw(20) << left << "Representative"
		<< setw(12) << right << "Quoted Price" << endl;
	// Use setfill and setw to create a separator line under the header
	cout << setfill('-') << setw(102) << "" << setfill(' ') << endl;

	// Then I loop through the cards array and print up each companies info into the table
	for (int i = 0; i < size; ++i) {
		cout << setw(20) << left << cards[i].name
			<< setw(20) << left << cards[i].address
			<< setw(15) << left << cards[i].phoneNumber
			<< setw(15) << left << cards[i].workingHours
			<< setw(20) << left << cards[i].representative
			<< setw(12) << right << fixed << setprecision(2) << cards[i].quotedPrice
			<< endl;
	}

}

// Function that loops through the bussiness cards and prints the cheapest company's information
// This function takes 2 parameters:
// 1. An array of BusinessCard structures
// 2. The size of the array
void printCheapest(BusinessCard cards[], int size) {
	// Here I set minPrice to the quoted price of the first card in the array
	double minPrice = cards[0].quotedPrice;
	// I set minIndex to 0
	// This variable will be used to keep track of the index of the card with the cheapest price
	int minIndex = 0;

	// Loop through the array of business cards starting from the second card (index 1)
	for (int i = 1; i < size; ++i) {
		// If the quoted price of the current card is less than the minimum price found so far
		if (cards[i].quotedPrice < minPrice) {
			// Then update minPrice to the quoted price of the current card
			minPrice = cards[i].quotedPrice;
			// And update minIndex to the index of the current card
			minIndex = i;
		}
	}
	
	// We then print the name of the company that offers the cheapest price and the price itself
	// 
	cout << "\n" << cards[minIndex].name << " offers the cheapest price of $" << fixed << setprecision(2) << cards[minIndex].quotedPrice << endl;
}




int main () {
	// Seed the random number generator
	srand(time(nullptr));

	// Business cards for 5 different companies
	// The quoted price is randomly generated between 1000 and 5000
	// We use the constructor of the BusinessCard structure to create each business card with different information for each company
	BusinessCard company1("Tech Solutions", "123 Tech Street", 1234567890, "9 AM - 5 PM", "Alice Johnson", 1000 + rand() % 4000 + 1);
	BusinessCard company2("Creative Designs", "456 Design Avenue", 9876543210, "10 AM - 6 PM", "Bob Smith", 1000 + rand() % 4000 + 1);
	BusinessCard company3("Green Energy", "789 Green Road", 5555555555, "8 AM - 4 PM", "Charlie Brown", 1000 + rand() % 4000 + 1);
	BusinessCard company4("Health Plus", "321 Health Blvd", 1112223333, "7 AM - 3 PM", "Diana Prince", 1000 + rand() % 4000 + 1);
	BusinessCard company5("Finance Experts", "654 Finance Lane", 4443332222, "9 AM - 5 PM", "Edward Norton", 1000 + rand() % 4000 + 1);

	// Size of the business cards array
	const int SIZE = 5;
	// I create an array of BusinessCard structures and initialize it with the 5 business cards created above
	// I didn't make this an array of pointers to BusinessCard structures because I wanted to keep it simple and straightforward
	// It'll make the logic inside the printCheapest function easier to understand and implement
	// My reasoning for this was just that we don't have that many business cards to manage and we won't need to actually modify the business cards directly
	BusinessCard cards[SIZE] = { company1, company2, company3, company4, company5 };

	// Here I call a function that will loop through the business cards and print up all the inforation about the companies
	printCompanyInfo(cards, SIZE);

	// Here I call a function that will loop through the cards and find the company that offers the cheapest price and print its name and the price
	printCheapest(cards, SIZE);


	return 0;

}