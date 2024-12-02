#include "TMS_Project.h"

int main() {
    TMS system;
    int choice;

    do {
        cout << "\n--- Transport Management System ---\n";
        cout << "1. Add Customer\n2. Add Driver\n3. Add Vehicle\n4. Book Service\n5. Print All Customers\n";
        cout << "6. Print All Drivers\n7. Print All Vehicles\n8. Print All Services\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, name);
            system.addCustomer(Customer(id, name));
            break;
        }
        case 2: {
            int id, exp;
            float sal, rank;
            string name;
            cout << "Enter Driver ID: ";
            cin >> id;
            cout << "Enter Driver Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Salary: ";
            cin >> sal;
            cout << "Enter Experience (years): ";
            cin >> exp;
            cout << "Enter Ranking: ";
            cin >> rank;
            system.addDriver(Driver(id, name, sal, exp, rank));
            break;
        }
        case 3: {
            int id;
            float mileage;
            string type, fuel;
            bool ac;
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Type: ";
            cin >> type;
            cout << "Enter Mileage: ";
            cin >> mileage;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Has AC? (1 for Yes, 0 for No): ";
            cin >> ac;
            system.addVehicle(Vehicle(id, type, mileage, fuel, ac));
            break;
        }
        case 4: {
            int custId, drvId, vehId;
            string src, dest;
            float dist;
            cout << "Enter Customer ID: ";
            cin >> custId;
            cout << "Enter Driver ID: ";
            cin >> drvId;
            cout << "Enter Vehicle ID: ";
            cin >> vehId;
            cout << "Enter Source: ";
            cin >> src;
            cout << "Enter Destination: ";
            cin >> dest;
            cout << "Enter Distance (km): ";
            cin >> dist;
            system.bookService(custId, drvId, vehId, src, dest, dist);
            break;
        }
        case 5:
            system.printAllCustomers();
            break;
        case 6:
            system.printAllDrivers();
            break;
        case 7:
            system.printAllVehicles();
            break;
        case 8:
            system.printAllServices();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
