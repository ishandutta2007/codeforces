#include<bits/stdc++.h>
#define db long double
#define pa pair<db,db>
#define ll long long
#define fi first
#define se second
using namespace std;
multiset<pa > S;
int dcmp(db a){
	if (fabs(a)<=1e-11) return 0;
	return a<0?-1:1;
}
pa operator -(pa x,pa y){
	return pa(x.fi-y.fi,x.se-y.se);
}
db cha(pa x,pa y){
	return x.fi*y.se-y.fi*x.se;
}
bool OK(pa a,pa b,pa c){
	return dcmp(cha(b-a,c-a))<=0;
}
void insert(pa x){
	multiset<pa>::iterator it,Ppre,pre,nxt;
	it=S.lower_bound(pa(x.fi,0));
	if (it!=S.end()&&(*it).se<=x.se) return;
	pre=it; pre--;
	if (it!=S.end()&&OK(*pre,x,*it)) return;
	nxt=pre=it=S.insert(x); 
	Ppre=--pre;	Ppre--; nxt++;
	for (;nxt!=S.end()&&(*nxt).fi==x.fi;)
		S.erase(nxt++);
	for (;pre!=S.begin()&&OK(*Ppre,*pre,x);)
		S.erase(pre--),Ppre--;
}
int main(){
	int Q,last=0;
	ll m;
	scanf("%d%lld",&Q,&m);
	S.insert(pa(0,0));
	for (int i=1;i<=Q;i++){
		int fl,a,b;
		scanf("%d%d%d",&fl,&a,&b);
		a=(a+last)%1000000+1;
		b=(b+last)%1000000+1;
		if (fl==1){
			insert(pa(a,b));
			continue;
		}
		db x=1.0*b/a;
		multiset<pa>::iterator it,pre,nxt;
		it=S.lower_bound(pa(x,0));
		if (it==S.end()){
			puts("NO");
			continue;
		}
		if (it->second*a<=m){
			puts("YES");
			last=i;
			continue;
		}
		pre=it; pre--;
		nxt=it;
		if (OK(pa(pre->fi*a,pre->se*a),pa(b,m),pa(it->fi*a,it->second*a))){
			puts("YES");
			last=i;
		}
		else puts("NO");
	}
}