#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int f[4096];

int main()
{
	int n, k;
	cin >> n >> k;
	
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i++)
		cin >> f[i];
	
	sort(f, f+n);
	
	long long ans=0;
	for(int i=0; i<n; i++)
	{
		if(i%k==0){ ans+=2*(f[n-i-1]-1);}
	}
	cout << ans << endl;
}