#include<cstdio>
#include<vector>
#include<algorithm>
 
using namespace std;
 
struct pnt
{
	long long x,y;pnt(long long _x=0,long long _y=0):x(_x),y(_y){}
};
long long operator^(pnt A,pnt B){return A.x*B.y-B.x*A.y;}
pnt operator-(pnt A,pnt B){return pnt(A.x-B.x,A.y-B.y);}
bool operator<(pnt A,pnt B){if(A.x!=B.x)return A.x<B.x;return A.y<B.y;}
 
vector<pnt> C[2];
 
vector<pnt> Convex_Hull(vector<pnt> P)
{
	vector<pnt> U,D;
	sort(P.begin(),P.end());
	//puts("CONVEX");
	//for(int i=0;i<P.size();i++)printf("%lld %lld\n",P[i].x,P[i].y);puts("");
	D.push_back(P[0]);
	for(int i=1;i<P.size();i++)
	{
		while(D.size()>=2&&((P[i]-D[D.size()-2])^(D.back()-D[D.size()-2]))>=0)D.pop_back();
		D.push_back(P[i]);
	}
	//for(int i=0;i<D.size();i++)printf("%lld %lld\n",D[i].x,D[i].y);puts("");
	U.push_back(P.back());
	for(int i=P.size()-2;i>=0;i--)
	{
		while(U.size()>=2&&((P[i]-U[U.size()-2])^(U.back()-U[U.size()-2]))>=0)U.pop_back();
		U.push_back(P[i]);
	}
	//puts("??");
	for(int i=1;i<U.size()-1;i++)D.push_back(U[i]);return D;
}
 
long long dis(pnt P){return P.x*P.x+P.y*P.y;}
 
typedef unsigned long long ull;
const ull BASE=998244353;
 
ull A[2][500000],E[500000];
 
ull query(ull *A,int l,int r)
{
	return A[r]-A[l-1]*E[r-l+1];
}
 
 
int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){long long x=0,y=0;scanf("%lld%lld",&x,&y);C[0].push_back(pnt(x,y));}
	for(int i=0;i<m;i++){long long x=0,y=0;scanf("%lld%lld",&x,&y);C[1].push_back(pnt(x,y));}
	C[0]=Convex_Hull(C[0]);C[1]=Convex_Hull(C[1]);
	/*printf("%d %d\n",C[0].size(),C[1].size());
	for(int i=0;i<C[0].size();i++)printf("%lld %lld\n",C[0][i].x,C[0][i].y);puts("");
	for(int i=0;i<C[1].size();i++)printf("%lld %lld\n",C[1][i].x,C[1][i].y);puts("");*/
	if(C[0].size()!=C[1].size()){puts("NO");return 0;}
	int N=n;
	n=C[0].size();
	E[0]=1;for(int i=1;i<=4*n;i++)E[i]=E[i-1]*BASE;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			pnt P=C[i][j],Q=C[i][(j+1)%n],R=C[i][(j+2)%n];
			A[i][2*j+1]=dis(Q-P),A[i][2*j+2]=dis(R-P);
		}
		for(int j=2*n+1;j<=4*n;j++)A[i][j]=A[i][j-2*n];
		//if(N==33)for(int j=1;j<=2*n;j++)printf("%llu ",A[i][j]);puts("");
		for(int j=2;j<=4*n;j++)A[i][j]+=A[i][j-1]*BASE;
	}
	ull H=query(A[1],1,2*n);
	for(int i=1;i<=2*n;i+=2)if(H==query(A[0],i,i+2*n-1)){puts("YES");return 0;}
	puts("NO");
}