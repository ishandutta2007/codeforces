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
    int N,M;cin>>N>>M;
    vector<int>mins(N);
    vector<int>maxs(N);
    iota(mins.begin(),mins.end(),0);
    maxs=mins;

    for(int i=1;i<N;++i){
        upd(MAX_N/2+i,1);
        //upd(MAX_N/2+i-1,-i);
    }
    vector<int>nums(MAX_N,-1);
    iota(nums.begin()+MAX_N/2,nums.end(),0);
    vector<int>places(N);
    iota(places.begin(),places.end(),MAX_N/2);
    
    for(int i=0;i<M;++i){
        
        //WHATS(maxs)
        //WHATS(places)
        int a;
        scanf("%d",&a);
        a--;
        int aplace=places[a];
        nums[aplace]=-1;
        maxs[a]=max(maxs[a],int(get(aplace)));
        mins[a]=0;
        //WHATS(aplace)
        upd(aplace,-100000000);
        upd(aplace+1,100000000);
        upd(0,1);
        upd(aplace,-1);

        int ax=MAX_N/2-i-1;
        int num=get(ax);
        //WHATS(num)
        places[a]=ax;
        nums[ax]=a;
        upd(ax,-num);
        upd(ax+1,num);
    }
    for(int i=0;i<places.size();++i){
        int tt=get(places[i]);
       // WHATS(places[i])
       // WHATS(tt)
       // WHATS(int(get(places[i])-get(places[i]-1)))
        maxs[i]=max(maxs[i],int(get(places[i])));
    }
    for(int i=0;i<N;++i){
        printf("%d %d\n",1+mins[i],1+maxs[i]);
    }

    return 0;
}