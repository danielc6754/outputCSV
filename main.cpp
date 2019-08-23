#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;


// Function used to check if csv file exist before output to it
bool fileExist(const std::string& filename) {
	struct stat buf;

	return stat(filename.c_str(), &buf) == 0;
}

void dmgConStrCalc(int *arrConStr) {

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			int hp = 50;
			int hitcount = 1;

			// Set con and str
			int con = (j + 1);
			int str = ((i + 1) * 3 + 4);

			int dmg = con - str;
			if (dmg > 0)
				dmg = 0;

			arrConStr[j * 25 + i] = 15 + dmg;
		}
	}

	return;
}

int dodgeCritCalc(int luk) {
	return 0;
}

int main() {
	
	string name = "damageCalc.csv";

	// Only run data function if file exists
	if (fileExist(name)) {

		// Create holding data
		int arrConStr[625];

		// Generate data
		dmgConStrCalc(arrConStr);
		
		// Output data
		ofstream myfile;
		myfile.open(name);

		// Constitution and Strength Relation
		myfile << "CON \\ STR";
		for (int i = 1; i < 26; i++)
			myfile << "," << i;

		int conValue = 1;
		myfile << "\n";

		for (int i = 0; i < 625; i++) {
			if (i % 25 == 0) {
				myfile << conValue;
				conValue++;
			}

			myfile << "," << arrConStr[i];

			if ((i + 1) % 25 == 0)
				myfile << "\n";
		}


		myfile.close();
	}

	else {
		printf("Error");
	}

	return 0;
}