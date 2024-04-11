#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 300006;
#define F first
#define S second

int a[N];
int pos[N];

void Swap(int p1,int p2) {
    int _ = a[p1], __ = a[p2];
    swap(a[p1],a[p2]);
    swap(pos[_],pos[__]);
}

int main () {
    int n; scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        pos[ a[i] ] = i;
    }
    vector<pii> ans;
    for (int i=1;i<=n;++i) {
        if (pos[i] == i) continue;
        if (pos[i] - i >= n/2) {
            ans.push_back(make_pair(i,pos[i]));
            Swap(i,pos[i]);
        }
        else if (abs(n - pos[i]) >= n/2) {
            ans.push_back(make_pair(pos[i],n));
            Swap(pos[i],n);
            ans.push_back(make_pair(n,i));
            Swap(n,i);
        }
        else {
            ans.push_back(make_pair(pos[i],1));
            int _ = pos[i];
            Swap(pos[i],1);
            if (abs(i - 1) >= n/2) {
                ans.push_back(make_pair(1,i));
                Swap(1,i);
                ans.push_back(make_pair(_,1));
                Swap(_,1);
            }
            else {
                ans.push_back(make_pair(1,n));
                Swap(1,n);
                ans.push_back(make_pair(n,i));
                Swap(n,i);
                ans.push_back(make_pair(1,_));
                Swap(1,_);
            }
        }
    }
    printf("%d\n",(int)ans.size());
    for (pii p:ans) {
        printf("%d %d\n",p.first,p.second);
    }
}