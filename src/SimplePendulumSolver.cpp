/*
 * SimplePendulumSolver.cpp
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#include "SimplePendulumSolver.h"

namespace ODE {

SimplePendulumSolver::SimplePendulumSolver():
    RungeKutta()
{
  // TODO Auto-generated constructor stub
  A_ << 0, 1, -9.81*1 , 0 ;

  std::cout << "Pendulum works!!" << std::endl;
}

SimplePendulumSolver::~SimplePendulumSolver()
{
  // TODO Auto-generated destructor stub
}


Eigen::VectorXd SimplePendulumSolver::F(double time, Eigen::VectorXd x) {
  return A_*x ;
}



} /* namespace ODE */
