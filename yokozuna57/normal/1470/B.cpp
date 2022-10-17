#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fr first
#define sc second

int n;
int a[300010];
int q;
ll w[300010];

void red(int i){
	int ret=1;
	for(int j=2;j*j<=a[i];j++){
		if(a[i]%j==0){
			int cnt=0;
			while(a[i]%j==0){
				a[i]/=j;
				cnt++;
			}
			if(cnt&1)ret*=j;
		}
	}
	a[i]*=ret;
}

void solve(){
	for(int i=0;i<n;i++)red(i);
	map<int,int> cnt;
	for(int i=0;i<n;i++)cnt[a[i]]++;
	int ret[2]={};
	for(auto p: cnt){
		if(p.fr==1||p.sc%2==0)ret[0]+=p.sc;
		ret[1]=max(ret[1],p.sc);
	}
	ret[0]=max(ret[0],ret[1]);
	for(int i=0;i<q;i++){
		if(w[i]==0)printf("%d\n",ret[1]);
		else printf("%d\n",ret[0]);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		scanf("%d",&q);
		for(int i=0;i<q;i++)scanf("%lld",&w[i]);
		solve();
	}
}