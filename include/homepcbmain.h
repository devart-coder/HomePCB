#ifndef HOMEPCBMAIN_H
#define HOMEPCBMAIN_H

#include <QMainWindow>
#include "scenepcb.h"
#include "crossarrows.h"
#include "crossarrowstoolbar.h"
#include "graphicsviewer.h"
#include "gcodewidget.h"
#include <QStatusBar>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QDockWidget>
class HomePCBMain : public QMainWindow
{
private:
    Q_OBJECT
    GraphicsViewer* pcbViewer = new GraphicsViewer(new ScenePCB(QRectF(0,0,250*10,250*10)));
    QLabel* crossArrowsPos = new QLabel("X \nY ");
    QStatusBar* statusBar = new QStatusBar();
    QPushButton* clearLinesButton = new QPushButton("clearLines");
    QPushButton* moveButton = new QPushButton("move");
    QToolBar* pcbTools = nullptr;
private:
    QMenuBar* menuInitialization();
    QMenu* fileMenuInitialize();
    QMenu* editMenuInitialize();
    QMenu* settingsMenuInitialize();
    QToolBar* graphicsToolsInitialize();
    QToolBar* pcbToolsInitialize();
public:
    HomePCBMain(QWidget *parent = nullptr);
    ~HomePCBMain();
signals:
    void addLine(bool flag);
};
#endif // HOMEPCBMAIN_H
