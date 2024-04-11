#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
mt19937 R(114514);
struct node{
	int l,r,fa,v,p;
	bool rev;int k,b;
	inline void addtag(int x,int y){
		v=v*x+y;k*=x;b=b*x+y;
	}
}t[N];int tcnt;
inline void upd(int x){
}
inline void pushdown(int x){
	if(t[x].rev){
		swap(t[x].l,t[x].r);
		t[x].rev=0;t[t[x].l].rev^=1;t[t[x].r].rev^=1;
	}
	if(t[x].k!=1 || t[x].b){
		if(t[x].l)t[t[x].l].addtag(t[x].k,t[x].b);
		if(t[x].r)t[t[x].r].addtag(t[x].k,t[x].b);
		t[x].k=1;t[x].b=0;
	}
}
int merge(int x,int y){
	if(!x || !y)return x|y;
	if(t[x].p>t[y].p)return pushdown(x),t[x].r=merge(t[x].r,y),t[t[x].r].fa=x,upd(x),x;
		else return pushdown(y),t[y].l=merge(x,t[y].l),t[t[y].l].fa=y,upd(y),y;
}
void split(int x,int&p,int&q,int k){
	if(!x){p=q=0;return;}
	pushdown(x);
	if(t[x].v<=k)p=x,split(t[x].r,t[p].r,q,k),t[t[p].r].fa=p,upd(p);
		else q=x,split(t[x].l,p,t[q].l,k),t[t[q].l].fa=q,upd(q);
}
inline bool find(int x,int v){
	for(;x;){
		if(t[x].v==v)return 1;
		pushdown(x);if(v<t[x].v)x=t[x].l;else x=t[x].r;
	}
	return 0;
}
int T,n,i,a[N],rt,p,q,r,zz,f,le,ri;
int main(){
	//freopen("1","r",stdin);
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);zz=0;tcnt=0;rt=0;f=0;
		if(a[1]%2==0)t[rt=tcnt=1]=node{0,0,0,a[1]/2,(int)R(),0,1,0},le=1,ri=0;else le=1,ri=0;
		for(i=2;i<=n;++i){
if(i==4)
++i,--i;
			if(zz){
				if(zz<=a[i]-1){
					t[rt=tcnt=1]=node{0,0,0,zz,(int)R(),0,1,0};le=1;ri=0;
					f+=2;
				}else rt=0,f+=2,le=1,ri=0;
			}else{
				split(rt,p,q,a[i]-1);
				if(!p && (le>ri || le>a[i]-1)){
					if(q || le<=ri)++f,rt=0,le=1,ri=0;else{
						rt=0;
						if(a[i-1]<a[i])le=1,ri=a[i-1]-1;else ++f,le=1,ri=0;
					}
				}else rt=p,ri=min(ri,a[i]-1),++f;
			}
			zz=0;
			if(a[i]%2==0){
				if(find(rt,a[i]/2) || (le<=a[i]/2 && a[i]/2<=ri))zz=a[i]/2;
					else split(rt,p,q,a[i]/2),t[++tcnt]=node{0,0,0,a[i]/2,(int)R(),0,1,0},
							rt=merge(merge(p,tcnt),q);
			}
			if(le<=ri)swap(ri=a[i]-ri,le=a[i]-le);
			t[rt].rev^=1;t[rt].addtag(-1,a[i]);
//for(int j=1;j<a[i];++j)printf("%d ",find(rt,j) || (le<=j && j<=ri)?j==zz?f+2:f+1:f);puts("");
		}
		printf("%d\n",n*2-(f+(rt>0 || le<=ri)+(zz>0)));
	}
}