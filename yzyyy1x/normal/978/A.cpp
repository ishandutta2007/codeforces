#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,m,a[N],b[N],cnt[N];
bool vis[N];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;int tot=n;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=n;i++)
		if(cnt[a[i]]>1)vis[i]=1,cnt[a[i]]--,tot--;	
		cout<<tot<<endl;
	for(int i=1;i<=n;i++)
		if(!vis[i])cout<<a[i]<<" "; 	
}