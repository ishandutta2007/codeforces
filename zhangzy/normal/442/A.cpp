#include<bits/stdc++.h>
using namespace std;

int n, a[5][5], ans=10, tot;
map<char,int>mp;
set<int>tmp;

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		string s; cin>>s;
		if (!mp.count(s[0])) mp[s[0]]=tot++;
		a[mp[s[0]]][s[1]-'1']=1;
	}
	for (int S=0;S<(1<<10);++S){
		tmp.clear();
		int fl=1;
		for (int i=0;i<5;++i)
			for (int j=0;j<5;++j)
				if (a[i][j]){
					int z=0;
					if (S>>i&1) z+=i+1;
					if (S>>(j+5)&1) z+=(j+1)*100;
					if (tmp.count(z)) fl=0;
					tmp.insert(z);
				}
		if (fl) ans=min(ans,(int)__builtin_popcount(S));
	}
	cout<<ans<<endl;
}