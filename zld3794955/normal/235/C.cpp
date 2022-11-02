#include<bits/stdc++.h>
using namespace std;
const int N=1000010,L=1000100,BufL=200,root=0,None=-1598753915;
const long long Base=233,mod=10000000000007ll;
struct node
{
	int s[26],val,par,R;
}t[N+N]={};
int n,l,tot=0,d[N+N]={},q[N+N]={};
char buf[BufL]={},ch[L]={};
void add(int p,int c)
{
	int np=++tot;
	t[np].val=t[p].val+1;
	t[np].R=1;
	while(p!=None && t[p].s[c]==0)
		t[p].s[c]=np,p=t[p].par;
	if(p==None)
		t[np].par=root;
	else
	{
		int q=t[p].s[c];
		if(t[p].val+1==t[q].val)
			t[np].par=q;
		else
		{
			int nq=++tot;
			t[nq]=t[q];
			t[nq].R=0;
			t[q].par=t[np].par=nq;
			t[nq].val=t[p].val+1;
			for(int i=p; i!=None && t[i].s[c]==q; i=t[i].par)
				t[i].s[c]=nq;
		}
	}
}
void init()
{
	gets(ch+1);
	int l=strlen(ch+1),p=root;
	t[root].par=None;
	for(int i=1;i<=l;++i)
	{
		add(p,ch[i]-'a');
		p=t[p].s[ch[i]-'a'];
	}
	for(int i=1;i<=tot;++i)
		++d[t[i].par];
	int head=0,tail=0;
	for(int i=1;i<=tot;++i)
		if(!d[i])
			q[++tail]=i;
	for(int i=1;i<=tot;++i)
	{
		int s=q[++head];
		while(s==0)
			;
		t[t[s].par].R+=t[s].R;
		if((--d[t[s].par])==0)
			q[++tail]=t[s].par;
	}
}
int trans(int now,int c,int &len)
{
	while(now!=None && t[now].s[c]==0)
		now=t[now].par;
	if(now==None)
		len=0,now=root;
	else
		len=min(len,t[now].val)+1,now=t[now].s[c];
	return now;
}
void work()
{
	gets(buf);
	sscanf(buf,"%d",&n);
	for(int i=1;i<=n;++i)
	{
		gets(ch+1);
		l=strlen(ch+1);
		long long sh=0,h=0,p=1;
		int now=root,ans=0,len=0;
		for(int j=1;j<=l;++j)
		{
			h=(h*Base+ch[j])%mod;
			p=p*Base%mod;
			now=trans(now,ch[j]-'a',len);
		}
		sh=h;
		for(int j=1;j<=l;++j)
		{
			if(len>=l)
				ans+=t[now].R;
			h=(h*Base+mod-ch[j]*p%mod+ch[j])%mod;
			if(h==sh)
				break;
			now=trans(now,ch[j]-'a',len);
			len=min(len,l);
			while(t[now].par!=None && t[t[now].par].val>=len)
				now=t[now].par;
		}
		printf("%d\n",ans);
	}
}
int main()
{
	init();
	work();
	return 0;
}