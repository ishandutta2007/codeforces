#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#include<memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}




using Value=ll;
const Value ini =-1;
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
Value connect(Value al,const Value ar){
	if(al==-1)return ar;
    else if(ar==-1)return al;
	return gcd(al,ar);
}
Value dat[2000001];
struct segtree {
	int N;

	segtree() {}
	
	segtree(int n,vector<Value>&v)  {
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			if(x<v.size()){
				dat[x+N-1]=v[x];
			}else{
				dat[x+N-1] = ini;
			}
		}
		for(int x=N-2;x>=0;--x){
			dat[x]=connect(dat[x*2+1],dat[x*2+2]);
		}
	}
	// update k th element
	void update(int k,const Value& a) {
		 k += N - 1;
		dat[k] = a;
		
		while (k > 0) {
			k = (k - 1) >>1;
			dat[k]=connect(dat[k * 2 + 1],dat[k * 2 + 2]);
		}
	}
	// min [a, b)
	int query(int a, int b,int va) { return query(a, b, 0, 0, N,va); }
	int query(int a, int b, int k, int l, int r,int va) {
		if (r <= a || b <= l) return 0;
		const int m = (l + r) / 2;

		if (a <= l && r <= b){
       
            if(dat[k]%va==-1||dat[k]%va==0)return 0;
            else{
                if(l+1==r)return 1;
                else{
                    int l_cnt=1,r_cnt=1;
                    if(dat[2*k+1]==-1||dat[2*k+1]%va==0)l_cnt=0;
                    if(dat[2*k+2]==-1||dat[2*k+2]%va==0)r_cnt=0;

                    if(l_cnt+r_cnt>=2)return 2;
                    else{
                        if(l_cnt==0){
                            return query(a,b,k*2+2,m,r,va);
                        }else{
                            return query(a,b,k*2+1,l,m,va);
                        }
                    }
                }
            }
        }
		return query(a, b, k * 2 + 1, l, m,va)+query(a, b, k * 2 + 2, m, r,va);
	}
	
};
using ll = long long int;

int main() {
	int N;cin>>N;
    vector<ll>as(N);
    for(int i=0;i<N;++i){
        int a;scanf("%d",&a);
        as[i]=a;
    }
    segtree seg(N,as);
    int Q;cin>>Q;
    while(Q--){
        //for(int i=0;i<30;++i)cout<<dat[i]<<' ';
        //cout<<endl;
        int type;
        scanf("%d",&type);
        if(type==1){
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            l--;
            int val=seg.query(l,r,x);
            bool ok=val<=1;
            //WHATS(val)
            if(ok)printf("YES\n");
            else printf("NO\n");
        }else{
            int x,y;scanf("%d %d",&x,&y);
            x--;
            seg.update(x,y);
        }
    }
    // int N;cin>>N;
    // vector<int>as(N);
    // ll answer=-1e9;
    // for(int i=0;i<N;++i){
    //    ll a;cin>>a;
    //     if(a<0)answer=max(answer,a);
    //     else{
    //         int xx=sqrt(a);
    //         if(ll(xx)*xx==a){

    //         }else{
    //             answer=max(answer,a);
    //         }
    //     }
    // }
    // cout<<answer<<endl;
	return 0;
}