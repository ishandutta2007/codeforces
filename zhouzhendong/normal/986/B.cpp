#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N],p[N];
int c[N];
void add(int x,int d){
	for (;x<=n;x+=x&-x)
		c[x]+=d;
}
int sum(int x){
	int ans=0;
	for (;x>0;x-=x&-x)
		ans+=c[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]]=i;
	memset(c,0,sizeof c);
	int ans=0;
	for (int i=1;i<=n;i++){
		ans^=(p[i]-1-sum(p[i]-1))&1;
		add(p[i],1);
	}
	puts(ans==n*3%2?"Petr":"Um_nik");
	return 0;
}