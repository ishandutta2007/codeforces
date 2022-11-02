#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
ll k;

const int maxn = 205;
int fail[maxn];

int A1[maxn][maxn];
ll A2[maxn][maxn];

const ll INF = 1e18 + 7;

void add(ll &a, ll b){
    a += b;
    if(a > INF)
        a = INF;
}

void build_automata(string s){
    int len = s.length();
    fail[0] = fail[1] = 0;
    int match = 0;
    for(int i = 2;i <= len;i++){
        while(match > 0 and s[match] != s[i - 1])
            match = fail[match];
        if(s[match] == s[i - 1])
            match++;
        fail[i] = match;
    }
    for(int i = 0;i <= len;i++){
        for(int j = 0;j < 2;j++){
            if(i < len and s[i] == (char)(j + '0'))
                A1[i][j] = i + 1;
            else if(i == 0){
                A1[i][j] = 0;
            }else{
                A1[i][j] = A1[fail[i]][j];
            }
            A2[i][j] = (A1[i][j] == len ? 1 : 0);
        }
    }
    for(int j = 2;j <= n;j++){
        for(int i = 0;i <= len;i++){
            A1[i][j] = A1[A1[i][j - 2]][j - 1];
            A2[i][j] = A2[i][j - 2];
            add(A2[i][j], A2[A1[i][j - 2]][j - 1]);
        }
    } 
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    string cur = "";
    for(int i = 0;i < m;i++){
        if(cur != "")
            build_automata(cur);
        ll x = 0;
        if(cur != "" and A1[0][n] == i)
            x = 1;
        if(k == 1 and x == 1)
            break;
        k -= x;
        build_automata(cur + '0');
        ll x1 = A2[0][n];
        if(k > x1){
            cur += '1';
            k -= x1;
        }else
            cur += '0';
    }
    cout << cur << endl;
    return 0;
}