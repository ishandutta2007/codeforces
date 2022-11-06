#define _CRT_SECURE_NO_WARNINGS
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
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
    
using namespace std;
    
using ll=long long;
using ld =long double;
    
#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
    
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
using Graph=vector<vector<int>>;


const ll MAX_S=2e5;

vector<ll>check(vector<ll>&x){
    vector<ll>anss(x.size());
    for(int i=0;i<int(x.size())-1;++i){
        anss[i+1]=x[i+1]-x[i];
    }
    anss[0]=x[0];
    return anss;
}


using Value=ll;
const Value ini =ll(1e18);
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return min(al,ar);
}
Value dat[1100001];
struct segtree {
	int N;

	segtree() {}
	
	segtree(int n)  {
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			dat[x+N-1] = ini;
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
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}

	
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    vector<ll>v(N);
    for(int i=0;i<(N+1)/2;++i){
        cin>>v[i];
    }
    ll X;cin>>X;
    for(int i=(N+1)/2;i<N;++i){
        v[i]=X;
    }
    vector<ll>sums(N+1);
    for(int i=0;i<N;++i){
        sums[i+1]=sums[i]+v[i];
    }
    ll sum=accumulate(v.begin(),v.end(),0ll);
    int answer=-1;
    if(sum>0){
        answer=N;
    }else{
        if(X>0){
            answer=-1;
        }else{
            const int fst_k=(N+2)/2;
             int now_k=(N+2)/2;
            segtree seg(N-now_k+1);
            
            for(int l=N-now_k;l>=0;--l){
                seg.update(l,sums[l+now_k]-sums[l]);
            }
            while(now_k<=N){
                ll amin=seg.query(0,N-now_k+1);
                if(amin>-(now_k-fst_k)*X){
                    if(N==500000){
                       // cout<<amin<<endl;
                        //cout<<X<<endl;
                        ll aamin=1e18;
                       // for(int l=0;l<=N-now_k;++l){
                       //     aamin=min(aamin,sums[l+now_k]-sums[l]);
                       // }
                        //cout<<aamin<<endl;
                        
                    }
                    answer=now_k;
                    break;
                }
                now_k++;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}