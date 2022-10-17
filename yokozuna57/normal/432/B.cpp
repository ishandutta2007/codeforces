#include<iostream>
using namespace std;

int main(){
	int n;
	static int x[100010],y[100010];
	static int cnt[100010]={0};

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		cnt[x[i]]++;
	}

	for(int i=0;i<n;i++){
		printf("%d %d\n",n-1+cnt[y[i]],n-1-cnt[y[i]]);
	}
}