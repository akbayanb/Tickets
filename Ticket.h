#pragma once

#include <iostream>
#include <string>

using namespace std;


class Ticket {
private:
	int route_no;
	string point_of_departure;
	string destination;
	string departure_time;
	string arrival_time;
	double price;

public:
	Ticket():route_no(0), point_of_departure(""), destination(""), departure_time("00/00/00"), arrival_time("00/00/00"), price(0.0){}
	Ticket(int route_no, string point_of_departure, string destination, string departure_time, string arrival_time, double price);

	int get_route_no();
	string get_point_if_departure();
	string get_destination();
	string get_departure_time();
	string get_arrival_time();
	double get_price();
	friend istream& operator>>(istream& is, Ticket& obj);
	friend ostream& operator<<(ostream& os, const Ticket& obj);


};
