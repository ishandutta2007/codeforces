#include<bits/stdc++.h>
using namespace std;

int n,T,m,an[201000];
struct OPT{
	int l,r,opt;
}o[201000],t;

int main(){
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=n;scanf("%d",&an[i++]));
	for (int i=1;i<=m;scanf("%d%d%d",&o[i].opt,&o[i].l,&o[i].r),i++);
	for (int x;T--;printf("%d ",an[x])){
		scanf("%d",&x);
		for (int i=m;i>0;i--){
			t=o[i];
			if (t.l<=x&&x<=t.r){
				if (t.opt==2){
					x=t.l+t.r-x;
				}else{
					x= x==t.l? t.r: x-1;
				}
			}
		}
	}
}