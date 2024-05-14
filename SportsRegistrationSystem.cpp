#include <iostream>
using namespace std;
// Function prototypes
void registerStudent(int ids[], string sports[], int& numStudents);
void viewStudentRecord(int id, int ids[], string sports[], int size);
void viewAllRecords(int ids[], string sports[], int numStudents);
void updateSport(int ids[], string sports[], int numStudents);
void deleteRecord(int ids[], string sports[], int& numStudents);
void searchStudent(int ids[], string sports[], int numStudents);
int main() {
	int ids[50];
	string sports[50];
	int numStudents = 0;
	int choice;
	// MENU
	do {
		cout << "\n \t *** STUDENT SPORTS REGISTRATION SYSTEM *** \n";
		cout << "\n \t 1. Register student";
		cout << "\n \t 2. View student record";
		cout << "\n \t 3. View all records";
		cout << "\n \t 4. Update student's sport";
		cout << "\n \t 5. Delete student record";
		cout << "\n \t 6. Search student";
		cout << "\n \t 7. Exit";
		cout << "\n \n \t Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			registerStudent(ids, sports, numStudents);
			cout << "\n \n";
			break;
		case 2:
			int id;
			cout << "\n Enter student ID: ";
			cin >> id;
			viewStudentRecord(id, ids, sports, numStudents);
			cout << "\n \n";
			break;
		case 3:
			viewAllRecords(ids, sports, numStudents);
			cout << "\n \n";
			break;
		case 4:
			updateSport(ids, sports, numStudents);
			cout << "\n \n";
			break;
		case 5:
			deleteRecord(ids, sports, numStudents);
			break;
		case 6:
			searchStudent(ids, sports, numStudents);
			cout << "\n \n";
			break;
		case 7:
			cout << "\n Exiting program...";
			cout << "\n \n";
			break;
		default:
			cout << "\n Invalid choice! Please try again.";
		}
	} while (choice != 7);
	return 0;
}
// Student registration function 
void registerStudent(int ids[], string sports[], int& numStudents) {
	int id;
	bool eligible = true;
	cout << "\nEnter student ID: ";
	cin >> id;
	// check if student is eligible to register
	int age;
	cout << "Enter student's age: ";
	cin >> age;
	if (age > 25) {
		cout << "Sorry, students above 25 years are not eligible to register." << endl;
		eligible = false;
	}
	char ta;
	cout << "Is the student also working as a teaching assistant (Y/N)? ";
	cin >> ta;
	if (ta == 'Y' || ta == 'y') {
		cout << "Sorry, teaching assistants are not eligible to register.";
		eligible = false;
	}
	if (eligible) {
		// check if student is already registered
		bool alreadyRegistered = false;
		for (int i = 0; i < numStudents; i++) {
			if (ids[i] == id) {
				cout << "Student is already registered for " << sports[i];
				alreadyRegistered = true;
				break;
			}
		}
		// if not already registered, allow registration
		if (!alreadyRegistered) {
			cout << "Enter student's sport (Cricket/Football/Hockey): ";
			string sport;
			cin >> sport;
			ids[numStudents] = id;
			sports[numStudents] = sport;
			numStudents++;
			cout << "Registration successful!";
		}
	}
}
// View student record function 
void viewStudentRecord(int id, int ids[], string sports[], int size) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (ids[i] == id) {
			cout << "Student ID: " << ids[i] << endl;
			cout << "Sport: " << sports[i] << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Student not found!" << endl;
	}
}
void viewAllRecords(int ids[], string sports[], int count) {
	cout << "All student records:" << endl;
	for (int i = 0; i < count; i++) {
		cout << "Student ID: " << ids[i] << ", Sport: " << sports[i] << endl;
	}
}
// Update a student's sport
void updateSport(int ids[], string sports[], int numStudents) {
	int id, index;
	string newSport;
	// Prompt user for student ID and new sport
	cout << "Enter student ID: ";
	cin >> id;
	cout << "Enter new sport: ";
	cin >> newSport;
	// Find index of student with given ID
	for (int i = 0; i < numStudents; i++) {
		if (ids[i] == id) {
			index = i;
			break;
		}
	}
	// Update sport if student is found
	if (index >= 0) {
		sports[index] = newSport;
		cout << "Sport updated successfully!\n";
	}
	else {
		cout << "Student not found!\n";
	}
}
// Delete a student record
void deleteRecord(int ids[], string sports[], int& numStudents) {
	int id, index = -1;
	// Prompt user for student ID
	cout << "Enter student ID: ";
	cin >> id;
	// Find index of student with given ID
	for (int i = 0; i < numStudents; i++) {
		if (ids[i] == id) {
			index = i;
			break;
		}
	}
	// Delete record if student is found
	if (index >= 0) {
		for (int i = index; i < numStudents - 1; i++) {
			ids[i] = ids[i + 1];
			sports[i] = sports[i + 1];
		}
		numStudents--;
		cout << "Record deleted successfully!";
	}
	else {
		cout << "Student not found!";
	}
}
// Search for a student
void searchStudent(int ids[], string sports[], int numStudents) {
	int id, index = -1; // initialize index to -1
	// Prompt user for student ID
	cout << "Enter student ID: ";
	cin >> id;
	// Find index of student with given ID
	for (int i = 0; i < numStudents; i++) {
		if (ids[i] == id) {
			index = i;
			break;
		}
	}
	// Display student's sport if found
	if (index >= 0) {
		cout << "Student found! Sport: " << sports[index];
	}
	else {
		cout << "Student not found!";
	}
}