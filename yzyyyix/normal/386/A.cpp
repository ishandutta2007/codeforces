#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,num[N],mx,ans,pos;

int main()
{
	int i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]>mx)
		{
			ans=mx;
			mx=num[i];
			pos=i;
		}
		else ans=max(ans,num[i]);
	}
	cout<<pos<<" "<<ans;
}