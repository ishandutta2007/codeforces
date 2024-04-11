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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;


void solve(){
    int r, c;
    cin >> r >> c;
    vector<string> ss(r);
    for(int i = 0; i < r; i++) cin >> ss[i];
    int ada = 0;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(ss[i][j] == 'P') ada = 1;
    if(!ada){
        cout << 0 << '\n';
        return;
    }
    ada = 0;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(ss[i][j] == 'A') ada = 1;
    if(!ada){
        cout << "MORTAL" << '\n';
        return;
    }
    //nyoba 1
    int i = 0, j = 0;
    int ya = 1;
    for(i = 0; i < r; i++){
        if(ss[i][j] == 'P') ya = 0;
    }
    if(ya){
        cout << 1 << '\n';
        return;
    }
    i = 0, j = c - 1;
    ya = 1;
    for(i = 0; i < r; i++){
        if(ss[i][j] == 'P') ya = 0;
    }
    if(ya){
        cout << 1 << '\n';
        return;
    }
    i = 0, j = 0;
    ya = 1;
    for(j = 0; j < c; j++){
        if(ss[i][j] == 'P') ya = 0;
    }
    if(ya){
        cout << 1 << '\n';
        return;
    }
    i = r - 1, j = 0;
    ya = 1;
    for(j = 0; j < c; j++){
        if(ss[i][j] == 'P') ya = 0;
    }
    if(ya){
        cout << 1 << '\n';
        return;
    }
    // nyoba 2
    if(ss[0][0] == 'A' || ss[0][c - 1] == 'A' || ss[r - 1][0] == 'A' || ss[r - 1][c - 1] == 'A'){
        cout << 2 << '\n';
        return;
    }
    for(int i = 0; i < r; i++){
        int aa = 1;
        for(int j = 0; j < c; j++){
            if(ss[i][j] == 'P') aa = 0;
        }
        if(aa){
            cout << 2 << '\n';
            return;
        }
    }
    for(int j = 0; j < c; j++){
        int aa = 1;
        for(int i = 0; i < r; i++){
            if(ss[i][j] == 'P') aa = 0;
        }
        if(aa){
            cout << 2 << '\n';
            return;
        }
    }
    
    //nyoba 3
    i = 0, j = 0;
    ya = 0;
    for(i = 0; i < r; i++){
        if(ss[i][j] == 'A') ya = 1;
    }
    if(ya){
        cout << 3 << '\n';
        return;
    }
    i = 0, j = c - 1;
    ya = 0;
    for(i = 0; i < r; i++){
        if(ss[i][j] == 'A') ya = 1;
    }
    if(ya){
        cout << 3 << '\n';
        return;
    }
    i = 0, j = 0;
    ya = 0;
    for(j = 0; j < c; j++){
        if(ss[i][j] == 'A') ya = 1;
    }
    if(ya){
        cout << 3 << '\n';
        return;
    }
    i = r - 1, j = 0;
    ya = 0;
    for(j = 0; j < c; j++){
        if(ss[i][j] == 'A') ya = 1;
    }
    if(ya){
        cout << 3 << '\n';
        return;
    }
    cout << 4 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}