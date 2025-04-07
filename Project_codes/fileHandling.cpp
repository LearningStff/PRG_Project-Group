#include <fstream>
#include <sstream>
#include <iostream>
#include "globals.h"
#include "department.h"
#include "product.h"
using namespace std;

int loadDataFromCsv(const char* filePath)
{
	ifstream file(filePath);
	if (!file.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	}
	string line;
	getline(file, line);// the first line is number of departments.
	TotalDepartments = stoi(line);
	StoreDepartments = new Department[TotalDepartments];
	for (int d = 0; d < TotalDepartments; d++)
	{
		getline(file, line);
		string depName;
		int pCount;

		stringstream ss(line);
		getline(ss, depName, ',');
		ss >> pCount;

		Product* P = new Product[pCount];

		for (int i = 0; i < pCount; i++)
		{
			getline(file, line);
			string pName;
			float pPrice;
			int pQuantity;

			stringstream ss(line);
			getline(ss, pName, ',');
			ss >> pPrice;
			ss.ignore();
			ss >> pQuantity;

			P[i].set(pName.c_str(), pPrice, pQuantity);
		}
		StoreDepartments[d].setDepartmentInfo(depName.c_str(), P, pCount);
	}
	file.close();
	return 0;
}

//Saves all changes made to the departments and their products
void saveChangesToCSV() {
	cout << "\n===== Save Changes to CSV =====" << endl;

	// Open file for writing
	FILE* file = fopen(csvFile, "w");

	//If the file couldn't be opened
	if (!file) {
		cerr << "Could not open file for writing.";
		return;
	}

	// Write the number of departments
	fprintf(file, "%d\n", TotalDepartments);

	// Write each department and its items
	for (int i = 0; i < TotalDepartments; i++) {
		Department& dept = StoreDepartments[i];

		// Write department info (name and item count)
		fprintf(file, "%s,%d\n", dept.displayDeptNames(), dept.getTotalProducts());

		// List all products and write to file
		for (int j = 0; j < dept.getTotalProducts(); j++) {
			Product product = dept.getProductAt(j);
			fprintf(file, "%s,%.2f,%d\n", product.getName(), product.getPrice(), product.getQuantity());
		}
	}

	fclose(file); // close the file
	cout << "Changes saved successfully." << endl;
}