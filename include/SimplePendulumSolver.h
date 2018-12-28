/*
 * SimplePendulumSolver.h
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#ifndef SimplePendulumSolver_H_
#define SimplePendulumSolver_H_

#include "RungeKutta.h"

namespace ODE {

class SimplePendulumSolver : public RungeKutta
{
 public:
  SimplePendulumSolver();
  virtual ~SimplePendulumSolver();

 protected:
  virtual Eigen::VectorXd F(double time, Eigen::VectorXd x) override;

 protected:
  Eigen::Matrix2d A_;

};

} /* namespace ODE */

#endif /* SimplePendulumSolver_H_ */
