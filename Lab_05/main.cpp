#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

// Structure for a company's business card
struct BusinessCard {
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

int main () {
	// Seed the random number generator
	srand(time(nullptr));

	// Business cards for 5 different companies
	// The quoted price is randomly generated between 1000 and 5000
	BusinessCard company1("Tech Solutions", "123 Tech Street", 1234567890, "9 AM - 5 PM", "Alice Johnson", 1000 + rand() % 4000 + 1);
	BusinessCard company2("Creative Designs", "456 Design Avenue", 9876543210, "10 AM - 6 PM", "Bob Smith", 1000 + rand() % 4000 + 1);
	BusinessCard company3("Green Energy", "789 Green Road", 5555555555, "8 AM - 4 PM", "Charlie Brown", 1000 + rand() % 4000 + 1);
	BusinessCard company4("Health Plus", "321 Health Blvd", 1112223333, "7 AM - 3 PM", "Diana Prince", 1000 + rand() % 4000 + 1);
	BusinessCard company5("Finance Experts", "654 Finance Lane", 4443332222, "9 AM - 5 PM", "Edward Norton", 1000 + rand() % 4000 + 1);




	return 0;

}