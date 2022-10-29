#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


bool adj[144][144];
int rudu[144],chudu[144];
int cnt[144];
vector<int> edg[144];

bool visit[144];
bool has[144];

vector<char> anss;

void dfs(int i) {
    anss.push_back(i);
    visit[i]=1;
    for (int j:edg[i]) {
        if (!visit[j]) dfs(j);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0;n>i;i++) {
        string s;
        cin >>s;
        memset(cnt,0,sizeof(cnt));
        for (char i:s) {
            has[i]=1;
            cnt[i]++;
            if (cnt[i] >= 2) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if (s.size() == 1) continue;
        for (int i=0;s.size()-1>i;i++) {
            adj[ s[i] ][s[i+1] ]++;
        }
    }
    for (int i=0;144>i;i++) {
        for (int j=0;144>j;j++) {
            if (adj[i][j]) {
                edg[i].push_back(j);
                rudu[j]++;
                chudu[i]++;
            }
        }
    }
    for (int i=0;144>i;i++) {
        if (rudu[i] > 1 || chudu[i] > 1) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    int tot=0;
    for (int i=0;144>i;i++) {
        if (has[i]) tot++;
        if (has[i] && !visit[i]) {
            if (rudu[i] == 0) {
                dfs(i);
            }
        }
    }
    if (tot != anss.size()) cout<<"NO";
    else {
        for (char i:anss) cout<<i;
    }
    cout<<endl;
}