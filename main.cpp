#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  ret = mymap.equal_range('4');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}
// #include "vector/vector.hpp"
// #include <iostream>
// #include <vector>

// class Foo
// {
// private:
//   int m_foo;

// public:
//   // single parameter constructor, can be used as an implicit conversion
//   // explicit Foo (int foo) : m_foo (foo) {}
//   Foo (int foo) : m_foo (foo) {}

//   int GetFoo () { return m_foo; }
// };

// void DoBar (Foo foo)
// {
//   int i = foo.GetFoo ();
//   std::cout << "i = " << i << std::endl;
// }

// int main ()
// {
//   DoBar (42);
// }

// map::equal_range