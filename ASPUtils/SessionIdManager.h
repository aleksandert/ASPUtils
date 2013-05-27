#include <stdio.h>
#include <windows.h>
#include <string>
#include <Wincrypt.h>

using namespace std;

class SessionIdManager
{
public:

	static HRESULT CreateSessionId(BSTR* sessionId);

};