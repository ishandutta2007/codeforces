#include<bits/stdc++.h>
#define xxx 1000000
#define ll long long
using namespace std;

int n,a[xxx];
struct B{
	int v,cnt;
}b[xxx+233];
ll ans=1e16,c1,c2;

int np[xxx+233]={0},p[xxx+233],g=0,pos[xxx+233];
void PRE(){
	for (int i=2;i<=xxx;i++){
		if (!np[i]){
			p[pos[i]=++g]=i;
			b[g].v=i;
			for (int j=i+i;j<=xxx;j+=i){
				np[i]=1;
			}
		}
	}
}

void add(int x){
	for (int i=1;p[i]*p[i]<=x;i++){
		if (x%p[i]==0){
			b[i].cnt++;
		}
		while (x%p[i]==0) x/=p[i];
	}
	if (x>1){
		b[pos[x]].cnt++;
	}
}

void doit(int x){
	ll t=0;
	for (int i=1;i<=n;i++){
		if (a[i]%x==0) continue;
		t+=min(c1,(ll)(x-a[i]%x)*c2);
		if (t>=ans) return;
	}
	ans=t;
}

bool cmp(B b1,B b2){
	return b1.cnt>b2.cnt;
}

int main(){
	PRE();
	scanf("%d%I64d%I64d",&n,&c1,&c2);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i]);
	}
	for (int i=1;i<=100;i++){
		doit(p[i]);
	}
	sort(b+1,b+g+1,cmp);
	for (int i=1;i<=100;i++){
		doit(b[i].v);
	}
	printf("%I64d\n",ans);
}