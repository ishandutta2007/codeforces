#include<bits/stdc++.h>
#define N 100100
using namespace std;

int n,m,ans,pre[N];
vector<int>have[N],tmp;

inline int gcd(int u,int v)
{
    for(;v;)
    {
	u%=v;
	swap(u,v);
    }
    return u;
}

inline void kmp()
{
    int i,j;
//    for(i=0;i<tmp.size();i++) printf("%d ",tmp[i]);puts("");
    for(i=0,j=-1;i<tmp.size();i++)
    {
	for(;j>=0&&tmp[j]!=tmp[i];j=pre[j]);
	pre[i]=j++;
    }
//    for(i=0;i<tmp.size();i++) printf("%d ",pre[i]);puts("");puts("");
    int t=tmp.size()-pre[tmp.size()-1]-1;
    if(tmp.size()%t)
    {
	puts("No");
	exit(0);
    }
    ans=gcd(ans,tmp.size()/t);
    if(ans==1)
    {
	puts("No");
	exit(0);
    }
}

int main()
{
    int i,j,k,p,q;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&p,&q);
	if(p>q) swap(p,q);
	int t=min(q-p,p+n-q);
	have[t].push_back(p);
	have[t].push_back(q);
    }
    for(i=1;i<=n;i++)
    {
	if(!have[i].size()) continue;
	if(have[i].size()==1)
	{
	    puts("No");
	    return 0;
	}
	sort(have[i].begin(),have[i].end());
	have[i].push_back(have[i][0]+n);
	tmp.clear();
	for(j=1;j<have[i].size();j++) tmp.push_back(have[i][j]-have[i][j-1]);
	kmp();
    }
    puts("Yes");
}