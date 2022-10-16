#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const long double PI=acos(-1),RANG=PI/12,EPS=0.4;

struct pnt
{
	long double x,y;pnt(long double _x=0,long double _y=0):x(_x),y(_y){}
}P[2500];
pnt rotate(pnt P,long double RANG)
{
	return pnt(P.x*cos(RANG)-P.y*sin(RANG),P.x*sin(RANG)+P.y*cos(RANG));
}
pnt read_pnt()
{
	pnt P;scanf("%Lf%Lf",&P.x,&P.y);return rotate(P,RANG);
}
pnt operator-(pnt A,pnt B){return pnt(A.x-B.x,A.y-B.y);}
long double area(pnt A,pnt B,pnt C)
{
	B=B-A,C=C-A;return abs(C.x*B.y-B.x*C.y)/2;
}

bool operator<(pnt A,pnt B){return A.x<B.x;}
int rk[2500],pos[2500];

struct query
{
	long double k;int i,j;query(int _i,int _j):i(_i),j(_j){k=(P[i].y-P[j].y)/(P[i].x-P[j].x);}
};
vector<query> Q;
bool operator<(query A,query B){return A.k<B.k;}

void print_pnt(pnt P)
{
	P=rotate(P,-RANG);printf("%d %d\n",(int)floor(P.x+0.1),(int)floor(P.y+0.1));
}

int main()
{
	int n=0;long long S=0;scanf("%d%lld",&n,&S);
	for(int i=1;i<=n;i++)P[i]=read_pnt();
	sort(P+1,P+n+1);for(int i=1;i<=n;i++)rk[i]=i,pos[i]=i;
	for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)Q.push_back(query(i,j));
	sort(Q.begin(),Q.end());//int ans=0;
	bool fl=0;
	for(int i=0;i<Q.size();i++)
	{
		int u=Q[i].i,v=Q[i].j;if(pos[u]>pos[v])swap(u,v);
		int l=pos[v]+1,r=n+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			long double x=area(P[u],P[v],P[rk[mid]]);if(x>=S-EPS)r=mid;else l=mid+1;
		}
		if(l<=n&&area(P[u],P[v],P[rk[l]])<=S+EPS)
		{
			puts("Yes");print_pnt(P[u]),print_pnt(P[v]),print_pnt(P[rk[l]]);
			fl=1;break;
		}
		
		l=0,r=pos[u]-1;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			long double x=area(P[u],P[v],P[rk[mid]]);if(x>=S-EPS)l=mid;else r=mid-1;
		}
		if(l>=1&&area(P[u],P[v],P[rk[l]])<=S+EPS)
		{
			puts("Yes");print_pnt(P[u]),print_pnt(P[v]),print_pnt(P[rk[l]]);
			fl=1;break;
		}
		
		swap(rk[pos[u]],rk[pos[v]]);swap(pos[u],pos[v]);
	}
	if(!fl)puts("No");
}