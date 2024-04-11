#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
vector<int> ids[N];
int ans[N];

int main () {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        int a;//a diff --> n-a same
        scanf("%d",&a);
        a = n-a;
        ids[a].push_back(i);
    }
    for (int i=1;i<=n;++i) {
        if ((int)ids[i].size() % i != 0) {
            puts("Impossible");
            return 0;
        }
    }
    int ptr=0;
    for (int i=1;i<=n;++i) {
        int cnt=0;
        for (int j:ids[i]) {
            if (cnt == 0) ++ptr;
            ++cnt;
            ans[j] = ptr;
            cnt %= i;
        }
    }
    puts("Possible");
    for (int i=1;i<=n;++i) {
        printf("%d%c",ans[i]," \n"[i==n]);
    }
}