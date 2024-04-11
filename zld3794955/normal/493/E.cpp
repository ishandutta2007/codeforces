#include<bits/stdc++.h>
using namespace std;
long long a,b,c,ans=0,w[110]={};
int tot=0;
bool tryy(long long s1,long long s2)
{
	if(s1==0 || s2==0)
	{
		if(s1==0 && s2==0)
		{
			++ans;
			return true;
		}
		else
			return false;
	}
	if(long long now=s2%b)
	{
		if((s1-now)%a==0)
		{
			w[++tot]=now;
			return tryy((s1-now)/a,(s2-now)/b);
		}
		else
			return false;
	}
	else
	{
		bool flag=false;
		int k=++tot;
		if(s1%a==0)
		{
			w[k]=0;
			flag=tryy(s1/a,s2/b);
		}
		if(s1==b && s2==b)
		{
			++ans;
			if(!flag)
			{
				w[k]=b;
				tot=k;
			}
			return true;
		}
		return flag;
	}
}
int main()
{	
	//freopen("polynomial.in","r",stdin);
	//freopen("polynomial.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		tot=-1;
		ans=0;
		if(b==1)
		{
			puts(c==1 ? (a==1 ? "inf" : "1") : "0");
			continue;
		}
		tryy(b,c);
		//ans+=(b==c && a!=b && a!=1);	// Constant function?
		cout<<ans<<endl;
		if(ans)
		{
			if(tot==-1)
			{
				tot=0;
				w[tot]=b;
			}/*
			cout<<tot<<' ';
			for(int i=tot;i>=0;--i)
				cout<<w[i]<<' ';
			cout<<endl;*/
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}