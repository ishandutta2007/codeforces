#include <bits/stdc++.h>
using namespace std;
const int N=5005,S=50005;
int n,m;
map <int,int> badp;
int f[S],p[S],pcnt;
int a[N],g[N];
void Get_Prime(int S){
	pcnt=0;
	for (int i=2;i<=S;i++){
		if (f[i])
			continue;
		p[++pcnt]=i;
		for (int j=i*2;j<=S;j+=i)
			f[j]=1;
	}
}
int F(int x){
	int ans=0;
	for (int i=1;p[i]*p[i]<=x;i++)
		if (x%p[i]==0){
			int val=badp[p[i]]==1?-1:1;
			while (x%p[i]==0)
				x/=p[i],ans+=val;
		}
	if (x>1)
		ans+=badp[x]==1?-1:1;
	return ans;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	Get_Prime(S-1);
	scanf("%d%d",&n,&m);
	badp.clear();
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while (m--){
		int b;
		scanf("%d",&b);
		badp[b]=1;
	}
	int tot=0;
	for (int i=1;i<=n;i++)
		tot+=F(a[i]);
	g[1]=a[1];
	for (int i=2;i<=n;i++)
		g[i]=gcd(g[i-1],a[i]);
	int ans=tot,prod=1;
	for (int i=n;i>=1;i--){
		g[i]/=prod;
		int val=F(g[i]);
		if (val<0){
			prod*=g[i];
			ans-=val*i;
		}
	}
	printf("%d",ans);
	return 0;
}