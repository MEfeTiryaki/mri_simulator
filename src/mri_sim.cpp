//============================================================================
// Name        : mri_sim.cpp
// Author      : Mehmet Efe Tiryaki
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "ode_solver/OdeSolver.h"
#include "ode_solver/RungeKutta.h"
#include "ode_solver/SimplePendulumSolver.h"


#include "PlotGui.h"

using namespace std;
using namespace ODE;
int main()
{

  Eigen::MatrixXd deneme;
  deneme = Eigen::MatrixXd::Zero(5, 5);

  SimplePendulumSolver solver = SimplePendulumSolver();

  Eigen::Vector2d initValue;
  initValue << 0.5, 0;
  solver.solve(initValue, 10.0, 1000);

  Eigen::VectorXd t = Eigen::VectorXd::Zero(1000);
  for (int i=0; i<1000; i++)
    t[i] = 10.0/1000.0*i;
  //cout << solver.getSolution() << endl;

  int argc;
  char **argv;
  QApplication app(argc, argv);
  PlotGui gui;

  gui.plot(t,solver.getSolution().col(0));
  gui.fillBelow(QColor(0,0,255,20));
  gui.holdOn();
  gui.scatter(t,solver.getSolution().col(1),Qt::red);
  std::vector<std::string> legendNames(2);
  legendNames[0] = "v";
  legendNames[1] = "a" ;
  gui.legend(legendNames);
  gui.setAxis(0.0,10.0,-5.0,5.0);
  gui.show();


  return app.exec();
}
