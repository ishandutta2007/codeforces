#include<bits/stdc++.h>
#define F(i,a,b) for (int i=(a);i<=(b);++i)
using namespace std;
const int M=1e6+10;
int n,ans[M],tt,up[M],dw[M];
char ch[M];
void dfs(int x){
	if (up[x]) up[x]--,dw[x+1]--,dfs(x+1);
	if (dw[x]) dw[x]--,up[x-1]--,dfs(x-1);
	ans[++tt]=x;
}
void work(){
	cin>>(ch+1);
	n=strlen(ch+1);
	int now=n; tt=0;
	F(i,0,2*n) up[i]=dw[i]=0;
	F(i,1,n){
		if (ch[i]=='0') dw[now]++,now--,up[now]++;
		else up[now]++,now++,dw[now]++;
	}
	dfs(now);
	F(i,1,tt-1) putchar(ans[i]<ans[i+1] ? '1' : '0');
	putchar('\n');
}
int main(){
	cin.tie(0);
	int T; cin>>T;
	while (T--) work();
	return 0;
}