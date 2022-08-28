#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 100005
#define BB 2*1024*128*2
#define MX 5
#define BT 45

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	int seg[BB];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=-1;
	}
	void add(int k,int x)
	{
		k+=mum-1;
		seg[k]=max(seg[k],x);
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -1;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			int vl=get(a,b,k*2+1,l,(l+r)/2);
			int vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
	int get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
}seg;
int n,m,s;
ll T;
P to[MX][SIZE][BT];
ll len[MX][SIZE][BT];
vector <int> vx;

int get_p(int x){return lower_bound(vx.begin(),vx.end(),x)-vx.begin();}
int main()
{
	scanf("%d %d",&n,&m);m--;
	scanf("%d %lld",&s,&T);s--;
	vx.push_back(m);
	vx.push_back(m+1);
	vx.push_back(s);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<vx.size();i++)
	{
		int x=vx[i];
		seg.init(2*n+2);
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				to[i][j][0]=P(i,n-1);
				len[i][j][0]=1;
				seg.add(0,0);
				seg.add(n,0);
			}
			else if(x<=m)
			{
				int v=(int) (((ll) j*(ll) (j+1)/2LL)%n);
				int l=m+1,r=n-1;
				int a=x+v-r,b=x+v-l;
				if(a<0) a+=n,b+=n;
				int g=seg.get(a,b+1);
				if(g==-1)
				{
					to[i][j][0]=P(i,n-j-1);
					len[i][j][0]=2*j+1;
				}
				else
				{
					int u=(int) (((ll) g*(ll) (g+1)/2LL)%n);
					int t=x+v-u;
					if(t<0) t+=n;
					if(t>=n) t-=n;
					int s=t-g-1;
					if(s<0) s+=n;
					//E
					if(m-s<=t-m-1)
					{
						int p=get_p(m+1);
						if(m-s<t-m-1)
						{
							len[i][j][0]=(j-g-1)+2*(m-s)+2;
							to[i][j][0]=P(p,j-len[i][j][0]);
						}
						else
						{
							len[i][j][0]=(j-g-1)+2*(m-s)+1;
							to[i][j][0]=P(p,j-len[i][j][0]);
						}
					}
					else
					{
						int p=get_p(m+1);
						len[i][j][0]=(j-g-1)+2*(t-m-1)+1;
						to[i][j][0]=P(p,j-len[i][j][0]);
					}
				}
				seg.add(v,j);
				seg.add(v+n,j);
			}
			else
			{
				int v=(int) (((ll) j*(ll) (j+1)/2LL)%n);
				int l=0,r=m;
				int a=l+v-x,b=r+v-x;
				if(a<0) a+=n,b+=n;
				int g=seg.get(a,b+1);
				if(g==-1)
				{
					to[i][j][0]=P(i,n-j-1);
					len[i][j][0]=2*j+1;
				}
				else
				{
					int u=(int) (((ll) g*(ll) (g+1)/2LL)%n);
					int t=x-v+u;
					if(t<0) t+=n;
					if(t>=n) t-=n;
					int s=t+g+1;
					if(s>=n) s-=n;
					//
					if(s-m-1<=m-t)
					{
						int p=get_p(m);
						if(s-m-1<m-t)
						{
							len[i][j][0]=(j-g-1)+2*(s-m-1)+2;
							to[i][j][0]=P(p,j-len[i][j][0]);
						}
						else
						{
							len[i][j][0]=(j-g-1)+2*(s-m-1)+1;
							to[i][j][0]=P(p,j-len[i][j][0]);
						}
					}
					else
					{
						int p=get_p(m);
						len[i][j][0]=(j-g-1)+2*(m-t)+1;
						to[i][j][0]=P(p,j-len[i][j][0]);
					}
				}
				seg.add(v,j);
				seg.add(v+n,j);
			}
		}
	}
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<vx.size();j++)
		{
			for(int k=0;k<n;k++)
			{
				P p=to[j][k][i];
				to[j][k][i+1]=to[p.first][p.second][i];
				len[j][k][i+1]=len[j][k][i]+len[p.first][p.second][i];
				len[j][k][i+1]=min(len[j][k][i+1],T+1);
			}
		}
	}
	for(int i=0;i<vx.size();i++)
	{
		if(vx[i]==s)
		{
			s=i;
			break;
		}
	}
	for(int i=BT-1;i>=0;i--)
	{
		if(len[s][T%n][i]<=T)
		{
			//printf("%d %lld %d : %lld\n",s,T,i,len[s][T%n][i]);
			P p=to[s][T%n][i];
			T-=len[s][T%n][i];
			s=p.first;
		}
	}
	s=vx[s];
	//printf("%d %lld\n",s,T);
	while(T>0)
	{
		if(s<=m) s+=T%n;
		else s-=T%n;
		if(s>=n) s-=n;
		if(s<0) s+=n;
		T--;
	}
	printf("%d\n",s+1);
	return 0;
}