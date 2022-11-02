#include<bits/stdc++.h>
using namespace std;
const int L=1000010; 
char ch[L+L]={};
int len,l,m=127;
int u1[L+L]={},u2[L+L]={},*x=u1,*y=u2;
int t[L+L]={},sa[L+L]={},ans[L+L]={},s[L+L]={};
bool can[L+L]={};
void init()
{
	gets(ch+1);
	len=strlen(ch+1);
	for(int i=1;i<=len;++i)
		ch[len+i]=ch[i];
	l=len<<1;
	ch[0]=ch[len];
}
inline bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}
void work()
{
	for(int i=1;i<=l;++i)
		++t[x[i]=ch[i]];
	for(int i=1;i<=m;++i)
		t[i]+=t[i-1];
	for(int i=l;i>=1;--i)
		sa[t[x[i]]--]=i;
	for(int j=1,p=0;j<=l && p!=l;m=p,j*=2,p=0)
	{
		for(int i=l-j+1;i<=l;++i)
			y[++p]=i;
		for(int i=1;i<=l;++i)
			if(sa[i]>j)
				y[++p]=sa[i]-j;
		for(int i=0;i<=m;++i)
			t[i]=0;
		for(int i=1;i<=l;++i)
			s[i]=x[y[i]];
		for(int i=1;i<=l;++i)
			++t[s[i]];
		for(int i=1;i<=m;++i)
			t[i]+=t[i-1];
		for(int i=l;i>=1;--i)
			sa[t[s[i]]--]=y[i];
		swap(x,y);
		x[sa[1]]=1,p=1;
		for(int i=2;i<=l;++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p : ++p;
	}
	/*
	for(int i=1;i<=l;++i)
		if(sa[i]<=len)
			putchar(ch[sa[i]-1]);
	puts("");
	for(int i=1;i<=l;++i)
		if(sa[i]<=len)
			cout<<sa[i]<<' ';
	cout<<endl;
	*/
}
void get_ans()
{
	int s1=0,s2=0;
	for(int i=1;i<=len;++i)
		++(ch[i]=='(' ? s1 : s2);
	deque<int> q;
	//cout<<"len="<<len<<" l="<<l<<endl;
	for(int i=l;i>len;--i)
	{
		s[i]=s[i+1]+(ch[i]=='(' ? 1 : -1);
		while(!q.empty() && s[i]>s[q.back()])
			q.pop_back();
		q.push_back(i);
		can[i]=false;
	}
	//for(auto i:q)
	//	cout<<s[i]<<endl;
	//cout<<"s1="<<s1<<" s2="<<s2<<endl; 
	for(int i=len;i>=1;--i)
	{
		s[i]=s[i+1]+(ch[i]=='(' ? 1 : -1);
		//cout<<"i="<<i<<endl;
		//cout<<"s[i]="<<s[i]<<" maxs="<<s[q.front()]<<endl;
		can[i]=(max(s2-s1,0)+(s[i]-s[q.front()])>=0);
		while(!q.empty() && s[i]>s[q.back()])
			q.pop_back();
		q.push_back(i);
		while(!q.empty() && q.front()>=i+len)
			q.pop_front();
	}
	int p=1;
	for(int i=1;i<=l;++i)
		if(can[sa[i]])
		{
			p=sa[i];
			break;
		}
	while(s1<s2)
	{
		++s1;
		putchar('(');
	}
	for(int i=p;i<=p+len-1;++i)
		putchar(ch[i]);
	while(s1>s2)
	{
		++s2;
		putchar(')');
	}
	putchar('\n');
}
int main()
{	
	init();
	work();
	get_ans();
	return 0;
}