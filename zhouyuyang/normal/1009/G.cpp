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
int v[100];
void upd(int at,int val){
	For(i,1,63) if (at&i) v[i]+=val;
}
bool check(){
	For(i,1,63) if (v[i]>0) return 0;
	return 1;
}
const int N=100005;
char s[N],ans[N];
int sta[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n) upd(1<<(s[i]-'a'),1);
	For(i,1,n) sta[i]=63;
	int lim; scanf("%d",&lim);
	For(i,1,lim){
		int at; scanf("%d%s",&at,s+1);
		int len=strlen(s+1); sta[at]=0;
		For(j,1,len) sta[at]|=1<<(s[j]-'a');
	}
	For(i,1,n) upd(sta[i],-1);
	For(i,1,n){
		upd(sta[i],1);
		For(j,0,5) if ((1<<j)&sta[i]){
			upd(1<<j,-1);
			if (check()){
				ans[i]=j+'a'; break;
			}
			upd(1<<j,1);
		}
		if (!ans[i])
			return puts("Impossible"),0;
	}
	For(i,1,n) putchar(ans[i]);
}