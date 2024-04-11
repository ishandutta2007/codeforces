#include <iostream>
#include <string>
using namespace std;

const int N = 500;

string A[N], B[N];
	

int main()
{
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		if (B[i] == "rat")
			cout << A[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (B[i] == "child" || B[i] == "woman")
			cout << A[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (B[i] == "man")
			cout << A[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		if (B[i] == "captain")
			cout << A[i] << endl;
	}
	return 0;
}