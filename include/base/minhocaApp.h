#ifndef MINHOCAAPP_H
#define MINHOCAAPP_H

#include "MooseApp.h"

class minhocaApp;

template <>
InputParameters validParams<minhocaApp>();

class minhocaApp : public MooseApp
{
public:
  minhocaApp(InputParameters parameters);
  virtual ~minhocaApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MINHOCAAPP_H */
