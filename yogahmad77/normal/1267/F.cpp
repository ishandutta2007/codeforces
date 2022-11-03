#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char, int> pci;
#define sz(x) ((int)x.size())
#define f first
#define s second
#define mp make_pair

const int mx = 300000;

int n, m, ka, kb, a[mx], b[mx], cnta[mx], cntb[mx];
vector<int> g[mx];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> ka >> kb;
    for(int i = 1; i <= ka; i++) cin >> a[i];
    for(int i = 1; i <= kb; i++) cin >> b[i];
    vector<int> freea, freeb;
    for(int i = 1; i <= ka; i++){
        cnta[a[i]] += 1;
    }
    for(int i = 1; i <= kb; i++){
        cntb[b[i]] += 1;
    }
    priority_queue<int, vector<int>, greater<int>> pqa, pqb;
    for(int i = 1; i <= n; i++){
        if(cnta[i] == 0)
            pqa.push(i);
    }
    for(int i = n + 1; i <= n + m; i++){
        if(cntb[i] == 0)
            pqb.push(i);
    }
    int nowa = 1, nowb = 1;
    int tadi = -1;
    while(nowa <= ka || nowb <= kb || !pqa.empty()){
        if(!pqa.empty() && nowb <= kb){
            int now = pqa.top(); pqa.pop();
            g[now].push_back(b[nowb]);
            cntb[b[nowb]] -= 1;
            if(cntb[b[nowb]] == 0){
                pqb.push(b[nowb]);
            }
            nowb += 1;
            continue;
        }
        if(!pqa.empty()){
            if(pqb.empty()){
                cout << "No\n";
                return 0;
            }
            tadi = pqa.top();
            g[pqa.top()].push_back(pqb.top());
            pqa.pop();
            continue;
        }
        if(!pqb.empty() && nowa <= ka){
            int now = pqb.top(); pqb.pop();
            g[a[nowa]].push_back(now);
            cnta[a[nowa]] -= 1;
            if(cnta[a[nowa]] == 0){
                pqa.push(a[nowa]);
            }
            nowa += 1;
            continue;
        }
        cout << "No\n";
        return 0;
    }
    assert(pqb.size() > 0);
    pqb.pop();
    if(tadi == -1 && pqb.size() > 0){
        cout << "No\n";
        return 0;
    }
    while(!pqb.empty()){
        g[tadi].push_back(pqb.top());
        pqb.pop();
    }
    cout << "Yes\n";
    for(int i = 1; i <= n + m; i++){
        for(int j : g[i]) cout << i << ' ' << j << '\n';
    }
}