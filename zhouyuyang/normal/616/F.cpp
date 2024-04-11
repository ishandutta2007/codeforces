#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,st[N],ed[N];
int cnt,np,mx[N*10];
int ch[N*10][26],fa[N*10];
#define ll long long
ll c[N*10];
vector<int> to[N*10];
char s[N*5];
void insert(int x,int val){
	if (ch[np][x]&&mx[ch[np][x]]==mx[np]+1){
		np=ch[np][x]; c[np]+=val;
		return;
	}
	int p=np; np=++cnt;
	mx[np]=mx[p]+1; c[np]=val;
	for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][x];
		if (mx[q]==mx[p]+1) fa[np]=q;
		else{
			int nq=++cnt;
			mx[nq]=mx[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][x]==q;p=fa[p])
				ch[p][x]=nq;
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		st[i]=ed[i-1]+1;
		scanf("%s",s+st[i]);
		int l=strlen(s+st[i]);
		ed[i]=ed[i-1]+l;
	}
	cnt=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		np=1;
		for (int j=st[i];j<=ed[i];j++)
			insert(s[j]-'a',x);
	}
	ll ans=0;
	for (int i=2;i<=cnt;i++)
		to[mx[i]].push_back(i);
	for (int i=ed[n];i;i--)
		for (int j=0;j<to[i].size();j++){
			c[fa[to[i][j]]]+=c[to[i][j]];
			ans=max(ans,i*c[to[i][j]]);
		}
	printf("%lld",ans);
}