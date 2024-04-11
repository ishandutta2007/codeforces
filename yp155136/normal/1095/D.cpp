#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[2][N];

bool vis[N];
int ptr=0;
int p[N];

int n;
bool can(int pos,int nxt) {
    //cout << "pos= = " << pos << " , nxt = " << nxt << endl;
    if (pos<0 || pos>n) return false;
    ++ptr;
    if (ptr == n+1) return true;
    if (vis[pos]) return false;
    p[pos]=nxt;
    vis[pos]=true;
    return can(nxt,(a[0][pos]^a[1][pos]^nxt));

}

int main () {
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[0][i] >> a[1][i];
    }
    memset(vis,0,sizeof(vis));
    if (can(1,a[0][1])) {
        for (int i=1,cnt=1;cnt<=n;i=p[i],++cnt) cout << i << ' ';
        return 0;
    }
    memset(vis,0,sizeof(vis));
    ptr=0;
    can(1,a[1][1]);
    for (int i=1,cnt=1;cnt<=n;i=p[i],++cnt) cout << i << ' ';
}