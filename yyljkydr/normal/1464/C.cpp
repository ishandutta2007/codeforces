#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n;

char s[N];

ll T;

int cnt[27];

int main()
{
	scanf("%d%lld",&n,&T);
	scanf("%s",s+1);
	T-=pow(2,s[n]-'a');
	T+=pow(2,s[n-1]-'a');
	T=abs(T);
	for(int i=1;i<=n-2;i++)
		cnt[s[i]-'a']++,T-=pow(2,s[i]-'a');
	T=-T;
	for(int i=25;i>=0;i--)
		while(T>=pow(2,i+1)&&cnt[i])
			T-=pow(2,i+1),cnt[i]--;
	puts(T?"No":"Yes");
}