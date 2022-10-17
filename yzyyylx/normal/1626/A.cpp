#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN
#define N 210
#define M 
using namespace std;
 
ll T,n,m,cnt[N];
char str[N];
 
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%s",str+1);
		n=strlen(str+1);
		for(i=1;i<=n;i++) cnt[str[i]]++;
		for(i='a';i<='z';i++) if(cnt[i]==1) printf("%c",(char)i);
		for(i='a';i<='z';i++) if(cnt[i]==2) printf("%c%c",(char)i,(char)i);
		puts("");
	}
}