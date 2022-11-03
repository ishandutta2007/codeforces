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
    int n, jaw = 0;
    cin >> n;
    vector<int> a(n), b(n), di(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= 1;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i] -= 1;
        di[b[i]] = i;
    }
    int mini = -1;
    for(int i = 0; i < n; i++){
        if(di[a[i]] < mini)
            jaw += 1;
        mini = max(mini, di[a[i]]);
    }
    cout << jaw << endl;
}