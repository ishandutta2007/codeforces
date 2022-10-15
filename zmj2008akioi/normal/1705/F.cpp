//15 in 10 querys!!!
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unordered_map>
const int N=1e3+10;
int n,qc[N],ans[N];
char buf[N];
std::unordered_map<unsigned long long,int> map[N];
const int len=10,flen=15;
const int st[10]={27639,3795,12252,14675,8766,19138,27693,16991,373,489};
inline int lowbit(int x){return x&(-x);}
inline int popcnt(int x){int res=0;while(x)++res,x-=lowbit(x);return res;}
inline int min(int x,int y){return x<y?x:y;}
void init(){
	for(int t=1;t<=flen;++t){
		for(int i=0;i<(1<<t);++i){
			unsigned long long nw=0,pw=1;
			for(int j=0;j<len-1;++j){
				int pv=st[j+1],pu=st[j];
				for(int q=t;q<flen;++q){
					int bit=1<<q;
					if(pu&bit)pu^=bit;
					if(pv&bit)pv^=bit;
				}
				int u=popcnt(i^pv)-popcnt(i^pu);
				u+=flen,nw+=u*pw,pw*=(flen<<1)+1;
			}
			map[t][nw]=i;
		}
	}
}
int query(int j,int l){
	for(int i=1;i<=n;++i)buf[i]='F';
	for(int i=0;i<flen;++i){
		int bit=st[j]&(1<<i);
		if(bit)buf[l+i]='T';
	}
	buf[n+1]='\0',puts(buf+1),fflush(stdout);
	int x;scanf("%d",&x);if(x==n)exit(0);return x;
}
int main(){
	scanf("%d",&n),init();
	for(int i=1;i<=n;i+=15){
		for(int j=0;j<len;++j)qc[j]=query(j,i);
		unsigned long long nw=0,pw=1;
		for(int j=0;j<len-1;++j){
			int u=qc[j]-qc[j+1];
			u+=flen,nw+=u*pw,pw*=(flen<<1)+1;
		}
		int len=min(15,n-i+1);
		assert(map[len].find(nw)!=map[len].end());
		int t=map[len][nw];
		for(int j=0;j<flen;++j)if(t&(1<<j))ans[i+j]=1;
	}
	for(int i=1;i<=n;++i)putchar(ans[i]?'T':'F');
	putchar('\n'),fflush(stdout);return 0;
}