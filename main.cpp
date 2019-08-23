#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;


// Function used to check if csv file exist before output to it
bool fileExist(const std::string& filename) {
	struct stat buf;

	return stat(filename.c_str(), &buf) == 0;
}

int main() {
	
	string name = "damageCalc.csv";

	// Only run data function if file exists
	if (fileExist(name)) {

		// Create some data points


		ofstream myfile;
		myfile.open(name);

		myfile << "STR, CON, ";

		// Generate data here
		for (int i = 1; i < 101; i++) {
			myfile << i << ",";
		}

		myfile << "\n";

		for (int con = 0; con < 101; con++) {
			myfile << "," << con << ",";
			for (int str = 1; str < 101; str++) {
				int dmg = con - str;
				if (dmg > 0)
					dmg = 0;

				myfile << dmg << ",";
			}

			myfile << "\n";
		}

		myfile.close();
	}

	else {
		printf("Error");
	}

	return 0;
}