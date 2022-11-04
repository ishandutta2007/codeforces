#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define Rep(i,j,k) for (int i=j;i>=k;i--)
using namespace std;
const int N=500005;
int cnt[N],rk[N],hei[N],sa[N];
int a[N],b[N],tmp[N],q[N*2];
int st[21][N],LG,n;
long long ans;
char s[N];
void getSA(){
	int l=1,r=n;
	For(i,1,n)
		if (s[i]=='(') sa[l++]=i;
		else sa[r--]=i;
	For(i,1,n)
		rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	for (int k=1;rk[sa[n]]<n;k<<=1){
		For(i,0,n) cnt[i]=0;
		For(i,1,n){
			a[i]=rk[i];
			b[i]=(i+k<=n?rk[i+k]:0);
			cnt[b[i]]++;
		}
		For(i,1,n) cnt[i]+=cnt[i-1];
		Rep(i,n,1) tmp[cnt[b[i]]--]=i;
		For(i,0,n) cnt[i]=0;
		For(i,1,n) cnt[a[i]]++;
		For(i,1,n) cnt[i]+=cnt[i-1];
		Rep(i,n,1) sa[cnt[a[tmp[i]]]--]=tmp[i];
		For(i,1,n)
			rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]||b[sa[i]]!=b[sa[i-1]]);
	}
	int v=0;
	For(i,1,n){
		if (rk[i]<n)
			for (;s[i+v]==s[sa[rk[i]+1]+v];v++);
		hei[rk[i]]=v?v--:0;
	}
}
int main(){
	scanf("%d%s",&n,s+1);
	getSA();
	st[0][n]=st[0][n+1]=n+1;
	For(i,0,n*2) q[i]=n+1;
	int cur=q[n]=n;
	Rep(i,n-1,0){
		if (s[i+1]==')') cur++;
		else q[cur--]=n+1;
		st[0][i]=q[cur];
		q[cur]=i;
	}
	for (bool jdb=1;jdb;){
		jdb=0; LG++;
		For(i,0,n+1){
			st[LG][i]=st[LG-1][st[LG-1][i]];
			if (st[LG][i]<=n)
				jdb=1;
		}
	}
	For(i,0,n-1){
		int over=i+1+hei[rk[i+1]];
		int cur=i;
		for (int j=LG;j>=0;j--)
			if (st[j][cur]<over)
				cur=st[j][cur];
		cur=st[0][cur];
		if (cur<=n){
			for (int j=LG;j>=0;j--)
				if (st[j][cur]<=n){
					ans+=1<<j;
					cur=st[j][cur];
				}
			ans++;
		}
	}
	printf("%lld",ans);
}