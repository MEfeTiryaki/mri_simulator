/*
 * OdeSolver.cpp
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#include "OdeSolver.h"

namespace ODE {

OdeSolver::OdeSolver()
    : currentTime_(0.0),
      stepSize_(0.0),
      maxTimeStep_(0),
      timeStep_(0.0)
{
  // TODO Auto-generated constructor stub

  //std::cout << "Ode solver works!!" << std::endl;
}

OdeSolver::~OdeSolver()
{
  // TODO Auto-generated destructor stub
}

void OdeSolver::solve(Eigen::VectorXd initialValue, double maxTime, int stepNumber)
{
  maxTimeStep_ = stepNumber;
  stepSize_ = maxTime / stepNumber;
  currentTime_ = 0.0;

  solutionMatrix_.resize(maxTimeStep_, initialValue.size());
  solutionMatrix_.row(0) = initialValue;

  for (timeStep_ = 0; timeStep_ < maxTimeStep_-1; timeStep_++) {
    solutionMatrix_.row(timeStep_ + 1) = solutionMatrix_.row(timeStep_) + updateEquation().transpose();

    currentTime_ = currentTime_ + stepSize_;
  }
}

Eigen::VectorXd OdeSolver::updateEquation()
{
  return Eigen::VectorXd::Zero(1);
}
;

} /* namespace ODE */
