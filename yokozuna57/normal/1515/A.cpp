#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n,x;
int w[102];

void solve(){
	int sum=0;
	for(int i=0;i<n;i++)sum+=w[i];
	if(sum==x){
		puts("NO");
		return;
	}
	sort(w,w+n);
	sum=0;
	for(int i=0;i<n;i++){
		sum+=w[i];
		if(sum==x){
			swap(w[i],w[i+1]);
			break;
		}
	}
	puts("YES");
	for(int i=0;i<n;i++){
		printf("%d%c",w[i],(i+1==n)?'\n':' ');
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&x);
		for(int i=0;i<n;i++)scanf("%d",&w[i]);
		solve();
	}
}