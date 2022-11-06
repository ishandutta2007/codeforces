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

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
	
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

	
using ll = long long int;

void solveB(){
    int N;cin>>N;
    while(N--){
        string st;cin>>st;
        vector<int>l_sums(st.size()+1);
        vector<int>r_sums(st.size()+1);

        for(int i=0;i<st.size();++i){
            l_sums[i+1]=l_sums[i]+int(st[i]=='1');
        }
        for(int i=st.size()-1;i>=0;--i){
            r_sums[i]=r_sums[i+1]+int(st[i]=='1');
        }
        int answer=10000000;
        for(int x=0;x<=st.size();++x){
            for(int t=0;t<2;++t){
                int al=l_sums[x];
                if(t)al=x-al;

                int ar=r_sums[x];
                if(t)ar=(st.size()-x)-ar;

                answer=min(answer,al+ar);
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int a=0,b=0;
        int K;cin>>K;
        for(int i=0;i<N;++i){
            int x;cin>>x;
            if(x%2==1)a++;
            else b++;
        }
        bool ok=false;
        for(int a_num=0;a_num<=a;++a_num){
            int b_num=K-a_num;
            if(b_num>=0&&b_num<=b){
                if(a_num%2==1)ok=true;
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
	return 0;
}