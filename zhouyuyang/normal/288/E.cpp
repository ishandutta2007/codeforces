#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)%s
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
const int mo=1000000007;
const int N=100005;
struct node{
	int ans,lv,rv,T,sum;
	node pushup(int v){
		node a=*this;
		a.ans=(a.ans+1ll*(a.T+mo-1)*v%mo*v+1ll*v*(2ll*a.sum+2ll*mo-a.lv-a.rv))%mo;
		a.lv=(a.lv+v)%mo; a.rv=(a.rv+v)%mo;
		a.sum=(a.sum+1ll*a.T*v)%mo;
		return a;
	}
	node operator +(const node &b)const{
		if (!T) return b;
		if (!b.T) return *this;
		node c;
		c.ans=(ans+b.ans+1ll*rv*b.lv)%mo;
		c.T=(T+b.T)%mo; c.sum=(sum+b.sum)%mo;
		c.lv=lv; c.rv=b.rv;
		return c;
	}
};
node f[N][2][2];
bool vis[N][2][2];
char s[N],t[N];
int n,P[N];
node calc(int at,int D,int U){
	if (!at) return (node){0,0,0,1,0};
	if (vis[at][D][U]) return f[at][D][U];
	node &ans=f[at][D][U]; vis[at][D][U]=1;
	if ((s[at]-'0'<=4||!D)&&(4<=t[at]-'0'||!U))
		ans=ans+calc(at-1,D&(4==s[at]-'0'),U&(4==t[at]-'0')).pushup(4ll*P[at]%mo);
	if ((s[at]-'0'<=7||!D)&&(7<=t[at]-'0'||!U))
		ans=ans+calc(at-1,D&(7==s[at]-'0'),U&(7==t[at]-'0')).pushup(7ll*P[at]%mo);
	return ans;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(t+1);
	reverse(s+1,s+n+1);
	reverse(t+1,t+n+1);
	P[1]=1;
	For(i,2,n) P[i]=P[i-1]*10ll%mo;
	printf("%d",calc(n,1,1).ans);
}