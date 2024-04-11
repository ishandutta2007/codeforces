#include<cstdio>
#include<cstring>
const int N=2000005;
int ch[N][26],xb,step[N],p,np,q,nq,lst,n,i,x,u,l,a[N],b[N],s[N],z,ans,vi[N],pre[N];
int cnt[26];
char c[N];
int main(){
	scanf("%s",c+1);lst=xb=1;
	for(i=1;c[i];++i){
		step[np=++xb]=step[p=lst]+1;++cnt[x=c[i]-'a'];
		for(;!ch[p][x];p=pre[p])ch[p][x]=np;
		if(p){
			q=ch[p][x];
			if(step[p]+1!=step[q]){
				step[nq=++xb]=step[p]+1;
				memcpy(ch[nq],ch[q],104);
				pre[nq]=pre[q];
				pre[q]=pre[np]=nq;
				for(;ch[p][x]==q;p=pre[p])ch[p][x]=nq;
			}else pre[np]=q;
		}else pre[np]=1;
		s[lst=np]=1;
	}
	for(i=1;i<=xb;++i)++b[step[i]];
	for(i=1;b[i];++i)b[i]+=b[i-1];
	for(i=1;i<=xb;++i)a[b[step[i]]--]=i;
	for(i=xb;i;--i)s[pre[a[i]]]+=s[a[i]];
	scanf("%d",&n);
	while(n){
		scanf("%s",c+1);l=strlen(c+1);
		if(l==1){printf("%d\n",cnt[c[1]-'a']);--n;continue;}
		memcpy(c+l+1,c+1,l-1);
		u=1;z=ans=0;
		for(i=1;i<l<<1;++i){
			x=c[i]-'a';
			if(!ch[u][x]){
				for(;u && !ch[u][x];u=pre[u]);
				if(ch[u][x])z=step[u]+1,u=ch[u][x];
					else z=0,u=1;
			}else u=ch[u][x],++z;
			if(z>=l && vi[u]!=n)vi[u]=n,ans+=s[u];
			for(;step[pre[u]]+1>=l;z=step[u=pre[u]]);
		}
		printf("%d\n",ans);--n;
	}
	return 0;
}