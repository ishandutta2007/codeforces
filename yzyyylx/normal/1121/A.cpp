#include<bits/stdc++.h>
#define N 110
using namespace std;

int n,m,K,ans,mx[N],num[N],id[N];
bool use[N];

int main()
{
    int i,j,p;
    cin>>n>>m>>K;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=1;i<=n;i++) scanf("%d",&id[i]),mx[id[i]]=max(mx[id[i]],num[i]);
    for(i=1;i<=K;i++)
    {
	scanf("%d",&p);
	if(num[p]==mx[id[p]]&&!use[id[p]]) use[id[p]]=1;
	else ans++;
    }
    cout<<ans;
}