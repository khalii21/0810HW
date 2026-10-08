#include <windows.h>
#include <iostream>
#include <string>

DWORD rcv(DWORD& err, HANDLE rd, char* b, size_t k)
{
  DWORD rcved = 0;
  while (rcved < k)
  {
    DWORD readed = 0;
    BOOL st = ReadFile(rd, b + rcved, static_cast< DWORD >(k - rcved), &readed, NULL);
    if (!st)
    {
      err = GetLastError();
      break;
    }
    rcved += readed;
  }
  return rcved;
}

DWORD rcvSize(DWORD& err, HANDLE rd, size_t& size)
{
    return rcv(err, rd, reinterpret_cast<char*>(&size), sizeof(size));
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "the argument is not specified" << '\n';
    return 1;
  }
  HANDLE read = reinterpret_cast< HANDLE >(std::stoull(argv[1]));
}
