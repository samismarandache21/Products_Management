#include "GUI.h"

void GUI::initGUI() {
	table->setSelectionMode(QAbstractItemView::SingleSelection);
	table->setModel(model);

	this->setLayout(main_ly);
	main_ly->addWidget(table);

	right_comp->setLayout(right_ly);
	right_ly->addWidget(lbl_nume);
	right_ly->addWidget(nume_txt);
	right_ly->addWidget(lbl_tip);
	right_ly->addWidget(tip_txt);
	right_ly->addWidget(lbl_id);
	right_ly->addWidget(id_txt);
	right_ly->addWidget(lbl_pret);
	right_ly->addWidget(pret_txt);
	right_ly->addWidget(lbl_pret_sld);
	right_ly->addWidget(slider);
	right_ly->addWidget(add_btn);

	main_ly->addWidget(right_comp);

	slider->setMinimum(1);
	slider->setMaximum(100);

}

void GUI::connectSlots() {
    QObject::connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, [this] {
        if (table->selectionModel()->selectedIndexes().isEmpty())
        {
            nume_txt->setText("");
            pret_txt->setText("");
            id_txt->setText("");
            tip_txt->setText("");
            return;
        }
        auto row = table->selectionModel()->selectedIndexes().at(0).row();
        nume_txt->setText(table->model()->data(table->model()->index(row, 1), Qt::DisplayRole).toString());
        id_txt->setText(table->model()->data(table->model()->index(row, 0), Qt::DisplayRole).toString());
        tip_txt->setText(table->model()->data(table->model()->index(row, 2), Qt::DisplayRole).toString());
        pret_txt->setText(table->model()->data(table->model()->index(row, 3), Qt::DisplayRole).toString());
        });

    QObject::connect(add_btn, &QPushButton::clicked, [this] {
        auto id = id_txt->text().toInt();
        auto nume = nume_txt->text().toStdString();
        auto tip = tip_txt->text().toStdString();
        auto pret = pret_txt->text().toDouble();
        try {
            srv.adauga(id, nume, tip, pret);
        }
        catch (ServiceException&) {
            QMessageBox::information(this, "Info", "Error");
        }
        reload_lista();
        });

    QObject::connect(slider, &QSlider::valueChanged, [this] {
        reload_lista();
        });
}

void GUI::reload_lista() {
    model->set_produse(srv.All(), slider->value());
}