#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n;
		scanf("%d",&n);
		if(n<=99){
			printf("%d\n",n%10);
		}
		else {
			int ret=10;
			while(n>0){
				ret=min(ret,n%10);
				n/=10;
			}
			printf("%d\n",ret);
		}
	}
}