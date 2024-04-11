#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
struct Graph
{
    int ndn,edn,last[101];
    int u[20001],v[20001],nxt[20001];
    void init(int n1) 
	{
	    ndn=n1; 
		edn=0; 
		memset(last,-1,sizeof(last));
	}
    void add(int u1, int v1)
    {
        u[edn]=u1; v[edn]=v1;
        nxt[edn]=last[u1];
        last[u1]=edn++;
    }
};
int N,M;
pa in[101];
int col[101];
char ans[101];
Graph G;
bool color(int u,int c)
{
    col[u]=c;
    for(int e=G.last[u],v; ~e; e=G.nxt[e])
    {
        v=G.v[e];
        if(col[v]!=-1&&col[v]!=1-c) return 0;
        if(col[v]==-1&&!color(v,1-c)) return 0;
    }
    return 1;
}
bool ins(int x,int y)
{
    int l1,r1,l2,r2;
    l1=in[x].first; 
	r1=in[x].second;
    l2=in[y].first; 
	r2=in[y].second;
    int in0=0,in1=0;
    if(l1<l2&&l2<r1) 
	in0=1;
    else if(l2<l1||r1<l2) 
	in0=-1;
    if(l1<r2&&r2<r1) 
	in1=1;
    else if(r2<l1||r1<r2)
	in1=-1;
    if(in0*in1==-1) return 1;
    else return 0;
}
int main()
{
    while(cin>>N>>M)
    {
        G.init(M);
        for(int i=1,l,r;i<=M;i++)
        {
            cin>>l>>r;
            in[i].first=min(l,r);
            in[i].second=max(l,r);
        }
        for(int i=1;i<=M;i++) 
		    for(int j=1;j<=M;j++) 
			    if(i!=j&&ins(i,j))
                    G.add(i,j);
        memset(col,-1,sizeof(col));
        bool ok=1;
        for(int i=1; i<=M; i++) 
		if(col[i]==-1)
        {
            if(!color(i,0)) 
			{
			    ok=0; 
				break;
			}
        }
        for(int i=0;i<M;i++) ans[i]=col[i+1]?'i':'o';
        ans[M]=0;
        if(ok) 
		cout<<ans<<endl;
        else 
		cout<<"Impossible"<<endl;
    }
    return 0;
}