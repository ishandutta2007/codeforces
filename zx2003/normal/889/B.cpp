#include<cstring>
#include<cstdio>
const int S=26,N=10005;
char c[N];
int i,n,pre[S],nxt[S],j,x,y,s;
bool vi[S];
int main(){
	memset(pre,-1,sizeof pre);memset(nxt,-1,sizeof nxt);
	for(scanf("%d",&n),i=1;i<=n;++i){
		scanf("%s",c);
		for(j=1;c[j];++j){
			x=c[j-1]-'a',y=c[j]-'a';
			if((~pre[y] && pre[y]!=x)||(~nxt[x] && nxt[x]!=y))return puts("NO"),0;
			pre[y]=x;nxt[x]=y;
		}
		for(j=0;c[j];)vi[c[j++]-'a']=1;
	}
	for(i=j=0;i<26;s+=vi[i++])if(vi[i] && pre[i]==-1)for(j=i;~j;j=nxt[j])--s;if(s)return puts("NO"),0;
	for(i=j=0;i<26;++i)if(vi[i] && pre[i]==-1)for(j=i;~j;j=nxt[j])putchar(j+'a');
	return 0;
}