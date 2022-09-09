#include<bits/stdc++.h>
using namespace std;
const int N=3005,mo=1e9+7;
typedef long long ll;
int lo[N*5];
struct S{
static const int N=::N*5;
	char c[N];
	int sa[N],rk[N],h[N],ff[20][N],n;
	inline void getsa(){
		static int f[N],g[N],ork[N],ork2[N];
		int d,i,j,p;
		memset(f,0,104);
		for(i=1;i<=n;++i)++f[c[i]-'a'];for(i=1;i<26;++i)f[i]+=f[i-1];
		for(i=1;i<=n;++i)g[f[c[i]-'a']--]=i;
		p=0;
		for(i=1;i<=n;++i)rk[g[i]]=p+=c[g[i]]>c[g[i-1]];
		for(i=1;i<=n;++i)sa[rk[i]]=i;sa[n+1]=0;
		for(d=2;p<n;d<<=1){
			memcpy(ork+1,rk+1,n<<2);
			memcpy(ork2+1,rk+(d>>1)+1,(n-(d>>1))<<2);
			memset(ork2+n+1-(d>>1),0,(d>>1)<<2);
			memset(f,0,(p+1)<<2);
			for(i=1;i<=n;++i)++f[ork2[i]];
			for(i=1;i<=p;++i)f[i]+=f[i-1];
			for(i=1;i<=n;++i)g[f[ork2[i]]--]=i;
			memset(f,0,(p+1)<<2);
			for(i=1;i<=n;++i)++f[ork[i]];
			for(i=1;i<=p;++i)f[i]+=f[i-1];
			for(i=n;i;--i)sa[f[ork[g[i]]]--]=g[i];p=0;
			for(i=1;i<=n;++i)rk[sa[i]]=p+=ork[sa[i]]>ork[sa[i-1]] || ork2[sa[i]]>ork2[sa[i-1]];
		}
		for(i=1,j=0;i<=n;h[rk[i++]]=j)
			for(j?--j:0;c[i+j]==c[sa[rk[i]+1]+j];++j);
		for(i=1;i<n;++i)ff[0][i]=h[i];
		for(i=1;1<<i<n;++i)for(j=1;j+(1<<i)-1<n;++j)ff[i][j]=min(ff[i-1][j],ff[i-1][j+(1<<i-1)]);
	}
	inline int lcp(int x,int y){
		x=rk[x];y=rk[y];if(x>y)swap(x,y);
		int l=lo[y-x];return min(ff[l][x],ff[l][y-(1<<l)]);
	}
}S;
char a[2][N],b[N];
int n,f[N][N][4],ans,i,j,m,d;
inline void add(int&x,int y){x+=y-mo;x+=x>>31&mo;}
bool F,FF;
inline void  calc(){
	memset(f,0,sizeof f);
	S.n=n+m*4;memcpy(S.c+m*4+1,b+1,n);
	for(i=1;i<=m;++i)S.c[i]=a[0][i],S.c[i+m]=a[0][m-i+1],S.c[i+m*2]=a[1][i],S.c[i+m*3]=a[1][m-i+1];
	S.getsa();
	for(i=1;i<=n;++i){
		d=i>>1;
		for(j=1;j<=m;++j){
			f[i][j][0]=i==1 && a[0][j]==b[1];
			f[i][j][1]=i==1 && a[1][j]==b[1];
			if(d>1 && !(i&1) && j>=d && S.lcp(m*3+m-j+1,m*4+1)>=d && S.lcp(j-d+1,m*4+d+1)>=d){
				f[i][j][2]=1;
				if(FF && d*2==n)add(ans,mo-1);
			}
			if(d>1 && !(i&1) && j>=d && S.lcp(m+m-j+1,m*4+1)>=d && S.lcp(m*2+j-d+1,m*4+d+1)>=d){
				f[i][j][3]=1;
				if(FF && d*2==n)add(ans,mo-1);
			}
		}
		for(j=1;j<=m;++j){
			if(b[i]==a[0][j])add(f[i][j][2],f[i-1][j][1]),add(f[i][j][0],f[i-1][j-1][0]),add(f[i][j][0],f[i-1][j-1][2]);
			if(b[i]==a[1][j])add(f[i][j][3],f[i-1][j][0]),add(f[i][j][1],f[i-1][j-1][1]),add(f[i][j][1],f[i-1][j-1][3]);
		}
		d=n-i+1>>1;
		if(d>1 && ((n-i)&1))for(j=1;j+d-1<=m;++j){
			if(S.lcp(j,m*4+n-d*2+1)>=d && S.lcp(m*3+m-(j+d-1)+1,m*4+n-d+1)>=d){
				if(!FF || d*2<n)add(ans,f[i][j][0]);
			}
			if(S.lcp(m*2+j,m*4+n-d*2+1)>=d && S.lcp(m+m-(j+d-1)+1,m*4+n-d+1)>=d){
				if(!FF || d*2<n)add(ans,f[i][j][1]);
			}
		}
	}
	for(j=1;j<=m;++j)for(i=0;i<4;++i)add(ans,f[n][j][i]);
}
int main(){
	for(int i=2;i<S::N;++i)lo[i]=lo[i>>1]+1;
	scanf("%s%s%s",a[0]+1,a[1]+1,b+1);n=strlen(b+1);m=strlen(a[0]+1);
	if(n==1){
		for(i=1;i<=m;++i)ans+=(a[0][i]==b[1])+(a[1][i]==b[1]);
	}else if(n==2){
		for(i=1;i<m;++i)ans+=(a[0][i]==b[1] && a[0][i+1]==b[2])+(a[1][i]==b[1] && a[1][i+1]==b[2])
			+(a[0][i]==b[2] && a[0][i+1]==b[1])+(a[1][i]==b[2] && a[1][i+1]==b[1]);
		for(i=1;i<=m;++i)ans+=(a[0][i]==b[1] && a[1][i]==b[2])+(a[0][i]==b[2] && a[1][i]==b[1]);
	}else{
		calc();
		F=FF=1;for(i=1;i<=n;++i)F=F && b[i]==b[n-i+1];std::reverse(b+1,b+n+1),calc();
	}
	printf("%d\n",ans);
	return 0;
}