#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[202000],b[202000],cnt,ch[5202333][2],p,c;

void add(int x){
	p=1;
	for (int i=29;i>=0;--i){
		c=x>>i&1;
		if (!ch[p][c]){
			ch[p][c]=++cnt;
			ch[cnt][0]=ch[cnt][1]=0;
		}
		p=ch[p][c];
	}
}

int que(int x){
	p=1; int res=0;
	for (int i=29;i>=0;--i){
		c=x>>i&1;
		if (!ch[p][c]) res|=1<<i;
		p=ch[p][c^(!ch[p][c])];
	}
	return res;
}

ll doit(int l,int r,int w){
	if (w<0||l>r) return 0;
	for (int i=l;i<=r;++i) b[i]=a[i];
	int p1=l-1,p2=r+1,res=0;
	for (int i=l;i<=r;i++){
		if (b[i]>>w&1) a[++p1]=b[i];
		else a[--p2]=b[i];
	}
	if (p1>=l&&r>=p2){
		res=1e9;
		cnt=1; ch[1][0]=ch[1][1]=0;
		for (int i=l;i<=p1;++i) add(a[i]);
		for (int i=p2;i<=r;++i) res=min(res,que(a[i]));
	}
	return res+doit(l,p1,w-1)+doit(p2,r,w-1);
}

int main(){
	cin>>n; for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cout<<doit(1,n,29);
}