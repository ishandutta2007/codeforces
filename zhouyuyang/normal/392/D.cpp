#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
#define pii pair<int,int>
#define se second
#define fi first
const int N=300005;
multiset<int> R;
set<pii > S;
int n,a[N],b[N],c[N];
int A[N],B[N],C[N];
int w[N],id[N],ans;
bool cmp(int x,int y){
	return A[x]>A[y];
}
void insert(pii now){
	set<pii>::iterator i,j,k;
	k=S.lower_bound(now);
	if (k->se>=now.se) return;
	S.insert(now); i=S.find(now); j=i; j--;
	R.erase(R.find(j->fi+k->se));
	R.insert(now.fi+k->se);
	R.insert(j->fi+now.se);
	for (;j->se<=now.se;){
		i=j; j--;
		R.erase(R.find(j->fi+i->se));
		R.erase(R.find(i->fi+now.se));
		S.erase(i);
		R.insert(j->fi+now.se);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),w[++*w]=a[i];
	For(i,1,n) scanf("%d",&b[i]),w[++*w]=b[i];
	For(i,1,n) scanf("%d",&c[i]),w[++*w]=c[i];
	sort(w+1,w+*w+1);
	*w=unique(w+1,w+*w+1)-w-1;
	For(i,1,*w) A[i]=B[i]=C[i]=3*n+1,id[i]=i;
	Rep(i,n,1) A[a[i]=lower_bound(w+1,w+*w+1,a[i])-w]=i;
	Rep(i,n,1) B[b[i]=lower_bound(w+1,w+*w+1,b[i])-w]=i;
	Rep(i,n,1) C[c[i]=lower_bound(w+1,w+*w+1,c[i])-w]=i;
	sort(id+1,id+*w+1,cmp);
	S.insert(pii(0,3*n+2)); S.insert(pii(3*n+2,0));
	R.insert(0); ans=A[id[1]];
	for (int i=1;i<=*w;i++){
		insert(pii(B[id[i]],C[id[i]]));
		ans=min(ans,A[id[i+1]]+*R.begin());
	}
	printf("%d",ans);
}