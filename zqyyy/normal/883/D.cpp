#include <cstdio>
#include <cctype>
#define re register
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=1e6+3;
int n,cd,cb,suf[MAXN];
char s[MAXN];bool f[MAXN];
namespace tp{
inline void solve(){
	int z=0,y=0,zz,yy,d;
	for(re int i=1;i<=n;i++)if(s[i]=='*'){zz=i;break;}
	for(re int i=n;i;i--)if(s[i]=='*'){yy=i;break;}
	for(re int i=1;i<=n;i++)if(s[i]=='P'){d=i;break;}
	for(re int i=1;i<d;i++)z+=s[i]=='*';
	for(re int i=n;i>d;i--)y+=s[i]=='*';
	if(z>y)printf("%d %d",z,d-zz);
	else if(y>z)printf("%d %d",y,yy-d);
	else printf("%d %d",z,min(d-zz,yy-d));
}}
inline bool check(int d){
	for(re int i=1;i<=n;i++)f[i]=0;
	for(re int i=1;i<=n;i++)
		if(f[i-1]){
			if(s[i]=='.')f[i]=1;
			else if(s[i]=='P')f[min(min(i+d,n),suf[i]-1)]=1;
			else if(suf[i]-i<=d){
				f[suf[i]]=1;
				if(suf[suf[i]]-i<=d)
					f[min(suf[suf[suf[i]]]-1,min(suf[i]+d,n))]=1;
			}
		}
	return f[n];
}
int main(){
	n=read();scanf("%s",s+1);suf[n+1]=1e9;
	for(re int i=n;i;i--)cb+=s[i]=='*',cd+=s[i]=='P',suf[i]=s[i+1]=='P'?i+1:suf[i+1];
	if(cd==1) return tp::solve(),0;
	printf("%d ",cb);int l=1,r=n,ans=1;f[0]=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}