#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
int c[N],B[N],O[N],R[N];
char s[N];
int n,k,z[N];
ll solve(int *x,int *y){
	if (!x[0]||!y[0]) return 0;
	ll ans=x[1]+y[1];
	z[0]=0;
	for (int i=2;i<=x[0];i++) z[++z[0]]=x[i];
	for (int i=2;i<=y[0];i++) z[++z[0]]=y[i];
	sort(z+1,z+z[0]+1,greater<int>());
	if (z[0]+2<k) return 0;
	for (int i=1;i<=k-2;i++) ans+=z[i];
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1) return puts("-1"),0;
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		if (s[i]=='W') B[++B[0]]=c[i];
		else if (s[i]=='R') R[++R[0]]=c[i];
		else O[++O[0]]=c[i];
	sort(O+1,O+O[0]+1,greater<int>());
	sort(R+1,R+R[0]+1,greater<int>());
	sort(B+1,B+B[0]+1,greater<int>());
	ll ans=max(solve(O,R),solve(O,B));
	printf("%lld\n",ans?ans:-1);
}