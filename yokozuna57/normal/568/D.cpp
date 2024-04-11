#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const ll INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

ll gcd(ll x,ll y){
	if(y == 0)return x;
	return gcd(y,x%y);
}
P yakubun(P x){
	if(x.sc < 0){
		x.fr *= -1;
		x.sc *= -1;
	}
	ll g = gcd(abs(x.fr),abs(x.sc));
	x.fr /= g; x.sc /= g;
	return x;
}

P2 inter(P2 l,P2 m){
	ll l_a = l.fr.sc , l_b = l.sc.fr , l_c = l.sc.sc;
	ll m_a = m.fr.sc , m_b = m.sc.fr , m_c = m.sc.sc;
	if(l_a*m_b - m_a*l_b == 0)return P2(P(INF,INF),P(INF,INF));
	P x = yakubun(P ( -m_c*l_b + l_c*m_b , l_a*m_b - m_a*l_b ) );
	P y = yakubun(P ( -m_c*l_a + l_c*m_a , l_b*m_a - m_b*l_a ) );
	return P2(x,y);
}

bool f(P2 l,P2 d){
	ld a = l.fr.sc , b = l.sc.fr , c = l.sc.sc;
	ld p = d.fr.fr , q = d.fr.sc , r = d.sc.fr , w = d.sc.sc;
	if(abs(a*p*w+b*q*r-c*q*w) <= 0.5)return true;
	return false;
}

ll ccc(ll x){
	return (x*(x-1))/2;
}

vector<P> ans;
vector<P2> lines[10];
map<P2,int> M;
bool solve(ll n,ll k){
	//cout << n << " " << k << endl;
	if(n <= k){
		rep(i,n){
			ans.pb( P ( lines[k][i].fr.fr , -1 ) );
		}
		return true;
	}
	else if(k == 0)return false;
	else if(n <= k*k){
		M.clear();
		rep(i,lines[k].size()){
			for(int j = i+1 ; j < lines[k].size() ; j ++){
				P2  p = inter(lines[k][i],lines[k][j]);
				if(p.fr.fr == INF && p.fr.sc == INF)continue;
				M[p] ++;
			}
		}
		for(map<P2,int>::iterator itr = M.begin() ; itr != M.end() ; itr++){
			if(itr->sc >= ccc((n+k-1)/k)){
				lines[k-1].clear();
				int v = -1 , u = -1;
				rep(i,lines[k].size()){
					if(!f(lines[k][i],itr->fr)){
						lines[k-1].pb(lines[k][i]);
					}
					else {
						if(v == -1)v = lines[k][i].fr.fr;
						else u = lines[k][i].fr.fr;
					}
				}
				ans.pb( P ( v, u ) );
				if(solve(lines[k-1].size(),k-1))return true;
				ans.pop_back();
			}
		}
		return false;
	}
	else {
		M.clear();
		rep(i,k*k+1){
			for(int j = i+1 ; j < k*k+1 ; j ++){
				P2  p = inter(lines[k][i],lines[k][j]);
				if(p.fr.fr == INF && p.fr.sc == INF)continue;
				M[p] ++;
			}
		}
		for(map<P2,int>::iterator itr = M.begin() ; itr != M.end() ; itr++){
			if(itr->sc >= ccc(k+1)){
				//cout << itr->fr.fr.fr << "/" << itr->fr.fr.sc << " " << itr->fr.sc.fr << "/" << itr->fr.sc.sc << endl;
				lines[k-1].clear();
				int v = -1 , u = -1;
				rep(i,lines[k].size()){
					if(!f(lines[k][i],itr->fr)){
						lines[k-1].pb(lines[k][i]);
					}
					else {
						if(v == -1)v = lines[k][i].fr.fr;
						else u = lines[k][i].fr.fr;
					}
				}
				ans.pb( P ( v, u ) );
				if(solve(lines[k-1].size(),k-1))return true;
				return false;
			}
		}
		return false;
	}
}

int main(){
	static ll n,k;
	static ll a[100010],b[100010],c[100010];
	scanf("%I64d%I64d",&n,&k);
	rep(i,n){
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
		lines[k].pb( P2 ( P ( i+1 , a[i] ) , P ( b[i] , c[i] ) ) );
	}
	
	if(solve(n,k)){
		puts("YES");
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			printf("%I64d %I64d\n",ans[i].fr,ans[i].sc);
		}
	}
	else puts("NO");
}