#include "vector/vector.hpp"
#include <iostream>
#include <vector>

class Foo
{
private:
  int m_foo;

public:
  // single parameter constructor, can be used as an implicit conversion
  // explicit Foo (int foo) : m_foo (foo) {}
  Foo (int foo) : m_foo (foo) {}

  int GetFoo () { return m_foo; }
};

void DoBar (Foo foo)
{
  int i = foo.GetFoo ();
  std::cout << "i = " << i << std::endl;
}

int main ()
{
  DoBar (42);
}