#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
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
int n,m,Y1,Y2;
int a[N],b[N];
namespace Map{
    static const int Ti=233,mod=214742;
    int cnt,k[200005],v[200005],nxt[200005],fst[mod+1];
    int Hash(int x){
        return x%mod+1;
    }
    void clear(){
        cnt=0;
        memset(fst,0,sizeof fst);
    }
    void update(int x){
        int y=Hash(x);
        for (int p=fst[y];p;p=nxt[p])
            if (k[p]==x){
                v[p]++;
                return;
            }
        k[++cnt]=x,nxt[cnt]=fst[y],fst[y]=cnt,v[cnt]=1;
        return;
    }
    int find(int x){
        int y=Hash(x);
        for (int p=fst[y];p;p=nxt[p])
            if (k[p]==x)
                return v[p];
        return 0;
    }
}
int main(){
	n=read(),Y1=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	m=read(),Y2=read();
	for (int j=1;j<=m;j++)
		b[j]=read();
	int ans=0;
	for (int i=1;i<=n;i++)
		Map :: update(a[i]);
	for (int i=1;i<=m;i++)
		Map :: update(b[i]);
	for (int i=1;i<=n;i++)
		ans=max(ans,Map :: find(a[i]));
	for (int i=1;i<=m;i++)
		ans=max(ans,Map :: find(b[i]));
	for (int d=1;d<=1e9;d<<=1){
		Map :: clear();
		int e=(d<<1)-1;
		for (int i=1;i<=n;i++)
			Map :: update(a[i]&e);
		for (int i=1;i<=m;i++)
			Map :: update((b[i]+d)&e);
		for (int i=1;i<=n;i++)
			ans=max(ans,Map :: find(a[i]&e));
		for (int i=1;i<=m;i++)
			ans=max(ans,Map :: find((b[i]+d)&e));
	}
	printf("%d",ans);
	return 0;
}