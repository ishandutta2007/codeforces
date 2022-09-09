#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,i,j,mxl,ans,l1,l2;
char s[N],c1[N],c2[N];
int ch[N][26],pre[N],len[N],xb,pos[N],jj[N];
int anc[22][N];
int climb(int u,int l){
	for(int i=21;i>=0;--i)if(len[anc[i][u]]>=l)u=anc[i][u];
	return u;
}
inline void solve(char*cc,int&l){
	memset(ch[0],0,104);memset(ch[1],0,104);pre[0]=1;xb=1;len[1]=-1;
	int lst=1,p,np,pp;
	for(i=1;i<=n;++i){
		p=lst;
		for(;s[i-len[p]-1]!=s[i];p=pre[p]);
		if(!ch[p][s[i]-'a']){
			memset(ch[++xb],0,104);len[xb]=len[p]+2;
			for(pp=pre[p];s[i-len[pp]-1]!=s[i];pp=pre[pp]);
			pre[xb]=ch[pp][s[i]-'a'];
			ch[p][s[i]-'a']=xb;
		}
		pos[i]=lst=ch[p][s[i]-'a'];
	}
	memcpy(anc[0],pre,xb+1<<2);
	for(i=1;i<22;++i)for(j=0;j<=xb;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	int mx=0,mxid=0;
	for(i=1;i<=n;++i){
		int j=len[pos[i]],v,mn=max(2*i-n+1,i-mxl);mn=max(mn,0);
if(i==6)
++i,--i;
		if(j<mn)continue;jj[i]=j=len[climb(pos[i],mn)];
		if(mxl+j>=i){
			v=(i-j)*2+j;
			if(v>mx)mx=v,mxid=i;
		}
	}
	l=0;
	if(!mxid)return;
	for(i=mxid;i<=mxid;++i){
		j=jj[i];
		for(int k=1;k<=i;++k)cc[++l]=s[k];
		for(int k=n-(i-j)+1;k<=n;++k)cc[++l]=s[k];
	}
	cc[l+1]=0;
}
int main(){
//	freopen("1","r",stdin);
	for(scanf("%d",&T);T--;){
		scanf("%s",s+1);n=strlen(s+1);
		for(mxl=0;mxl+1<<1<=n && s[mxl+1]==s[n-mxl];++mxl);
		if(mxl*2+1>=n){puts(s+1);continue;}
		solve(c1,l1);
		reverse(s+1,s+n+1);
		solve(c2,l2);
		if(mxl*2+1>=max(l1,l2)){
			for(i=1;i<=mxl+1;++i)putchar(s[i]);
			for(i=n-mxl+1;i<=n;++i)putchar(s[i]);
			puts("");
		}else if(l1>l2)puts(c1+1);else puts(c2+1);
	}
}