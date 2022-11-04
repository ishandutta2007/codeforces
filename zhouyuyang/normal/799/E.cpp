#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
int n,m,k,x,t1;
int v[N],tot[4],a[N],pos[4];
ll b[4][N],s[4][N],ans;
int getcnt(int t,int x,int y){
	for (int i=0;i<4;i++){
		pos[i]=upper_bound(b[i],b[i]+tot[i],t)-b[i];
		if (i==3) pos[i]=max(pos[i],x);
		else if (i) pos[i]=max(pos[i],y);
	}
	return pos[0]+pos[1]+pos[2]+pos[3];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	scanf("%d",&t1);
	for (int i=1;i<=t1;i++)
		scanf("%d",&x),a[x]|=1;
	scanf("%d",&t1);
	for (int i=1;i<=t1;i++)
		scanf("%d",&x),a[x]|=2;
	for (int i=1;i<=n;i++)
		b[a[i]][tot[a[i]]++]=v[i];
	for (int i=0;i<4;i++)
		sort(b[i],b[i]+tot[i]);
	for (int i=0;i<4;i++)
		for (int j=1;j<=tot[i];j++)
			s[i][j]=s[i][j-1]+b[i][j-1];
	ans=1e18;
	for (int i=0;i<=k&&i<=tot[3];i++){
		if (k-i>min(tot[1],tot[2])) continue;
		if (k*2-i>m) continue;
		int l=0,r=1e9;
		while (l<r){
			int mid=(l+r)/2;
			if (getcnt(mid,i,k-i)>=m)
				r=mid;
			else l=mid+1;
		}
		int cnt=getcnt(l,i,k-i);
		ll tmp=0;
		for (int j=0;j<4;j++)
			tmp+=s[j][pos[j]];
		tmp-=1ll*(cnt-m)*l;
		ans=min(ans,tmp);
	}
	printf("%lld",ans>1e17?-1:ans);
}