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


int main() {
    int T;cin>>T;
    while(T--){
        string A,B;cin>>A>>B;
        bool ok=false;
        for(int num1=0;num1<=int(B.size());++num1){
            int num2=int(B.size())-num1;
            vector<vector<int>>maxs(A.size()+1,vector<int>(num1+1,-1));
            maxs[0][0]=0;
            for(int ax=0;ax<A.size();++ax){
                for(int bx1=0;bx1<=num1;++bx1){
                    int bx2=maxs[ax][bx1];
                    if(bx2==-1)continue;
                    else{
                        if(bx1!=num1&&A[ax]==B[bx1]){
                            maxs[ax+1][bx1+1]=max(maxs[ax][bx1],maxs[ax+1][bx1+1]);
                        }
                        if(bx2!=int(B.size())-num1&&A[ax]==B[num1+bx2]){
                            maxs[ax+1][bx1]=max(maxs[ax][bx1]+1,maxs[ax+1][bx1]);
                        }

                        maxs[ax+1][bx1]=max(maxs[ax][bx1],maxs[ax+1][bx1]);
                    }
                }
            }
            bool nok=maxs[A.size()][num1]==B.size()-num1;
            //WHATS(maxs)
           // WHATS(nok)
            if(nok)ok=true;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
    return 0;
}