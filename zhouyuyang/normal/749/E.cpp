#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll b[N];
int p[N];
double ans;
int n;
void add(int x,int v){
	for (;x<=n;x+=x&(-x)) b[x]+=v;
}
ll ask(int x){
	ll s=0;
	for (;x;x-=x&(-x)) s+=b[x];
	return s;
} 
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++)
		scanf("%d",&x),p[x]=i;
	for (int i=1;i<=n;i++){
		ans+=1.0*(n-p[i]+1)/n/(n+1)*ask(p[i]);
		add(p[i],p[i]);
	}
	for (int i=1;i<=n;i++)
		b[i]=0;
	for (int i=n;i;i--){
		ans-=1.0*(n-p[i]+1)/n/(n+1)*ask(p[i]);
		add(p[i],p[i]);
	}
	for (int i=1;i<=n;i++)
		b[i]=0;
	for (int i=n;i;i--){
		ans+=ask(p[i]);
		add(p[i],1);
	}
	printf("%.10lf\n",ans);
}