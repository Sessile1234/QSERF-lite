#include <iostream>	//< main library
#include <cstdlib>	//< funcions idk needed for V
#include <ctime>	//< for rand time related thing
#include <thread>	//< allows more stuff of code to run at the same time
#include <chrono>	//< for the delays things

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    bool reactorActivated = false;
    double fuelLevel = 50.0;
    double temperature = 800.0;
    int powerIntensity = 0;
    int coolantLevel = 0;
    
	cout<<"* * *   *****  ****  ****  ****    *     *  *****  ****"<<endl;
    cout<<"*   *   *****  ****  ****  ****    *     *    *    ****"<<endl;
    cout<<"*   *       *  *     * *   *       *     *    *    *"<<endl;
    cout<<"* *  *  * * *  ****  *  *  *       ****  *    *    ****"<<endl;
    cout<<"\nDMR and systems by Quantum Science Inc.\n";
    cout<<"Project made by FuffyDoesNothing.\n";
    cout<<"\nIn this project there are:\n";
	cout<<"-Basic systems of DMR\n";
	cout<<"-Phase one shutdown\n";
	cout<<"-Refueling system\n";
	cout<<"-DMR startup failure\n";
    
	while (!reactorActivated) {
        cout << "\nPress ENTER to start the reactor...";
        cin.ignore();

        int failChance = rand() % 100;
        if (failChance < 2) {
            cout << "FAAS: Reactor startup failed! Shutting down neutron bombardment units.\n";
        } else {
            reactorActivated = true;
            cout << "FAAS: Reactor activated successfully!\n";
        }
    }

    while (powerIntensity < 1 || powerIntensity > 5) {
        cout << "\nSet the power laser level (1-5): ";
        cin >> powerIntensity;
        if (powerIntensity < 1 || powerIntensity > 5) {
            cout << "Invalid input. Please enter a value between 1 and 5.\n";
        }
    }

    while (coolantLevel < 1 || coolantLevel > 5) {
        cout << "\nSet the coolant level (1-5): ";
        cin >> coolantLevel;
        if (coolantLevel < 1 || coolantLevel > 5) {
            cout << "Invalid input. Please enter a value between 1 and 5.\n";
        }
    }

    while (true) {
        double tempChange = (powerIntensity * 10) - (coolantLevel * 5);
        temperature += tempChange;

        fuelLevel -= 1.0;

        cout << "\nDMR temperature: " << temperature << " K";
        cout << "\nFuel cells level: " << fuelLevel << "%\n";

        this_thread::sleep_for(chrono::milliseconds(1000));

        if (fuelLevel <= 20.0) {
            cout << "\nFAAS: Warning: Fuel cells level low!\n";

            char refuelChoice;
            cout << "Do you want to refuel? (Y/N): ";
            cin >> refuelChoice;

            if (refuelChoice == 'Y' || refuelChoice == 'y') {
                cout << "\nFAAS: Maintenance activated, lowering DMR.\n";

                fuelLevel = 100.0;

                cout << "\nFAAS: Refueling complete. Reactor restarting...\n";
                continue;
            } else {
                cout << "\nFAAS: Warning: Fuel cells level low!\n";
            }
        }

        if (fuelLevel <= 0.0) {
            cout << "\nFAAS: Reactor fuel depleted.\n";

            fuelLevel = 100.0;

            cout << "\nFAAS: Refueling complete. Reactor restarting...\n";
            continue;
        }

        if (temperature >= 1200 && temperature < 3500) {
            cout << "FAAS: Warning: Reactor temperature is high, cool the reactor immediately\n";
        } else if (temperature <= 275) {
            cout << "FAAS: Warning: Reactor temperature is too low!\n";
        }

        if (temperature >= 3500) {
            cout << "\nFAAS: Warning: Superstructure rupture detected!\n";
            cout << "FAAS: Engage cooling systems immediately.\n";

            double superstructureDamage = 100.0;

            while (superstructureDamage >= -50.0) {
                superstructureDamage -= 5.0;

                temperature += 50.0; 

                fuelLevel += 5.0;
                if (fuelLevel > 100.0) {
                    fuelLevel = 100.0;
                }

                cout << "\nSuperstructure level: " << superstructureDamage << "%";
                cout << " | Reactor temperature: " << temperature << " K";
                cout << " | Fuel level: " << fuelLevel << "%\n";

                this_thread::sleep_for(chrono::milliseconds(1000));

                if (superstructureDamage <= 0.0) {
                    cout << "\nFASS: Code Red: You have 5 minutes to shutdown the reactor.\n";

                    int emergencyCode = rand() % 900000 + 100000;
                    cout << "Emergency shutdown code: " << emergencyCode << "\n";

                    int userCode;
                    cout << "Enter the code to shut down the reactor: ";
                    cin >> userCode;

                    if (userCode == emergencyCode) {
                        cout << "\nReactor successfully shut down. Crisis averted.\n";
                        return 0;
                    } else {
                        cout << "\nCode Black: Incorrect code. Reactor explosion imminent!\n";
                        cout << "\nBOOM! Reactor has exploded catastrophically.\n";
                        return 1;
                    }
                }
            }

            break;
        }
    }

    return 0;
}
