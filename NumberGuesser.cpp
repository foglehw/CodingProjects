#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>

using namespace std;

void wait()
{
	cout << "Press ENTER to continue...\n";
	cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}

int main() {

	int max, min;

	string dummy;

	cout << "Enter the max number for me to guess: \n";

	cin >> max;

	cout << "Pick a number between 0 and " << max << ". Type go when you're ready.\n";

	cin >> dummy;

	min = 0;

	bool correct = false;

	string response;
	string higherOrLower;

	while (!correct) {
		cout << "Is your number " << (min + max) / 2 << "? Enter yes or no.\n";

		cin >> response;

		transform(response.begin(), response.end(), response.begin(), ::toupper);
		if(response.compare("NO") == 0) {
			cout << "Is the number higher or lower\n";
			cin >> higherOrLower;
			
			transform(higherOrLower.begin(), higherOrLower.end(), higherOrLower.begin(), ::toupper);

			if (higherOrLower.compare("HIGHER") == 0) {
				min = (min + max) / 2;
			}
			else if (higherOrLower.compare("LOWER") == 0) {
				max = (min + max) / 2;
			}
			else {
				cout << "Please enter only higher or lower.\n";
			}
		}
		else if (response.compare("YES") == 0) {
			cout << "I did it!";
			correct = true;
		}
		else {
			cout << "Please enter either yes or no.\n";
		}

	}

	return 0;
}
