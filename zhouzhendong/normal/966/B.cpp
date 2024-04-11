#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005;
int n,x1,x2,c[N],id[N];
bool cmp(int a,int b){
	return c[a]>c[b];
}
void solve(int f){
	int i=1;
	while (i<=n&&1LL*i*c[id[i]]<x1)
		i++;
	int j=i+1;
	while (j<=n&&1LL*(j-i)*c[id[j]]<x2)
		j++;
	if (j<=n){
		puts("Yes");
		if (f==0)
			printf("%d %d\n",i,j-i);
		else
			printf("%d %d\n",j-i,i);
		if (f==0){
			for (int a=1;a<=i;a++)
				printf("%d ",id[a]);
			puts("");
			for (int a=i+1;a<=j;a++)
				printf("%d ",id[a]);
		}
		else {
			for (int a=i+1;a<=j;a++)
				printf("%d ",id[a]);
			puts("");
			for (int a=1;a<=i;a++)
				printf("%d ",id[a]);
		}
		exit(0);
	}
}
int main(){
	scanf("%d%d%d",&n,&x1,&x2);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	solve(0);
	swap(x1,x2);
	solve(1);
	puts("No");
	return 0;
}