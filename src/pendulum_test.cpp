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
#include "ode_solver/Euler.h"
#include "ode_solver/EulerModified.h"
#include "ode_solver/RungeKutta.h"
#include "ode_solver/SimplePendulumSolver.h"


#include "PlotGui.h"

using namespace std;
using namespace ODE;
int main()
{

  // Initial state
  Eigen::Vector2d initValue;
  initValue << 0.5, 0;
  Eigen::VectorXd t = Eigen::VectorXd::Zero(1000);
  for (int i=0; i<1000; i++)
    t[i] = 10.0/1000.0*i;

  //  Runge Kutta
  SimplePendulumSolver<RungeKutta> solverKutta = SimplePendulumSolver<RungeKutta>();
  solverKutta.solve(initValue, 10.0, 1000);

  SimplePendulumSolver<Euler> solverEuler = SimplePendulumSolver<Euler>();
  solverEuler.solve(initValue, 10.0, 1000);

  SimplePendulumSolver<EulerModified> solverEulerModified = SimplePendulumSolver<EulerModified>();
  solverEulerModified.solve(initValue, 10.0, 1000);


  int argc;
  char **argv;
  QApplication app(argc, argv);
  PlotGui gui;

  gui.plot(t,solverKutta.getSolution().col(0));
  gui.holdOn();
  //gui.plot(t,solverEuler.getSolution().col(0),Qt::red);
  //gui.plot(t,solverEulerModified.getSolution().col(0),Qt::magenta);

  //std::vector<std::string> legendNames(2);
  //legendNames[0] = "Runge Kutta";
  //legendNames[1] = "Euler" ;
  //gui.legend(legendNames);
  gui.setAxis(0.0,10.0,-1.0,1.0);
  gui.show();


  return app.exec();
}
