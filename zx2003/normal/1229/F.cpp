#include<bits/stdc++.h>
using namespace std;
const int N=35005;
typedef long long ll;
typedef priority_queue<int>Q;
int n,a[N],l[N],r[N],i,L,R,M,lb,rb,z;
Q ql,qr;ll y;
inline int gett(const Q&a){return a.empty()?0:a.top();}
inline void F(Q&a,Q&b,int x,int L){
	z=gett(a);
	if(x>=z)b.push(L-x);else if(a.empty())b.push(L);else{
		b.push(L-z);a.pop();
		if(x>=0)a.push(x);
	}
}
inline ll calc(int m){
	for(;!ql.empty();ql.pop());for(;!qr.empty();qr.pop());y=0;lb=rb=m;
	for(i=1;i<=n;++i){
		int xl=lb+gett(ql),xr=rb-gett(qr);
		if(0<xl)y+=xl;else if(xr<0)y-=xr;
		if(0<rb)F(ql,qr,-lb,rb-lb);
		if(lb<0)F(qr,ql,rb,rb-lb);
		lb+=l[i];rb+=r[i];
	}
	for(;!ql.empty() && ql.top()+lb>m;y+=ql.top()+lb-m,ql.pop());
	for(;!qr.empty() && rb-qr.top()<m;y+=m-(rb-qr.top()),qr.pop());
	return y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i]>>l[i]>>r[i],l[i]-=a[i],r[i]-=a[i],R+=a[i];L=-R;
	for(;L<R;){
		M=L+(1ll*R-L>>1);
		if(calc(M)>calc(M+1))L=M+1;else R=M;
	}
	cout<<calc(L)<<endl;
	return 0;
}