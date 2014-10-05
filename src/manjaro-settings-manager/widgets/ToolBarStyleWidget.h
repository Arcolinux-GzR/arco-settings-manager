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

#ifndef TOOLBARSTYLEWIDGET_H
#define TOOLBARSTYLEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <QRegion>
#include <QPalette>


class ToolBarStyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBarStyleWidget(QWidget *parent = 0);
    
protected:
    void paintEvent(QPaintEvent *);
    
};

#endif // TOOLBARSTYLEWIDGET_H
