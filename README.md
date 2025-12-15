# Contact-Management-System
The Contact Management System is a menu-driven console application written in C language. It uses structures and file handling to store contact information permanently in a text file. The program provides functionalities to add new contacts, display all contacts, search contacts by name, update existing contact details, and delete contacts.

# FEATURES
- Add a new contact
- View all saved contacts
- Search a contact by name
- Update existing contact details
- Delete a contact
- Data is stored permanently using file handling

# TECHNOLOGIES USED

Programming Language: C
Compiler / IDE: Dev-C++

Concepts Used: - Structures
               - Functions

File Handling (fopen, fprintf, fgets, remove, rename)
String Handling (strcmp, sscanf)

# PROJECT STRUCTURE

Contact_Management_System
-- contact_management.c (Main source code)
-- contacts.txt (Stores contact data – auto created)
-- README.txt / README.md (Project documentation)

# HOW TO RUN THE PROGRAM 
- Open any Compiler
- Open the file contact_management.c
- Compile and Run the program (Press F11)
- Choose an option from the menu
- Enter details as asked

# CONTACT FILE FORMAT

Each contact is stored in the following format:
- Name|Phone_Number|Email
- Example:
  Rahul|9876543210|rahul@gmail.com

# CONCEPTS COVERED
- Structure declaration and usage
- File handling in C
- Menu-driven program
- Modular programming using functions
- Basic string manipulation

# FUTURE IMPROVEMENTS
- Allow names with spaces
- Add password protection
- Sort contacts alphabetically
- Continuous menu loop
- Convert text file to binary file
