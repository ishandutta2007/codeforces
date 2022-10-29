#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 100006;

vector<int> v[MAX_N];

int main () {
    int n,k,m;
    cin >> n >> k >> m;
    for (int i=0;n>i;i++) {
        int x;
        cin >> x;
        v[x%m].push_back(x);
    }
    for (int i=0;m>i;i++) {
        int tot=0;
        if (v[i].size()>=k) {
            puts("Yes");
            int kk=k;
            for (int j:v[i]) {
                if (kk==k) ;
                else printf(" ");
                k--;
                printf("%d",j);
                if (!k) break;
            }
            puts("");
            return 0;
        }
    }
    puts("No");
}