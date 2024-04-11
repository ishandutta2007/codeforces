#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

const int N=1000005;
ll ans;
char s[N],t[N];
int sum[N][3][3];
int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	For(i,1,n) s[i]=(s[i]=='B'?2:s[i]=='G');
	For(i,1,m) t[i]=(t[i]=='B'?2:t[i]=='G');
	Rep(i,m,1){
		CPY(sum[i],sum[i+1]);
		if (i>1) sum[i][t[i-1]][t[i]]++;
	}
	int l=1,r=1;
	for (int i=1;i<=n&&l<=m;i++){
		for (;r<=m&&s[i]!=t[r];r++);
		if (r<=m&&s[i]==t[r]) r++;
		if (l<r){
			ans+=r-l;
			if (i>=2&&s[i]!=s[i-1])
				ans-=sum[l][s[i]][s[i-1]]-sum[r][s[i]][s[i-1]];
		}
		if (l<=m&&s[i]==t[l]) l++;
	}
	printf("%lld\n",ans);
}