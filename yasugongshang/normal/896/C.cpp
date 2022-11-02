#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline long long read(){
	long long x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long long N=100005,mod=1000000007;
long long rr,ret,n,m,seed,vmax,a[N];
inline long long rnd(){
	ret=seed;
	seed=((long long)seed*7+13)%mod;
	return ret;
}
multiset<pair<pair<long long,long long>,long long> > s;
multiset<pair<pair<long long,long long>,long long> >::iterator it;
pair<long long,long long> que[N];
pair<pair<long long,long long>,long long> qu[N];
inline long long ksm(long long x,long long y,long long mod){
	long long ans=1; x%=mod;
	for(;y;y>>=1,x=(long long)x*x%mod)if(y&1){
		ans=(long long)ans*x%mod;
	}
	return ans;
}
int main(){
	n=read(); m=read(); seed=read(); vmax=read();
	for(long long i=1;i<=n;i++)s.insert(mp(mp(i,i),a[i]=rnd()%vmax+1));
	for(long long i=1;i<=m;i++){
		long long op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
		if(l>r)swap(l,r);
		if(op==3)x=rnd()%(r-l+1)+1; else x=rnd()%vmax+1;
		if(op==4)y=rnd()%vmax+1; 
		//for(it=s.begin();it!=s.end();it++){cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;}
		//cout<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<op<<endl;
		rr=0;
		if(op==1){
		    it=s.lower_bound(mp(mp(l,0),0));
		    if((*it).first.second<l)qu[++rr]=mp(mp(l-1,(*it).first.second),(*it).second);
			for(;it!=s.end()&&(*it).first.first<=r;s.erase(it++)){
				qu[++rr]=mp(mp((*it).first.first,max(l,(*it).first.second)),(*it).second+x);
			}
			if(it!=s.end()){
				if((*it).first.second<=r)qu[++rr]=mp(mp(r,max(l,(*it).first.second)),(*it).second+x);
				qu[++rr]=mp(mp((*it).first.first,r+1),(*it).second);
				s.erase(it);
			}
			for(long long i=1;i<=rr;i++)s.insert(qu[i]);
		}else if(op==2){
			it=s.lower_bound(mp(mp(l,0),0));
		    if((*it).first.second<l)qu[++rr]=mp(mp(l-1,(*it).first.second),(*it).second);
		    for(;it!=s.end()&&(*it).first.first<=r;s.erase(it++));
			if(it!=s.end()&&(*it).first.second<=r){
				qu[++rr]=mp(mp((*it).first.first,r+1),(*it).second);
				s.erase(it);
			}
			for(long long i=1;i<=rr;i++)s.insert(qu[i]);
			s.insert(mp(mp(r,l),x));
		}else if(op==3){
			it=s.lower_bound(mp(mp(l,0),0));
			for(;it!=s.end()&&(*it).first.first<=r;it++){
				que[++rr]=mp((*it).second,(*it).first.first-max(l,(*it).first.second)+1);
			}
			if(it!=s.end()&&(*it).first.second<=r){
				que[++rr]=mp((*it).second,r-max(l,(*it).first.second)+1);
			}
			sort(&que[1],&que[rr+1]);
			for(long long i=1;i<=rr;i++){
				if((x-=que[i].second)<=0){
					writeln(que[i].first); break;
				}
			}
		}else{
			it=s.lower_bound(mp(mp(l,0),0));
			long long ans=0;
			for(;it!=s.end()&&(*it).first.first<=r;it++){
				ans=(ans+(long long)ksm((*it).second,x,y)*((*it).first.first-max(l,(*it).first.second)+1))%y;
			}
		    if(it!=s.end())ans=(ans+(long long)ksm((*it).second,x,y)*(r-max(l,(*it).first.second)+1))%y;  //if(r<(*it).first.second)return 0;
			writeln(ans);
		}
	}
}