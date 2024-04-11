#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#pragma GCC optimize(2) 
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+10;
bitset<M> s[30],ans;
char ch[M],t[M];
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin>>(ch+1); n=strlen(ch+1);
	F(i,1,n){
		s[ch[i]-'a'][i-1]=1;
	}
	cin>>m; 
	while (m--){
		int ty,x,y,z;
		cin>>ty>>x;
		if (ty==1){
			char c; cin>>c;
			s[ch[x]-'a'][x-1]=0; 
			s[c-'a'][x-1]=1; 
			ch[x]=c;
		}
		else{
			cin>>y; cin>>(t+1); int l=strlen(t+1);
			ans.set();
			F(i,1,l){
//				cout<<ans.count()<<" "<<t[i]<<"   sb\n";
				ans&=(s[t[i]-'a']>>(i-1));
			}
			int lans=(ans>>(x-1)).count(),rans=(ans>>(y-l+1)).count(); 
			cout<<max(lans-rans,0)<<"\n"; 
		}
	}
	return 0;
}