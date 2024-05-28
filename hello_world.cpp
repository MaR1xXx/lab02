#include <iostream>
#include <string>
int
main()
{
  std::string name;
  // name input
  getline(std::cin, name);

  // output
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}

