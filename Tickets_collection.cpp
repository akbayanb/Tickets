#include "Tickets_collection.h"



void Tickets_collection::add(Ticket t)
{
	ts.push_back(t);
}

Tickets_collection Tickets_collection::filter(string field, string key)
{
	Tickets_collection new_collection;
	vector<Ticket> nv;
	
	if (field == "route_no") {
		int route_no = atoi(key.c_str());
		for_each(ts.begin(), ts.end(), [&new_collection, route_no](Ticket t) {if(t.get_route_no()==route_no)new_collection.add(t); });
	}
	else if (field == "dep_point") {
		for_each(ts.begin(), ts.end(), [&new_collection, key](Ticket t) {
			if (t.get_point_if_departure().find(key)!=-1)new_collection.add(t); });
	}
	else if (field == "dest") {
		for_each(ts.begin(), ts.end(), [&new_collection, key](Ticket t) {
			if (t.get_destination().find(key) != -1)new_collection.add(t); });
	}
	else if (field == "arrival_time") {
		
		for_each(ts.begin(), ts.end(), [&new_collection, key](Ticket t) {
			auto date = t.get_arrival_time();
			if (key.length() == 7) {
				date = date.substr(0, 7);
			}
			if (date==key)new_collection.add(t); });
	}
	else if (field == "dep_time") {

		for_each(ts.begin(), ts.end(), [&new_collection, key](Ticket t) {
			auto date = t.get_departure_time();
			if (key.length() == 7) {
				date = date.substr(0, 7);
			}
			if (date == key)new_collection.add(t); });
	}
	else if (field == "price") {
		double price = atof(key.c_str());
		for_each(ts.begin(), ts.end(), [&new_collection, price](Ticket t) {if (t.get_price()<price)new_collection.add(t); });
	}
	return new_collection;
}

void Tickets_collection::sort(string field)
{

	if (field == "route_no") {
		std::sort(ts.begin(), ts.end(), [](Ticket t1, Ticket t2) {return t1.get_route_no() < t2.get_route_no(); });
	}
	else if (field == "dep_point") {
		std::sort(ts.begin(), ts.end(), [](Ticket t1, Ticket t2) {return t1.get_point_if_departure() < t2.get_point_if_departure(); });
	}
	else if (field == "dest") {
		std::sort(ts.begin(), ts.end(), [](Ticket t1, Ticket t2) {return t1.get_destination() < t2.get_destination(); });
	}
	else if (field == "arrival_time") {
		std::sort(ts.begin(), ts.end(), [](Ticket t1, Ticket t2) {return t1.get_arrival_time() < t2.get_arrival_time(); });
	}
	else if (field == "dep_time") {
		std::sort(ts.begin(), ts.end(), [](Ticket t1, Ticket t2) {return t1.get_departure_time() < t2.get_departure_time(); });
	}
	else if (field == "price") {
		std::sort(ts.begin(), ts.end(), [](Ticket t1, Ticket t2) {return t1.get_price() < t2.get_price(); });

		}
}

void Tickets_collection::print()
{
	for_each(ts.begin(), ts.end(), [](Ticket t) {cout << t; });
}
