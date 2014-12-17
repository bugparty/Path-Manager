#include <windows.h>
#include <tchar.h>
#include "util.h"
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
HKEY GetRegistry(TCHAR* path, HWND hwnd)
{
    HKEY hk;

    int result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, path, NULL, KEY_READ, &hk);

    if(result != ERROR_SUCCESS) {
	if(result == ERROR_FILE_NOT_FOUND) {

	    MessageBox(hwnd, _T("no such key in RegOpenKeyEx"), _T("title"), MB_ICONWARNING);
	}

	else {
	    Error2Msgbox(result, hwnd);
	}
	return NULL;
    }
    return hk;
}
VOID Error2Msgbox(DWORD dwError, HWND hwnd)
{
    HLOCAL hlocal = NULL; // Buffer that gets the error message string

    // Get the error code`s textual description
    BOOL fOk = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
                             NULL,
                             dwError,
                             MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED),
                             (LPTSTR)&hlocal,
                             0,
                             NULL);
    if(hlocal != NULL) {
	MessageBox(hwnd, (LPTSTR)hlocal, _T("Error Message is"), MB_OK);
	LocalFree(hlocal);
    }
}
void DebugRegistrySubkey(HKEY hk, HWND hwnd)
{
    TCHAR achKey[MAX_KEY_LENGTH];        // buffer for subkey name
    DWORD cbName;                        // size of name string
    TCHAR achClass[MAX_PATH] = TEXT(""); // buffer for class name
    DWORD cchClassName = MAX_PATH;       // size of class string
    DWORD cSubKeys = 0;                  // number of subkeys
    DWORD cbMaxSubKey;                   // longest subkey size
    DWORD cchMaxClass;                   // longest class string
    DWORD cValues;                       // number of values for key
    DWORD cchMaxValue;                   // longest value name
    DWORD cbMaxValueData;                // longest value data
    DWORD cbSecurityDescriptor;          // size of security descriptor
    FILETIME ftLastWriteTime;            // last write time

    DWORD i, retCode;

    TCHAR achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

    // Get the class name and the value count.
    retCode = RegQueryInfoKey(hk,                    // key handle
                              achClass,              // buffer for class name
                              &cchClassName,         // size of class string
                              NULL,                  // reserved
                              &cSubKeys,             // number of subkeys
                              &cbMaxSubKey,          // longest subkey size
                              &cchMaxClass,          // longest class string
                              &cValues,              // number of values for this key
                              &cchMaxValue,          // longest value name
                              &cbMaxValueData,       // longest value data
                              &cbSecurityDescriptor, // security descriptor
                              &ftLastWriteTime);     // last write time

    // Enumerate the subkeys, until RegEnumKeyEx fails.
    TCHAR buf[1024];
    wsprintf(buf, _T("has %i subkeys, %i values"), cSubKeys, cValues);
    MessageBox(hwnd, buf, _T("debug"), MB_ICONINFORMATION);
}
