#include "minhocaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<minhocaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

minhocaApp::minhocaApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  minhocaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  minhocaApp::associateSyntax(_syntax, _action_factory);
}

minhocaApp::~minhocaApp() {}

void
minhocaApp::registerApps()
{
  registerApp(minhocaApp);
}

void
minhocaApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
minhocaApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
minhocaApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
minhocaApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
minhocaApp__registerApps()
{
  minhocaApp::registerApps();
}

extern "C" void
minhocaApp__registerObjects(Factory & factory)
{
  minhocaApp::registerObjects(factory);
}

extern "C" void
minhocaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  minhocaApp::associateSyntax(syntax, action_factory);
}
