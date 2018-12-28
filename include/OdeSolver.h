/*
 * OdeSolver.h
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#ifndef ODESOLVER_H_
#define ODESOLVER_H_

#include <Eigen/Core>

#include <iostream>
namespace ODE {

class OdeSolver
{
 public:
  OdeSolver();
  virtual ~OdeSolver();
  void solve(Eigen::VectorXd initialValue, double maxTime, int stepNumber);
  // virtual decleration of updateEquation
  virtual Eigen::VectorXd updateEquation();

  Eigen::MatrixXd getSolution()
  {
    return solutionMatrix_;
  }
  ;
 protected:

  virtual Eigen::VectorXd F(double time, Eigen::VectorXd x)
  {
    return Eigen::VectorXd::Zero(1);
  }
  ;

 protected:
  // simulation time step
  double stepSize_;
  // current time in simulation
  double currentTime_;
  //  time step of the simulation
  int timeStep_;
  int maxTimeStep_;
  // solution matrix to be filled during calculation
  Eigen::MatrixXd solutionMatrix_;

};

} /* namespace ODE */

#endif /* ODESOLVER_H_ */
