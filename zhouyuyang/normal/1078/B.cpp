#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define inf 0x3f3f3f3f
using namespace std;
int cnt[105],n,ans;
bitset<10005> s[105],t[105];
void calc(int ban,int v){
	For(j,0,v) s[j]=0;
	s[0][0]=1;
	int tp=0;
	For(i,1,100)
		For(j,1,i==ban?v-1:cnt[i]){
			Rep(k,tp,0) s[k+1]|=s[k]<<i;
			tp=min(tp+1,v);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	int type=0;
	For(i,1,100) type+=(cnt[i]!=0);
	calc(-1,n);
	For(i,0,100) t[i]=s[i];
	For(i,1,100) For(j,1,cnt[i]){
		calc(i,j);
		if (s[j][i*j]^t[j][i*j])
			ans=max(ans,j);
	}
	printf("%d\n",type==2?n:ans);
}
/*
9
1 3 4 5 5 5 5 5 8
*/