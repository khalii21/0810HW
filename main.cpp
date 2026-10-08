#include <windows.h>
#include <string>
#include <iostream>
#include <cstddef>

DWORD stringsize(DWORD& err, HANDLE wr, size_t size)
{
  return send(err, wr, reinterpret_cast< const char* >(&size), sizeof(size));
}

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

  PROCESS_IFORMATION pi{};
  STARTUPINFOA si{};

  si.cb = sizeof(si);
  std::string cmd = std::string(argv[1]) + ' ' + std::to_string(reinterpret_cast< DWORD_PTR >(read));
  if (!CreateProcessA(argv[1], &cmd[0], NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
  {
    CloseHandle(read);
    CloseHandle(write);
    std::cerr << "main: " << GetLastError() << '\n';
    return 1;
  }
  CloseHandle(read);
  CloseHandle(write);
}
