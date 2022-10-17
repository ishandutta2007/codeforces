#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll n,cnt;
char str[N];

int main()
{
    ll i,j;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(i=1;i<=n;i++) if(str[i]!='a') cnt++;
    if(cnt&1)
    {
	puts(":(");
	return 0;
    }
    for(i=1,j=n-cnt/2+1;j<=n;i++,j++)
    {
	for(;str[i]=='a';i++);
	if(str[i]!=str[j])
	{
	    puts(":(");
	    return 0;
	}
    }
    for(i=1;i<=n-cnt/2;i++) printf("%c",str[i]);
}