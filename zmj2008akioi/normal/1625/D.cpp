#include <cstdio>
#include <map>
const int rt=0,P=29,N=3e5+10;
int n,k,a[N];
std::map<int,bool> map;
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x,char end=' '){
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar(end);
	}
}using basic::read;using basic::write;
struct stack{
	int p,arr[N];
	stack():p(0){};
	inline int size(){return p;}
	inline void push(int x){arr[++p]=x;}
	inline int top(){return arr[p--];}
}ans;
namespace trie{
	int tnt,val[N<<6],tr[N<<6][2];
	inline int gd(int x,int d){return (x>>d)&1;}
	inline int find(int &x){if(!x)x=++tnt;return x;}
	void insert(int x,int v){
		int u=rt;
		for(int i=P;~i;--i)u=find(tr[u][gd(x,i)]);
		val[u]=v;
	}
	void ff(int u,int dep){
		if(~dep){
			if(tr[u][0])ff(tr[u][0],dep-1);
			else ff(tr[u][1],dep-1);
		}
		else ans.push(val[u]);
	}
	bool dfs(int a,int b,int dep,int k){
		if(k>=(1<<(dep+1)))return false;
		else if(k<=0){
			ff(a,dep),ff(b,dep);
			return true;
		}
		else{
			if(tr[a][0]&&tr[b][1]){if(dfs(tr[a][0],tr[b][1],dep-1,k-(1<<dep)))return true;}
			if(tr[a][1]&&tr[b][0]){if(dfs(tr[a][1],tr[b][0],dep-1,k-(1<<dep)))return true;}
			if(tr[a][0]&&tr[b][0]){if(dfs(tr[a][0],tr[b][0],dep-1,k))return true;}
			if(tr[a][1]&&tr[b][1]){if(dfs(tr[a][1],tr[b][1],dep-1,k))return true;}
			return false;
		}
	}
	void calc(int u,int dep){
		if(k>=(1<<dep)){
			if(!tr[u][0]||!tr[u][1])ff(u,dep);
			else if(!dfs(tr[u][0],tr[u][1],dep-1,k-(1<<dep)))ff(u,dep);
		}
		else{
			if(tr[u][0])calc(tr[u][0],dep-1);
			if(tr[u][1])calc(tr[u][1],dep-1);
		}
	}
}using trie::insert;using trie::calc;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read(),insert(a[i],i);
	if(!k){
		write(n,'\n');
		for(int i=1;i<=n;++i)write(i);
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;++i){
			if(!map[a[i]])ans.push(i);
			map[a[i]]=true;
		}
		write(ans.size(),'\n');
		while(ans.size())write(ans.top());
		return 0;
	}
	trie::calc(rt,P);
	if(ans.size()<2)puts("-1");
	else{
		write(ans.size(),'\n');
		while(ans.size())write(ans.top());
	}
	return 0;
}