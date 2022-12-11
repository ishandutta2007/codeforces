#include <bits/stdc++.h>
using namespace std;

typedef __int64 LL;

int main()
{
	int N, A;
	int flag = 0;
	cin >> N;
	for(int i=0; i < N; ++i)
		cin >> A,
		flag += (A^1);
	if( (N==1 && !flag) || (N>1 && flag == 1) ) puts("YES");
	else puts("NO");
	return 0;
}