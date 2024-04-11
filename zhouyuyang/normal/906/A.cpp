#include<bits/stdc++.h>
#define int long long
int n,k,ans,l,kk;
char c,s[1000000];
using namespace std;
signed main(){
	scanf("%d",&n);
	k=(1ll<<26)-1;
	for (int t=1;t<=n;t++){
		cin>>c>>s;l=strlen(s);
		if (c=='!'){
			if ((k&(-k))==k)ans++;
			kk=0;for (int i=0;i<l;i++)kk|=1ll<<(s[i]-'a');
			k&=kk;
		}if (c=='.')for (int i=0;i<l;i++)if (k&(1ll<<(s[i]-'a')))k-=1ll<<(s[i]-'a');
		if (c=='?'){
			if (t!=n&&(k&(-k))==k)ans++;if (k&(1<<(s[0]-'a')))k-=1ll<<(s[0]-'a');
		}
	}cout<<ans<<endl;
}