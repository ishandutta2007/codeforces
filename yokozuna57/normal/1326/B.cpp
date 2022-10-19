#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	static int n;
	static int b[200010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	
	static int a[200010];
	static int x[200010];
	a[0]=b[0];
	x[0]=0;
	for(int i=1;i<n;i++){
		x[i]=max(a[i-1],x[i-1]);
		a[i]=b[i]+x[i];
	}
	for(int i=0;i<n;i++){
		printf("%d%c",a[i],(i+1==n)?'\n':' ');
	}
}