#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) ((x)*(x))
using namespace std;

const int N=200005;
int n,S,T,sz;
int a[N],pos[N];
map<int,int> mp,id;
set<int> s[N];
bool vis[N]; 
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void exgcd(int x,int y,int &a,int &b){
	if (!y){a=1,b=0; return;}
	exgcd(y,x%y,b,a); b-=x/y*a;
}
int main(){
	scanf("%d%d",&T,&n);
	For(i,1,n){
		int x; scanf("%d",&x);
		if (i>1) a[i]=(a[i-1]+x)%T;
		if (!mp[a[i]]) mp[a[i]]=vis[i]=1;
		S=(S+x)%T;
	}
	int G=gcd(S,T),x,y;
	S/=G; T/=G; exgcd(S,T,x,y);
	For(i,1,n){
		int z=a[i]%G;
		if (!id[z]) id[z]=++sz;
		pos[i]=1ll*x*(a[i]-z)/G%T;
		s[id[z]].insert(pos[i]); 
	}
	For(i,1,n){
		if (!vis[i]){
			putchar('0');
			putchar(' ');
			continue;
		}
		int z=id[a[i]%G];
		set<int>::iterator it;
		it=s[z].LB(pos[i]); it++;
		if (it!=s[z].end())
			printf("%d ",(*it)-pos[i]);
		else printf("%d ",(*s[z].begin())+T-pos[i]);
	} 
}