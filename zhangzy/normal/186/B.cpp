#include<bits/stdc++.h>
using namespace std;
int n,t1,t2,k,a,b;
struct P{
	int val,pos;
}p[520233];

bool cmp(P p1,P p2){
	return p1.val==p2.val ? p1.pos<p2.pos : p1.val>p2.val;
}

int main(){
	cin>>n>>t1>>t2>>k;
	t1*=100-k;t2*=100;
	for (int i=1;i<=n;i++){
		cin>>a>>b;
		p[i].val=max(a*t1+b*t2 , a*t2+b*t1);
		p[i].pos=i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++){
		printf("%d %.2lf\n",p[i].pos,(double)p[i].val/100.0);
	}
}