#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n,m,d;
int v[N],ans[N];
struct ID{
	int x;
	ID(){}
	ID(int _x){
		x=_x;
	}
	friend bool operator < (ID a,ID b){
		if (v[a.x]!=v[b.x])
			return v[a.x]<v[b.x];
		return a.x<b.x;
	}
};
set <ID> S;
int main(){
	n=read(),m=read(),d=read();
	for (int i=1;i<=n;i++)
		v[i]=read(),S.insert(i);
	int tot=1,t=1;
	for (int i=1;i<=n;i++){
		v[0]=t;
		set <ID> :: iterator p=S.lower_bound(0);
		if (p==S.end()){
			tot++;
			p=S.begin();
		}
		int x=(*p).x;
		S.erase(*p);
		ans[x]=tot;
		t=v[x]+d+1;
	}
	printf("%d\n",tot);
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}