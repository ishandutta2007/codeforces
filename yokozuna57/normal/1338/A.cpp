#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n;
		int a[100010];
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		int ret=0;
		int MAX=-1000000000;
		for(int i=0;i<n;i++){
			chmax(ret,MAX-a[i]);
			chmax(MAX,a[i]);
		}
		int sum=0;
		for(int x=0;x<32;x++){
			if(ret<=sum){
				printf("%d\n",x);
				break;
			}
			sum+=1<<x;
		}
	}
}