#include<cstdio>
#include<iostream>
#include<cmath>
#define mid ((l+r)>>1)
using namespace std;
double t[100100],t1,t2;
int n,q,type,st,en,w;
struct line_tree{
	double sum_up,single;
}tr[2332333],nil;
line_tree together(line_tree tr1,line_tree tr2){
	return (line_tree){tr1.sum_up+tr1.single*tr2.sum_up,tr1.single*tr2.single};
}
line_tree build(int x,int l,int r){
	if (l==r) return tr[x]=(line_tree){t[l],t[l]};
	return tr[x]=together(build(x<<1,l,mid),build(x<<1|1,mid+1,r));
}
line_tree change(int x,int l,int r,int p){
	if (l>p||r<p) return tr[x];
	if (l==r) return tr[x]=(line_tree){t[l],t[l]};
	return tr[x]=together(change(x<<1,l,mid,p),change(x<<1|1,mid+1,r,p));
}
line_tree que(int x,int l,int r,int st,int en){
	if (l==st&&r==en) return tr[x];
	if (en<=mid) return que(x<<1,l,mid,st,en);
	if (st> mid) return que(x<<1|1,mid+1,r,st,en);
	return together(que(x<<1,l,mid,st,mid),que(x<<1|1,mid+1,r,mid+1,en)); 
}
int main()
{
	nil.single=1;nil.sum_up=0;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		cin>>t1>>t2;
		t[i]=(1.0-(t1/t2))/(t1/t2);
	}
	build(1,1,n);
	while (q--){
		cin>>type;
		if (type==1){
			cin>>w>>t1>>t2;
			t[w]=(1.0-(t1/t2))/(t1/t2);
			change(1,1,n,w);
		}
		else{
			cin>>st>>en;
			t1=que(1,1,n,st,en).sum_up;
			printf("%.10lf\n",t1>1e15?0:1.0/(t1+1));
		}
	}
}