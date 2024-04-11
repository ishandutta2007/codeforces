#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=200000+10;
const ll inf=1000000000000000;
int a[maxn],b[maxn],c[maxn],cc[maxn],e[maxn],sta[maxn];
int h[maxn],go[maxn*2],nxt[maxn*2],fa[maxn],d[maxn];
int i,j,k,l,r,t,n,m,u,v,w,z,tot,top,S,T,ansu,ansv;
ll num,sum,ans;
bool bz[maxn];
bool czy;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void add(int x,int y){
	go[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
void dfs(int x,int y){
	d[x]=d[y]+1;
	fa[x]=y;
	int t=h[x];
	while (t){
		if (go[t]!=y) dfs(go[t],x);
		t=nxt[t];
	}
}
bool pd(){
	int i;
	fo(i,1,n)
		if (a[i]!=b[i]) return 0;
	return 1;
}
void re(){
	int i;
	fo(i,1,n){
		a[i]=c[i];
		b[i]=cc[i];
	}
	num=0;
}
int lca(int x,int y){
	while (x!=y){
		if (d[x]>d[y]) x=fa[x];
		else y=fa[y];
	}
	return x;
}
int main(){
	///t=read();
	n=read();
	fo(i,1,n){
		c[i]=a[i]=read();
		if (!a[i]) S=i;
	}
	fo(i,1,n){
		cc[i]=b[i]=read();
		if (!b[i]) T=i;
	}
	fo(i,1,n-1){
		j=read();k=read();
		add(j,k);add(k,j);
	}
	d[0]=-1;
	dfs(S,0);
	k=T;
	while (k){
		bz[k]=1;
		sta[++top]=k;
		k=fa[k];
	}
	/*while (top){
		if (top==1) a[sta[top]]=0;else a[sta[top]]=a[sta[top-1]];
		top--;
	}*/
	fo(i,1,top-1) b[sta[i]]=b[sta[i+1]];
	b[sta[top]]=0;
	if (pd()){
		printf("0 %d\n",d[T]);
		return 0;
	}
	ans=inf;
	num=d[T];
	u=0;v=0;
	fo(i,1,n)
		if (a[i]!=b[i]){
			czy=1;
			t=h[i];
			while (t){
				if (go[t]!=fa[i]&&a[go[t]]!=b[go[t]]){
					czy=0;
					break;
				}
				t=nxt[t];
			}
			if (!czy) continue;
			if (!u) u=i;else v=i;
		}
	if (!v){
		k=u;
		top=0;
		while (a[k]!=b[k]){
			sta[++top]=k;
			k=fa[k];
		}
		l=k;
		while (!bz[l]) l=fa[l];
		num+=2*(d[k]-d[l]);
		fo(i,1,top+1)
			if (i>top||b[sta[i]]==a[u]) break;
		if (i<=top){
			fo(j,1,top) e[j]=a[sta[j]];
			t=0;
			fo(j,i,top) a[sta[j]]=e[++t];
			fo(j,1,i-1) a[sta[j]]=e[++t];
			if (pd()){
				sum=num+(ll)(top+1)*(i-1);
				if (sum<ans){
					ansu=k;
					ansv=u;
					ans=sum;
				}
				r=lca(u,T);
				sum=num+(ll)(top+1)*(top-i+1);
				if (d[r]>d[k]) sum-=(ll)2*(d[r]-d[k]);
				if (sum<ans){
					ansu=k;
					ansv=u;
					ans=sum;
				}
			}
			/*num+=(ll)(top+1)*min(i-1,top-i+1);
			if (pd()&&num<ans){
				ansu=k;
				ansv=u;
				ans=num;
			}*/
		}
	}
	else{
		w=lca(u,v);
		l=w;
		while (!bz[l]) l=fa[l];
		num+=2*(d[w]-d[l]);
		top=0;
		k=u;
		while (k!=w){
			if (fa[k]==w) r=k;
			sta[++top]=k;
			k=fa[k];
		}
		reverse(sta+1,sta+top+1);
		k=v;
		while (k!=w){
			sta[++top]=k;
			k=fa[k];
		}
		fo(i,1,top+1)
			if (i>top||b[sta[i]]==a[r]) break;
		if (i<=top){
			fo(j,1,top) e[j]=a[sta[j]];
			t=0;
			fo(j,i,top) a[sta[j]]=e[++t];
			fo(j,1,i-1) a[sta[j]]=e[++t];
			if (pd()){
				r=lca(u,T);
				sum=num+(ll)(top+1)*(i-1);
				if (d[r]>d[w]) sum-=(ll)2*(d[r]-d[w]);
				if (sum<ans){
					ansu=u;
					ansv=v;
					ans=sum;
				}
				r=lca(v,T);
				sum=num+(ll)(top+1)*(top-i+1);
				if (d[r]>d[w]) sum-=(ll)2*(d[r]-d[w]);
				if (sum<ans){
					ansu=u;
					ansv=v;
					ans=sum;
				}
			}
			/*if (pd()&&num<ans){
				ansu=u;
				ansv=v;
				ans=num;
			}*/
		}
	}
	/*re();
	u=0;v=0;
	fo(i,1,n)
		if (i!=T&&a[i]!=b[i]){
			czy=1;
			t=h[i];
			while (t){
				if (go[t]!=fa[i]&&a[go[t]]!=b[go[t]]){
					czy=0;
					break;
				}
				t=nxt[t];
			}
			if (!czy) continue;
			if (!u) u=i;else v=i;
		}
	if (u&&v){
		w=lca(u,v);
		if (lca(T,v)==w) swap(u,v);
		if (d[lca(T,v)]>d[w]){
			z=lca(T,v);
			top=0;
			k=T;
			while (k!=z){
				sta[++top]=k;
				k=fa[k];
			}
			l=top;
			k=v;
			while (k!=z){
				sta[++top]=k;
				k=fa[k];
			}
			sta[++top]=z;
			reverse(sta+l+1,sta+top+1);
			k=u;
			while (k){
				sta[++top]=k;
				k=fa[k];
			}
			num=top-1;
			fo(i,1,top-1) b[sta[i]]=b[sta[i+1]];
			b[sta[top]]=0;
			top=0;
			k=u;
			while (k!=w){
				if (fa[k]==w) r=k;
				sta[++top]=k;
				k=fa[k];
			}
			reverse(sta+1,sta+top+1);
			k=v;
			while (k!=w){
				sta[++top]=k;
				k=fa[k];
			}
			fo(i,1,top+1)
				if (i>top||b[sta[i]]==a[r]) break;
			if (i<=top){
				fo(j,1,top) e[j]=a[sta[j]];
				t=0;
				fo(j,i,top) a[sta[j]]=e[++t];
				fo(j,1,i-1) a[sta[j]]=e[++t];
				num+=(ll)(top+1)*min(i-1,top-i+1);
				if (pd()&&num<ans){
					ansu=u;
					ansv=v;
					ans=num;
				}
			}
		}
	}
	re();*/
	if (ans==inf) printf("-1\n");
	else{
		if (ansu>ansv) swap(ansu,ansv);
		printf("%d %d %lld\n",ansu,ansv,ans);
	}
}