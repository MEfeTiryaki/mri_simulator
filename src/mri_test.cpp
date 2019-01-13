

#include <iostream>
#include <vector>
#include <Eigen/Core>
#include "ode_solver/Simulator.h"
#include "ode_solver/RungeKutta.h"
#include "plotgui/ScopeGui.h"
#include <boost/bind.hpp>

using namespace ODE;
using namespace std;
//using namespace std::placeholders;
double gamma_ = 42.5e6;
double B_0 = 1.5;
double B_1 = 0.01;
double w =  42.5e6*1.5 * 1;
double M_0 = 0.8 ;
double T_1 = 0.001;
double T_2 = 0.0002;

double w_r = gamma_*B_0;
double v = w/2/M_PI;
double T_90 = M_PI/(2*gamma_*B_1/2);
double T_applied = 7.3920e-06;

Eigen::VectorXd BlockEquation(double t, Eigen::VectorXd y){


  //std::cout << "t = " <<  t << std::endl;
  //std::cout << "y = "<< y.transpose() << std::endl;
  Eigen::VectorXd dy =  Eigen::VectorXd::Zero(3);
  if (t<T_applied){
    //std::cout << "y = "<< y.transpose() << std::endl;
    dy[0] = gamma_ * B_0 * y[1];
    dy[1] = gamma_ * (-B_0 *y[0] + B_1 * cos(w*t)*y[2]);
    dy[2] = -gamma_ * B_1 * cos(w*t)*y[01];
  }else{
    dy[0] = gamma_ * B_0 * y[1] - y[0]/T_2;
    dy[1] = gamma_ * (-B_0 *y[0] + B_1 * cos(w*t)*y[2])- y[1]/T_2;
    dy[2] = -gamma_ * B_1 * cos(w*t)*y[1] + (M_0-y[2])/T_1;
  }
  //std::cout << "dy = "<< dy.transpose() << std::endl;
  return dy;

}

int main() {

  // Scope
  int argc;
  char **argv;
  QApplication app(argc, argv);
  ScopeGui gui;

  // Solver
  RungeKutta* solver = new RungeKutta();
  solver->setDynamics(boost::bind(&BlockEquation, _1, _2));

  double maxTime = 7.3920e-06*5;
  int stepNumber = 10000;
  double stepSize = 7.3920e-08;
  Eigen::Vector3d initValue;
  initValue << 0, 0, M_0;


  // Simulator
  Simulator sim;
  sim.initilize(solver);
  sim.setRealTimeFactor(100000);

  sim.start(initValue, maxTime, stepNumber);
  //solver.start(initValue, stepSize);
  gui.setScopeNumber(3);
  std::vector<std::string> legendNames(0);
  legendNames.push_back("Mx");
  gui.setXAxisRange(maxTime);
  gui.setYAxis(-0.5,0.5);
  gui.addTimeSignal(boost::bind(&Simulator::getBuffer,&sim,-1));
  gui.addStopFunction(boost::bind(&Simulator::setStop,&sim, _1));
  gui.addClearFunction(boost::bind(&Simulator::clearBuffer,&sim));

  gui.addGraph(0, boost::bind(&Simulator::getBuffer,&sim, 0));
  gui.legend(0,legendNames);

  gui.addGraph(1, boost::bind(&Simulator::getBuffer,&sim, 1));
  legendNames[0] = "My" ;
  gui.legend(1,legendNames);

  gui.addGraph(2, boost::bind(&Simulator::getBuffer,&sim, 2));
  legendNames[0] = "Mz" ;
  gui.legend(2,legendNames);

  gui.stopGui(true);

  gui.show();

  return app.exec();
}
