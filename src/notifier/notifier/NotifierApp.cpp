/*
 *  This file is part of Arco Settings Manager.
 *
 *  Ramon Buldó <ramon@manjaro.org>
 *  Kacper Piwiński
 *
 *  Arco Settings Manager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Arco Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Arco Settings Manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "NotifierApp.h"

#include <QtGui/QIcon>

#include <QDebug>

NotifierApp::NotifierApp( int& argc, char* argv[] )
    : QApplication( argc, argv )
{
    setOrganizationName( "Arco" );
    setOrganizationDomain( "Arco" );
    setApplicationName( "MSM Notifier" );
    setApplicationVersion( PROJECT_VERSION );
    setQuitOnLastWindowClosed( false );
}


NotifierApp::~NotifierApp()
{
    qDebug() << "Shutting down MSM Notifier...";
}


void
NotifierApp::init()
{
    setWindowIcon( QIcon::fromTheme( "preferences-system" ) );
}


NotifierApp*
NotifierApp::instance()
{
    return qobject_cast<NotifierApp*>( QApplication::instance() );
}
