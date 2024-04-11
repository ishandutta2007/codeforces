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


struct node{
    shared_ptr<node>l_ch,r_ch;
    node(){
        l_ch=nullptr;
        r_ch=nullptr;
    }
};
void add(int t,shared_ptr<node>now,int x){
    //WHATS(t)
   // WHATS(x)
    if(x&(1<<t)){
        if(!now->l_ch)now->l_ch=make_shared<node>();
        if(t)add(t-1,now->l_ch,x);
    }else{
        if(!now->r_ch)now->r_ch=make_shared<node>();
        assert(now->r_ch);
        if(t)add(t-1,now->r_ch,x);
    }
}
int solve(int t,shared_ptr<node>now){
    //WHATS(t)
    if(t!=-1){
        int ans=0;
        if(now->l_ch&&now->r_ch){
            ans+=1<<t;
            ans+=min(solve(t-1,now->l_ch),solve(t-1,now->r_ch));
        }else{
            if(now->l_ch){
                ans=solve(t-1,now->l_ch);
            }else{
                ans=solve(t-1,now->r_ch);
            }
        }
        return ans;
    }else{
        return 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int N;cin>>N;
    shared_ptr<node>root=make_shared<node>();
    while(N--){
        int x;cin>>x;
        add(29,root,x);
    }
    int answer=solve(29,root);
    cout<<answer<<endl;

    return 0;
}