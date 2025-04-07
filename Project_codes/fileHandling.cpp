#include <fstream>

extern Department* StoreDepartments = nullptr;
extern int TotalDepartments = 0;
extern const char* csvFile = "grocery.csv";

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
}