/*
 * RungeKutta.h
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#ifndef RUNGEKUTTA_H_
#define RUNGEKUTTA_H_

#include "OdeSolver.h"

namespace ODE {

class RungeKutta : public OdeSolver
{
 public:
  RungeKutta();
  virtual ~RungeKutta();
  virtual Eigen::VectorXd updateEquation() override;


 protected:
  Eigen::VectorXd k1_;
  Eigen::VectorXd k2_;
  Eigen::VectorXd k3_;
  Eigen::VectorXd k4_;

};

} /* namespace ODE */



#endif /* RUNGEKUTTA_H_ */
