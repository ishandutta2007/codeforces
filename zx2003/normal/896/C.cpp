#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
struct atom{
	int id,s;
	ll v;
	bool operator<(const atom&rhs)const{
		return id<rhs.id;
	}
}z,w;
pair<ll,int>a[100005];
set<atom>s;
int seed,n,m,i,vm,o,l,r,x,y,xb;
ll ans;
inline int rnd(){
	int res=seed;
	return seed=(1ll*seed*7+13)%1000000007,res;
}
inline int pow(int a,int b){
	int ans=1%y;
	for(;b;b>>=1,a=1ll*a*a%y)ans=b&1?1ll*a*ans%y:ans;
	return ans; 
}
inline void outln(ll x){
	if(x){
		static int buf[30],xb;
		for(xb=0;x;x/=10)buf[++xb]=x%10;
		for(;xb;)putchar(buf[xb--]|48);
	}else putchar('0');
	putchar('\n');
}
int main(){
	//freopen("c1.txt","w",stdout);
	scanf("%d%d%d%d",&n,&m,&seed,&vm);
	for(i=1;i<=n;++i){
		x=rnd()%vm+1;
		if(s.empty()){s.insert((atom){i,1,x});continue;}
		if(x!=s.rbegin()->v)s.insert((atom){i,1,x});
			else{
				z=*--s.end();s.erase(--s.end());++z.s;
				s.insert(z);
			}
	}
	register set<atom>::iterator it;int cnt=0;
	while(m--){
		o=rnd()%4+1;l=rnd()%n+1;r=rnd()%n+1;
		if(l>r)x=l,l=r,r=x;
		if(o==3)x=rnd()%(r-l+1)+1;
			else x=rnd()%vm+1;
		if(o==4)y=rnd()%vm+1;
		if(o==1){
			it=--s.upper_bound((atom){l,0,0});
			w=*it;
			s.erase(it++);
			if(w.id+w.s-1>r)s.insert((atom){r+1,w.id+w.s-1-r,w.v}),s.insert((atom){l,r-l+1,w.v+x});
				else s.insert((atom){l,w.id+w.s-l,w.v+x});
			if(w.id<l)s.insert((atom){w.id,l-w.id,w.v});
			for(;it!=s.end() && it->id<=r;){
				z=*it;s.erase(it++);
				if(z.id+z.s-1<=r)z.v+=x,s.insert(z);
					else s.insert((atom){z.id,r-z.id+1,z.v+x}),s.insert((atom){r+1,z.id+z.s-1-r,z.v});
			}
		}
		if(o==2){
			it=--s.upper_bound((atom){l,0,0});
			w=*it;
			s.erase(it++);
			if(w.id+w.s-1>r)s.insert((atom){r+1,w.id+w.s-1-r,w.v});
			if(w.id<l)s.insert((atom){w.id,l-w.id,w.v});
			for(;it!=s.end() && it->id<=r;){
				z=*it;s.erase(it++);
				if(z.id+z.s-1>r)s.insert((atom){r+1,z.id+z.s-1-r,z.v});
			}
			s.insert((atom){l,r-l+1,x});
		}
		if(o==3){
			if(++cnt==13){
				++o,--o;
			}
			it=--s.upper_bound((atom){l,0,0});xb=0;
			w=*it++;
			if(w.id+w.s>r)a[++xb]=make_pair(w.v,r-l+1);
				else a[++xb]=make_pair(w.v,w.id+w.s-l);
			for(;it!=s.end() && it->id<=r;){
				z=*it++;
				if(z.id+z.s-1<=r)a[++xb]=make_pair(z.v,z.s);
					else a[++xb]=make_pair(z.v,r-z.id+1);
			}
			sort(a+1,a+xb+1);
			for(i=1;i<=xb;x-=a[i++].second)if(x<=a[i].second)break;
			outln(a[i].first);
		}
		if(o==4){
			if(++cnt==13){
				++o,--o;
			}
			it=--s.upper_bound((atom){l,0,0});ans=0;
			w=*it++;
			if(w.id+w.s>r)ans=(ans+1ll*(r-l+1)*pow(w.v%y,x))%y;
				else ans=(ans+1ll*(w.id+w.s-l)*pow(w.v%y,x))%y;
			for(;it!=s.end() && it->id<=r;){
				z=*it++;
				if(z.id+z.s-1<=r)ans=(ans+1ll*z.s*pow(z.v%y,x))%y;
					else ans=(ans+1ll*(r-z.id+1)*pow(z.v%y,x))%y;
			}			
			outln(ans);
		}
	}
	return 0;
}