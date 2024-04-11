#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,m,lcp[N][N];
char str[N];
struct seg{
	int l,r;
	bool operator <(const seg &q) const {
		int t=lcp[l][q.l];
		if(t>=min(r-l+1,q.r-q.l+1))return r-l+1<q.r-q.l+1;
		return str[l+t]<str[q.l+t];
	}
}a[N*N];
ll K,f[N][N],s[N];
inline ll check(int mid){
	memset(f,0,sizeof(f));
	f[n+1][0]=1;int len=a[mid].r-a[mid].l+1;
	for(int k=1;k<=m;k++){
		s[n+1]=k==1;
		for(int i=n;i;i--){
			s[i]=min(s[i+1]+f[i][k-1],K);
			int t=lcp[i][a[mid].l];
			if(t<len && str[a[mid].l+t]<str[i+t])f[i][k]=s[i+t+1];
			else if(t>=len)f[i][k]=s[i+len];
		}
	}
	return f[1][m];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),K=read(),scanf("%s",str+1);
	for(int i=n;i;i--)
		for(int j=n;j;j--)
			lcp[i][j]=str[i]==str[j]?lcp[i+1][j+1]+1:0;
	int tot=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)a[++tot]={i,j};
	sort(a+1,a+tot+1);int l=1,r=tot;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)>=K)l=mid+1;
		else r=mid-1;
	}
	for(int i=a[r].l;i<=a[r].r;i++)putchar(str[i]);
	return 0;
}