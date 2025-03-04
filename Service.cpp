#include "Service.h"
#include "algorithm"
#include "iterator"
#include "vector"
vector<Produs> Service::sorted(vector<Produs> vect) {
	sort(vect.begin(), vect.end(), [](Produs& p1, Produs& p2) {
		return p1.get_pret() < p2.get_pret();
		});
	return vect;
}

void Service::valideaza(int id, string& nume, string& tip, double pret) {
	for (auto& p : All()) {
		if (p.get_id() == id)
			throw ServiceException();
	}
	if (nume.empty() || tip.empty() || pret < 1.0 || pret>100.0)
		throw ServiceException();

}

void Service::adauga(int id, string nume, string tip, double pret) {
	valideaza(id, nume, tip, pret);
	repo.adauga(Produs(id, nume, tip, pret));
}

vector<Produs> Service::filtrare(double pret, vector<Produs> vect) {
	vector<Produs> rez;
	copy_if(vect.begin(), vect.end(), back_inserter(rez), [pret](Produs& p1) {
		return p1.get_pret() < pret;
		});
	return rez;
}

