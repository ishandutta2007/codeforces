#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

void no() {
    puts("NO");
    exit(0);
}

vector<pii> v;

void show() {
    puts("YES");
    for (pii p:v) {
        printf("%d %d\n",p.F,p.S);
    }
    exit(0);
}

int main () {
    int n,k; cin >> n >> k;
    for (int st=2;st<=k;++st) {
        int j = st;
        for (int i=1;i<=k;++i) {
            v.push_back(make_pair(i,j));
            j++;
            if (j == k+1) j = 1;
            if (v.size() == n) show();
        }
    }
    no();
}