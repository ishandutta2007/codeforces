#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,l,fl[23],bas;
char s[23];
ll c[23],mx=0,ans;

bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	for (cin>>n;n--;){
		cin>>s; l=strlen(s);
		fl[s[0]-'a']=bas=1;
		for (int i=l-1;i>=0;--i){
			c[s[i]-'a']+=bas;
			bas*=10;
		}
	}
	for (int i=0;i<10;++i) if (!fl[i]) mx=max(mx,c[i]);
	for (int i=0;i<10;++i) if (!fl[i]&&mx==c[i]){
		swap(c[0],c[i]); break;
	}
	sort(c+1,c+10,cmp);
	for (int i=1;i<10;++i) ans+=c[i]*i;
	cout<<ans;
}