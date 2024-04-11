#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
const int xx=55;
char s[xx];
int t[26];
signed main(){
	T=read();
	while(T--)
	{
		int n;
		n=read();
		memset(t,0,sizeof(t));
		scanf("%s",s);
		t[s[0]-'A']=1;
		int vis=1;
		for(int i=1;i<n;i++)
		{
			if(s[i]!=s[i-1])
			{
				if(t[s[i]-'A'])
				{
					puts("NO");
					vis=0;
					break;
				}
				t[s[i]-'A']=1;
			}
		}
		if(vis)puts("YES");
	}
	return 0;
}