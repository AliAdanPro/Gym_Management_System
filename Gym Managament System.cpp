#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int columns = 4;
const int rows = 10;
int arr[rows][columns] = { 0 };

void addequipment() {
	//Declare Variables to store equipment information.
	int id;
	string name, Quantity, Price;
	//Open/Create file data.txt in append mode
	ofstream fout;
	fout.open("data.txt", ios::app);
	//Prompt use to enter ID
	cout << "Enter equipment ID: ";
	//Validate ID entry
	do {
		cin >> id;
		if (id > 99 || id < 01) {
			cout << "Invalid ID format try again: ";
		}
	} while (id < 01 || id>99);
	//Prompt use to enter Name
	cout << "Enter equipment name: ";
	//Validate Name entry
	do {
		cin >> name;
		if (name.length() > 7)
			cout << "Name is too long please abbreviate or shorten: ";
	} while (name.length() > 7);
	//Prompt user to enter Price
	cout << "Enter Price: ";
	//Validate Price entry
	do {
		cin >> Price;
		if (Price.length() > 7)
			cout << "Price is too long please abbreviate or shorten: ";
	} while (Price.length() > 7);
	//Prompt user to enter Quantity
	cout << "Enter Quantity: ";
	//Read Quantity
	cin >> Quantity;
	//Print new line for formatting
	cout << endl;
	//Write user data to file
	fout << id << " " << name << " " << Price << " " << Quantity << endl;
	//Close file
	fout.close();
}

void dispequipments() {
	ifstream fin;
	//Exception handling for file managment
	try {
		//Open file data.txt to read user data
		fin.open("data.txt");
		if (fin.fail()) {
			throw runtime_error("File could not be opened");
		}
	}
	catch (runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		exit(1);
	}
	//Initialize variables to read data from file to
	int id;
	string name, Price, Quantity;
	//Generate table
	cout << "ID\tName\tPrice\tQuantity\n" << endl;
	//Read and display a single record from file in each loop
	while (fin >> id >> name >> Price >> Quantity) {
		cout << id << "\t" << name << "\t" << Price << "\t" << Quantity << endl;
	}
	//Print new line for formatting
	cout << endl;
	//Close file data.txt
	fin.close();
}

void crossrefrence() {
	//Initialize a flag to hold if entered name exists in database
	bool namestatus = false;
	//Initialize variables to read data from file to
	string checkname, name, Price, Quantity;
	int id;
	//Prompt use to enter name to chek in database
	cout << "Enter the name you want to cross-refrence: ";
	//Read User entered name
	cin >> checkname;
	//Print line for formatting
	cout << endl;
	//Open file data.txt to read User data from
	ifstream fin;
	//Exception handling for file managment
	try {
		//Open file data.txt to read user data
		fin.open("data.txt");
		if (fin.fail()) {
			throw runtime_error("File could not be opened");
		}
	}
	catch (runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		exit(2);
	}
	//Use while loop to read one record at a time
	while (fin >> id >> name >> Price >> Quantity) {
		//Check for and display if entered name is present in file
		if (name == checkname) {
			cout << "ID\tName\tPrice\tQuantity\n" << endl;
			cout << id << "\t" << name << "\t" << Price << "\t" << Quantity << endl;
			cout << endl;
			namestatus = true;
			break;
		}
		else {
			namestatus = false;

		}
	}
	//Display if name does not exist, cannot be placed in loop since it would print again and again.
	if (namestatus == false) {
		cout << "Status: This Equipment does not exist in records." << endl;
		//Print line for formatting
		cout << endl;
	}
	//Close file data.txt
	fin.close();
}

void appendrecord() {
	//Initialize variables to store data read from file and the data of record to be appended.
	int id, idnew, idapp;
	string name, Price, Quantity, namenew, Pricenew, Quantitynew;
	//Prompt user to enter id of record to be appended
	cout << "Enter ID of equipment whose Quantity you want to update: ";
	//Read ID entered
	cin >> idapp;
	//Open file data.txt to read user data from
	ifstream fin;
	//Exception handling for file managment
	try {
		//Open file data.txt to read user data
		fin.open("data.txt");
		if (fin.fail()) {
			throw runtime_error("File could not be opened");
		}
	}
	catch (runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		exit(3);
	}
	//Open/Create data1.txt to write updated user data to
	ofstream fout;
	fout.open("data1.txt");
	//Read one whole record every loop from data.txt
	while (fin >> id >> name >> Price >> Quantity) {
		//If entered id and current id in loop match store record info to be printed later
		if (id == idapp) {
			idnew = id;
			namenew = name;
			Pricenew = Price;
			continue;
		}
		//Else write record to new file data1.txt
		else {
			fout << id << " " << name << " " << Price << " " << Quantity << endl;;
		}

	}
	//Prompt user to enter updated Quantity for ID previously selected
	cout << "Enter updated Quantity: ";
	//Read Quantity to be updated
	cin >> Quantitynew;
	//Print line for formatting
	cout << endl;
	//Now write previously withheld record along with updated Quantity
	fout << idnew << " " << namenew << " " << Pricenew << " " << Quantitynew << endl;
	//Close data.txt
	fin.close();
	//Close data1.txt
	fout.close();

	//Outdated file data.txt is deleted
	remove("data.txt");
	//Updated file data1.txt is named to data.txt so that it is opened in the next iteration of program
	rename("data1.txt", "data.txt");
}

void deleterecord() {
	//Initialize variable to store user data read from file along with id of record to be deleted
	int iddel, id;
	string name, Price, Quantity;
	//Prompt user to endter id of record to be deleted
	cout << "Enter ID of equipment you want to remove from database: ";
	//Read entered id
	cin >> iddel;
	//Print line for formatting
	cout << endl;
	//Open data.txt to read user data from
	ifstream fin;
	//Exception handling for file managment
	try {
		//Open file data.txt to read user data
		fin.open("data.txt");
		if (fin.fail()) {
			throw runtime_error("File could not be opened");
		}
	}
	catch (runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		exit(4);
	}
	//Open/Create data1.txt to write updated user data to
	ofstream fout;
	fout.open("data1.txt");
	//Read user data from data.txt one record at a time
	while (fin >> id >> name >> Price >> Quantity) {
		//Dont write to new file if entered id matches record in loop
		if (id == iddel) {
			continue;
		}
		//Otherwise write data to updated file
		else {
			fout << id << " " << name << " " << Price << " " << Quantity << endl;;
		}
	}
	//Close data.txt
	fin.close();
	//Close data1.txt
	fout.close();

	//Outdated file data.txt is deleted
	remove("data.txt");
	//Updated file data1.txt is named to data.txt so that it is opened in the next iteration of program
	rename("data1.txt", "data.txt");
}

//Define a function addbranch that will take a pointer to an array of integers with 4 columns and an integer that represents the rows
void addbranch(int(*arr)[columns], int rows) {
	//Loop through rows
	for (int i = 0; i < rows; i++) {
		if (arr[i][0] == 0) { //Checks if the first element in the row is a 0
			cout << "Enter branch # : "; //Prompt for branch number
			cin >> arr[i][0]; //Read the branch number
			cout << "Enter branch reg# : "; //Prompt for the branch registration
			cin >> arr[i][1]; //Read the branch registation
			cout << "Enter branch maximum capacity : "; //Prompt for the max capacity
			cin >> arr[i][2]; //Read max capacity
			cout << "Enter branch current members : "; //Prompt for the current members
			cin >> arr[i][3]; //Read current members
			break; //Exit loop
		}
	}
	cout << endl; //Print Newline
}
//Function to view the content of the array
void viewarr(int(*arr)[columns], int row) {
	cout << left << setw(15) << "Branch#" << left << setw(15) << "BranchReg#" << left << setw(15) << "BranchCap" << left << setw(15) << "BranchMembers" << endl; //Display headings
	cout << endl; //Print a newline
	for (int i = 0; i < row; i++) { //Loop through rows
		if (arr[i][0] != 0) { //Check if the first element in the row is not 0
			cout << left << setw(15) << arr[i][0] << left << setw(15) << arr[i][1] << left << setw(15) << arr[i][2] << left << setw(15) << arr[i][3] << endl;
		}
		else {
			break; //Exit loop if the element in the row is a 0
		}
	}
	cout << endl; // Print a new line
}
//Function to check and display the branch details
void checkbranch(int(*arr)[columns], int row) {
	int branch; //Declare the branch variable
	bool checkstatus = false; //Flag to check the branch status
	cout << "Enter to branch # to crossrefrence : "; //Prompt for branch number to search
	cin >> branch; //Read branch number
	cout << endl; //Print new line
	for (int i = 0; i < row; i++) { //Loop through rows
		if (arr[i][0] == branch) { //Check if the first element in the row matches entered branch number
			cout << left << setw(15) << "Branch#" << left << setw(15) << "BranchReg#" << left << setw(15) << "BranchCap" << left << setw(15) << "BranchMembers" << endl; //Display headings
			cout << endl; //Print new line
			cout << left << setw(15) << arr[i][0] << left << setw(15) << arr[i][1] << left << setw(15) << arr[i][2] << left << setw(15) << arr[i][3] << endl; //Display the branch details
			checkstatus = true;//Set check status to true if branch is found
			break; //Exit loop
		}
		else { //If the if statement is not true, then else will work
			checkstatus = false; //Set check status to false
		}
	}
	if (checkstatus == false) { //If branch not found
		cout << "Branch does not exist in database!" << endl; //Display error message
	}
	cout << endl; //Print new line
}
//Function to update branch members
void updatemembers(int(*arr)[columns], int row) {
	int branch; //Declare branch variable
	bool checkexist = false; //Flag to check branch existance
	cout << "Enter branch# whose members to update : "; //Prompt for branch number to update
	cin >> branch; //Read branch number
	for (int i = 0; i < row; i++) { //loop through rows
		if (arr[i][0] == branch) {//Check if the first element in the row matches the entered branch number
			cout << "Enter new member count : "; //Prompt for new member count
			cin >> arr[i][3]; //Update member count in array
			checkexist = true; //Set checkexist to true if the branch has been found
			break;//Exit loop
		}
		else {//If the if statement is not true, then else will work
			checkexist = false; //Set checkexist to false if branch not found
		}
	}
	if (checkexist == false) { //If branch not found
		cout << "Branch does not exist in database!" << endl; //Display error message
	}
	cout << endl; //Print new line
}

//Function to delete a record
void deletebranch(int(*arr)[columns], int row) {
	int branch; //Initialize variable of record to remove
	cout << "Enter branch you want to remove : ";
	cin >> branch; //Read branch
	cout << endl;
	//Loop that runs till branch to be removed is found
	for (int i = 0; i < row; i++) {
		if (arr[i][0] == branch) { //Check for branch to be deleted
			for (int j = i; j < row; j++) { //Loop to replace current record with next one and keep doing this for rest of array
				arr[j][0] = arr[j + 1][0]; //Replacing current Branch# with next one
				arr[j][1] = arr[j + 1][1]; //Replacing current BranchReg# with next one
				arr[j][2] = arr[j + 1][2]; //Replacing current BranchCap with next one
				arr[j][3] = arr[j + 1][3]; //Replacing current BranchMembers with next one
			}
			break; //Stop outer loop once branch to be removed is found and replaced.
		}
	}
}

//Function to store array data in a file
void storedata(int(*arr)[columns], int row) {
	ofstream fout; //Declare ofstream
	fout.open("branchdata.txt"); //Opening the file
	for (int i = 0; i < row; i++) {//Loop through rows
		fout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << endl; //Write branch details to the file
	}
	fout.close();//Close the file
}
//Function to load data from file into the array
void loaddata(int(*arr)[columns], int row) {
	ifstream fin; //Declare ifstream
	fin.open("branchdata.txt"); //Open file to be read
	for (int i = 0; i < row; i++) { //Loop through rows
		fin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3]; //Read branch details from file into array
	}
	fin.close(); //Close the file
}



//Declare functions choiceddisplay, landingpage and choiced display 2
void choicedisplay();

void landingpage();

void choicedisplay2();
//Main function
int main() {
	loaddata(arr, rows); //Load data into the array
	//Program runs till exited
	while (true) { //Continuous loop
		landingpage(); //Call landing page function



	}
}

void choicedisplay() {
	//Initialize variable to store user function choice
	char choice;
	cout << "GYM EQUIPMENT MANAGEMENT SYSTEM! \n";
	//Prompt user to enter which funtion to use
	cout << "Press 1. To add new equipment. \nPress 2. To view existing records. \nPress 3. To crossrefrence. \nPress 4. To Update Quantity. \nPress 5. To Delete a Record. \nPress 6. To go back. \n";
	cout << "Enter choice: ";
	//Read entered choice
	cin >> choice;
	//Print line for formatting
	cout << endl;
	//Use switch to call funtion based on choice entered from menu
	switch (choice) {
	case '1':
		//Call addequipment function to add new equipment
		addequipment();
		break;
	case '2':
		//Call dispequipments function to show all records in file
		dispequipments();
		break;
	case '3':
		//Call crossrefrence function to check if a name exists in file
		crossrefrence();
		break;
	case '4':
		//Call appendrecord function to updates an entity in a record
		appendrecord();
		break;
	case '5':
		//Call deleterecord function to delete a record
		deleterecord();
		break;
	case '6':
		//Stop program
		cout << "DATABASE CLOSED!";
		cout << endl;
		landingpage();
	default:
		//Default for any other choice entered
		cout << "Invalid Choice! \n";
		//Print line for formatting
		cout << endl;

	}
}
//Function to display options for the gym branch management system
void choicedisplay2() {
	char choice; //Declare choice
	cout << "GYM BRANCH MANAGEMENT SYSTEM! \n"; //Display title
	cout << "Press 1. To add new branch. \nPress 2. To view existing records. \nPress 3. To crossrefrence. \nPress 4. To Update Quantity. \nPress 5. To delete a record. \nPress 6. To go back. \n"; //Display options
	cout << "Enter choice: ";
	cin >> choice; //Reading Choice
	cout << endl; //Print Newline
	//Switch statement based on user's choice
	switch (choice) {
	case '1': //Runs if user presses 1
		addbranch(arr, rows); //Calling function for adding new branch
		break; //stops
	case '2': //Runs if user presses 2
		viewarr(arr, rows); //Call function to view the existing records
		break; //stops
	case '3': //Runs if user presses 3
		checkbranch(arr, rows); //Call function to cross-reference
		break; //Stops
	case '4': //Runs if user presses 4
		updatemembers(arr, rows); //Call function to update quantity
		break; //Stops
	case '5':
		deletebranch(arr, 5);
		break;
	case '6': //Runs if user presses 5
		storedata(arr, rows); //Call function to store data
		cout << "DATABASE CLOSED!" << endl; //Display Message
		cout << endl; //Print newline
		landingpage(); //Go back to the landing page
	default: //Runs if user prompts other than numbers 1 to 5
		cout << "Invalid Choice! \n"; //Display message for invalid choice
		cout << endl; //Print newline

	}
}
//Function for the landing page
void landingpage() {
	char option; //Declare option
	cout << "Press 1. To open Gym equipment mangment system. \nPress 2. To open Gym branch managment system.\nPress 3. To exit.\n"; //Display options
	cout << "Enter choice : "; //Display "Enter choice"
	cin >> option; //Read option
	cout << endl; //Print new line
	switch (option) { //Using switch for multiple options
	case '1': //Runs if user inputs 1
		while (true) { //Continuous loop
			choicedisplay(); //Calls choicedisplay

		}
	case '2'://Runs if user inputs 2
		while (true) { //Continuous loop
			choicedisplay2(); //Calls choicedisplay2

		}
	case '3'://Runs if user inputs 3
		cout << "PROGRAM CLOSED!"; //Display program closure
		exit(0); //Exiting the program
	}
}

