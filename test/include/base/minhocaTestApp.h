#ifndef MINHOCATESTAPP_H
#define MINHOCATESTAPP_H

#include "MooseApp.h"

class minhocaTestApp;

template <>
InputParameters validParams<minhocaTestApp>();

class minhocaTestApp : public MooseApp
{
public:
  minhocaTestApp(InputParameters parameters);
  virtual ~minhocaTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MINHOCATESTAPP_H */
