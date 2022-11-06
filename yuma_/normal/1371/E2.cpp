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
// 1 3 3 5 6 6
// 3 4 5 6 7 8
// 1 0 1 0 0 1 
// 2 1 2 1 1 1
// 3 2 3 2 2 1
// 4 3 4 3 2 1
// 5 4 4 3 2 1
// 6 5 4 3 2 1

// 36 32 7 4 3 2 1
int main() {
	int N,P;cin>>N>>P;
    vector<int>v(N);
    for(int i=0;i<N;++i){
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
    vector<int>oks(N+1);

    vector<map<int,int>>mps(P);

    int ok_min=0;
    for(int i=0;i<N;++i){
        int x=v[i];
        ok_min=max(ok_min,x-i);
    }
    ok_min=max(ok_min,0);
    for(int i=0;i<N;++i){
    //cout<<'a'<<endl;

        int num=upper_bound(v.begin(),v.end(),ok_min+i)-v.begin()-i;
        int al=(P-num)%P;
        if(al<0)al+=P;
        int rest=i-al;
        if(rest>=0){
            int ar=al+rest/P*P;
            WHATS(al)
            WHATS(ar)
            WHATS(i)
            mps[(ok_min+al)%P][ok_min+al]++;
            mps[(ok_min+al)%P][ok_min+ar+P]--;
        }
    }
    for(int i=0;i<P;++i){
        mps[(i+ok_min)%P][ok_min+i+P]+=100000000;

    }

    // 2 2 3 3 6 7 7 7 8
    // 2 3 4 5 6 7 8 9 10
    // 2 3 2 1 1 3 3 2 1
    // 4 3 2 2 4 4 3 2 1
    // 4 3 3 5 5 4 3 2 1
    // 4 4 6 6 5 4 3 2 1
    // 5 7 7 6 5 4 3 2 1
    // 8 8 7 6 5 4 3 2 1
    vector<int>answers;
    for(int i=0;i<P;++i){
        int sum=0;
        for(auto it=mps[i].begin();it!=mps[i].end();++it){
            sum+=it->second;
            if(sum>0){
                int al=it->first;
                
                int ar=(next(it)==mps[i].end()) ? al+int(1e6) : next(it)->first;

                for(int x=al;x<ar;x+=P){
                    answers.push_back(x);
                }
            }
        }
    }
    //WHATS(ok_min)
    //WHATS(ng_max)
    sort(answers.begin(),answers.end());
    {
        vector<int>answers2;
        for(int i=ok_min;i<=ok_min+N;++i){
            if(!binary_search(answers.begin(),answers.end(),i)){
                answers2.push_back(i);
            }
        }
        answers=answers2;
    }
    cout<<answers.size()<<endl;
    for(auto ans:answers)cout<<ans<<' ';
    cout<<endl;
	return 0;
}