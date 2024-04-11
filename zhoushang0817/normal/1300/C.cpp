#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],c[N],t,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<30;j++)
			if((1<<j)&a[i])
				c[j]++;
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=0;j<30;j++)
			if(((1<<j)&a[i])&&c[j]==1)
				t+=(1<<j);
		if(t>A)
			swap(a[1],a[i]),A=t;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}