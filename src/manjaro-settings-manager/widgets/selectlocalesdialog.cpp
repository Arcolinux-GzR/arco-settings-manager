/*
 *  Manjaro Settings Manager
 *  Roland Singer <roland@manjaro.org>
 *  Ramon Buldó <ramon@manjaro.org>
 *
 *  Copyright (C) 2007 Free Software Foundation, Inc.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "selectlocalesdialog.h"
#include "ui_selectlocalesdialog.h"

SelectLocalesDialog::SelectLocalesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectLocalesDialog)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->languageListView, &QListView::activated,
            this, &SelectLocalesDialog::languageListViewActivated);
    connect(ui->countryListView, &QListView::activated,
            this, &SelectLocalesDialog::countryListViewActivated);
    connect(ui->buttonCancel, &QPushButton::clicked,
            this, &SelectLocalesDialog::close);
    connect(ui->buttonAdd, &QPushButton::clicked,
            this, &SelectLocalesDialog::buttonAdd_clicked);
}



SelectLocalesDialog::~SelectLocalesDialog()
{
    delete ui;
}


bool SelectLocalesDialog::localeAdded()
{
    return m_accepted;
}


QString SelectLocalesDialog::getLocale()
{
    if (ui->localeComboBox->count() <= 0) {
        return QString();
    }
    return ui->localeComboBox->currentText();
}



int SelectLocalesDialog::exec()
{
    m_accepted = false;
    m_supportedLocalesModel = new SupportedLocalesModel();
    m_supportedLocalesProxyModel = new QSortFilterProxyModel();
    m_supportedLocalesProxyModel->setSourceModel(m_supportedLocalesModel);
    m_supportedLocalesProxyModel->setSortRole(SupportedLocalesModel::KeyRole);
    m_supportedLocalesProxyModel->setSortLocaleAware(true);
    m_supportedLocalesProxyModel->sort(0, Qt::AscendingOrder);

    ui->languageListView->setModel(m_supportedLocalesProxyModel);

    ui->localeComboBox->hide();

    updateApplyEnabledState();

    return QDialog::exec();
}



void SelectLocalesDialog::updateApplyEnabledState()
{
    ui->buttonAdd->setEnabled(ui->localeComboBox->isVisible());
}


//###
//### Private
//###


void SelectLocalesDialog::languageListViewActivated(const QModelIndex &index)
{
    if (index.isValid()) {
        ui->countryListView->setModel(m_supportedLocalesProxyModel);
        ui->countryListView->setRootIndex(index);
        ui->localeComboBox->hide();
        updateApplyEnabledState();
    }
}



void SelectLocalesDialog::countryListViewActivated(const QModelIndex &index)
{
    if (index.isValid()) {
        ui->localeComboBox->setModel(m_supportedLocalesProxyModel);
        ui->localeComboBox->setRootModelIndex(index);

        /* Select locale with UTF-8 encoding by default */
        QModelIndexList localeIndexList = m_supportedLocalesProxyModel->match(index.child(0,0),
                                                                              SupportedLocalesModel::KeyRole,
                                                                              "UTF-8",
                                                                              -1,
                                                                              Qt::MatchContains);
        if (localeIndexList.size() > 0) {
            QModelIndex modelIndex = localeIndexList.first();
            ui->localeComboBox->setCurrentIndex(modelIndex.row());
        } else {
            ui->localeComboBox->setCurrentIndex(0);
        }

        ui->localeComboBox->show();
        updateApplyEnabledState();
    }
}


void SelectLocalesDialog::buttonAdd_clicked()
{
    m_accepted = true;
    close();
}
