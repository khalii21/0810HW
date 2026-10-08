#include <windows.h>
#include <string>
#include <iostream>
#include <cstddef>

int main()
{
  std::string str;
  std::getline(std::cin, str);
  std::cout << str << '\n';

  HANDLE read, write;

  SECURITY_ATTRIBUTES sa{};

  sa.nLength = sizeof(SECURITY_ATTRIBUTES);
  sa.bInheritHandle = TRUE;
  sa.lpSecurityDescriptor = NULL;
  if (!CreatePipe(&read, &write, &sa, 256))
  {
    std::cerr << GetLastError() << '\n';
    return 1;
  }

  CloseHandle(read);
  CloseHandle(write);
}
