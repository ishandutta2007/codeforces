#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n;
int a[100010];

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		if(n==3){
			if(a[1]%2==0)printf("%d\n",a[1]/2);
			else puts("-1");
		}
		else {
			bool ok=false;
			ll ret=0;
			for(int i=1;i<n-1;i++){
				if(a[i]>=2)ok=true;
				ret+=(a[i]+1)/2;
			}
			if(!ok)puts("-1");
			else printf("%lld\n",ret);
		}
	}
}