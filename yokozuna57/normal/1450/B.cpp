#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fr first
#define sc second

int n,k;
int x[102],y[102];

int solve(){
	for(int i=0;i<n;i++){
		bool ok=true;
		for(int j=0;j<n;j++){
			ok&=abs(x[i]-x[j])+abs(y[i]-y[j])<=k;
		}
		if(ok)return 1;
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
		printf("%d\n",solve());
	}
}