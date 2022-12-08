#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int DP[4096];

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	for(int i=0; i<=n; i++)
		DP[i]=-8000;
	DP[0]=0;
	
	for(int i=1; i<=n; i++)
	{
		if(i>=a) DP[i]=max(DP[i],DP[i-a]+1);
		if(i>=b) DP[i]=max(DP[i],DP[i-b]+1);
		if(i>=c) DP[i]=max(DP[i],DP[i-c]+1);
	}
	cout << DP[n] << endl;
}