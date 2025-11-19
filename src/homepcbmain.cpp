#include "homepcbmain.h"
#include <QAction>
#include <QFileDialog>
#include <QToolButton>
#include <QCheckBox>


QMenu* HomePCBMain::fileMenuInitialize()
{
    QMenu* fileMenu = new QMenu ("File");
    auto actionOpen = new QAction("Open");
    actionOpen->setShortcut(Qt::CTRL + Qt::Key_O);
    connect(actionOpen,&QAction::triggered,[](bool flag){
        auto str = QFileDialog::getSaveFileName(nullptr,"Open Dialog","");
    });
    fileMenu->addAction(actionOpen);
    auto smenu = fileMenu->addMenu("Recent Files ");
    smenu->addAction("Test");
    fileMenu->addAction("Save");
    fileMenu->addSeparator();
    fileMenu->addAction("Quit");
    return fileMenu;

}
QMenu *HomePCBMain::editMenuInitialize()
{
    QMenu* editMenu = new QMenu("Edit");
    return editMenu;
}
QMenu *HomePCBMain::settingsMenuInitialize()
{
    QMenu* settingsMenu = new QMenu("Settings");
    return settingsMenu;
}
QMenuBar *HomePCBMain::menuInitialization()
{
    QMenuBar* menuBar = new QMenuBar();

    menuBar->addMenu(fileMenuInitialize());
    menuBar->addMenu(editMenuInitialize());
    menuBar->addMenu(settingsMenuInitialize());

    return menuBar;
}
QToolBar* HomePCBMain::graphicsToolsInitialize()
{
    QToolBar* graphicTools = new QToolBar("GraphicsToolsBar");
    //PreInitializatuion
    moveButton->setCheckable(true);

    graphicTools->setMovable(false);
    graphicTools->setFloatable(false);

    auto tb = new QToolButton ();
    auto action = new QAction("AddShapes");

    tb->setDefaultAction(action);
    auto menu = new QMenu();

    auto addLine = menu->addAction("Line");
    addLine->setCheckable(true);

    auto addpolygon = menu->addAction("Polygon");
    addpolygon->setCheckable(true);

    auto addEclipce = menu->addAction("Ellipce");
    addEclipce->setCheckable(true);

    auto addArch = menu->addAction("Arch");
    addArch->setCheckable(true);

    auto addRectangle = menu->addAction("Rectangle");
    addRectangle->setCheckable(true);


    tb->setPopupMode(QToolButton::InstantPopup);
    tb->setMenu(menu);

    graphicTools->addWidget(tb);
    graphicTools->addWidget(clearLinesButton);
    graphicTools->addWidget(moveButton);

    connect(addLine,&QAction::toggled,[this](bool flag){
        auto scene = dynamic_cast<ScenePCB*>(pcbViewer->scene());
        if(flag){
            scene->cursor()->spot()->show();//spotVisionToogle();
            scene->getLineCheckFlag(true);
            pcbTools->setVisible(true);
        }
        else{
            scene->cursor()->spot()->hide();
            pcbTools->setVisible(false);
            scene->getLineCheckFlag(false);
        }
    } );
    connect(clearLinesButton,&QPushButton::clicked, [&]{
        auto scene = pcbViewer->scene();
        if(auto itemsList = scene->items(); !itemsList.empty()){
            for(auto items : itemsList)
                if(dynamic_cast<LinePCB*>(items))
                    scene->removeItem(items);
        }
    });
    connect(moveButton,&QPushButton::toggled, pcbViewer ,[this](auto flag){
        if(flag)
            pcbViewer->setDragMode(QGraphicsView::RubberBandDrag);
        else
            pcbViewer->setDragMode(QGraphicsView::ScrollHandDrag);
    });
    return graphicTools;
}
QToolBar *HomePCBMain::pcbToolsInitialize()
{

    QToolBar* pcbTools = new QToolBar("PCBToolsBar");
    pcbTools->setMovable(false);
    pcbTools->setFloatable(false);
    pcbTools->addWidget(new CrossArrowToolBar(dynamic_cast<ScenePCB*>(pcbViewer->scene())->cursor()));
    return pcbTools;
}
HomePCBMain::HomePCBMain(QWidget *parent)
    : QMainWindow(parent){
    setMenuBar(menuInitialization());

    QDockWidget*  w = new QDockWidget("GCode Widget");
    w->setFloating(false);
    w->setWidget(new GCodeWidget());
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea,w);
    connect( dynamic_cast<ScenePCB*>(pcbViewer->scene()), &ScenePCB::itemAppented,
             dynamic_cast<GCodeWidget*>(w->widget()), &GCodeWidget::addShape );

    //addToolBarsToMainWindow
    addToolBar(Qt::ToolBarArea::LeftToolBarArea, graphicsToolsInitialize());
    auto fileActions = new QToolBar("FileActions");
    auto openAction  = fileActions->addWidget(new QPushButton("Open"));

    fileActions->addWidget(new QPushButton("Save"));
    fileActions->addWidget(new QPushButton("Close"));
    fileActions->setMovable(false);
    fileActions->setFloatable(false);
    fileActions->addSeparator();

    addToolBar(Qt::ToolBarArea::TopToolBarArea,fileActions);
    pcbTools = pcbToolsInitialize();
    addToolBar(Qt::ToolBarArea::TopToolBarArea, pcbTools) ;
    pcbTools->setVisible(false);
    //statusBar
    statusBar->addWidget(crossArrowsPos);
    setStatusBar(statusBar);

    //Watch crossArrows coordinates from Scene inside StatusBar
    connect(dynamic_cast<ScenePCB*>(pcbViewer->scene()), &ScenePCB::getCursorPosition, [this](auto&& mousePoint){
        crossArrowsPos->setText("X " + QString().setNum(mousePoint.x()) + "\n" + "Y " + QString().setNum(mousePoint.y()) );
    });

    setCentralWidget(pcbViewer);

}

HomePCBMain::~HomePCBMain() {}
