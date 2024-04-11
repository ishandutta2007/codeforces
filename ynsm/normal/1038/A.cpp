#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n,k,ans,cnt[100];
string s;
int main(){

	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'A']++;
	ans=1e9;
	for(int i=0;i<k;i++)
		ans=min(ans,cnt[i]);
	cout<<ans*k;				
	return 0;
}