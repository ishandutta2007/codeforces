#include <cstdio>
#include <cassert>
#include <vector>
const int N=1e5+10;
int T,n,c,b[N];
std::vector<int> nv,nx[N];
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
struct queue{
	int p,q,a[N];queue():p(0),q(0){};
	void clr(){p=q=0;}int size(){return q-p;}
	void push(int x){a[++q]=x;}int front(){return a[++p];}
}q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),q.clr();int k=-1;
		for(int i=0;i<=n+1;++i)nx[i].clear();
		for(int i=1;i<=n;++i){
			scanf("%d",&b[i]);int l=i,r=b[i];
			if(l>r){swp(l,r);if(k==-1)k=r-1;}
			nx[b[i]].push_back(i);
		}
		for(int i:nx[0])q.push(i);
		for(int i:nx[n+1])q.push(i);
		if(k==-1)k=n;printf("%d\n",k);
		do{
			c=0,nv.clear();
			while(q.size()){
				int u=q.front();
				if(nx[u].size())c=u;
				else nv.push_back(u);
			}
			for(int i:nv)printf("%d ",i);
			if(c){
				for(int i:nx[c])q.push(i);
				printf("%d ",c);
			}
		}while(c);
		putchar('\n');
	}
	return 0;
}