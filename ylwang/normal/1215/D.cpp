#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,s1,c1,s2,c2;
char s[1000005];
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n/2)
		if (s[i]=='?') c1++;
		else s1+=s[i]-'0';
	For(i,n/2+1,n)
		if (s[i]=='?') c2++;
		else s2+=s[i]-'0';
	s1+=c1/2*9; c1%=2;
	s2+=c2/2*9; c2%=2;
	puts(s1==s2?"Bicarp":"Monocarp");
}