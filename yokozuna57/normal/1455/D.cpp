#include <bits/stdc++.h>
using namespace std;

int n;
int a[502];
int x;

int solve(){
	int ret=0;
	for(int i=0;i<n;i++){
		bool ok=true;
		for(int j=0;j+1<n;j++){
			ok&=a[j]<=a[j+1];
		}
		if(ok)return ret;
		if(a[i]>x){
			swap(a[i],x);
			ret++;
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&n,&x);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		printf("%d\n",solve());
	}
}