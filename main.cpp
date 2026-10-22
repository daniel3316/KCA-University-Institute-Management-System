#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <sstream> // Required for backward-compatible string conversions

using namespace std;

// Helper function to convert numeric types to string safely on older C++ standards
template <typename T>
string numberToString(T number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

// ============================================================================
// 1. CLASS DESIGN & ENCAPSULATION
// ============================================================================

class Person {
protected: 
    string idNumber;
    string fullName;
    string contactDetails;

public:
    Person() : idNumber("UNKNOWN"), fullName("UNKNOWN"), contactDetails("UNKNOWN") {}
    Person(string idNumber, string fullName, string contactDetails) {
        this->idNumber = idNumber;
        this->fullName = fullName;
        this->contactDetails = contactDetails;
    }
    virtual ~Person() {} 

    string getIdNumber() const { return idNumber; }
    string getFullName() const { return fullName; }
    string getContactDetails() const { return contactDetails; }

    void setIdNumber(string id) { this->idNumber = id; }
    void setFullName(string name) { this->fullName = name; }
    void setContactDetails(string contact) { this->contactDetails = contact; }

    virtual void displayDetails() const {
        cout << "ID Number: " << idNumber << " | Name: " << fullName 
             << " | Contact: " << contactDetails;
    }

    virtual string getRole() const { return "Person"; }
    virtual string toFileString() const {
        return idNumber + "," + fullName + "," + contactDetails;
    }
};

class Trainee : public Person {
private:
    string admissionNumber;
    string course;
    double assessmentMarks;

public:
    Trainee() : Person(), admissionNumber("UNKNOWN"), course("UNKNOWN"), assessmentMarks(0.0) {}
    Trainee(string id, string name, string contact, string admNum, string crs, double marks)
        : Person(id, name, contact), admissionNumber(admNum), course(crs) {
        setAssessmentMarks(marks);
    }

    string getAdmissionNumber() const { return admissionNumber; }
    string getCourse() const { return course; }
    double getAssessmentMarks() const { return assessmentMarks; }

    void setAdmissionNumber(string adm) { admissionNumber = adm; }
    void setCourse(string crs) { course = crs; }
    
    void setAssessmentMarks(double marks) {
        if (marks >= 0.0 && marks <= 100.0) {
            this->assessmentMarks = marks;
        } else {
            this->assessmentMarks = 0.0; 
            throw runtime_error("Validation Error: Marks must be between 0 and 100.");
        }
    }

    string getRole() const { return "Trainee"; }

    void displayDetails() const {
        Person::displayDetails();
        cout << " | AdmNo: " << admissionNumber << " | Course: " << course 
             << " | Marks: " << assessmentMarks << "%" << endl;
    }

    string toFileString() const {
        return Person::toFileString() + "," + admissionNumber + "," + course + "," + numberToString(assessmentMarks);
    }
};

class Trainer : public Person {
private:
    string employeeNumber;
    string specialization;
    int yearsOfExperience;

public:
    Trainer() : Person(), employeeNumber("UNKNOWN"), specialization("UNKNOWN"), yearsOfExperience(0) {}
    Trainer(string id, string name, string contact, string empNum, string spec, int exp)
        : Person(id, name, contact), employeeNumber(empNum), specialization(spec) {
        setYearsOfExperience(exp);
    }

    string getEmployeeNumber() const { return employeeNumber; }
    string getSpecialization() const { return specialization; }
    int getYearsOfExperience() const { return yearsOfExperience; }

    void setEmployeeNumber(string emp) { employeeNumber = emp; }
    void setSpecialization(string spec) { specialization = spec; }
    
    void setYearsOfExperience(int exp) {
        if (exp >= 0) {
            this->yearsOfExperience = exp;
        } else {
            this->yearsOfExperience = 0;
            throw runtime_error("Validation Error: Experience years cannot be negative.");
        }
    }

    string getRole() const { return "Trainer"; }

    void displayDetails() const {
        Person::displayDetails();
        cout << " | EmpNo: " << employeeNumber << " | Specialization: " << specialization 
             << " | Exp: " << yearsOfExperience << " years" << endl;
    }

    string toFileString() const {
        return Person::toFileString() + "," + employeeNumber + "," + specialization + "," + numberToString(yearsOfExperience);
    }
};

class TrainingProgramme {
private:
    string programmeCode;
    string programmeName;
    int durationWeeks;
    int maxEnrolment;

public:
    TrainingProgramme() : programmeCode("UNKNOWN"), programmeName("UNKNOWN"), durationWeeks(0), maxEnrolment(0) {}
    TrainingProgramme(string code, string name, int duration, int maxEnr) {
        this->programmeCode = code;
        this->programmeName = name;
        setDurationWeeks(duration);
        setMaxEnrolment(maxEnr);
    }

    string getProgrammeCode() const { return programmeCode; }
    string getProgrammeName() const { return programmeName; }
    int getDurationWeeks() const { return durationWeeks; }
    int getMaxEnrolment() const { return maxEnrolment; }

    void setDurationWeeks(int d) {
        if (d > 0) this->durationWeeks = d;
        else throw runtime_error("Validation Error: Duration must be greater than 0.");
    }
    void setMaxEnrolment(int m) {
        if (m > 0) this->maxEnrolment = m;
        else throw runtime_error("Validation Error: Max enrollment must be greater than 0.");
    }

    void display() const {
        cout << "Code: " << programmeCode << " | Name: " << programmeName 
             << " | Duration: " << durationWeeks << " weeks | Max Capacity: " << maxEnrolment << endl;
    }

    string toFileString() const {
        return programmeCode + "," + programmeName + "," + numberToString(durationWeeks) + "," + numberToString(maxEnrolment);
    }
};

class Equipment {
private:
    string equipmentID;
    string description;
    string condition;
    string maintenanceStatus;

public:
    Equipment() : equipmentID("UNKNOWN"), description("UNKNOWN"), condition("UNKNOWN"), maintenanceStatus("UNKNOWN") {}
    Equipment(string id, string desc, string cond, string status) 
        : equipmentID(id), description(desc), condition(cond), maintenanceStatus(status) {}

    string getEquipmentID() const { return equipmentID; }
    string getDescription() const { return description; }
    string getCondition() const { return condition; }
    string getMaintenanceStatus() const { return maintenanceStatus; }

    void setEquipmentID(string id) { equipmentID = id; }
    void setDescription(string d) { description = d; }
    void setCondition(string c) { condition = c; }
    void setMaintenanceStatus(string s) { maintenanceStatus = s; }

    bool operator==(const Equipment& other) const {
        return this->equipmentID == other.equipmentID;
    }

    void display() const {
        cout << "ID: " << equipmentID << " | Desc: " << description 
             << " | Cond: " << condition << " | Status: " << maintenanceStatus << endl;
    }

    string toFileString() const {
        return equipmentID + "," + description + "," + condition + "," + maintenanceStatus;
    }
};

class MaintenanceRecord {
private:
    string maintenanceDate;
    string equipmentID;
    string faultDescription;
    double repairCost;

public:
    MaintenanceRecord() : maintenanceDate("UNKNOWN"), equipmentID("UNKNOWN"), faultDescription("UNKNOWN"), repairCost(0.0) {}
    MaintenanceRecord(string date, string eqID, string fault, double cost) 
        : maintenanceDate(date), equipmentID(eqID), faultDescription(fault) {
        setRepairCost(cost);
    }

    string getMaintenanceDate() const { return maintenanceDate; }
    string getEquipmentID() const { return equipmentID; }
    string getFaultDescription() const { return faultDescription; }
    double getRepairCost() const { return repairCost; }

    void setRepairCost(double cost) {
        if (cost >= 0.0) this->repairCost = cost;
        else throw runtime_error("Validation Error: Repair cost cannot be negative.");
    }

    void display() const {
        cout << "Date: " << maintenanceDate << " | EquipID: " << equipmentID 
             << " | Fault: " << faultDescription << " | Cost: KES " << fixed << setprecision(2) << repairCost << endl;
    }

    string toFileString() const {
        return maintenanceDate + "," + equipmentID + "," + faultDescription + "," + numberToString(repairCost);
    }
};

// ============================================================================
// SYSTEM ENGINE (MANAGES FILE HANDLING, MEMORY, AND INTERFACE)
// ============================================================================

class InstituteManager {
private:
    vector<Person*> users; 
    vector<TrainingProgramme> programmes;
    vector<Equipment> inventory;
    vector<MaintenanceRecord> records;

    vector<string> splitCSV(const string& str) {
        vector<string> result;
        string cell = "";
        for (size_t i = 0; i < str.length(); ++i) {
            char c = str[i];
            if (c == ',') {
                result.push_back(cell);
                cell = "";
            } else {
                cell += c;
            }
        }
        result.push_back(cell);
        return result;
    }

    // Helper function to convert safe file strings back to numbers manually
    double stringToDouble(const string& s) {
        stringstream ss(s);
        double val;
        ss >> val;
        return val;
    }

    int stringToInt(const string& s) {
        stringstream ss(s);
        int val;
        ss >> val;
        return val;
    }

public:
    ~InstituteManager() {
for (size_t i = 0; i < users.size(); ++i) {
delete users[i];
}
users.clear();
}
void addUser(Person* p) {
users.push_back(p);
}
void addProgramme(const TrainingProgramme& tp) {
programmes.push_back(tp);
}
void addEquipment(const Equipment& eq) {
inventory.push_back(eq);
}
void addMaintenanceRecord(const MaintenanceRecord& mr) {
records.push_back(mr);
}
void viewAllUsers() const {
cout << "\n--- REGISTERED USERS SYSTEM ---\n";
if (users.empty()) cout << "No database entries found.\n";
for (size_t i = 0; i < users.size(); ++i) {
users[i]->displayDetails();
}
}
void viewProgrammes() const {
cout << "\n--- TRAINING PROGRAMMES ---\n";
if (programmes.empty()) cout << "No courses registered.\n";
for (size_t i = 0; i < programmes.size(); ++i) programmes[i].display();
}
void viewInventory() const {
cout << "\n--- RAILWAY EQUIPMENT INVENTORY ---\n";
if (inventory.empty()) cout << "Inventory empty.\n";
for (size_t i = 0; i < inventory.size(); ++i) inventory[i].display();
}
void viewMaintenanceReport() const {
cout << "\n--- SYSTEM MAINTENANCE LOGS ---\n";
double totalExpenses = 0;
if (records.empty()) cout << "Logs clear.\n";
for (size_t i = 0; i < records.size(); ++i) {
records[i].display();
totalExpenses += records[i].getRepairCost();
}
cout << "-------------------------------------------\n";
cout << "Accumulated Institutional Repair Cost: KES " << totalExpenses << "\n";
}
void saveData() {
ofstream userFile("users.txt");
ofstream progFile("programmes.txt");
ofstream equipFile("equipment.txt");
ofstream recordFile("maintenance.txt");
for (size_t i = 0; i < users.size(); ++i) {
userFile << users[i]->getRole() << "," << users[i]->toFileString() << "\n";
}
for (size_t i = 0; i < programmes.size(); ++i) progFile << programmes[i].toFileString() << "\n";
for (size_t i = 0; i < inventory.size(); ++i) equipFile << inventory[i].toFileString() << "\n";
for (size_t i = 0; i < records.size(); ++i) recordFile << records[i].toFileString() << "\n";
cout << "[System Master] All records safely persistent to disk files.\n";
}
void loadData() {
for (size_t i = 0; i < users.size(); ++i) delete users[i];
users.clear(); programmes.clear(); inventory.clear(); records.clear();
string line;
ifstream userFile("users.txt");
if (userFile.is_open()) {
while (getline(userFile, line)) {
if (line.empty()) continue;
vector<string> parts = splitCSV(line);
if (parts[0] == "Trainee" && parts.size() >= 7) {
users.push_back(new Trainee(parts[1], parts[2], parts[3], parts[4], parts[5], stringToDouble(parts[6])));
} else if (parts[0] == "Trainer" && parts.size() >= 7) {
users.push_back(new Trainer(parts[1], parts[2], parts[3], parts[4], parts[5], stringToInt(parts[6])));
}
}
}
ifstream progFile("programmes.txt");
if (progFile.is_open()) {
while (getline(progFile, line)) {
if (line.empty()) continue;
vector<string> parts = splitCSV(line);
if (parts.size() >= 4) {
programmes.push_back(TrainingProgramme(parts[0], parts[1], stringToInt(parts[2]), stringToInt(parts[3])));
}
}
}
ifstream equipFile("equipment.txt");
if (equipFile.is_open()) {
while (getline(equipFile, line)) {
if (line.empty()) continue;
vector<string> parts = splitCSV(line);
if (parts.size() >= 4) {
inventory.push_back(Equipment(parts[0], parts[1], parts[2], parts[3]));
}
}
}
ifstream recFile("maintenance.txt");
if (recFile.is_open()) {
while (getline(recFile, line)) {
if (line.empty()) continue;
vector<string> parts = splitCSV(line);
if (parts.size() >= 4) {
records.push_back(MaintenanceRecord(parts[0], parts[1], parts[2], stringToDouble(parts[3])));
}
}
}
}
};
// ============================================================================
// MAIN RUNTIME APPLICATION INTERFACE
// ============================================================================
int main() {
InstituteManager manager;
try {
manager.loadData();
} catch (...) {
cout << "[System Info] Starting fresh database initialization files.\n";
}
int primaryChoice = 0;
do {
cout << "\n=============================================\n";
cout << "      KCA UNIVERSITY MANAGEMENT SYSTEM        \n";
cout << "=============================================\n";
cout << "1. Add a Trainee\n";
cout << "2. Add a Trainer\n";
cout << "3. Register Training Programme\n";
cout << "4. Register Railway Equipment\n";
cout << "5. File a Maintenance Log\n";
cout << "6. Generate Reports Dashboard\n";
cout << "7. Save Database Changes\n";
cout << "8. Exit System Execution\n";
cout << "Enter operation index (1-8): ";
if (!(cin >> primaryChoice)) {
cin.clear();
cin.ignore(1000, '\n');
cout << "Critical: Numerical selections only.\n";
continue;
}
cin.ignore();
try {
if (primaryChoice == 1) {
string id, name, contact, adm, course;
double marks;
cout << "National ID/Passport: "; getline(cin, id);
cout << "Full Trainee Name: "; getline(cin, name);
cout << "Contact Number/Email: "; getline(cin, contact);
cout << "Admission Identifier: "; getline(cin, adm);
cout << "Registered Course Code: "; getline(cin, course);
cout << "Initial Examination Mark (0-100): "; cin >> marks;
manager.addUser(new Trainee(id, name, contact, adm, course, marks));
cout << "Success: Trainee Profile Synced.\n";
} else if (primaryChoice == 2) {
string id, name, contact, emp, spec;
int exp;
cout << "National ID/Passport: "; getline(cin, id);
cout << "Full Instructor Name: "; getline(cin, name);
cout << "Contact Number/Email: "; getline(cin, contact);
cout << "Employee Badge Number: "; getline(cin, emp);
cout << "Core Specialization Area: "; getline(cin, spec);
cout << "Field Operational Experience (Years): "; cin >> exp;
manager.addUser(new Trainer(id, name, contact, emp, spec, exp));
cout << "Success: Trainer Account Registered.\n";
} else if (primaryChoice == 3) {
string code, name;
int duration, maxEnr;
cout << "Programme Serial Code: "; getline(cin, code);
cout << "Programme Curriculum Title: "; getline(cin, name);
cout << "Duration Lifecycle (Weeks): "; cin >> duration;
cout << "Cohort Capacity Ceiling: "; cin >> maxEnr;
manager.addProgramme(TrainingProgramme(code, name, duration, maxEnr));
cout << "Success: Curriculum Added.\n";
} else if (primaryChoice == 4) {
string id, desc, cond, status;
cout << "Equipment Inventory Reference ID: "; getline(cin, id);
cout << "Item Technical Description: "; getline(cin, desc);
cout << "Structural Condition Rank: "; getline(cin, cond);
cout << "Operational Status Field: "; getline(cin, status);
manager.addEquipment(Equipment(id, desc, cond, status));
cout << "Success: Hardware Inventory Record Updated.\n";
} else if (primaryChoice == 5) {
string date, eqID, fault;
double cost;
cout << "Log Timestamp Date (YYYY-MM-DD): "; getline(cin, date);
cout << "Target Equipment Asset ID: "; getline(cin, eqID);
cout << "Reported Mechanical Fault Summary: "; getline(cin, fault);
cout << "Invoiced Repair Maintenance Cost: KES "; cin >> cost;
manager.addMaintenanceRecord(MaintenanceRecord(date, eqID, fault, cost));
cout << "Success: Invoiced Log Tracked.\n";
} else if (primaryChoice == 6) {
int reportSelection = 0;
cout << "\n--- SELECT OUTPUT REPORT METRIC ---\n";
cout << "1. Full Institutional Roll Call (Users)\n";
cout << "2. Active Academic Course Syllabi\n";
cout << "3. Mechanical Hardware Inventory State\n";
cout << "4. Audited Facility Repair Expenditure Logs\n";
cout << "Selection (1-4): "; cin >> reportSelection;
if (reportSelection == 1) manager.viewAllUsers();
else if (reportSelection == 2) manager.viewProgrammes();
else if (reportSelection == 3) manager.viewInventory();
else if (reportSelection == 4) manager.viewMaintenanceReport();
else cout << "Invalid Selection.\n";
} else if (primaryChoice == 7) {
manager.saveData();
}
}
catch (const runtime_error& error) {
cout << "\n[Execution Halted] " << error.what() << "\nReverting operation safely...\n";
}
catch (...) {
cout << "\n[Fatal Failure] Runtime tracking fault recorded.\n";
}
} while (primaryChoice != 8);
manager.saveData();
cout << "\n[System Safe Shutdown] Goodbye!\n";
return 0;
}
