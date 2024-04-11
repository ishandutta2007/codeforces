#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

struct STA{
	string a,b;

	char fir,sec;

	int len;

	void update(char ch)
	{
		if(ch!=fir)
			sec=fir;
		len++;
		fir=ch;
		a=fir+a;
		if(a.size()>10)
		{
			if(!b.size())
				b=a.substr(a.size()-2,2);
			a.resize(10);
		}
	}
}ans[N];

int n;

char s[N];

signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n;i>=1;i--)
	{
		ans[i]=ans[i+1];
		ans[i].update(s[i]);
		if(i+1<=n&&s[i]==s[i+1])
		{
			if(ans[i+2].fir<ans[i].fir||(ans[i+2].fir==ans[i].fir&&ans[i+2].sec<ans[i+2].fir))
				ans[i]=ans[i+2];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i].len<<" ";
		if(ans[i].len<=10)
			cout<<ans[i].a<<"\n";
		else
			cout<<ans[i].a.substr(0,5)<<"..."<<ans[i].b<<"\n";
	}
}