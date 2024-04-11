#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
long long n,h,a[N],s,A;
int main()
{
	cin>>n>>h;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sort(a+1,a+i+1),s=0;
		if(i&1)
			s=a[1];
		for(int j=i;j>=2;j-=2)
			s+=max(a[j],a[j-1]);
		if(s<=h)
			A=i;
	}
	cout<<A;
	return 0;
}