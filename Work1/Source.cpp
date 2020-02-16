#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include <codecvt>
#include <sstream>

using namespace std;

std::wstring readFile(const char* filename)
{
    std::wifstream wif(filename);
    wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}

std::string ConvertWideToANSI(const std::wstring& wstr)
{
    int num_chars = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
    std::string str;
    str.resize(num_chars);
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, &str[0], wstr.length(), NULL, NULL);
    return str;
}

std::wstring ConvertAnsiToWide(const std::string& str)
{
    int num_chars = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), NULL, 0);
    std::wstring wstr;
    wstr.resize(num_chars);
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), &wstr[0], num_chars);
    return wstr;
}

inline constexpr std::uint32_t str2int(const char* str, std::uint32_t hash = 2166136261UL) {
    return *str ? str2int(str + 1, (hash ^ *str) * 16777619ULL) : hash;
}

std::string GetLastErrorAsString()
{
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0)
        return std::string();

    LPSTR messageBuffer = nullptr;
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    std::string message(messageBuffer, size);

    LocalFree(messageBuffer);

    return message;
}

int main()
{
    string input = "";

    setlocale(LC_ALL, "Russian");

    cin >> input;

    int Error = 0;
    SYSTEM_INFO siSysInfo;

    ifstream fileANSII("ansii.txt");
    ifstream fileF("wide.txt");
    wofstream  fileWide("wide.txt");
    
    string line;
    wstring lineForWide;

    switch (str2int(input.c_str()))
    {
    case str2int("-e"):

        ShellExecuteA(NULL, NULL, "C:\\AbraKadabra.exe", NULL, NULL, SW_SHOWNORMAL);

        Error = GetLastError();

        cout << "Error = " << GetLastErrorAsString() << "\n";

        break;
    default:
    case str2int("-s"):

        GetSystemInfo(&siSysInfo);
        
        printf("Hardware information: \n");
        printf("  OEM ID: %u\n", siSysInfo.dwOemId);
        printf("  Number of processors: %u\n",
            siSysInfo.dwNumberOfProcessors);
        printf("  Page size: %u\n", siSysInfo.dwPageSize);
        printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
        printf("  Minimum application address: %lx\n",
            siSysInfo.lpMinimumApplicationAddress);
        printf("  Maximum application address: %lx\n",
            siSysInfo.lpMaximumApplicationAddress);
        printf("  Active processor mask: %u\n",
            siSysInfo.dwActiveProcessorMask);
        break;
    case str2int("-a"):
        while (getline(fileANSII, line))
        {
            wstring temp = L"";
            temp = ConvertAnsiToWide(line);

            if (temp != L"")
            {
                fileWide << temp << endl;
            }
        }
        break;
    case str2int("-u"):
        lineForWide = readFile("wide.txt");
        wcout << lineForWide;
        break;
    }
    
    system("pause");
	return 0;
}