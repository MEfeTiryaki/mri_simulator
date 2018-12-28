/*
 * PlotGui.cpp
 *
 *  Created on: 27 Dec 2018
 *      Author: efe
 */

#include "PlotGui.h"
#include "ui_plotgui.h"

PlotGui::PlotGui(QWidget *parent)
    : QMainWindow(parent),
    ui_(new Ui::PlotGui)
{
  ui_->setupUi(this);
}
PlotGui::~PlotGui()
{
  delete ui_;
}


void PlotGui::plot(Eigen::VectorXd x_eig, Eigen::VectorXd y_eig){
  QVector<double> x(x_eig.size()), y(y_eig.size()); // initialize with entries 0..100
  for (int i=0; i<x.size(); ++i)
  {
    x[i] = x_eig[i]; // x goes from -1 to 1
    y[i] = y_eig[i]; // let's plot a quadratic function
  }
  // create graph and assign data to it:
  ui_->customPlot->addGraph();
  ui_->customPlot->graph(0)->setData(x, y);
  // give the axes some labels:
  ui_->customPlot->xAxis->setLabel("x");
  ui_->customPlot->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  ui_->customPlot->xAxis->setRange(x_eig[0], x_eig[x_eig.size()-1]);
  ui_->customPlot->yAxis->setRange(y_eig.minCoeff(), y_eig.maxCoeff());
  ui_->customPlot->replot();
}

void PlotGui::makeTestPlot(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }

    // create graph and assign data to it:
    ui_->customPlot->addGraph();
    ui_->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui_->customPlot->xAxis->setLabel("x");
    ui_->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui_->customPlot->xAxis->setRange(-1, 1);
    ui_->customPlot->yAxis->setRange(0, 1);
    ui_->customPlot->replot();
}
