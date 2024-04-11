#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,dd,b,i,xb,a[N],l,r,m,x,y,z,j;
struct seg{
	int l,r,x;
	bool operator<(const seg&rhs)const{return r>rhs.r;}
}s[N];
priority_queue<seg>d;
int main(){
	scanf("%d%d%d",&n,&dd,&b);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i])s[++xb]=(seg){(i-1)/(dd+1)+1,n-(n-i)/(dd+1),a[i]};
	}
	for(l=0,r=(n+1)>>1;l<r;){
		m=(l+r)>>1;
		x=m+1,y=n-m;
		while(!d.empty())d.pop();
		for(i=x,j=1;i<=y;++i){
			while(s[j].l<=i && j<=xb)
				d.push(s[j++]);
			z=b;bool fl=0;
			while(!d.empty()){
				seg u=d.top();d.pop();
				if(u.r<i)continue;
				if(u.x>z){
					u.x-=z;d.push(u);fl=1;break;
				}else if(u.x==z){
					fl=1;break;
				}else z-=u.x;
			}
			if(!fl)break;
		}
		if(i<=y)l=m+1;else r=m;
	}printf("%d\n",l);
	return 0;
}