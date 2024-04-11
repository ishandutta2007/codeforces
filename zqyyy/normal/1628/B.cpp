#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n;
map<string,bool>h1,h2;
inline void work(){
	n=read();bool ok=0;h1.clear(),h2.clear();
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(ok)continue;
		if((int)s.size()==1){ok=1;continue;}
		h1[s]=1;
		if((int)s.size()==3){
			string t=s.substr(0,2);
			h2[t]=1;
		}
		reverse(s.begin(),s.end());
		if(h1[s] || h2[s]){ok=1;continue;}
		if((int)s.size()==3){
			string t=s.substr(0,2);
			if(h1[t]){ok=1;continue;}
		}
	}
	puts(ok?"YES":"NO");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}