#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,mo=1e9+7;
int n;
struct node{
	node *son,*next;
	ll f[2];
	void dp(){
		f[0]=1;
		for(node *v=son;v;v=v->next){
			v->dp();
			ll g[2]={(f[0]*v->f[0]+f[1]*v->f[1])%mo,(f[0]*v->f[1]+f[1]*v->f[0])%mo};
			f[0]=g[0]; f[1]=g[1];
		}
		f[0]=f[0]*2%mo;
		f[1]=f[1]*2%mo;
		ll g[2]={1,0};
		for(node *v=son;v;v=v->next){
			ll gg[2]={(g[0]+g[1]*v->f[1])%mo,(g[1]+g[0]*v->f[1])%mo};
			g[0]=gg[0]; g[1]=gg[1];
		}
		f[1]=(f[1]+mo-g[1])%mo;
		g[0]=1;
		for(node *v=son;v;v=v->next)
			g[0]=g[0]*v->f[0]%mo;
		f[0]=(f[0]+mo-g[0])%mo;
		swap(f[0],f[1]);
		(++f[0])%=mo;
	}
} V[N];

int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int p; scanf("%d",&p);
		V[i].next=V[p].son;
		V[p].son=V+i;
	}
	V[1].dp();
	printf("%d\n",int((V[1].f[0]+V[1].f[1]+mo-1)%mo));
	scanf("\n");
}