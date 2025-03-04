#pragma once
#include <set>
#include "map"
#include "Repo.h"
using namespace std;
class ServiceException: public exception
{

};

class Service {
private:
	Repo& repo;
public:
	explicit Service(Repo& r) : repo{ r } {}
	
	vector<Produs> sorted(vector<Produs> vect);
	vector<Produs> All() {
		return sorted(repo.get_all());
	}
	void valideaza(int id, string& nume, string& tip, double pret);
	void adauga(int id, string nume, string tip, double pret);
	vector<Produs> filtrare(double pret, vector<Produs> vect);
	
};
