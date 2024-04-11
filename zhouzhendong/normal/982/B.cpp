#include <bits/stdc++.h>
using namespace std;
const int N=400005;
int n,w[N],id[N],last[N];
char s[N];
bool cmp(int a,int b){
	return w[a]<w[b];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]),id[i]=i;
	scanf("%s",s+1);
	sort(id+1,id+n+1,cmp);
	int inow=0,las=0;
	for (int i=1;i<=n*2;i++)
		if (s[i]=='0'){
			inow++;
			printf("%d ",id[inow]);
			last[inow]=las;
			las=inow;
		}
		else {
			printf("%d ",id[las]);
			las=last[las];
		}
	return 0;
}