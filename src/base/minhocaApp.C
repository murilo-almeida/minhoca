#include "minhocaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
minhocaApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

minhocaApp::minhocaApp(InputParameters parameters) : MooseApp(parameters)
{
  minhocaApp::registerAll(_factory, _action_factory, _syntax);
}

minhocaApp::~minhocaApp() {}

void
minhocaApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"minhocaApp"});
  Registry::registerActionsTo(af, {"minhocaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
minhocaApp::registerApps()
{
  registerApp(minhocaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
minhocaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  minhocaApp::registerAll(f, af, s);
}
extern "C" void
minhocaApp__registerApps()
{
  minhocaApp::registerApps();
}
