/*
 * SingleSpinSimulation.h
 *
 *  Created on: 21 Dec 2018
 *      Author: efe
 */

#ifndef SingleSpinSimulation_H_
#define SingleSpinSimulation_H_

#include "RungeKutta.h"
#include "ScopeGui.h"

namespace ODE {

class SingleSpinSimulation : public BaseSolver,public ScopeGui
{
 public:
  SingleSpinSimulation();
  virtual ~SingleSpinSimulation();

 protected:
  virtual Eigen::VectorXd F(double time, Eigen::VectorXd x) override;
  virtual void addData() override;

 protected:
   ScopeGui gui_;
   Eigen::Matrix2d A_;

};

} /* namespace ODE */


#endif /* SingleSpinSimulation_H_ */
