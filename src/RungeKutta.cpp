/*
 * RungeKutta.cpp
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#include "RungeKutta.h"

namespace ODE {

RungeKutta::RungeKutta():
    OdeSolver()
{
  // TODO Auto-generated constructor stub

  //std::cout << "Runge kutta works!!" << std::endl;
}

RungeKutta::~RungeKutta()
{
  // TODO Auto-generated destructor stub
}

Eigen::VectorXd RungeKutta::updateEquation()
{
  //std::cout << "Runge kutta works!!" << std::endl;
  k1_.resize(this->solutionMatrix_.cols());
  k2_.resize(this->solutionMatrix_.cols());
  k3_.resize(this->solutionMatrix_.cols());
  k4_.resize(this->solutionMatrix_.cols());
  Eigen::VectorXd x = this->solutionMatrix_.row(this->timeStep_);
  k1_ = this->stepSize_ *  this->F(this->currentTime_,x);
  k2_ = this->stepSize_ *  this->F(this->currentTime_+ this->stepSize_/2 , x + 0.5 *k1_);
  k3_ = this->stepSize_ *  this->F(this->currentTime_+ this->stepSize_/2 , x + 0.5 *k2_);
  k4_ = this->stepSize_ *  this->F(this->currentTime_+ this->stepSize_ , x + k3_);
  return (k1_ + 2 *k2_ + 2 *k3_ + k4_)/6;
}


} /* namespace ODE */
