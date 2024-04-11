#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD=998244353,N=1000010;
int n,m,k;
inline ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) (res*=x)%=MOD;
		(x*=x)%=MOD;y>>=1;
	}
	return res;
}

map<int,array<int,2> > R,C;
map<int,bool> all[N];
int cntR[4],cntC[4],flgRC[2];

inline ll calc(){
	ll res=0;
	if(!R.size()&&!C.size()){
		return (qpow(2,n)+qpow(2,m)-2)%MOD;
	}
	if(!cntR[3]) res+=qpow(2,n-R.size());
	if(!cntC[3]) res+=qpow(2,m-C.size());
	if(flgRC[0]&&flgRC[1]);
	else res--;
	res=(res+MOD)%MOD;
	return res;
}

int Type(int x,int typ){
	if(typ==1){
		auto it=R.find(x);
		if(it==R.end()) 
			return 0;
		if(it->se[0]&&it->se[1]) return 3;
		else if(it->se[0]) return 1;
		else if(it->se[1]) return 2;
		else return 0;
	}
	else{
		auto it=C.find(x);
		if(it==C.end()) 
			return 0;
		if(it->se[0]&&it->se[1]) return 3;
		else if(it->se[0]) return 1;
		else if(it->se[1]) return 2;
		else return 0;
	}
}

void Delete(int x,int y){
	if(all[x].find(y)==all[x].end()) return;
	int val=all[x][y];all[x].erase(y);
	
	flgRC[(x^y^val)&1]--;
	
	int pret=Type(x,1);
	R[x][(y^val)&1]--;
	int nowt=Type(x,1);
	if(!nowt) R.erase(x);
	cntR[pret]--,cntR[nowt]++;
	
	pret=Type(y,2);
	C[y][(x^val)&1]--;
	nowt=Type(y,2);
	if(!nowt) C.erase(y);
	cntC[pret]--,cntC[nowt]++;
}

void Insert(int x,int y,int val){
	flgRC[(x^y^val)&1]++;
	all[x][y]=val;
	
	int pret=Type(x,1);
	R[x][(y^val)&1]++;
	int nowt=Type(x,1);
	cntR[pret]--,cntR[nowt]++;
	
	pret=Type(y,2);
	C[y][(x^val)&1]++;
	nowt=Type(y,2);
	cntC[pret]--,cntC[nowt]++;
}

int main(){
#ifdef LOCAL
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=rdi(),m=rdi(),k=rdi();
	while(k--){
		int x=rdi(),y=rdi(),typ=rdi();
		if(typ==-1) Delete(x,y);
		else if(typ==0) Delete(x,y),Insert(x,y,0);
		else Delete(x,y),Insert(x,y,1);
		printf("%lld\n",calc());
	}
    return 0;
}