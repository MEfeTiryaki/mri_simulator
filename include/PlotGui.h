/*
 * PlotGui.h
 *
 *  Created on: 27 Dec 2018
 *      Author: efe
 */

#ifndef PLOTGUI_H_
#define PLOTGUI_H_
#pragma once

#include <iostream>
#include <Eigen/Core>
#include <QMainWindow>

namespace Ui{
  class PlotGui;
}

class PlotGui : public QMainWindow
{
  Q_OBJECT
 public:
  explicit PlotGui(QWidget *parent = nullptr);

   ~PlotGui();

public:
  void plot(Eigen::VectorXd x, Eigen::VectorXd y);

private slots:
  void makeTestPlot();


 private:
  Ui::PlotGui *ui_;
};

#endif /* PLOTGUI_H_ */
