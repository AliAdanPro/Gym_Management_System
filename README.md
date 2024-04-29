# Gym_Management_System Part 1
The code is based on a simple Gym Management System in C++. It provides the 
functionalities to manage equipment records, like adding new equipment, displaying the 
existing records, cross referencing, updating and deleting of records. This is the first part. Here is the breakdown 
of its functionality:
## void addequipment():
+ It will collect information about a new equipment item like ID, name, price and 
quantity from the user.
+ It will validate the ID, name length and the price length. It will accept the user input 
for each field.
+ It will append the entered equipment data into a file named “data.txt”.
## void dispequipments():
+ This will read from “data.txt” file and will display all the equipment records in a 
tabular format
## void crossreference():
+ It will help the user search for a specific equipment name within the existing 
records stored in “data.txt”.
+ It will prompt the user to enter the name and checks if it exists in the records. If 
found, it will reveal the details; otherwise, it indicates that the equipment doesn’t 
exist in the records.
## void appendrecord():
+ It will enable the user to update the quantity of a specific equipment by entering its 
ID.
+ It will read from “data,txt” and will update the quantity of the specified equipment 
and will write the updated data into a new file named “data1.txt”.
+ The original “data.txt” file is then replaced by “data1.txt”.
## void deleterecord():
+ It will allow the user to delete a specific equipment record by providing its ID.
+ It will read data from “data.txt” and will skip the record to be deleted. It will then 
write all the rest of data into a new file called “data1.txt”, and then replaces the 
original file with a new updated file.
## void choicedisplay():
+ It will display a menu to choose from: add equipment, view records, cross-reference, 
update quantity, delete record or exit. 
+ The user choice will be inputted and read by program and it will call the 
corresponding function.
# Gym_Management_System Part 2
This code is on Gym branch management system. In project task 1, we made the gym management system. This is an extension to that. This is a code that handles all the branch details. It is able to add a branch, view existing records of a branch, checks whether a specific branch is in records or not, can update the number of members in a specific branch and can delete a branch record in its entirety. It stores the branch data in a file called branch data.txt and loads it from the file respectively. Here is a explanation of each function in this code:
## addbranch function:
### + Purpose: 
Adds a new branch to the system.
### +	Parameters: 
+	Int(*arr)[columns]: Pointer to an array with 4 columns representing branch details.
+	Int rows: Number of rows in the array.
### +	Functionality: 
+	It iterates through rows and checks for an empty branch.
+ If an empty branch is found, it will prompt the user for branch number, registration, capacity and current members and will store the details.
## storedata Function:
### +	Purpose: 
Stores the array data in a file named “branchdata.txt”.
### +	Parameters:
+ Int(*arr)[columns]: Pointer to an array with 4 columns representing branch details.
+	Int rows: Number of rows in the array.
### +	Functionality: 
+	Writes the branch details from array to a file in a formatted manner.
## loaddata Function:
### +	Purpose: 
Loads data from the “branchdata.txt” file into the array.
### +	Parameters:
+	Int(*arr)[columns]: Pointer to an array with 4 columns representing branch details.
+	Int rows: Number of rows in the array.
### +	Functionality: 
+	Reads the branch details from file and loads them into the array.
## choicedisplay, choicedisplay2, landingpage:
### +	Purpose: 
Display menus and handle user choices for different functionalities.
### +	Functionality:
+	choicedisplay: Displays options for gym equipment management system
+	choicedisplay2: Displays options for gym branch management system.
+	landingpage: Main landing page to choose between equipment and branch management systems or exit. 
## main Function:
### +	Functionality: 
+	Calls loaddata to load existing branch data into the array.
+	Runs an infinite loop presenting options to the user through landingpage.



