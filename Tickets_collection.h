#pragma once

#include "Ticket.h"
#include <vector>
#include <algorithm>

class Tickets_collection {
	vector<Ticket> ts;

public:
	void add(Ticket t);
	Tickets_collection filter(string field, string key);
	void sort(string field);
	void print();



};
