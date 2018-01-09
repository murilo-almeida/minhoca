#include "minhocaTestApp.h"
#include "minhocaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<minhocaTestApp>()
{
  InputParameters params = validParams<minhocaApp>();
  return params;
}

minhocaTestApp::minhocaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  minhocaApp::registerObjectDepends(_factory);
  minhocaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  minhocaApp::associateSyntaxDepends(_syntax, _action_factory);
  minhocaApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    minhocaTestApp::registerObjects(_factory);
    minhocaTestApp::associateSyntax(_syntax, _action_factory);
  }
}

minhocaTestApp::~minhocaTestApp() {}

void
minhocaTestApp::registerApps()
{
  registerApp(minhocaApp);
  registerApp(minhocaTestApp);
}

void
minhocaTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
minhocaTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
minhocaTestApp__registerApps()
{
  minhocaTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
minhocaTestApp__registerObjects(Factory & factory)
{
  minhocaTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
minhocaTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  minhocaTestApp::associateSyntax(syntax, action_factory);
}
