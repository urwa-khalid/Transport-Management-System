#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Name Class
class Name {
private:
    string fName;
    string lName;

public:
    Name(const string& fN = "", const string& lN = "") : fName(fN), lName(lN) {}
    const string& getfName() const { return fName; }
    const string& getlName() const { return lName; }
    void setFname(const string& fN) { fName = fN; }
    void setLname(const string& lN) { lName = lN; }
    friend ostream& operator<<(ostream& out, const Name& n) {
        out << n.fName << " " << n.lName;
        return out;
    }
};

// Date Class
class Date {
private:
    int day, month, year;

public:
    Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}
    void setDate(int d, int m, int y) { day = d; month = m; year = y; }
    friend ostream& operator<<(ostream& out, const Date& date) {
        out << date.day << "/" << date.month << "/" << date.year;
        return out;
    }
    friend istream& operator>>(istream& in, Date& date) {
        char delim;
        in >> date.day >> delim >> date.month >> delim >> date.year;
        return in;
    }
};

// Vehicle Class
class Vehicle {
private:
    int vId;
    string type;
    float avgMileage;
    string fuelType;
    bool ac;
    float overallRanking;
    bool status;

public:
    Vehicle(int id = 0, const string& t = "", float mileage = 0.0, const string& fuel = "", bool hasAc = false)
        : vId(id), type(t), avgMileage(mileage), fuelType(fuel), ac(hasAc), overallRanking(0.0), status(true) {}

    int getId() const { return vId; }
    const string& getType() const { return type; }
    bool isFree() const { return status; }
    void setFree(bool s) { status = s; }
    void updateRanking(float rank) { overallRanking = (overallRanking + rank) / 2.0; }
    friend ostream& operator<<(ostream& out, const Vehicle& v) {
        out << "Vehicle ID: " << v.vId << ", Type: " << v.type << ", Fuel: " << v.fuelType
            << ", Mileage: " << v.avgMileage << ", AC: " << (v.ac ? "Yes" : "No") << ", Ranking: " << v.overallRanking
            << ", Status: " << (v.status ? "Free" : "Booked");
        return out;
    }
};

// Driver Class
class Driver {
private:
    int dId;
    string name;
    float salary;
    int experience;
    float ranking;
    bool status;

public:
    Driver(int id = 0, const string& n = "", float sal = 0.0, int exp = 0, float rank = 0.0, bool stat = true)
        : dId(id), name(n), salary(sal), experience(exp), ranking(rank), status(stat) {}

    int getId() const { return dId; }
    bool isFree() const { return status; }
    void setFree(bool stat) { status = stat; }
    void updateRanking(float rank) { ranking = (ranking + rank) / 2.0; }
    void calculateBonus() {
        if (ranking > 4.5) salary *= 1.15;
    }
    friend ostream& operator<<(ostream& out, const Driver& d) {
        out << "Driver ID: " << d.dId << ", Name: " << d.name << ", Salary: " << d.salary
            << ", Ranking: " << d.ranking << ", Status: " << (d.status ? "Free" : "Booked");
        return out;
    }
};

// Customer Class
class Customer {
private:
    int cId;
    string name;

public:
    Customer(int id = 0, const string& n = "") : cId(id), name(n) {}
    int getId() const { return cId; }

    friend ostream& operator<<(ostream& out, const Customer& c) {
        out << "Customer ID: " << c.cId << ", Name: " << c.name;
        return out;
    }
};

// Service Class
class Service {
private:
    int sId;
    string source;
    string destination;
    float distance;
    float fare;
    int cId, dId, vId;

public:
    Service(int id = 0, const string& src = "", const string& dest = "", float dist = 0.0, float f = 0.0,
        int custId = 0, int drvId = 0, int vehId = 0)
        : sId(id), source(src), destination(dest), distance(dist), fare(f), cId(custId), dId(drvId), vId(vehId) {}

    void calculateFare(float baseRate, float mileageFactor, float driverRanking, float vehicleRanking) {
        fare = distance * baseRate * mileageFactor * (1.0 + (driverRanking + vehicleRanking) / 10.0);
    }

    friend ostream& operator<<(ostream& out, const Service& s) {
        out << "Service ID: " << s.sId << ", Source: " << s.source << ", Destination: " << s.destination
            << ", Distance: " << s.distance << " km, Fare: " << s.fare << ", Customer ID: " << s.cId
            << ", Driver ID: " << s.dId << ", Vehicle ID: " << s.vId;
        return out;
    }
};

// Transport Management System Class
class TMS {
private:
    vector<Driver> drivers;
    vector<Customer> customers;
    vector<Vehicle> vehicles;
    vector<Service> services;

public:
    // Add Customer
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
        cout << "Customer added successfully.\n";
    }

    // Add Driver
    void addDriver(const Driver& driver) {
        drivers.push_back(driver);
        cout << "Driver added successfully.\n";
    }

    // Add Vehicle
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
        cout << "Vehicle added successfully.\n";
    }

    // Book Service
    void bookService(int custId, int drvId, int vehId, const string& src, const string& dest, float distance) {
        float baseRate = 10.0, mileageFactor = 1.0, driverRanking = 4.0, vehicleRanking = 4.0;
        Service newService(services.size() + 1, src, dest, distance, 0.0, custId, drvId, vehId);
        newService.calculateFare(baseRate, mileageFactor, driverRanking, vehicleRanking);
        services.push_back(newService);
        cout << "Service booked successfully!\n";
    }

    // Print All Drivers
    void printAllDrivers() const {
        cout << "\n--- Drivers ---\n";
        for (const auto& driver : drivers)
            cout << driver << endl;
    }

    // Print All Vehicles
    void printAllVehicles() const {
        cout << "\n--- Vehicles ---\n";
        for (const auto& vehicle : vehicles)
            cout << vehicle << endl;
    }

    // Print All Customers
    void printAllCustomers() const {
        cout << "\n--- Customers ---\n";
        for (const auto& customer : customers)
            cout << customer << endl;
    }

    // Print All Services
    void printAllServices() const {
        cout << "\n--- Services ---\n";
        for (const auto& service : services)
            cout << service << endl;
    }
};
