#include <iostream>
#include <windows.h>
using namespace std;

//long long Factorial(int num) {
//	long long res = 1;
//	for (int i = 1; i <= num; i++)
//	{
//		res *= i;
//	}
//	return res;
//}

//HANDLE CreateThread(
//	LPSECURITY_ATTRIBUTES   lpThreadAttributes,
//	SIZE_T                  dwStackSize,
//	LPTHREAD_START_ROUTINE  lpStartAddress,
//	LPVOID lpParameter,
//	DWORD                   dwCreationFlags,
//	LPDWORD                 lpThreadId
//);

DWORD WINAPI Factorial(LPVOID iNum) {
	long long n = 1;
	for (int i = 1; i <= (int)iNum; i++)
	{
		n *= i;
	}
	cout << "n = " << n << "\n";
	return 0;
}

int main()
{
	int num1 = 6;
	int num2 = 5;
	HANDLE hThread[2];
	DWORD IDThread;
	hThread[0] = CreateThread(NULL, 0, Factorial, (void*)num1, 0, &IDThread);
	hThread[1] = CreateThread(NULL, 0, Factorial, (void*)num2, 0, &IDThread);
	if (hThread[0] == NULL || hThread[1] == NULL) {
		return GetLastError();
	}
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	return 0;
}


