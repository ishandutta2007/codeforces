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
vector<int>nums(int(3e5));

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    int sx,sy;cin>>sx>>sy;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    vector<int>nums(4);
    for(int i=0;i<N;++i){
        int x,y;cin>>x>>y;
        if(x<sx)nums[0]++;
        if(x>sx)nums[2]++;
        if(y<sy)nums[3]++;
        if(y>sy)nums[1]++;
    }
    auto it=max_element(nums.begin(),nums.end());
    cout<<*it<<endl;
    cout<<sx+dx[it-nums.begin()]<<' '<<sy+dy[it-nums.begin()]<<endl;
    return 0;
}