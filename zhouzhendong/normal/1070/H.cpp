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
const int N=10005;
int n;
char s[N][10];
map <LL,int> Map;
int tot[N*100],id[N*100],cnt=0;
LL Ha(char *s,int n){
	LL res=0;
	for (int i=0;i<n;i++)
		res=(res<<7)|s[i];
	return res;
}
int main(){
	n=read();
	Map.clear();
	for (int x=1;x<=n;x++){
		LL c[1000];
		int ct=0;
		scanf("%s",s[x]);
		int m=strlen(s[x]);
		for (int i=0;i<m;i++)
			for (int j=i;j<m;j++)
				c[++ct]=Ha(s[x]+i,j-i+1);
		sort(c+1,c+ct+1);
		ct=unique(c+1,c+ct+1)-c-1;
		for (int i=1;i<=ct;i++){
			LL v=c[i];
			if (!Map[v]){
				Map[v]=++cnt;
				id[cnt]=x;
			}
			tot[Map[v]]++;
		}
	}
	int q=read();
	while (q--){
		char ss[10];
		scanf("%s",ss);
		LL now=Ha(ss,strlen(ss));
		int k=Map[now];
		int ans=tot[k];
		cout << ans << " ";
		if (ans)
			cout << s[id[k]] << endl;
		else
			cout << "-\n";
	}
	return 0;
}