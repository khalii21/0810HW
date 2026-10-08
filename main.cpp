#include <windows.h>
#include <string>
#include <iostream>
#include <cstddef>

DWORD send(DWORD& err, HANDLE wr, const char* a, size_t k)
{
  DWORD r = 0;
  while (r < k)
  {
    DWORD written = 0;
    BOOL st = WriteFile(wr, b + r, static_cast< DWORD >(k - r), &written, NULL);
    if !(st)
    {
      err = GetLastError();
      break;
    }
    r += written;
  }
  return r;
}

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
