/*
 * SingleSpinSimulation.cpp
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#include "SingleSpinSimulation.h"

namespace ODE {


SingleSpinSimulation::SingleSpinSimulation():
  gui_()
{
  gui_.addGraph();
  gui_.show();
}


SingleSpinSimulation::~SingleSpinSimulation()
{
  // TODO Auto-generated destructor stub
}


Eigen::VectorXd SingleSpinSimulation::F(double time, Eigen::VectorXd x) {
  return A_*x ;
}

void SingleSpinSimulation::addData() {

}

} /* namespace ODE */
