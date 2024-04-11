#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
ll x[5002],y[5002];
int p[5002];

bool f(int s,int t,int u){
	ll inn=(x[s]-x[t])*(x[u]-x[t])+(y[s]-y[t])*(y[u]-y[t]);
	return inn>0;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&x[i],&y[i]);
	p[0]=0;
	p[1]=1;
	for(int i=2;i<n;i++){
		if(f(p[i-2],p[i-1],i)){
			p[i]=i;
			continue;
		}
		if(f(i,p[0],p[1])){
			for(int j=i;j>0;j--){
				p[j]=p[j-1];
			}
			p[0]=i;
			continue;
		}
		for(int j=0;j+1<i;j++){
			bool ok=f(p[j],i,p[j+1]);
			if(j-1>=0&&!f(p[j-1],p[j],i))ok=false;
			if(j+2<i&&!f(i,p[j+1],p[j+2]))ok=false;
			if(ok){
				for(int k=i;k>j+1;k--){
					p[k]=p[k-1];
				}
				p[j+1]=i;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d%c",p[i]+1,(i+1==n)?'\n':' ');
	}
}