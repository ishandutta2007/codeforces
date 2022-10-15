#include <cstdio>
#include <unordered_set>
const int N=1e5+10;
int T,n;char a[N],b[N];
std::unordered_set<int> set;
int id(int p,int q){return p*26+q;}
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s %s",&n,a+1,b+1),set.clear();
		for(int i=1;i<=n;++i){
			int p=a[i]-'a',q=b[n+1-i]-'a';
			if(p>q)swp(p,q);auto it=set.find(id(p,q));
			if(it!=set.end())set.erase(it);
			else set.insert(id(p,q));
		}
		if(set.size()>1)puts("NO");
		else if(n&1){
			int w=*set.begin();
			puts(w/26==w%26?"YES":"NO");
		}
		else puts(set.size()?"NO":"YES");
	}
	return 0;
}