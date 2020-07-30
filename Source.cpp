#include <fstream>
#include "Tickets_collection.h"

int main() {

	ifstream in_file("tickets.txt");

	Ticket obj;
	int choice;
	Tickets_collection tickets;
	string field, key, order;
	while (in_file >> obj) {
		tickets.add(obj);

	}

	while (true) {
		cout << "Enter 1 to print list of tickets" << endl;
		cout << "Enter 2 to filter tickets" << endl;
		cout << "Enter 3 to sort tickets" << endl;
		cout << "Enter 0 to exit" << endl;
		cin >> choice;
		if (!choice) break;
		switch (choice)
		{
		case 1:
			tickets.print();
			break;
		case 2: {
			cout << "Enter field and key for filter" << endl;
			cout << "Possible values od fields:" << endl;
			cout << "route_no, dep_point, dest, arrival_time, dep_time, price" << endl;
			cin >> field >> key;
			auto obj = tickets.filter(field, key);
			obj.print();
		}
			break;
		case 3: {
			cout << "Enter field to sort by" << endl;
			cout << "Possible values od fields:" << endl;
			cout << "route_no, dep_point, dest, arrival_time, dep_time, price" << endl;
			cin >> field;
			
			tickets.sort(field);
			tickets.print();

		}
			break;

		default:
			break;
		}
	}
	tickets.print();



}