#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct node{
    int suflink, len, endpoints;
    map <char, int> go;
} v[2 * MAXN];

vector <int> g[2 * MAXN];

int vn, last;
void init(){
    v[0].suflink = -1;
    v[0].len = 0;
    v[0].endpoints = 0;
    vn = 1;
    last = 0;
}

void add(char c){
    int nlast = vn++;
    v[nlast].len = v[last].len + 1;
    v[nlast].endpoints = 1;

    while(last != -1 && !v[last].go.count(c)){
        v[last].go[c] = nlast;
        last = v[last].suflink;
    }

    if(last == -1){
        v[nlast].suflink = 0;
    }else{
        int u = v[last].go[c];
        if(v[last].len + 1 == v[u].len){
            v[nlast].suflink = u;
        }else{
            int parent = vn++;
            v[parent].suflink = v[u].suflink;
            v[parent].len = v[last].len + 1;
            v[parent].endpoints = 0;
            v[parent].go = v[u].go;

            while(last != -1 && v[last].go[c] == u){
                v[last].go[c] = parent;
                last = v[last].suflink;
            }

            v[u].suflink = parent;
            v[nlast].suflink = parent;
        }
    }
    last = nlast;
}

long long dfs(int u){
    long long ret = 0;
    for(int cu : g[u]){
        ret += dfs(cu);
        v[u].endpoints += v[cu].endpoints;
    }
    if(u != 0){
        long long y = 1LL * v[u].endpoints * (v[u].endpoints + 1) / 2;
        ret += y * (v[u].len - v[v[u].suflink].len);
    }
    return ret;
}

long long solve(){
    for(int i = 0; i < vn; i++)if(v[i].suflink != -1){
        g[v[i].suflink].push_back(i);
    }

    return dfs(0);
}

void print(){
    for(int i = 0; i < vn; i++){
        cout << i << ',' << v[i].suflink << ',' << v[i].len << ',' << v[i].endpoints << " :: ";
        for(auto e : v[i].go){
            cout << e.first << ',' << e.second << ' ';
        }
        cout << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    init();
    for(char c : s)add(c);

    //print();

    cout << solve() << '\n';

    return 0;
}