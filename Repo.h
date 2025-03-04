#pragma once
#include "Domain.h"
#include "vector"
using namespace std;
class Repo
{
private:
	vector<Produs> lista;

	void load_from_file();
	void save_to_file();
public:
	Repo() { load_from_file(); }
	vector<Produs> get_all() { return lista; };
	void adauga(const Produs& p) {
		lista.push_back(p);
		save_to_file();
	}
};

