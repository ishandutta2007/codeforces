#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
#define MOD 1000000007 

int main(){
    int n;
    cin >> n;
    int brp = 0;
    int neg = 0, pos = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(abs(x) % 2 == 0){
            cout << x / 2 << '\n';
        }
        else if(x > 0){
            if(pos){
                cout << x / 2 + 1 << '\n';
                pos ^= 1;
            }
            else{
                cout << x / 2 << '\n';
                pos ^= 1;
            }
        }
        else{
            if(neg)
                cout << (x / 2) - 1 << '\n';
            else cout << x / 2 << '\n';
            neg ^= 1;
        }
    }
}