#include<bits/stdc++.h>
using namespace std;
const int N=265000;
int t1[N*2],t2[N*2];
int id[N],h[N],ans[N];
int hp[N],st[15],n,m,l;
void insert(int v){
	int x=++*hp; hp[x]=v;
	for (;x!=1&&hp[x]<hp[x/2];x/=2)
		swap(hp[x],hp[x/2]);
}
void del(){
	hp[1]=hp[*hp]; (*hp)--; int x=1;
	for (int s;x*2<=*hp;x=s){
		s=x*2+(x*2+1<=*hp&&hp[x*2+1]<hp[x*2]);
		if (hp[x]<hp[s]) break;
		else swap(hp[x],hp[s]);
	}
}
void chg(int *t,int x,int v){
	t[x+=l-1]=v;
	for (x>>=1;x;x>>=1)
		t[x]=max(t[x*2],t[x*2+1]);
}
int ask(int *t,int x){
	int ans=0; x+=l-1;
	for (;x;x>>=1) if (!(x&1)) ans=max(ans,t[x+1]);
	return ans+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (l=1;l<200000;l*=2);
	for (;m;m--){
		int fl; scanf("%d",&fl);
		if (fl==1){
			int x,y;
			scanf("%d%d",&x,&y);
			id[y+=m]=x; h[x]=y;	insert(x);
			for (int i=m;i<y;i++)
				if (id[i]) chg(t1,id[i],0);
			for (int i=y;i>=m;i--)
				if (id[i]){
					ans[id[i]]=ask(t1,id[i]);
					chg(t1,id[i],ans[id[i]]);
					chg(t2,i,ans[id[i]]);
				}
		}
		else{
			int x;
			scanf("%d",&x);
			for (;x;--x){
				st[++*st]=hp[1]; del();
				chg(t2,h[st[*st]],0);
			}
			chg(t1,st[*st],0);
			ans[st[*st]]=0;
			id[h[st[*st]]]=0;
			for (--*st;*st;--*st){
				ans[st[*st]]=ask(t2,h[st[*st]]);
				chg(t1,st[*st],ans[st[*st]]);
				chg(t2,h[st[*st]],ans[st[*st]]);
				insert(st[*st]);
			}
		}
		printf("%d\n",t1[1]);
	}
}