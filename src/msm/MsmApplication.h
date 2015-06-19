/*
 *  Manjaro Settings Manager
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

#ifndef MSMAPPLICATION_H
#define MSMAPPLICATION_H

#include <QtWidgets/QApplication>

#define APP MsmApplication::instance()

class MsmWindow;

class MsmApplication : public QApplication
{
    Q_OBJECT
public:
    MsmApplication(int& argc, char* argv[]);
    virtual ~MsmApplication();

    void init();
    static MsmApplication* instance();

    void setDebug(bool enabled);
    bool isDebug();

    MsmWindow* mainWindow();

private:
    MsmWindow* m_mainwindow;
    bool m_debugMode;
};

#endif //MSMAPPLICATION_H

