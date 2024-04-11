#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n,l,r;
int c[200010];

int cnt[2][200010];

void solve(){
	for(int i=0;i<n;i++)cnt[0][i]=cnt[1][i]=0;
	for(int i=0;i<l;i++)cnt[0][c[i]]++;
	for(int i=l;i<n;i++)cnt[1][c[i]]++;
	int t=0;
	if(l<r){
		swap(l,r);
		t=1;
	}
	int ret=n/2;
	int p=0;
	for(int i=0;i<n;i++){
		ret-=min(cnt[0][i],cnt[1][i]);
		if(cnt[t][i]>min(cnt[0][i],cnt[1][i])){
			p+=(cnt[t][i]-min(cnt[0][i],cnt[1][i]))/2;
		}
	}
	int x=max(l,r)-min(l,r);
	x-=2*p;
	ret+=max(0,x/2);
	printf("%d\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d%d",&n,&l,&r);
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
			c[i]--;
		}
		solve();
	}
}