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

#include "LanguagePackagesItem.h"

LanguagePackagesItem::LanguagePackagesItem() :
    m_name( QString() ),
    m_languagePackage( QString() ),
    m_parentPackages( QStringList() ),
    m_parentPkgInstalled( QStringList() ),
    m_languagePkgInstalled( QStringList() ),
    m_languagePkgAvailable( QStringList() )
{
}

LanguagePackagesItem::LanguagePackagesItem(
    const QString& name,
    const QString& languagePackage,
    const QStringList& parentPackages,
    const QStringList& parentPkgInstalled,
    const QStringList& languagePkgInstalled,
    const QStringList& languagePkgAvailable )
    : m_name( name ),
      m_languagePackage( languagePackage ),
      m_parentPackages( parentPackages ),
      m_parentPkgInstalled( parentPkgInstalled ),
      m_languagePkgInstalled( languagePkgInstalled ),
      m_languagePkgAvailable( languagePkgAvailable )
{
}


LanguagePackagesItem::~LanguagePackagesItem()
{
}


QString
LanguagePackagesItem::name() const
{
    return m_name;
}


void
LanguagePackagesItem::setName( const QString& name )
{
    m_name = name;
}


QString
LanguagePackagesItem::languagePackage() const
{
    return m_languagePackage;
}


void
LanguagePackagesItem::setLanguagePackage( const QString& languagePackage )
{
    m_languagePackage = languagePackage;
}


QStringList
LanguagePackagesItem::parentPackages() const
{
    return m_parentPackages;
}


void
LanguagePackagesItem::setParentPackages( const QStringList& parentPackages )
{
    m_parentPackages = parentPackages;
}


QStringList
LanguagePackagesItem::parentPkgInstalled() const
{
    return m_parentPkgInstalled;
}


void
LanguagePackagesItem::setParentPkgInstalled( const QStringList& parentPkgInstalled )
{
    m_parentPkgInstalled = parentPkgInstalled;
}


QStringList
LanguagePackagesItem::languagePkgInstalled() const
{
    return m_languagePkgInstalled;
}


void
LanguagePackagesItem::setLanguagePkgInstalled( const QStringList& languagePkgInstalled )
{
    m_languagePkgInstalled = languagePkgInstalled;
}


QStringList
LanguagePackagesItem::languagePkgAvailable() const
{
    return m_languagePkgAvailable;
}


void
LanguagePackagesItem::setLanguagePkgAvailable( const QStringList& languagePkgAvailable )
{
    m_languagePkgAvailable = languagePkgAvailable;
}
