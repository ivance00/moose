/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef COMPUTEAXISYMMETRICRZINCREMENTALSTRAIN_H
#define COMPUTEAXISYMMETRICRZINCREMENTALSTRAIN_H

#include "Compute2DIncrementalStrain.h"

/**
 * ComputeAxisymmetricRZIncrementalStrain defines a strain increment only
 * for incremental strains in an Axisymmetric simulation.
 * The COORD_TYPE in the Problem block must be set to RZ.
 */
class ComputeAxisymmetricRZIncrementalStrain : public Compute2DIncrementalStrain
{
public:
  ComputeAxisymmetricRZIncrementalStrain(const InputParameters & parameters);

protected:
  virtual void initialSetup();

  /// Computes the current deformation gradient for axisymmetric problems, where
  ///  \f$ \epsilon_{\theta} = \frac{u_r}{r} \f$
  virtual Real computeDeformGradZZ();

  /// Computes the old  deformation gradient for axisymmetric problems, where
  ///  \f$ \epsilon_{\theta-old} = \frac{u_{r-old}}{r_{old}} \f$
  virtual Real computeDeformGradZZold();

  /// the old value of the first component of the displacements vector
  const VariableValue & _disp_old_0;
};

#endif //COMPUTEAXISYMMETRICRZINCREMENTALSTRAIN_H
