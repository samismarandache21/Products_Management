#include "Repo.h"
#include "fstream"
#include"sstream"
#include "Domain.h"

void Repo::load_from_file() {
	lista.clear();
	ifstream in("input.txt");
	string line;
	while (getline(in, line)) {
		int nr = 0;
		string nume, tip;
		string curent;
		int id;
		double pret;
		stringstream linestream(line);
		while (getline(linestream, curent, ',')) {
			if (nr == 0)
				id = stoi(curent);
			if (nr == 1)
				nume = curent;
			if (nr == 2)
				tip = curent;
			if (nr == 3)
				pret = stod(curent);
			nr++;
		}
		lista.push_back(Produs(id, nume, tip, pret));
	}
	in.close();
}

void Repo::save_to_file() {
	ofstream out("input.txt");
	for (auto& p : lista) {
		out << p.get_id() << "," << p.get_nume() << "," << p.get_tip() << "," << p.get_pret() << endl;
	}
	out.close();

}