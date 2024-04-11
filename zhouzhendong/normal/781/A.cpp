#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=200005;
int n,in[N],c[N];
vector <int> e[N];
void solve(int x,int pre){
	int cx=0;
	for (auto y : e[x])
		if (y!=pre){
			for (cx++;cx==c[x]||cx==c[pre];cx++);
			c[y]=cx;
		}
	for (auto y : e[x])
		if (y!=pre)
			solve(y,x);
}
int main(){
	n=read();
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		in[a]++,in[b]++;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int ans=1;
	for (int i=1;i<=n;i++)
		if (in[i]+1>=ans)
			ans=max(ans,in[i]+1);
	c[1]=1;
	solve(1,0);
	cout << ans << endl;
	for (int i=1;i<=n;i++)
		printf("%d ",c[i]);
	return 0;
}