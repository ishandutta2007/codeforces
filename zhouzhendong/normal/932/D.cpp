#include <cstring>
#include <cstdio>
#include <cmath>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=400005;
typedef long long LL;
int n,cnt=1,fa[N][20],depth[N];
LL w[N],sum[N],last,type,R,x;
bool isd(char ch){
	return '0'<=ch&&ch<='9';
}
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isd(ch))
		ch=getchar();
	while (isd(ch))
		x=x*10+ch-48,ch=getchar();
	return x;
}
int find_fa(int now,LL x){
	if (w[now]>=x)
		return now;
	for (int i=19;i>=0;i--)
		if (w[fa[now][i]]<x)
			now=fa[now][i];
	return fa[now][0];
}
int main(){
	n=read();
	memset(fa,0,sizeof fa);
	memset(sum,0,sizeof sum);
	memset(w,0,sizeof w);
	w[0]=1e15;
	depth[0]=0,depth[1]=1;
	sum[0]=sum[1]=w[0];
	last=0;
	while (n--){
		type=read(),R=read(),x=read();
		R^=last,x^=last;
		if (type==1){
			fa[++cnt][0]=find_fa(R,x);
//			printf("fa[%d]=%d\n",cnt,fa[cnt][0]);
			w[cnt]=x;
			depth[cnt]=depth[fa[cnt][0]]+1;
			sum[cnt]=sum[fa[cnt][0]]+w[cnt];
//			printf("%I64d\n",sum[cnt]);
			for (int i=1;i<=19;i++)
				fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
		}
		else {
			int res=0;
			if (x>=w[R])
				for (int i=19,y=R;i>=0;i--)
					if (sum[R]-sum[fa[y][i]]<=x)
						res+=1<<i,y=fa[y][i];
			printf("%d\n",last=min(res,depth[R]));
		}
	}
	return 0;
}