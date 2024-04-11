#include<bits/stdc++.h>
#define maxn 1010000
using namespace std;
int n,len,a[maxn],vis[maxn],ls[maxn];
int pre[maxn],nxt[maxn],A[maxn],sz;
int lst[maxn],tg[maxn];
void no(){
	puts("no");
	exit(0);
}
void del(int x){
	tg[x]=1;
//	printf("[del:%d]",x);
	nxt[pre[x]]=nxt[x];
	pre[nxt[x]]=pre[x];
}
int getone(){
	return A[sz--];
}
void deal(int l,int r){
	if(l==r)return ;
	map<int,int> lst;
	for(int i=l;i<r;i=nxt[i])
		lst[a[i]]=-1;
	for(int i=l;i<r;i=nxt[i]){ 
		if(a[i]&&lst[a[i]]!=-1&&!tg[i]){
			if(tg[lst[a[i]]])no();
			deal(lst[a[i]],i);
		}
		if(lst[a[i]]==-1&&a[i])
			lst[a[i]]=i;
	}
//	printf("[%d,%d(%d)]",l,r,sz); 
//	puts("");
//	for(int i=l;i<=r;i=nxt[i])printf("[%d(%d)]",a[i],i);puts("");
	for(int s=0;s<10;++s)
	for(int i=l;i<r;i=nxt[i]){
		int z=pre[pre[i]];
		if(a[i]){
			while(true){
				int z,flg=0;
				z=nxt[nxt[i]];
				if(z<r&&a[z]==a[i]){
					if(!a[nxt[i]])a[nxt[i]]=getone();
					del(z),del(pre[z]);
					continue;
				}
				int x=pre[i],y=nxt[i];
				if(x>l&&y<r&&!(a[x]&&a[y])&&(a[x]||a[y])){
					a[x]=a[y]=a[x]+a[y];
				//	printf("[%d,%d]",i,nxt[i]);
					del(i),del(nxt[i]),i=x;
					continue;
				}
				break;
			}	
		}
	}
	int rt=0;
//	printf("[exit:(%d,%d)]\n",l,r);
//	for(int i=l;i<=r;i=nxt[i])printf("[%d(%d)]",a[i],i);puts("");
	for(int i=nxt[l];i<r;i=nxt[i]){
		int z=pre[i];
		if(z>l&&a[z]&&a[i])no();
	}
//	puts("OK");
	int p=0; 
	for(int i=nxt[l];i<=r;i=nxt[i]){
		if(!a[i]){
			if(p==1)a[i]=a[l];
			else if(a[pre[i]]!=a[l]&&pre[pre[i]]>=l){
				a[i]=a[pre[pre[i]]];
			} else a[i]=getone();
		}
		p^=1;
	}
	if(p!=0)no();
	
//	printf("[full:(%d,%d)]\n",l,r);
//	for(int i=l;i<=r;i=nxt[i])printf("[%d]",a[i]);puts("");
	for(int i=nxt[l];i<=r;i=nxt[i])
		del(i);
}
int main(){
	scanf("%d",&n);
	len=2*n-1;
	for(int i=1;i<=len;++i)
		scanf("%d",&a[i]);
	if(a[1]&&a[len]&&a[1]!=a[len])no();
	a[1]|=a[len],a[len]|=a[1];
	int pos=0;
	for(int i=1;i<=len;++i)vis[a[i]]=1;
	for(int i=1;i<=n;++i)if(!vis[i])A[++sz]=i;
	for(int i=1;i<=len&&!pos;++i)
		if(a[i])pos=i;
	if(!pos){
		puts("yes");
		for(int i=1,p=1;i<=len;++i)
			printf("%d ",i&1?1:++p);
		return 0;
	}
	int tp=0;
	for(int i=pos;i<=len;++i)ls[++tp]=a[i];
	for(int i=2;i<=pos;++i)ls[++tp]=a[i];
	for(int i=1;i<=len;++i)a[i]=ls[i];
	a[len]|=a[1];
	for(int i=1;i<=len;++i)pre[i]=i-1,nxt[i]=i+1;
	nxt[0]=1,pre[len+1]=len;
	deal(1,len);
	for(int i=1;i<=len;++i)if(!a[i])a[i]=getone();
	puts("yes");
	for(int i=len-pos+1;i<=len;++i)
		printf("%d ",a[i]);
	for(int i=2;i<=len-pos+1;++i)
		printf("%d ",a[i]);
//	return sz;
}