#include <cstdio>
#include <cstring>
#include <set>
const int N=2e5+10;
int T,n;char s[N],ans[N];
std::multiset<int> g;
template<typename T>T min(T x,T y){return x<y?x:y;}
struct pr{
	int p,v;pr(){};pr(int p,int v):p(p),v(v){};
	bool operator<(const pr &nxt)const{return v<nxt.v||(v==nxt.v&&p<nxt.p);}
};std::set<pr> f;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),f.clear(),g.clear();
		for(int i=1;i<=n;++i)f.insert(pr(i,s[i]^48));
		int b=10,ls=0;pr a;
		for(int i=1;i<=n;++i){
			while(f.size()&&(a=*f.begin()).p<ls)f.erase(f.begin());
			if(g.size())b=*g.begin();
			if(f.size()&&(!g.size()||a.v<b)){
				ans[i]=a.v^48,f.erase(f.begin());
				while(++ls<a.p)f.erase(pr(ls,s[ls]^48)),g.insert(min((s[ls]^48)+1,9));
			}
			else ans[i]=b^48,g.erase(g.find(b));
		}
		ans[n+1]='\0',puts(ans+1);
	}
	return 0;
}