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
	
	if (fileExist("damageCalc.csv")) {
		printf("Found");
	}

	else {
		printf("Error");
	}
}