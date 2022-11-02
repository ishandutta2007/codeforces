#include <bits/stdc++.h>
#define right _47hurnf
using namespace std;
typedef long long LL;
const int N=1000005;
int n,m;
char s[N];
struct SAM{
	int Next[26],fa,Max;
}t[N<<1];
int tax[N],id[N<<1],right[N<<1];
int size;
void init(){
	memset(t,0,sizeof t);
	size=1,t[0].Max=-1;
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
int Fail[N];
int KMP(char s[],int n){
	Fail[0]=Fail[1]=0;
	for (int i=2;i<=n;i++){
		int k=Fail[i-1];
		while (k>0&&s[i]!=s[k+1])
			k=Fail[k];
		Fail[i]=k+(s[k+1]==s[i]?1:0);
	}
	int x=Fail[n];
	while (x>0&&n%(n-x)!=0)
		x=Fail[x];
	return n-x;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	init();
	for (int i=1,p=1;i<=n;i++)
		p=extend(p,s[i]-'a'),right[p]++;
	for (int i=1;i<=size;i++)
		tax[t[i].Max]++;
	for (int i=1;i<=n;i++)
		tax[i]+=tax[i-1];
	for (int i=1;i<=size;i++)
		id[tax[t[i].Max]--]=i;
	for (int i=size;i>=1;i--)
		right[t[id[i]].fa]+=right[id[i]];
	scanf("%d",&m);
	while (m--){
		scanf("%s",s+1);
		int len=strlen(s+1),r=KMP(s,len);
		LL ans=0;
		int p=1,Matched=0;
		for (int i=1;i<=len;i++){
			int c=s[i]-'a';
			while (!t[p].Next[c])
				p=t[p].fa,Matched=t[p].Max;
			p=t[p].Next[c];
			Matched++;
		}
		for (int i=1;i<=r;i++){
			int c=s[i]-'a';
			while (!t[p].Next[c])
				p=t[p].fa,Matched=t[p].Max;
			p=t[p].Next[c];
			Matched++;
			while (t[t[p].fa].Max>=len)
				p=t[p].fa,Matched=t[p].Max;
			if (Matched>=len)
				ans+=right[p];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}