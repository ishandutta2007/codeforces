#include<bits/stdc++.h>
using namespace std;

namespace sam{
	#define N 2002000
	int ch[N][26],fa[N],dep[N],ttt[N],nt[N],cnt,las,sum[N],used[N],cas;
	int RE(){
		cnt=las=1;
	}
	int ins(int x){
		int p=las,np=++cnt; dep[np]=dep[p]+1, ttt[np]=1, las=np;
		for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
		if (!p) return fa[np]=1;
		int q=ch[p][x],nq;
		if (dep[q]==dep[p]+1) return fa[np]=q;
		
		nq=++cnt; dep[nq]=dep[p]+1, fa[nq]=fa[q], memcpy(ch[nq],ch[q],sizeof ch[q]);
		for (;ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
		fa[np]=fa[q]=nq;
	}
	int gao(){
		for (int i=1;i<=cnt;++i) ++sum[dep[i]];
		for (int i=1;i<=cnt;++i) sum[i]+=sum[i-1];
		for (int i=1;i<=cnt;++i) nt[sum[dep[i]]--]=i;
		for (int i=cnt;i>0;--i) ttt[fa[nt[i]]]+=ttt[nt[i]];
	}
	int doit(char s[]){
		int l=strlen(s), p=1, len=0, c, fl=++cas, res=0;
		for (int i=0;i<l*2;++i){
			c=s[i%l]-'a';
			for (;p&&!ch[p][c]; p=fa[p],len=dep[p]);
			if (!p) p=1;
			else p=ch[p][c], ++len;
			if (len>=l){
				for (;dep[fa[p]]>=l; p=fa[p],len=dep[p]);
				if (used[p]-fl){
					used[p]=fl;
					res+=ttt[p];
				}
			}
		}
		return res;
	}
}

char s[N]; int l,n;

int main(){
	scanf("%s",s); l=strlen(s);
	sam::RE();
	for (int i=0;i<l;++i) sam::ins(s[i]-'a');
	sam::gao();
	for (cin>>n;n--;printf("%d\n",sam::doit(s))) scanf("%s",s);
}