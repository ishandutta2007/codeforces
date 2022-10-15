#include <cstdio>
#include <set>
const int N=2e5+10;
int T,n,ans,top,stk[N];
std::multiset<int> a,b;
int log(int x){
	int res=1;
	while(x>9)x/=10,++res;
	return res;
}
void chk(){
	for(int i:a)if(b.find(i)!=b.end())stk[++top]=i,b.erase(b.find(i));
	while(top)a.erase(a.find(stk[top--]));
}
void sub(std::multiset<int> &a){
	top=0;for(int i:a)if(i>9)stk[++top]=i;
	ans+=top;while(top)a.erase(a.find(stk[top])),a.insert(log(stk[top--]));
}
void add(std::multiset<int> &a){for(int i:a)if(i!=1)++ans;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=top=0,a.clear(),b.clear();
		for(int w,i=1;i<=n;++i)scanf("%d",&w),a.insert(w);
		for(int w,i=1;i<=n;++i)scanf("%d",&w),b.insert(w);
		chk(),sub(a),sub(b),chk(),add(a),add(b),printf("%d\n",ans);
	}
	return 0;
}