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
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;

#define ll long long
#define ld long double
vector<int>nums(1e8);

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

const int MAX_N=200000;
const int K=300;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string st;cin>>st;
    ll answer=0;
    for(int x=1;x<=K;++x){
        int asum=0;
        
        //assert(all_of(nums.begin(),nums.end(),[](const int a){return a==0;}));
        nums[K*MAX_N]++;
        
        for(int i=0;i<st.size();++i){
            if(st[i]=='1')asum--;
            int cnt=i+1+asum*x;

            cnt+=K*MAX_N;
            answer+=nums[cnt];
            nums[cnt]++;
        }
        asum=0;
        for(int i=0;i<st.size();++i){
           if(st[i]=='1')asum--;
            int cnt=i+1+asum*x;

            cnt+=K*MAX_N;
            nums[cnt]--;
        }
        nums[K*MAX_N]--;
        //WHATS(answer)
    }
   // WHATS(answer);
    vector<int>places{-1};
    vector<int>sums(st.size()+1);
    for(int i=0;i<st.size();++i){
        sums[i+1]=sums[i];
        if(st[i]=='1'){
            places.push_back(i);
            sums[i+1]++;
        }
    }
    places.push_back(st.size());
    for(int i=0;i<st.size();++i){
        int one_total=sums[i];
 
        for(int ak=1;ak<=MAX_N/K+10;++ak){
            if(places.size()<=one_total+ak+1)continue;
            int ng_r=places[one_total+ak+1]+1;
            int ok_l=max(places[one_total+ak]+1,i+ak*(K+1));
            // WHATS(i)
            // WHATS(ak)
            // WHATS(ok_l)
            // WHATS(ng_r)
            if(ok_l<ng_r)answer+=max(0,(ng_r-1-i)/ak-(ok_l-1-i)/ak);
        }
        int ok=i+K+1;
    }
    cout<<answer<<endl;
    return 0;
}