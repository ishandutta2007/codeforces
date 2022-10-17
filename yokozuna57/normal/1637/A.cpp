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
int a[10010];

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		
		bool ok=true;
		for(int i=0;i+1<n;i++)if(a[i]>a[i+1])ok=false;
		if(ok)puts("NO");
		else puts("YES");
	}
}