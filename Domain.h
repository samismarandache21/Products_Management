#pragma once
#include "string"
using namespace std;
class Produs
{
	int id;
	double pret;
	string nume, tip;
public:
	Produs(int i, string n, string t, double p) : id{ i }, nume{ n }, tip{ t }, pret{ p } {}
	int get_id() { return  id; };
	double get_pret() { return pret; };
	string get_nume() { return nume; };
	string get_tip() { return tip; };
	
	int nr_vocale();

};

