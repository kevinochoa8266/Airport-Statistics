#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <chrono>
using namespace std;
using namespace std::chrono;
class Airport {
public:
	// Default constructor.
	Airport();
	Airport(string airportCode, string airportName, string yearMonth, string monthNum, string monthName,
	        string year, string delayCarrier, string delayLateAircraft, string delayNAS, string delaySecurity,
	        string delayWeather, string totalCarriers, string flightsCancelled, string flightsDelayed,
	        string flightsDiverted, string flightsOnTime, string totalFlights, string delayMinutesCarrier,
	        string delayMinutesAircraft, string delayMinutesNSA, string delayMinutesSecurity, string delayMinutesTotal,
	        string delayMinutesWeather);
	void readFile();
	// Function will make sure airport code exists within the file.
	void validateAirportCode(string userCode);
	// Function will give choices to user.
	void menuOptions(const string& userCode);
	//Radix sort helper functions.
	static int getMax(vector<int> vect, int n);
	static void countingSort(vector<int>& vect, int size, int place);
	void radixSort(vector<int>& vect);
	//Shell sort algorithm.
	void shellSort(vector<int>& vect);

private:
	string path = "C:\\Users\\hp\\Downloads\\airlines (2).csv";
	vector<Airport> airportList;
	int elements = 152;
	int topFive = 5;
	//Variables will be used to store data points within the file.
	string airportCode;
	string airportName;
	string yearMonth;
	string monthNum;
	string monthName;
	string year;
	string delayCarrier;
	string delayLateAircraft;
	string delayNAS;
	string delaySecurity;
	string delayWeather;
	string totalCarriers;
	string flightsCancelled;
	string flightsDelayed;
	string flightsDiverted;
	string flightsOnTime;
	string totalFlights;
	string delayMinutesCarrier;
	string delayMinutesAircraft;
	string delayMinutesNSA;
	string delayMinutesSecurity;
	string delayMinutesTotal;
	string delayMinutesWeather;
};
Airport::Airport() {
	airportCode = "";
	airportName = "";
	yearMonth = "";
	monthNum = "";
	monthName = "";
	year = "";
	delayCarrier = "";
	delayLateAircraft = "";
	delayNAS = "";
	delaySecurity = "";
	delayWeather = "";
	totalCarriers = "";
	flightsCancelled = "";
	flightsDelayed = "";
	flightsDiverted = "";
	flightsOnTime = "";
	totalFlights = "";
	delayMinutesCarrier = "";
	delayMinutesAircraft = "";
	delayMinutesNSA = "";
	delayMinutesSecurity = "";
	delayMinutesTotal = "";
	delayMinutesWeather = "";
}
Airport::Airport(string airportCode, string airportName, string yearMonth, string monthNum, string monthName,
                 string year, string delayCarrier, string delayLateAircraft, string delayNAS, string delaySecurity,
                 string delayWeather, string totalCarriers, string flightsCancelled, string flightsDelayed,
                 string flightsDiverted, string flightsOnTime, string totalFlights, string delayMinutesCarrier,
                 string delayMinutesAircraft, string delayMinutesNSA, string delayMinutesSecurity,
                 string delayMinutesTotal, string delayMinutesWeather) {
	this->airportCode = airportCode;
	this->airportName = airportName;
	this->yearMonth = yearMonth;
	this->monthNum = monthNum;
	this->monthName = monthName;
	this->year = year;
	this->delayCarrier = delayCarrier;
	this->delayLateAircraft = delayLateAircraft;
	this->delayNAS = delayNAS;
	this->delaySecurity = delaySecurity;
	this->delayWeather = delayWeather;
	this->totalCarriers = totalCarriers;
	this->flightsCancelled = flightsCancelled;
	this->flightsDelayed = flightsDelayed;
	this->flightsDiverted = flightsDiverted;
	this->flightsOnTime = flightsOnTime;
	this->totalFlights = totalFlights;
	this->delayMinutesCarrier = delayMinutesCarrier;
	this->delayMinutesAircraft = delayMinutesAircraft;
	this->delayMinutesNSA = delayMinutesNSA;
	this->delayMinutesSecurity = delayMinutesSecurity;
	this->delayMinutesTotal = delayMinutesTotal;
	this->delayMinutesWeather = delayMinutesWeather;
}

void Airport::readFile() {
	// Read data from the airlines.csv file.
	ifstream file;
	string line;
	file.open(path);
	getline(file, line);
	while(getline(file, line)) {
		istringstream stream(line);
		getline(stream, airportCode, ',');
		stream.ignore();
		getline(stream, airportName, '"');
		stream.ignore();
		getline(stream, yearMonth, ',');
		getline(stream, monthNum, ',');
		getline(stream, monthName, ',');
		getline(stream, year, ',');
		getline(stream, delayCarrier, ',');
		getline(stream, delayLateAircraft, ',');
		getline(stream, delayNAS, ',');
		getline(stream, delaySecurity, ',');
		getline(stream, delayWeather, ',');
		getline(stream, totalCarriers, ',');
		getline(stream, flightsCancelled, ',');
		getline(stream, flightsDelayed, ',');
		getline(stream, flightsDiverted, ',');
		getline(stream, flightsOnTime, ',');
		getline(stream, totalFlights, ',');
		getline(stream, delayMinutesCarrier, ',');
		getline(stream, delayMinutesAircraft, ',');
		getline(stream, delayMinutesNSA, ',');
		getline(stream, delayMinutesSecurity, ',');
		getline(stream, delayMinutesTotal, ',');
		getline(stream, delayMinutesWeather, ',');
		Airport airports(airportCode, airportName, yearMonth, monthNum, monthName, year, delayCarrier,
				delayLateAircraft, delayNAS, delaySecurity, delayWeather, totalCarriers,
				flightsCancelled, flightsDelayed, flightsDiverted, flightsOnTime, totalFlights,
				delayMinutesCarrier, delayMinutesAircraft, delayMinutesNSA, delayMinutesSecurity,
				delayMinutesTotal, delayMinutesWeather);
		// Add airport objects to vector.
		airportList.push_back(airports);
	}
	file.close();
}

void Airport::validateAirportCode(string userCode) {
	bool flag = false;
	string userAirportName;
	// Check if airport code exists.
	for (auto & it : airportList) {
		if (userCode == it.airportCode) {
			userAirportName = it.airportName;
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << userAirportName << endl;
		//If the code exists then go ahead and continue to the menu.
		menuOptions(userCode);
	} else {
		cout << "The airport code was not found within the dataset, please try a different code: ";
		cin >> userCode;
		cout << endl;
		// If the code does not exist, then try again.
		validateAirportCode(userCode);
	}
}

void Airport::menuOptions(const string& userCode) {
	int choice;
	//Display menu.
	cout << "1. Display the top five dates with the most cancelled flights from 2003-2016.\n"
		 << "2. Display the top five dates with the most weather delays from 2003-2016.\n"
		 << "3. Display the top five dates with the most total flights from 2003-2016.\n";
	cout << "Please select a choice: ";
	cin >> choice;
	cout << endl;
	while (choice) {
		if (choice == 1) {
			vector<int> cancelled_radix;
			vector<int> top_five;
			vector<int> cancelled_shell;
			for (auto & it : airportList) {
				if (userCode == it.airportCode) {
					// store flights cancelled in a separate vector.
					cancelled_radix.push_back(stoi(it.flightsCancelled));
				}
			}
			// copy vector to test shell sort on unsorted list of values.
			cancelled_shell = cancelled_radix;
			//Calculate sorting times.
			auto start = high_resolution_clock::now();
			radixSort(cancelled_radix);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			auto startShell = high_resolution_clock::now();
			shellSort(cancelled_shell);
			auto stopShell = high_resolution_clock::now();
			auto durationShell = duration_cast<microseconds>(stopShell - startShell);
			for (int i = (cancelled_radix.size() - 1); i >= (cancelled_radix.size() - topFive) ; i--) {
				//Store only the top five values in a new vector.
				top_five.push_back(cancelled_radix[i]);
			}
			int j = 0;
			int k = 1;
			while (j < 5) {
				for (auto it = airportList.begin(); it != airportList.end() && j < 5; ++it) {
					if (top_five[j] == stoi(it->flightsCancelled) && it->airportCode == userCode) {
						// Display month and year in which top 5 occured.
						cout << k << ". " << it->monthName << " " << it->year << ", " << it->flightsCancelled
							 << " flight's cancelled." << endl;
						j++;
						k++;
					}
				}
			}
			cout << endl;
			// Display sort times.
			cout << "Radix Sort took " << duration.count() << " microseconds to sort through the cancelled flight data." << endl;
			cout << "Shell Sort took " << durationShell.count() << " microseconds to sort through the cancelled flight data." << endl;
			cout << endl;
			break;
		} else if (choice == 2) {
			vector<int> weather_radix;
			vector<int> top_five;
			vector<int> weather_shell;
			for (auto & it : airportList) {
				if (userCode == it.airportCode) {
					// store weather delays in a separate vector.
					weather_radix.push_back(stoi(it.delayWeather));
				}
			}
			// copy vector to test shell sort on unsorted list of values.
			weather_shell = weather_radix;
			//Calculate sorting times.
			auto start = high_resolution_clock::now();
			radixSort(weather_radix);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			auto startShell = high_resolution_clock::now();
			shellSort(weather_shell);
			auto stopShell = high_resolution_clock::now();
			auto durationShell = duration_cast<microseconds>(stopShell - startShell);
			for (int i = (weather_radix.size() - 1); i >= (weather_radix.size() - topFive) ; i--) {
				//Store only the top five values in a new vector.
				top_five.push_back(weather_radix[i]);
			}
			int j = 0;
			int k = 1;
			while (j < 5) {
				for (auto it = airportList.begin(); it != airportList.end() && j < 5; ++it) {
					if (top_five[j] == stoi(it->delayWeather) && it->airportCode == userCode) {
						// Display month and year in which top 5 occured.
						cout << k << ". " << it->monthName << " " << it->year << ", " << it->delayWeather
						     << " weather delays." << endl;
						j++;
						k++;
					}
				}
			}
			cout << endl;
			// Display sort times.
			cout << "Radix Sort took " << duration.count() << " microseconds to sort through the weather delay data." << endl;
			cout << "Shell Sort took " << durationShell.count() << " microseconds to sort through the weather delay data." << endl;
			cout << endl;
			break;
		} else if (choice == 3) {
			vector<int> totalFlightsRadix;
			vector<int> top_five;
			vector<int> totalFlightsShell;
			for (auto & it : airportList) {
				if (userCode == it.airportCode) {
					// store total flights in a separate vector.
					totalFlightsRadix.push_back(stoi(it.totalFlights));
				}
			}
			// copy vector to test shell sort on unsorted list of values.
			totalFlightsShell = totalFlightsRadix;
			//Calculate sorting times.
			auto start = high_resolution_clock::now();
			radixSort(totalFlightsRadix);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			auto startShell = high_resolution_clock::now();
			shellSort(totalFlightsShell);
			auto stopShell = high_resolution_clock::now();
			auto durationShell = duration_cast<microseconds>(stopShell - startShell);
			for (int i = (totalFlightsRadix.size() - 1); i >= (totalFlightsRadix.size() - topFive) ; i--) {
				//Store only the top five values in a new vector.
				top_five.push_back(totalFlightsRadix[i]);
			}
			int j = 0;
			int k = 1;
			while (j < 5) {
				for (auto it = airportList.begin(); it != airportList.end() && j < 5; ++it) {
					if (top_five[j] == stoi(it->totalFlights) && it->airportCode == userCode) {
						// Display month and year in which top 5 occured.
						cout << k << ". " << it->monthName << " " << it->year << ", " << it->totalFlights
						     << " total flights." << endl;
						j++;
						k++;
					}
				}
			}
			cout << endl;
			// Display sort times.
			cout << "Radix Sort took " << duration.count() << " microseconds to sort through the total flight data." << endl;
			cout << "Shell Sort took " << durationShell.count() << " microseconds to sort through the total flight data." << endl;
			cout << endl;
			break;
		}
	}
}

int Airport::getMax(vector<int> vect, int n) {
	int max = vect[0];
	for (int i = 1; i < n; i++) {
		if (vect[i] > max) {
			max = vect[i];
		}
	}
	return max;
}

void Airport::countingSort(vector<int>& vect, int size, int place) {
	const int max = 10;
	int output[size];
	int count[max];

	for (int & i : count) {
		i = 0;
	}

	for (int i = 0; i < size; i++) {
		count[(vect[i] / place) % 10]++;
	}

	for (int i = 1; i < max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		output[count[(vect[i] / place) % 10] - 1] = vect[i];
		count[(vect[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++) {
		vect[i] = output[i];
	}
}

void Airport::radixSort(vector<int>& vect) {
	int max = getMax(vect, elements);
	for (int i = 1; max / i > 0; i *= 10) {
		countingSort(vect, elements, i);
	}
}

void Airport::shellSort(vector<int> &vect) {
	for (int gap = elements / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < elements; i++) {
			int temp = vect[i];
			int j;
			for (j = i; j >= gap && vect[j - gap] > temp; j -= gap) {
				vect[j] = vect[j - gap];
			}
			vect[j] = temp;
		}
	}
}

int main() {
	Airport airports;
	string airport_Code;
	// Open and read file.
	airports.readFile();
	// Introduction.
	cout << "United States Airport Statistics 2003 - 2016" << endl;
	cout << "In addition to revealing airport statistics, this program will also " <<
		    "compare and display the computing times of Radix Sort and Shell Sort.\n";
	cout << endl;
	cout << "Please enter an airport code you wish to learn more about: ";
	cin >> airport_Code;
	cout << endl;
	airports.validateAirportCode(airport_Code);
	return 0;
}

