#pragma once

#include "Qt/QMainWindow.h"

class QAction;
class QLabel;
class QVTKWidget;

class MainWin : public QMainWindow
{
//  Q_OBJECT

public:
  MainWin(void);
  ~MainWin(void);

protected:
//  void closeEvent(QCloseEvent *event);

private slots:
  void newFile();
  void open();
  bool save();
  bool saveAs();
  void about();

private:
  void CreateActions();

  void SetRenderWindow(QVTKWidget* mainViewWidget);
  void SetRenderWindowForTest(QVTKWidget* mainViewWidget);


private:
  QVTKWidget* _mainViewWidget;

  QAction* _newAct;
  QAction* _openAct;
  QAction* _aboutQtAction;
};

