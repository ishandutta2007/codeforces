#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n;
		int a[102],b[102];
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0;i<n;i++){
			printf("%d%c",a[i],(i+1==n)?'\n':' ');
		}
		for(int i=0;i<n;i++){
			printf("%d%c",b[i],(i+1==n)?'\n':' ');
		}
	}
}