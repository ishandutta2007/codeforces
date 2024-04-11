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
int a[100010],b[100010];

void solve(){
	sort(a,a+n);
	sort(b,b+n);
	int A=0,B=0;
	int k=n-n/4;
	for(int i=0;i<k;i++)A+=a[n-1-i];
	for(int i=0;i<k;i++)B+=b[n-1-i];
	int x=n-k;
	int y=n-k-1;
	for(int ret=0;;ret++){
		if(A>=B){
			printf("%d\n",ret);
			return;
		}
		if((n+ret+1)%4==0){
			A+=100;
			if(x<n)A-=a[x++];
			else A-=100;
		}
		else {
			A+=100;
			if(y>=0)B+=b[y--];
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
		solve();
	}
}