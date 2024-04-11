#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
vector<int>p[1010];
char c[1010];
int n,m,v[1010],ans,l,r,sn;
int main(){
	cin>>c+1;
	n=strlen(c+1);
	while(1){
		l=1;r=n;sn=0;
		while(l<r){
			while(l<=n&&(v[l]||c[l]==')'))l++;
			while(r&&(v[r]||c[r]=='('))r--;
			if(l>=r)break;
			v[l]=v[r]=1;
			if(!sn){
				sn=1;ans++;
			}
			p[ans].emplace_back(l);p[ans].emplace_back(r);
		}
		if(!sn)break;
	}
	cout<<ans<<endl;
	F(i,1,ans){
		cout<<p[i].size()<<endl;
		sort(p[i].begin(),p[i].end());
		for(auto t:p[i])cout<<t<<" ";
		cout<<endl;
	}
	return 0;
}