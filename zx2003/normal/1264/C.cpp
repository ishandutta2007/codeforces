#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=998244353;
int n,q,p[N],i,M,aa[N],ans,inv[105];
struct info{int k,b;}T[N<<2];
info uni(info a,info b){return (info){int(1ll*b.k*a.k%mo),int((1ll*a.b*b.k+b.b)%mo)};}
int ask(int l,int r){
	int z=aa[l];if(l==r)return z;
	l+=M;r+=M+1;
	info L=(info){1,0},R=(info){1,0};
	for(;l^r^1;l>>=1,r>>=1){
		if(!(l&1))L=uni(L,T[l^1]);
		if(r&1)R=uni(T[r^1],R);
	}
	L=uni(L,R);
	return (1ll*z*L.k+L.b)%mo;
}
set<int>s;
int main(){
	for(i=1;i<105;++i)inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo;
	scanf("%d%d",&n,&q);
	for(M=1;M<n+2;M<<=1);
	for(i=1;i<=n;++i)scanf("%d",p+i),aa[i]=100ll*inv[p[i]]%mo,T[M+i]=(info){aa[i],aa[i]};
	for(i=M-1;i;--i)T[i]=uni(T[i<<1],T[i<<1|1]);
	s.insert(1);s.insert(n+1);ans=ask(1,n);
	for(;q--;){
		scanf("%d",&i);
		if(!s.count(i)){
			auto it=s.upper_bound(i),it2=it--;
			ans=(ans+1ll*mo-ask(*it,*it2-1)+ask(*it,i-1)+ask(i,*it2-1))%mo;
			s.insert(i);
		}else{
			auto it1=s.find(i),it3=it1--,it2=it3++;
			ans=(ans+2ll*mo-ask(*it1,*it2-1)-ask(*it2,*it3-1)+ask(*it1,*it3-1))%mo;
			s.erase(it2);
		}
		printf("%d\n",ans);
	}
	return 0;
}