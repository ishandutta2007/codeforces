#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<30)
using namespace std;

const int N=100005;
vector<int> di[N];
int s[8];
int main(){
	For(i,1,N-1) For(j,1,(N-1)/i) di[i*j].PB(i);
	int T;
	scanf("%d",&T);
	while (T--){
		int x,y,z,ans=0;
		scanf("%d%d%d",&x,&y,&z);
		memset(s,0,sizeof(s));
		For(i,0,di[x].size()-1){
			int fl=1;
			if (y%di[x][i]==0) fl|=2;
			if (z%di[x][i]==0) fl|=4;
			s[fl]++;
		}
		For(i,0,di[y].size()-1){
			if (x%di[y][i]==0) continue;
			int fl=2;
			if (z%di[y][i]==0) fl|=4;
			s[fl]++;
		}
		For(i,0,di[z].size()-1){
			if (x%di[z][i]==0) continue;
			if (y%di[z][i]==0) continue;
			s[4]++;
		}
		For(i,1,7) For(j,i,7) For(k,j,7){
			if ((i|j|k)!=7) continue;
			if ((i!=1)+(j!=1)+(k!=1)<=1) continue;
			if ((i!=2)+(j!=2)+(k!=2)<=1) continue;
			if ((i!=4)+(j!=4)+(k!=4)<=1) continue;
			if (i!=j&&i!=k&&j!=k) ans+=s[i]*s[j]*s[k];
			else if (i==k) ans+=s[i]*(s[i]+1)*(s[i]+2)/6;
			else if (i==j) ans+=s[i]*(s[i]+1)/2*s[k];
			else ans+=s[i]*s[j]*(s[j]+1)/2;
		}
		printf("%d\n",ans);
	}
}
//x==y==z di[gcd(x,y,z)]
//x==y!=z di[gcd(