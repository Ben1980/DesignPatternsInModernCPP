#include <functional>

struct SingletonTester
{
  template <typename T>
  bool is_singleton(std::function<T*()> factory)
  {
    auto * object1 = factory();
    auto * object2 = factory();

    return object1 == object2;
  }
};

// Example of Singleton implementation with std::function and lambda
// struct SingletonTest {
//   int a{42};
// };
// 
// std::function<SingletonTest*()> wrongSingletonFactory = []() -> SingletonTest* { return new SingletonTest; };
// 
// std::function<SingletonTest*()> correctSingletonFactory = []() -> SingletonTest* { 
//   static SingletonTest test;
//   return &test; 
// };
// 
// could be also done with 
// auto correctSingletonFactoryWithAuto = []() -> SingletonTest* { 
//   static SingletonTest test;
//   return &test; 
// };
//
// SingletonTester tester;
// std::cout << tester.is_singleton(wrongSingletonFactory) << std::endl; //false
// std::cout << tester.is_singleton(correctSingletonFactory) << std::endl; //true
