#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	//creating a csv file reader
	ifstream file;

	//creating a file writer
	ofstream fileout;

	//opening file using reader
	file.open("name_of_file.csv");

	//checking whether file is opened sucessfully
	if (file.fail()) {
		cout << "The file that is being opened does not exist." << endl;
		system("pause");
		return -1;
	}

	//creating a string to read file into
	string str;
	vector<string> fileread;

	while (!file.eof()) {
		getline(file, str, '\n');
		fileread.push_back(str);
	}

  //initializing the variable for creating dynamic file names
	int x = 0;
  
  //creating a path where the new workbooks will be stored
	string path = "E:\\workbooks\\";
	string path2 = ".csv"; // or .txt , whatever format is required
	string final;
  
  //loop to write data of vector into separate files
	while (x != fileread.size() - 1) {

    //creating a file name
		final = path + to_string(x) + path2;
		fileout.open(final);

		fileout << fileread[x];
		fileout.close();
		x++;
	}

	system("pause");
}
