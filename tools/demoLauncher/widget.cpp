/****************************************************************************
**
** Copyright (C) 2013 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Enterprise Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "widget.h"
#include <QDir>
#include <QGridLayout>
#include <QApplication>
#include "graphicsbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(800, 600);

    m_appFolder = QDir(QApplication::applicationDirPath());
#ifdef Q_OS_MAC
    // The executable is inside an application bundle (a folder) on OSX
    m_appFolder.cdUp();
    m_appFolder.cdUp();
    m_appFolder.cdUp();
#endif

    QDir imageFolder = m_appFolder;
    imageFolder.cdUp();
    imageFolder.cdUp();
    imageFolder.cd("doc");
    imageFolder.cd("images");

    // Create push buttons for starting the executables
    QGridLayout* demosLayout = new QGridLayout;

    GraphicsButton *button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() + "demos_audio.png", m_appFolder, "audio", this);
    demosLayout->addWidget(button, 0, 0);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"demos_callout.png", m_appFolder, "callout", this);
    demosLayout->addWidget(button, 0, 1);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"demo_chartthemes_blue_cerulean.png", m_appFolder, "chartthemes", this);
    demosLayout->addWidget(button, 0, 2);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"demos_nesteddonuts.png", m_appFolder, "nesteddonuts", this);
    demosLayout->addWidget(button, 1, 0);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"examples_zoomlinechart1.png", m_appFolder, "zoomlinechart", this);
    demosLayout->addWidget(button, 1, 1);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"examples_stackedbarchartdrilldown1.png", m_appFolder, "stackedbarchartdrilldown", this);
    demosLayout->addWidget(button, 1, 2);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"piechart_customization.png", m_appFolder, "piechartcustomization", this);
    demosLayout->addWidget(button, 2, 0);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"examples_datetimeaxis.png", m_appFolder, "datetimeaxis", this);
    demosLayout->addWidget(button, 2, 1);

    button = new GraphicsButton(imageFolder.absolutePath() + QDir::separator() +"examples_donutbreakdown.png", m_appFolder, "donutbreakdown", this);
    demosLayout->addWidget(button, 2, 2);

    setLayout(demosLayout);
}

Widget::~Widget()
{
}