#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 300005
#define INF 1e9
using namespace std;
struct node{int l,r,k,f,tg;}t[N*2];
int cnt,rt,n,l[N],r[N];
int newnode(int v){
	t[++cnt].k=((rand()<<15)+rand());
	t[cnt].f=v;
	return cnt;
}
void pushdown(int x){
	if (!t[x].tg) return;
	if (t[x].l){
		t[t[x].l].tg+=t[x].tg;
		t[t[x].l].f+=t[x].tg;
	}
	if (t[x].r){
		t[t[x].r].tg+=t[x].tg;
		t[t[x].r].f+=t[x].tg;
	}
	t[x].tg=0;
}
int merge(int a,int b){
	if (!a||!b) return a+b;
	if (t[a].k>t[b].k){
		pushdown(a);
		t[a].r=merge(t[a].r,b);
		return a;
	}
	else{
		pushdown(b);
		t[b].l=merge(a,t[b].l);
		return b;
	}
}
pa split(int x,int k){
	if (!x) return pa(0,0);
	pa y; pushdown(x);
	if (t[x].f>=k){
		y=split(t[x].l,k);
		t[x].l=y.second;
		y.second=x;
	}
	else{
		y=split(t[x].r,k);
		t[x].r=y.first;
		y.first=x;
	}
	return y;
}
int getmin(int x){
	for (;t[x].l;pushdown(x),x=t[x].l);
	return t[x].f;
}
int getans(int x){
	if (!x) return 0;
	pushdown(x);
	return getans(t[x].l)+getans(t[x].r)+(t[x].f<=INF);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=n;i++)
		rt=merge(rt,newnode(INF+i));
	for (int i=1;i<=n;i++){
		pa a,b,c;
		a=split(rt,l[i]);
		b=split(a.second,r[i]);
		if (b.first)
			t[b.first].tg++,t[b.first].f++;
		int mn=getmin(b.second);
		c=split(b.second,mn+1);
		rt=merge(a.first,newnode(l[i]));
		rt=merge(rt,b.first);
		rt=merge(rt,c.second);
	}
	printf("%d\n",getans(rt));
}