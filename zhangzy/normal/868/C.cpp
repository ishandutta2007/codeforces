#include<bits/stdc++.h>
using namespace std;
int cnt[233]={0};
int n,k;

void in(){
	int x,t=0;
	for (int i=0;i<k;i++){
		scanf("%d",&x);
		if (x==0) t|=(1<<i);
	}
	cnt[t]++;
}

void doit(int now){
	for (int i=0;i<(1<<k);i++){
		if (cnt[i]&& ( (now|i)==((1<<k)-1) ) )
			exit(0*printf("YES"));
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		in();
	}
	if (n==1){
		return 0*puts(cnt[(1<<k)-1]?"YES":"NO");
	}
	for (int i=0;i<(1<<k);i++){
		if (cnt[i]){
			cnt[i]--;
			doit(i);
			cnt[i]++;
		}
	}
	printf("NO");
}