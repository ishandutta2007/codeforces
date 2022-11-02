#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500005;
int m,n,a[N],fa[N],L[N],R[N];
LL s1[N],s2[N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
struct Node{
	int x;
	Node(){}
	Node(int _x){x=_x;}
	friend bool operator < (Node a,Node b){
		if (s2[a.x]-s1[a.x]==s2[b.x]-s1[b.x])
			return a.x<b.x;
		return s2[a.x]-s1[a.x]<s2[b.x]-s1[b.x];
	}
};
set <Node> S;
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	n--;
	a[n+1]=0;
	for (int i=0;i<=n+1;i++)
		s1[i]=0,s2[i]=a[i],fa[i]=L[i]=R[i]=i;
	s2[0]=s2[n+1]=2e9+5;
	S.clear();
	for (int i=0;i<=n+1;i++)
		S.insert(Node(i));
	for (int i=1;i<=m;i++){
		int x=(*(S.begin())).x;
		S.erase(Node(x));
		swap(s1[x],s2[x]);
		int	l=getf(L[x]-1),r=getf(R[x]+1);
		S.erase(Node(l));
		S.erase(Node(r));
		fa[l]=fa[r]=x;
		s1[x]+=s1[l]+s1[r];
		s2[x]+=s2[l]+s2[r];
		L[x]=L[l],R[x]=R[r];
		S.insert(Node(x));
	}
	int ans=0;
	for (set <Node>::iterator i=S.begin();i!=S.end();i++)
		ans+=s1[(*i).x];
	printf("%d",ans);
	return 0;
}