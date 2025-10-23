#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string name;
    int age;
    string contactNo;
    string docAssigned;
    string appointmentDate;
    string appointmentTime;

public:
    Patient(string n = "Unknown", int a = 0, string contact = "N/A")
        : name(n), age(a), contactNo(contact), docAssigned("None"), appointmentDate("Not Scheduled"), appointmentTime("Not Scheduled") {}

    void scheduleAppointment(string doctor, string date, string Time) {
        docAssigned = doctor;
        appointmentDate = date;
        appointmentTime = Time;
        cout << "Appointment scheduled with Dr." << docAssigned << " on " << appointmentDate << " at " << appointmentTime << endl;
    }

    virtual void display(){
        cout<<"-------------------------------------------\n";
        cout<<"PATIENT'S DETAILS\n";
        cout<<"Name: " << name << endl;
        cout<<"Age: " << age << endl;
        cout<<"Contact Number: " << contactNo << endl;
        cout<<"Doctor Assigned: " << docAssigned << endl;
        cout<<"Appointment Date: " << appointmentDate << endl;
        cout<<"Appointment Time: " << appointmentTime << endl;
        cout<<"-------------------------------------------\n";
    }

    string getName() const { 
        return name; 
        
    }
    string getDocAssigned() const {
        return docAssigned; 
        
    }
    string getAppointmentDate() const {
        return appointmentDate; 
        
    }
    string getAppointmentTime() const {
        return appointmentTime; 
        
    }
};

class SpecialPatient : public Patient {
private:
    string medicalCondition;

public:
    SpecialPatient(string n, int a, string condition, string contact)
        : Patient(n, a, contact), medicalCondition(condition) {}

    void display()override {
        Patient::display();
        cout << "Medical Condition: " << medicalCondition << endl;
    }
};

class Clinic {
private:
    static const int MAX_PATIENTS = 100;
    Patient* patients[MAX_PATIENTS];
    int totalPatients;

public:
    Clinic() : totalPatients(0) {}

    void addPatient() {
        if (totalPatients >= MAX_PATIENTS) {
            cout << "Clinic is full. Cannot add more patients.\n";
            return;
        }

        string name, contact, condition;
        int age, type;
        cout << "Enter Patient Type (1. REGULAR 2. SPECIAL): ";
        cin>>type;
        cin.ignore(); // Ignore remaining newline character
        cout<<"Enter Patient Name: ";
        getline(cin,name);
        cout<<"Enter Age: ";
        cin>>age;
        cin.ignore();
        cout<<"Enter Contact Number: ";
        getline(cin, contact);

        if (type == 1) {
            patients[totalPatients] = new Patient(name, age, contact);
        } else if (type == 2) {
            cout << "Enter the condition: ";
            getline(cin, condition);
            patients[totalPatients] = new SpecialPatient(name, age, condition, contact);
        }

        totalPatients++;
        cout << "Patient Added Successfully!\n";
    }

    bool checkConflictingAppointment(string doctor, string date, string Time) {
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i]->getDocAssigned() == doctor &&
                patients[i]->getAppointmentDate() == date &&
                patients[i]->getAppointmentTime() == Time) {
                return true; // Conflict found
            }
        }
        return false; // No conflict
    }

    void scheduleAppointment() {
        string name, doctor, date, Time;
        cout << "Enter patient name: ";
        getline(cin, name);
        cout << "Enter doctor name: ";
        getline(cin, doctor);
        cout << "Enter appointment date (dd/mm/yy):";
        getline(cin, date);
        cout << "Enter appointment time (hh:mm): ";
        getline(cin, Time);

        if (checkConflictingAppointment(doctor, date, Time)) {
            cout << "Conflict: Doctor " << doctor << " already has an appointment on " << date << " at " << Time << endl;
            return;
        }
        bool patientfound=false;
        for (int i = 0; i < totalPatients; i++) {
            if (patients[i]->getName() == name) {
                patientfound=true;
                patients[i]->scheduleAppointment(doctor, date, Time);
                return;
            }
        }
        if(patientfound==false){
        cout << "Patient not found.\n";
    }
    }

    void viewPatientDetails() {
        string name;
        cout << "Enter patient name: ";
        getline(cin, name);

        for (int i = 0; i < totalPatients; i++) {
            if (patients[i]->getName() == name) {
                patients[i]->display();
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    void listAllPatients() const {
        cout << "Listing All Patients\n";
        if (totalPatients == 0) {
            cout << "No Patients Registered\n";
            return;
        }

        for (int i = 0; i < totalPatients; i++) {
            cout << "-" << patients[i]->getName() << endl;
        }
    }
};

int main() {
    Clinic clinic;
    int choice;
    do {
        cout << "\nClinic Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Schedule Appointment\n";
        cout << "3. View Patient Details\n";
        cout << "4. List All Patients\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the leftover newline after choice

        switch (choice) {
            case 1:
                clinic.addPatient();
                break;
            case 2:
                clinic.scheduleAppointment();
                break;
            case 3:
                clinic.viewPatientDetails();
                break;
            case 4:
                clinic.listAllPatients();
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}