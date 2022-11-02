#include<bits/stdc++.h>
using namespace std;
const int L=50500,C=27,N=11,root=0,None=-987958798;
const char END='{';
struct node
{
	int s[C],b[N],par,val;
}t[L*22]={};
char ch[L*22]={};
int n,l=0,tot=0,x[N]={},y[N]={},d[N]={},in[L*22]={},q[L*22]={},head=0,tail=0;
long long ans=0;
void add(int p,int c)
{
	int np=++tot;
	t[np].val=t[p].val+1;
	while(p!=None && t[p].s[c]==0)
		t[p].s[c]=np, p=t[p].par;
	if(p==None)
		t[np].par=root;
	else
	{
		int q=t[p].s[c];
		if(t[p].val+1 == t[q].val)
			t[np].par=q;
		else
		{
			int nq=++tot;
			t[nq]=t[q];
			t[nq].val=t[p].val+1;
			t[q].par=t[np].par=nq;
			for(int i=p; i!=None && t[i].s[c]==q; i=t[i].par)
				t[i].s[c]=nq;
		}
	}
}
int main()
{
	t[root].par=None;
	d[0]=++l;
	cin>>(ch+d[0])>>n;
	l+=strlen(ch+d[0]);
	for(int i=1;i<=n;++i)
	{
		ch[l]=END;
		d[i]=++l;
		cin>>(ch+d[i])>>x[i]>>y[i];
		l+=strlen(ch+d[i]);
	}
	ch[l]=END;
	for(int i=1,p=root; i<l; p=t[p].s[ch[i++]-'a'])
		add(p,ch[i]-'a');
	for(int i=0;i<=n;++i)
		for(int j=d[i],p=t[root].s[ch[j]-'a']; ch[j]!=END; p=t[p].s[ch[++j]-'a'])
			++t[p].b[i];
	for(int i=1;i<=tot;++i)
		++in[t[i].par];
	for(int i=1;i<=tot;++i)
		if(!in[i])
			q[++tail]=i;
	for(int tmp=1;tmp<=tot;++tmp)
	{
		int s=q[++head];
		bool flag=t[s].b[0];
		for(int i=1;i<=n;++i)
			flag&=x[i]<=t[s].b[i] && t[s].b[i]<=y[i];
		if(flag)
			ans+=t[s].val-t[t[s].par].val;
		for(int i=0;i<=n;++i)
			t[t[s].par].b[i]+=t[s].b[i];
		if((--in[t[s].par])==0)
			q[++tail]=t[s].par;
	}
	cout<<ans<<endl;
}