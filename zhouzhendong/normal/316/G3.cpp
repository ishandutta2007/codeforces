#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=550005;
int n,m,L[15],R[15];
int size=1,root=1,last=1;
int tax[N<<1],id[N<<1];
LL tot[N<<1][12];
char s[N];
struct SAM{
	int Next[27],fa,Max;
}t[N<<1];
void extend(int c,int id){
	int p=last,np=++size,q,nq;
	tot[np][id]++;
	t[np].Max=t[p].Max+1;
	for (;!t[p].Next[c];p=t[p].fa)
		t[p].Next[c]=np;
	q=t[p].Next[c];
	if (t[q].Max==t[p].Max+1)
		t[np].fa=q;
	else {
		nq=++size;
		t[nq]=t[q],t[nq].Max=t[p].Max+1;
		t[q].fa=t[np].fa=nq;
		for (;t[p].Next[c]==q;p=t[p].fa)
			t[p].Next[c]=nq;
	}
	last=np;
}
int main(){
	t[0].Max=-1;
	for (int i=0;i<27;i++)
		t[0].Next[i]=1;
	scanf("%s",s);
	m=strlen(s);
	for (int i=0;i<m;i++)
		extend(s[i]-'a',0);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		extend(26,n+1);
		scanf("%s%d%d",s,&L[i],&R[i]);
		m=strlen(s);
		for (int j=0;j<m;j++)
			extend(s[j]-'a',i);
	}
	for (int i=1;i<=size;i++)
		tax[t[i].Max]++;
	for (int i=1;i<=size;i++)
		tax[i]+=tax[i-1];
	for (int i=1;i<=size;i++)
		id[tax[t[i].Max]--]=i;
	LL ans=0;
	for (int i=size;i>=2;i--){
		int x=id[i];
		for (int j=0;j<=n;j++)
			tot[t[x].fa][j]+=tot[x][j];
		if (tot[x][0]==0)
			continue;
		bool flag=1;
		for (int j=1;flag&&j<=n;j++)
			flag&=L[j]<=tot[x][j]&&tot[x][j]<=R[j];
		if (flag)
			ans+=t[x].Max-t[t[x].fa].Max;
	}
	printf("%I64d",ans);
	return 0;
}