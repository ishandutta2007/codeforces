#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
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
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005;
char s[N];
ull a[64][3200];
ull b[64][3200];
int cnt[65536];
int count(ull x){
	return cnt[x&65535]+cnt[(x>>16)&65535]
		  +cnt[(x>>32)&65535]+cnt[x>>48];
}
int main(){
	scanf("%s",s);
	For(i,0,63) for (int j=0;s[i+j];j++)
		if (s[i+j]=='1') a[i][j>>6]|=1ull<<(j&63);
	scanf("%s",s);
	For(i,0,63) for (int j=0;s[i+j];j++)
		if (s[i+j]=='1') b[i][j>>6]|=1ull<<(j&63);
	for (int i=0;i<1<<16;i++) cnt[i]=cnt[i/2]+(i&1);
	int Q; scanf("%d",&Q);
	while (Q--){
		int x,y,len,ans=0;
		scanf("%d%d%d",&x,&y,&len);
		int i=x>>6,j=y>>6; x&=63; y&=63;
		for (;len>=64;len-=64,i++,j++)
			ans+=count(a[x][i]^b[y][j]);
		ans+=count((a[x][i]^b[y][j])&((1ull<<len)-1));
		printf("%d\n",ans);
	}
}