#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct node{
    int suflink, len, endpoint;
    map <char, int> go;
} v[2 * MAXN];

int vn, last;
void init(){
    v[0].suflink = -1;
    v[0].len = 0;
    v[0].endpoint = -1;
    last = 0;
    vn = 1;
}
void add(char c){
    int nlast = vn++;
    v[nlast].len = v[last].len + 1;
    v[nlast].endpoint = v[last].len;

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
            v[parent].endpoint = -1;
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

string forbidden;

vector <int> g[2 * MAXN];
int cnt[2 * MAXN];

long long dfs(int u){
    if(v[u].endpoint == -1 || forbidden[v[u].endpoint] == '1'){
        cnt[u] = 0;
    }else{
        cnt[u] = 1;
    }

    long long ret = 0;
    for(int cu : g[u]){
        ret = max(ret, dfs(cu));
        cnt[u] += cnt[cu];
    }
    ret = max(ret, 1LL * cnt[u] * v[u].len);

    return ret;
}

long long solve(){
    for(int i = 0; i < vn; i++)
        if(v[i].suflink != -1)g[v[i].suflink].push_back(i);

    return dfs(0);
}

void print(){
    for(int i = 0; i < vn; i++){
        cout << i << ',' << v[i].suflink << ',' << v[i].len << ',' << v[i].endpoint << " :: ";
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

    int n;
    string s;
    cin >> n >> s >> forbidden;

    init();
    for(char c : s)add(c);
    
    //print();

    cout << solve() << '\n';

    return 0;
}