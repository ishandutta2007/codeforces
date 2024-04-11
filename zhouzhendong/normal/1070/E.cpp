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
int T,n,m;
LL t;
int p[N];
int f(int d){
	int cnt=0,ans=0;
	LL Time=0,nowT=0;
	for (int i=1;i<=n&&Time<=t;i++){
		if (p[i]>d)
			continue;
		if (Time+p[i]>t)
			break;
		cnt++,ans++;
		nowT+=p[i];
		Time+=p[i];
		if (cnt==m)
			cnt=0,Time+=nowT,nowT=0;
	}
	return ans;
}
int fck(int d){
	int cnt=0,ans=0;
	LL Time=0,nowT=0;
	int i;
	for (i=1;i<=n&&Time<=t;i++){
		if (p[i]>d)
			continue;
		if (Time+p[i]>t)
			return 0;
		cnt++,ans++;
		nowT+=p[i];
		Time+=p[i];
		if (cnt==m)
			cnt=0,Time+=nowT,nowT=0;
	}
	return i>n;
}
void Main(){
	n=read(),m=read(),t=read();
	for (int i=1;i<=n;i++)
		p[i]=read();
	int k=0;
	for (int i=19;i>=0;i--)
		if (fck(k+(1<<i)))
			k|=1<<i;
	int ans=0,id=1;
	for (int i=k;i<=k+10;i++){
		int v=f(i);
		if (v>ans)
			ans=v,id=i;
	}
	cout << ans << " " << min((LL)id,t)<< endl;
}
int main(){
	T=read();
	while (T--)
		Main();
	return 0;
}