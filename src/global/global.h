/*
 *  Manjaro Settings Manager
 *  Roland Singer <roland@manjaro.org>
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

#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QStringList>
#include <QList>
#include <QHash>
#include <QMap>
#include <QRegExp>
#include <QDebug>
#include <QProcess>
#include <QDir>
#include "const.h"


class Global
{
public:
    struct LanguagePackage {
        QString languagePackage, parentPackage, locale;
    };

    struct KeyboardInfo {
        QString description;
        QMap< QString, QString > variants;
    };

    struct Locale {
        QString description, locale;
    };

    struct LocaleInfo {
        QString locale, language, territory, description;
    };

    struct User {
        QString username, homePath;
        int uuid;
    };

    struct Group {
        QString name;
        QStringList members;
    };

    static int runProcess(QString cmd, QStringList args, QStringList writeArgs, QString & error);

    static QString getConfigValue(QString value, QString config);
    static bool setConfigValue(QString value, QString text, QString config);

    static bool getLanguagePackages(QList<Global::LanguagePackage> *availablePackages, QList<Global::LanguagePackage> *installedPackages);
    static bool isSystemUpToDate();

    static QMap< QString, KeyboardInfo > getKeyboardLayouts();
    static QMap<QString, QString> getKeyboardModels();
    static bool getCurrentXorgKeyboardLayout(QString & layout, QString & variant);

    static QList<Global::LocaleInfo> getAllEnabledLocales();
    static QString getCurrentLocale();
    static QString getCurrentFormats();
    static QHash<QString, QHash<QString, QList<Global::Locale> > > getAllLocales();
    static QString localeToValidLocaleGenString(QString locale);

    static QList<Global::User> getAllUsers();
    static QList<Global::Group> getAllGroups();

    static QStringList getAllInstalledKernels();
    static QStringList getAllAvailableKernels();
    static QString getRunningKernel();
    static QString getKernelVersion(const QString &package, const bool local);
    static QStringList getKernelModules(const QString &package);
    static QStringList getLtsKernels();
    static QStringList getRecommendedKernels();

private:
    struct LocaleSplit {
        QString language, territory;
    };

    static QStringList getAllInstalledPackages(const QStringList & checkPackages);
    static QStringList getAllAvailableRepoPackages(const QStringList & checkPackages);
    static QList<LocaleSplit> getAllEnabledLocalesSplit();
    static QList<Global::LocaleInfo> getLocaleInfoList();
};


#endif // GLOBAL_H
