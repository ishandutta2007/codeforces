#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
LL read(){
    char ch=getchar(); LL w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
pair<int,int> calc(LL x){
	int mi=10,mx=0;
	while (x) mx=max(x%10,1ll*mx),mi=min(1ll*mi,x%10),x/=10;
	return make_pair(mi,mx);
}
int main(){
	int T=read();
	while (T--){
		LL a=read(),k=read();
		bool flag=0;
		F(i,1,k-1){
			pair<int,int> o=calc(a);
			if (o.first==0) {
				cout<<a<<'\n';
				flag=1;
				break;
			}
			a=a+o.first*o.second;
		}
		if (!flag) cout<<a<<"\n";
	}
    return 0;
}