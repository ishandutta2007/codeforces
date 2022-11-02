#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check(int mid)
{
	int a2=mid/2,a3=mid/3,a6=mid/6;
	a2-=a6,a3-=a6;
	return a6>=max(0,n-a2)+max(0,m-a3);
}
int main()
{	
	cin>>n>>m;
	int l=0,r=10000000;
	while(l!=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}