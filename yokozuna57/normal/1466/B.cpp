#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

void solve(){
	int cnt=0,M=0;
	for(int i=0;i<n;i++){
		if(M<a[i]){
			cnt++;
			M=a[i];
		}
		else if(M==a[i]){
			cnt++;
			M=a[i]+1;
		}
	}
	printf("%d\n",cnt);
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		solve();
	}
}