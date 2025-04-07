#pragma once
#include "department.h"
#include "product.h"

// Function to load data from the CSV file
int loadDataFromCsv(const char* filePath);

//Function to save all changes to the CSV file
void saveChangesToCSV();

