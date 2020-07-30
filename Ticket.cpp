#include "Ticket.h"

Ticket::Ticket(int route_no, string point_of_departure, string destination, string departure_time, string arrival_time, double price)
{
	this->route_no = route_no;
	this->point_of_departure = point_of_departure;
	this->destination = destination;
	this->departure_time = departure_time;
	this->arrival_time = arrival_time;
	this->price = price;
}

int Ticket::get_route_no()
{
	return route_no;
}

string Ticket::get_point_if_departure()
{
	return point_of_departure;
}

string Ticket::get_destination()
{
	return destination;
}

string Ticket::get_departure_time()
{
	return departure_time;
}

string Ticket::get_arrival_time()
{
	return arrival_time;
}

double Ticket::get_price()
{
	return price;
}

istream& operator>>(istream& is, Ticket& obj)
{
	is >> obj.route_no >> obj.point_of_departure >> obj.departure_time >> obj.destination >> obj.arrival_time >> obj.price;
	return is;
}

ostream& operator<<(ostream& os, const Ticket& obj)
{
	os << "Route_No: " << obj.route_no << endl
		<< "Point of departure: " << obj.point_of_departure << endl
		<< "Destination: " << obj.destination << endl
		<< "Departure time: " << obj.departure_time << endl
		<< "Arrival time: " << obj.arrival_time << endl
		<< "Price: " << obj.price << endl << endl;
	return os;

}
