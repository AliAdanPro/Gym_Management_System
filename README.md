# Gym_Management_System
The code is based on a simple Gym Management System in C++. It provides the 
functionalities to manage equipment records, like adding new equipment, displaying the 
existing records, cross referencing, updating and deleting of records. Here is the breakdown 
of its functionality:
# void addequipment():
• It will collect information about a new equipment item like ID, name, price and 
quantity from the user.
• It will validate the ID, name length and the price length. It will accept the user input 
for each field.
• It will append the entered equipment data into a file named “data.txt”.
# void dispequipments():
• This will read from “data.txt” file and will display all the equipment records in a 
tabular format
# void crossreference():
• It will help the user search for a specific equipment name within the existing 
records stored in “data.txt”.
• It will prompt the user to enter the name and checks if it exists in the records. If 
found, it will reveal the details; otherwise, it indicates that the equipment doesn’t 
exist in the records.
# void appendrecord():
• It will enable the user to update the quantity of a specific equipment by entering its 
ID.
• It will read from “data,txt” and will update the quantity of the specified equipment 
and will write the updated data into a new file named “data1.txt”.
• The original “data.txt” file is then replaced by “data1.txt”.
# void deleterecord():
• It will allow the user to delete a specific equipment record by providing its ID.
• It will read data from “data.txt” and will skip the record to be deleted. It will then 
write all the rest of data into a new file called “data1.txt”, and then replaces the 
original file with a new updated file.
# void choicedisplay():
• It will display a menu to choose from: add equipment, view records, cross-reference, 
update quantity, delete record or exit. 
• The user choice will be inputted and read by program and it will call the 
corresponding function
