#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,n,a[100005],top,cnt[100005]={0};
	cin>>n;
	top=n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==top)
		{
			cout<<a[i]<<" ";
			top--;
			while(cnt[top]==1)
			{
				cout<<top<<" ";
				cnt[top]=0;
				top--;
			}
		}
		else
		{
			cnt[a[i]]++;
		}
		cout<<endl;
	}
}