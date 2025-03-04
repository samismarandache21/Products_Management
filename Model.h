#pragma once
#include<QAbstractTableModel>
#include <QBrush>
#include <Qt>
#include "Domain.h"
#include <vector>
#include <QFont>

using std::vector;

class MyTableModel : public QAbstractTableModel {
private:
	vector<Produs> produse;
	int nr;
public:
	MyTableModel(const vector<Produs>& v, int n) :produse{ v }, nr{ n } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return produse.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}


	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override{
		if (role == Qt::BackgroundRole) {
			auto p = produse[index.row()];
			int pret = p.get_pret();
			int row = index.row();
			if (pret <= nr) {
				QBrush bg(Qt::darkRed);
				return bg;
			}
		}
		if (role == Qt::DisplayRole) {
			Produs p = produse[index.row()];
			if (index.column() == 0)
				return QString::number(p.get_id());
			else if (index.column() == 1)
				return QString::fromStdString(p.get_nume());
			else if (index.column() == 2)
				return QString::fromStdString(p.get_tip());
			else if (index.column() == 3)
				return QString::number(p.get_pret());
			else if (index.column() == 4)
				return QString::number(p.nr_vocale());

		}
		return QVariant{};

	}

	void set_produse(vector<Produs> prod, int n) {
		this->produse = prod;
		this->nr = n;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		emit dataChanged(topLeft, bottomRight);
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const {
		if (role == Qt::DisplayRole) {
			if (orientation == Qt::Horizontal) {
				switch (section)
				{
				case 0:
					return tr("Id");
				case 1:
					return tr("Nume");
				case 2:
					return tr("Tip");
				case 3:
					return tr("Pret");
				case 4:
					return tr("Vocale");

				}
			}
		}
		return QVariant();
	}

};