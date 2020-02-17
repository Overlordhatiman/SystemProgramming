#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

//std::wstring readFile(const char* filename)
//{
//    std::wifstream wif(filename);
//    wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
//    std::wstringstream wss;
//    wss << wif.rdbuf();
//    return wss.str();
//}
//
//std::string ConvertWideToANSI(const std::wstring& wstr)
//{
//    int num_chars = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.length(), NULL, 0, NULL, NULL);
//    std::string str;
//    str.resize(num_chars);
//    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, &str[0], wstr.length(), NULL, NULL);
//    return str;
//}
//
//std::wstring ConvertAnsiToWide(const std::string& str)
//{
//    int num_chars = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), NULL, 0);
//    std::wstring wstr;
//    wstr.resize(num_chars);
//    MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), &wstr[0], num_chars);
//    return wstr;
//}


void ANSIToUnicode(HANDLE ReadF, HANDLE WriteF);
void UnicodeToANSI(HANDLE ReadF, HANDLE WriteF);
string GetLastErrorAsString();
CHAR DataBuferOnMByte[(MAXBYTE) * sizeof(CHAR)] = { 0 };
WCHAR DataBuferOnWChar[(MAXBYTE) * sizeof(WCHAR)] = { 0 };
DWORD CountReadCh = 0;
DWORD CountChangedCh = 0;
DWORD CountWriteCh = 0;
LPCWSTR fileANSII = L"ansii.txt";
LPCWSTR fileWide = L"wide.txt";
HANDLE ReadF;
HANDLE WriteF;

void clearing()
{
    for (int i = 0; i < MAXBYTE * sizeof(CHAR); i++)
    {
        DataBuferOnMByte[i] = 0;
    }
    for (int i = 0; i < MAXBYTE * sizeof(WCHAR); i++)
    {
        DataBuferOnWChar[i] = 0;
    }
}

//ansi to utf
void ANSIToUnicode(HANDLE ReadF, HANDLE WriteF)
{
    clearing();
    CountReadCh = 0;
    CountChangedCh = 0;
    CountWriteCh = 0;

    do {
        if (!ReadFile(ReadF, DataBuferOnMByte, (MAXBYTE - 1) * sizeof(CHAR), &CountReadCh, NULL))
        {
            cout << "Error: " << GetLastErrorAsString() << endl;
            return;
        }
        CountChangedCh = MultiByteToWideChar(CP_ACP, 0, DataBuferOnMByte, -1, DataBuferOnWChar, CountReadCh * sizeof(WCHAR));
        if (!WriteFile(WriteF, DataBuferOnWChar, (CountChangedCh - 1) * sizeof(WCHAR), &CountWriteCh, NULL))
        {
            cout << "Error: " << GetLastErrorAsString() << endl;
            return;
        }
    } while (CountReadCh == MAXBYTE);
    printf(("Transcoding complete.\n"));
}

//utf to ansi
void UnicodeToANSI(HANDLE InF, HANDLE OutF)
{
    clearing();
    CountReadCh = 0;
    CountChangedCh = 0;
    CountWriteCh = 0;
    if (!ReadFile(InF, DataBuferOnWChar, 2, &CountReadCh, NULL))
    {
        cout << "Error: " << GetLastErrorAsString() << endl;
    }
    else if (*DataBuferOnWChar == 0xFEFF || *DataBuferOnWChar == 0xFFFE)
    {
        do {
            if (!ReadFile(InF, DataBuferOnWChar, (MAXBYTE - 1) * sizeof(WCHAR), &CountReadCh, NULL))
            {
                cout << "Error: " << GetLastErrorAsString() << endl;
                return;
            }
            CountChangedCh = WideCharToMultiByte(CP_MACCP, 0, DataBuferOnWChar, -1, DataBuferOnMByte, CountReadCh, NULL, NULL);
            if (!WriteFile(OutF, DataBuferOnMByte, CountChangedCh - 1, &CountWriteCh, NULL))
            {
                cout << "Error: " << GetLastErrorAsString() << endl;
                return;
            }
        } while (CountReadCh == MAXBYTE);
        printf(("Transcoding complete.\n"));
    }
    else
    {
        printf(("Error:\n"));
        printf(("It`s not Unicode Text!\n"));
    }
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

bool CreateFileForWork()
{
    ReadF = CreateFile(fileANSII,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (ReadF == INVALID_HANDLE_VALUE) {
        cout << "Error input file : ";
        cout << "Error: " << GetLastErrorAsString() << endl;
        return true;
    }
    WriteF = CreateFile(fileWide,
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (WriteF == INVALID_HANDLE_VALUE) {
        cout << "Error out file: ";
        cout << "Error: " << GetLastErrorAsString() << endl;
        return true;
    }

    return false;
}

int main()
{
    string input = "";

    setlocale(LC_ALL, "Russian");

    cin >> input;

    int Error = 0;
    SYSTEM_INFO siSysInfo;
    
    switch (str2int(input.c_str()))
    {
    case str2int("-e"):

        ShellExecuteA(NULL, NULL, "C:\\AbraKadabra.exe", NULL, NULL, SW_SHOWNORMAL);
        
        cout << "Error: " << GetLastErrorAsString() << "\n";

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
        if (!CreateFileForWork())
        {
            UnicodeToANSI(ReadF, WriteF);
        }
        break;
    case str2int("-u"):
        if (!CreateFileForWork())
        {
            ANSIToUnicode(ReadF, WriteF);
        }
        break;
    }
    
    system("pause");
	return 0;
}