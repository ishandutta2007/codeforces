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

//0-indexed
const int MAX_N=600004;

ll f[MAX_N];

void upd(int pos, ll x){
    if(pos<0)return;
	for(; pos < MAX_N; pos |= pos + 1)
		f[pos] += x;
}

ll get(int pos){
    
	ll res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}
int main() {
    
    
    ios::sync_with_stdio(false);
    int N;cin>>N;
    string st;cin>>st;
    vector<char>lasts;
    vector<int>colors;

    for(auto c:st){
        pair<char,int>p('a'-1,-1);

        for(int x=0;x<lasts.size();++x){
            char ch_last=lasts[x];
            if(ch_last<=c){
                p=max(p,make_pair(ch_last,x));
            }
        }
        int acolor;
        if(p.second==-1){
            acolor=lasts.size();
            lasts.push_back(c);
        }else{
            acolor=p.second;
            lasts[p.second]=c;
        }
       // WHATS(lasts)
        colors.push_back(acolor);
    }
    cout<<lasts.size()<<endl;
    for(int i=0;i<st.size();++i){
        cout<<1+colors[i]<<' ';
    }
    cout<<endl;
    return 0;
}