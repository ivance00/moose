[Problem]
  type = FEProblem
  solve = false
  kernel_coverage_check = false
[]

[Mesh]
  type = EBSDMesh
  filename = Ti_2Phase_28x28_Sqr_Marmot.txt
[]

[GlobalParams]
  op_num = 3
  var_name_base = gr
[]

[UserObjects]
  [./ebsd]
    type = EBSDReader
  [../]
[]

[ICs]
  [./PolycrystalICs]
    [./ReconVarIC]
      ebsd_reader = ebsd
      phase = 1
    [../]
  [../]
[]

[Variables]
  [./PolycrystalVariables]
  [../]
[]

[Executioner]
  type = Transient
  num_steps = 0
[]

[Outputs]
  exodus = true
[]
