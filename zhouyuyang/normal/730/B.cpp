#include<bits/stdc++.h>
using namespace std;
int x[55],y[55];
char query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char s[10];
	scanf("%s",s+1);
	return s[1];
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		int L=0;
		for (int i=1;i<n;i+=2)
			if (query(i,i+1)=='>')
				x[++L]=i+1,y[L]=i;
			else x[++L]=i,y[L]=i+1;
		if (n&1){
			x[++L]=n;
			y[L]=n;
		}
		int ans1=1,ans2=1;
		for (int i=2;i<=L;i++){
			if (query(x[i],x[ans1])=='<') ans1=i;
			if (query(y[i],y[ans2])=='>') ans2=i;
		}
		printf("! %d %d\n",x[ans1],y[ans2]);
		fflush(stdout);
	}
}