//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "minhocaTestApp.h"
#include "minhocaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
minhocaTestApp::validParams()
{
  InputParameters params = minhocaApp::validParams();
  return params;
}

minhocaTestApp::minhocaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  minhocaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

minhocaTestApp::~minhocaTestApp() {}

void
minhocaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  minhocaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"minhocaTestApp"});
    Registry::registerActionsTo(af, {"minhocaTestApp"});
  }
}

void
minhocaTestApp::registerApps()
{
  registerApp(minhocaApp);
  registerApp(minhocaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
minhocaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  minhocaTestApp::registerAll(f, af, s);
}
extern "C" void
minhocaTestApp__registerApps()
{
  minhocaTestApp::registerApps();
}
