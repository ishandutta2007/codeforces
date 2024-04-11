#include <bits/stdc++.h>
using namespace std;

int n;
int a[52];

void solve(){
	bool b[52];
	for(int i=0;i<52;i++)b[i]=false;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			b[a[j]-a[i]]=true;
		}
	}
	int cnt=0;
	for(int i=0;i<52;i++)if(b[i])cnt++;
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