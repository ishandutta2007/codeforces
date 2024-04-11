#include <bits/stdc++.h>
#define right __fjw82
using namespace std;
const int N=300005,S=N*2,mod=1e9+7;
char s[N];
int n=1e9,in[S],q[S],ans[N],right[S][3],head,tail;
int root,size;
struct SAM{
	int Next[26],fa,Max;
}t[N<<1];
void init(){
	memset(t,0,sizeof t);
	root=size=1;
	t[0].Max=-1;
	for (int i=0;i<26;i++)
		t[0].Next[i]=1;
}
int extend(int p,int c){
	if (t[p].Next[c]&&t[p].Max+1==t[t[p].Next[c]].Max)
		return t[p].Next[c];
	int np=++size,q,nq;
	t[np].Max=t[p].Max+1;
	for (;!t[p].Next[c];p=t[p].fa)
		t[p].Next[c]=np;
	q=t[p].Next[c];
	if (t[p].Max+1==t[q].Max)
		t[np].fa=q;
	else {
		nq=++size;
		t[nq]=t[q],t[nq].Max=t[p].Max+1;
		t[q].fa=t[np].fa=nq;
		for (;t[p].Next[c]==q;p=t[p].fa)
			t[p].Next[c]=nq;
	}
	return np;
}
int main(){
	init();
	for (int i=0,now;i<3;i++){
		scanf("%s",s+1);
		n=min(n,now=strlen(s+1));
		for (int j=1,p=root;j<=now;j++)
			right[p=extend(p,s[j]-'a')][i]++;
	}
	for (int i=2;i<=size;i++)
		in[t[i].fa]++;
	head=tail=0;
	for (int i=2;i<=size;i++)
		if (in[i]==0)
			q[++tail]=i;
	while (head<tail){
		int x=q[++head];
		for (int i=0;i<3;i++)
			right[t[x].fa][i]+=right[x][i];
		in[t[x].fa]--;
		if (t[x].fa>1&&!in[t[x].fa])
			q[++tail]=t[x].fa;
	}
	memset(ans,0,sizeof ans);
	for (int i=2;i<=size;i++){
		int add=1LL*right[i][0]*right[i][1]*right[i][2]%mod;
		(ans[t[t[i].fa].Max+1]+=add)%=mod;
		(ans[t[i].Max+1]+=mod-add)%=mod;
	}
	for (int i=1;i<=n;i++){
		ans[i]=(ans[i]+ans[i-1])%mod;
		printf("%d ",ans[i]);
	}
	return 0;
}