#include<bits/stdc++.h>
using namespace std;
const int N=11;
const char C[]={'a','c','o','d','e','f','o','r','c','e','s'};
long long k,a[N],s,c;
int main()
{
	cin>>k;
	for(int i=1;i<N;i++)
		a[i]=1;
	while(1)
	{
		s=1;
		for(int i=1;i<N;i++)
			s*=a[i];
		if(s>=k)
			break;
		a[c%10+1]++,c++;
	}
	for(int i=1;i<N;i++)
		for(int j=1;j<=a[i];j++)
			cout<<C[i];
	return 0;
}