#include "orcaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
orcaApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

orcaApp::orcaApp(InputParameters parameters) : MooseApp(parameters)
{
  orcaApp::registerAll(_factory, _action_factory, _syntax);
}

orcaApp::~orcaApp() {}

void
orcaApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<orcaApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"orcaApp"});
  Registry::registerActionsTo(af, {"orcaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
orcaApp::registerApps()
{
  registerApp(orcaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
orcaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  orcaApp::registerAll(f, af, s);
}
extern "C" void
orcaApp__registerApps()
{
  orcaApp::registerApps();
}
