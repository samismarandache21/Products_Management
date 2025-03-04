#pragma once
#include <QWidget>
#include <QTableView>
#include <utility>
#include "QLayout"
#include "QPushButton"
#include "QSlider"
#include "QLineEdit"
#include "QLabel"
#include "QMessageBox"
#include "service.h"
#include "MODEL.h"
class GUI : public QWidget
{
private:
	Service& srv;
	QWidget* main_wnd = new QWidget;
	QWidget* left_comp = new QWidget;
	QWidget* right_comp = new QWidget;

	QHBoxLayout* main_ly = new QHBoxLayout;
	QVBoxLayout* right_ly = new QVBoxLayout;

	QTableView* table = new QTableView;
	MyTableModel* model = new MyTableModel{ srv.All(), 0 };

	QSlider* slider = new QSlider(Qt::Horizontal);
	QLabel* lbl_pret_sld = new QLabel{ "Pret filtrare" };
	QLabel* lbl_id = new QLabel{ "ID" };
	QLabel* lbl_nume = new QLabel{ "Nume" };
	QLabel* lbl_tip = new QLabel{ "Tip" };
	QLabel* lbl_pret = new QLabel{ "Pret" };

	QLineEdit* id_txt = new QLineEdit;
	QLineEdit* nume_txt = new QLineEdit;
	QLineEdit* tip_txt = new QLineEdit;
	QLineEdit* pret_txt = new QLineEdit;

	QPushButton* add_btn = new QPushButton{"ADD"};

	void initGUI();
	void connectSlots();
	void reload_lista();

public:
	GUI(Service& service) : srv{ service } {
		initGUI();
		connectSlots();
		reload_lista();
	}

	void run() {
		this->show();
	}

};

