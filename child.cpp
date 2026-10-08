#include <windows.h>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "the argument is not specified" << '\n';
    return 1;
  }
  HANDLE read = reinterpret_cast< HANDLE >(std::stoull(argv[1]));
}
