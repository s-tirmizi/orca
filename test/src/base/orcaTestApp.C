//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "orcaTestApp.h"
#include "orcaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
orcaTestApp::validParams()
{
  InputParameters params = orcaApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

orcaTestApp::orcaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  orcaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

orcaTestApp::~orcaTestApp() {}

void
orcaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  orcaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"orcaTestApp"});
    Registry::registerActionsTo(af, {"orcaTestApp"});
  }
}

void
orcaTestApp::registerApps()
{
  registerApp(orcaApp);
  registerApp(orcaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
orcaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  orcaTestApp::registerAll(f, af, s);
}
extern "C" void
orcaTestApp__registerApps()
{
  orcaTestApp::registerApps();
}
