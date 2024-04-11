#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

vector<int> G[N];

int deg[N];
int deg_cnt[N];
int e[N];
int clr[N];

int saki;

void dfs(int now,int par) {
    //set<int> st;
    if (deg[now] > saki) {
        for (int eid:G[now]) {
            if (clr[eid] == -1) {
                clr[eid] = 1;
            }
        }
    }
    else {
        set<int> st;
        for (int eid:G[now]) {
            if (clr[eid] != -1) {
                st.insert(clr[eid]);
            }
        }
        int ptr=1;
        for (int eid:G[now]) {
            if (clr[eid] == -1) {
                while (st.find(ptr) != st.end()) ++ptr;
                clr[eid] = ptr;
                st.insert(ptr);
            }
        }
    }
    for (int eid:G[now]) {
        int to = e[eid]^now;
        if (to == par) continue;
        dfs(to,now);
    }
}

int main () {
    int n, k; cin >> n >> k;
    for (int i=1;i<n;++i) {
        int x,y; cin >> x >> y;
        e[i] = (x^y);
        G[x].push_back(i);
        G[y].push_back(i);
        deg[x]++;
        deg[y]++;
    }
    for (int i=1;i<=n;++i) {
        deg_cnt[ deg[i] ]++;
    }
    int prek=0;
    int needr=-1;
    for (int r=n;r>=0;--r) {
        if (prek + deg_cnt[r] > k) {
            needr = r;
            break;
        }
        prek += deg_cnt[r];
    }
    memset(clr,-1,sizeof(clr));
    cout << needr << endl;
    saki = needr;
    dfs(1,1);
    for (int i=1;i<n;++i) cout << clr[i] << ' '; cout << endl;
}