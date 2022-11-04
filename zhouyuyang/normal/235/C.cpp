#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int ch[N][26],cnt,la,l[N],fa[N];
int vis[N],wzp[26],a[N],b[N],sum[N];
char s[N];
int main(){
	scanf("%s",s+1);
	la=cnt=1;
	for (int i=1;s[i];i++){
		int np=++cnt,p=la,c=s[i]-'a';
		l[np]=l[p]+1; ++wzp[c];
		for (;!ch[p][c];p=fa[p]) ch[p][c]=np;
		if (!p) fa[np]=1;
		else{
			int q=ch[p][c];
			if (l[p]+1==l[q]) fa[np]=q;
			else{
				int nq=++cnt; l[nq]=l[p]+1;
				memcpy(ch[nq],ch[q],sizeof(ch[nq]));
				fa[nq]=fa[q]; fa[q]=fa[np]=nq;
				for (;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		sum[la=np]=1;
	}
	for (int i=1;i<=cnt;i++) ++b[l[i]];
	for (int i=1;b[i];i++) b[i]+=b[i-1];
	for (int i=1;i<=cnt;i++) a[b[l[i]]--]=i;
	for (int i=cnt;i;i--) sum[fa[a[i]]]+=sum[a[i]];
	int Q; scanf("%d",&Q);
	while (Q--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		if (len==1){
			printf("%d\n",wzp[s[1]-'a']);
			continue;
		}
		memcpy(s+len+1,s+1,len-1);
		int x=1,z=0,ans=0;
		for (int i=1;i<len<<1;i++){
			int c=s[i]-'a';
			if (!ch[x][c]){
				for (;x&&!ch[x][c];x=fa[x]);
				if (ch[x][c]) z=l[x]+1,x=ch[x][c];
				else z=0,x=1;
			}
			else
				x=ch[x][c],++z;
			if (z>=len&&vis[x]!=Q+1)
				vis[x]=Q+1,ans+=sum[x];
			for (;l[fa[x]]+1>=len;z=l[x=fa[x]]);
		}
		printf("%d\n",ans);
	}
}