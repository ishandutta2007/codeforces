#include <cstdio>
#include <vector>
const int N=45;
const int rev[5]={1,0,2,4,3};
int n,k;
long long dp[N<<1][N<<1];
char s[N];
namespace basic{
	int lt,res,dig[50];
	long long nw;
	char cdc;
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(long long x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
	}
}using basic::read;using basic::write;
struct limit{
	int v,opt;
	limit(){};
	limit(int v,int opt):v(v),opt(opt){};
};std::vector<limit> lim[N<<1];
inline int tap(char *s){
	if(s[0]=='=')return 2;
	if(s[0]=='>'&&!s[1])return 0;
	if(s[0]=='<'&&!s[1])return 1;
	if(s[0]=='>')return 3;
	if(s[0]=='<')return 4;
	return -1;
}
//two sides
bool check1(int l,int r){
	int v,opt;
	for(limit nw:lim[l]){
		v=nw.v,opt=nw.opt;
		switch(opt){
			case 0:if(v>=l&&v<=r)return false;break;
			case 1:if(v<=l||v>=r)return false;break;
			case 2:if(v!=l&&v!=r)return false;break;
			case 3:if(v>l&&v<r)return false;break;
			case 4:if(v<l||v>r)return false;break;
			default:break;
		}
	}
	for(limit nw:lim[r]){
		v=nw.v,opt=nw.opt;
		switch(opt){
			case 0:if(v>=l&&v<=r)return false;break;
			case 1:if(v<=l||v>=r)return false;break;
			case 2:if(v!=l&&v!=r)return false;break;
			case 3:if(v>l&&v<r)return false;break;
			case 4:if(v<l||v>r)return false;break;
			default:break;
		}
	}
	return true;
}
//left side
bool check2(int l,int r){
	int v,opt;
	for(limit nw:lim[l]){
		v=nw.v,opt=nw.opt;
		switch(opt){
			case 0:if(v>=l&&v<=r)return false;break;
			case 1:if(v<=l+1||v>r)return false;break;
			case 2:if(v!=l&&v!=l+1)return false;break;
			case 3:if(v>l+1&&v<=r)return false;break;
			case 4:if(v<l||v>r)return false;break;
			default:break;
		}
	}
	for(limit nw:lim[l+1]){
		v=nw.v,opt=nw.opt;
		switch(opt){
			case 0:if(v>=l&&v<=r)return false;break;
			case 1:if(v<=l+1||v>r)return false;break;
			case 2:if(v!=l&&v!=l+1)return false;break;
			case 3:if(v>l+1&&v<=r)return false;break;
			case 4:if(v<l||v>r)return false;break;
			default:break;
		}
	}
	return true;
}
//right side
bool check3(int l,int r){
	int v,opt;
	for(limit nw:lim[r]){
		v=nw.v,opt=nw.opt;
		switch(opt){
			case 0:if(v>=l&&v<=r)return false;break;
			case 1:if(v<l||v>=r-1)return false;break;
			case 2:if(v!=r&&v!=r-1)return false;break;
			case 3:if(v>=l&&v<r-1)return false;break;
			case 4:if(v<l||v>r)return false;break;
			default:break;
		}
	}
	for(limit nw:lim[r-1]){
		v=nw.v,opt=nw.opt;
		switch(opt){
			case 0:if(v>=l&&v<=r)return false;break;
			case 1:if(v<l||v>=r-1)return false;break;
			case 2:if(v!=r&&v!=r-1)return false;break;
			case 3:if(v>=l&&v<r-1)return false;break;
			case 4:if(v<l||v>r)return false;break;
			default:break;
		}
	}
	return true;
}
int main(){
	n=read(),k=read();
	for(int u,v,opt,i=1;i<=k;++i){
		u=read(),scanf("%s",s),v=read(),opt=tap(s);
		lim[u].push_back(limit(v,opt)),lim[v].push_back(limit(u,rev[opt]));
	}
	for(int i=1;i<(n<<1);++i)if(check1(i,i+1))dp[i][i+1]=1;
	for(int i=2;i<=n;++i){
		int len=i<<1;
		for(int j=1;j+len-1<=(n<<1);++j){
			if(check1(j,j+len-1))dp[j][j+len-1]+=dp[j+1][j+len-2];//two sides;
			if(check2(j,j+len-1))dp[j][j+len-1]+=dp[j+2][j+len-1];//left side;
			if(check3(j,j+len-1))dp[j][j+len-1]+=dp[j][j+len-3];//right side;
		}
	}
	write(dp[1][n<<1]);
	return 0;
}