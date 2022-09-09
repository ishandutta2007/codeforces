#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef pair<double,int>P;
multiset<P>s1,s2;
multiset<P>::iterator it1[N],it2[N];
int n,t,q,p[N],l[N],nw[N],o,x,i,ct;
double ans;
inline double D(int x,int k){return p[x]*l[x]*1.0/(l[x]+k)/(l[x]+k+1);}
inline double V(int x,int k){return p[x]*k*1.0/(l[x]+k);}
inline void del1(int x){if(nw[x])s1.erase(it1[x]);}
inline void del2(int x){if(nw[x]<l[x])s2.erase(it2[x]);}
inline void ins1(int x){if(nw[x])it1[x]=s1.insert(P(D(x,nw[x]-1),x));}
inline void ins2(int x){if(nw[x]<l[x])it2[x]=s2.insert(P(D(x,nw[x]),x));}
inline void F(){
	if(s2.empty() || ct==t)return;
	P u=*--s2.end();s2.erase(--s2.end());
	++ct;ans+=u.first;
	int xx=u.second;
	del1(xx);++nw[xx];ins1(xx);ins2(xx);
}
int main(){
	scanf("%d%d%d",&n,&t,&q);
	for(i=1;i<=n;++i)scanf("%d",p+i);
	for(i=1;i<=n;++i)scanf("%d",l+i),it2[i]=s2.insert(P(D(i,0),i));
	for(i=1;i<=t;++i)F();
	for(;q--;){
		scanf("%d%d",&o,&x);
		ans-=V(x,nw[x]);
		if(o==1){
			if(ct<t){del1(x);++l[x],++nw[x];ans+=V(x,nw[x]);ins1(x);++ct;}else{
				del1(x);del2(x);
				if(nw[x])--nw[x],--ct;
				++l[x];ans+=V(x,nw[x]);
				ins1(x);ins2(x);
				F();
			}
		}else{
			if(nw[x]==l[x]){del1(x);--l[x],--nw[x];ans+=V(x,nw[x]);ins1(x);if(--ct<t)F();}else{
				del1(x);del2(x);
				--l[x];ans+=V(x,nw[x]);
				ins1(x);ins2(x);
			}
		}
		for(;!s2.empty() && !s1.empty() && *s2.rbegin()>*s1.begin();){
			int xx=s1.begin()->second;ans-=s1.begin()->first;
			del1(xx);del2(xx);--ct;--nw[xx];ins1(xx);ins2(xx);
			F();
		}
		printf("%.8f\n",ans);
	}
	return 0;
}