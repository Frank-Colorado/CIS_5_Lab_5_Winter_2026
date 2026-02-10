#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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



	return 0;

}