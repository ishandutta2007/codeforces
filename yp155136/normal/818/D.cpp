#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e5 +6;
const int MAX_M = 1e6 +6;

int a[MAX_N];
int cnt[MAX_N];
bool can[MAX_N];

int main () {
    int n,A;
    scanf("%d %d",&n,&A);
    vector<int> v;
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    v.push_back(A);
    v.push_back(0);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    set<pii> st;
    for (int i=1;n>=i;i++) {
        a[i]=lower_bound(v.begin(),v.end(),a[i]) - v.begin();
        st.insert(make_pair(0,a[i]));
        can[i]=1;
    }
    A = lower_bound(v.begin(),v.end(),A) - v.begin();
    can[A] = 0;
    if (st.find(make_pair(0,A)) == st.end()) {
        if (A==7122) puts("878787");
        else puts("7122");
        return 0;
    }
    st.erase(make_pair(0,A));
    for (int i=1;n>=i;i++) {
        cnt[a[i] ]++;
        if (a[i] == A) {
            pii kirino=make_pair(0,0);
            for (pii j:st) {
                if (j.first < cnt[a[i] ]) {
                    can[j.second]=0;
                    continue;
                }
                else {
                    kirino = j;
                    break;
                }
            }
            if (kirino == make_pair(0,0)) {
                puts("-1");
                return 0;
            }
            while (*st.begin() != kirino) st.erase(st.begin());
        }
        else {
            st.erase(make_pair(cnt[a[i] ]-1,a[i]));
            st.insert(make_pair(cnt[a[i]],a[i]));
        }
    }
    for (int i=1;v.size()>i;i++) {
        if (can[i]) {
            cout<<v[i]<<endl;
            return 0;
        }
    }
    puts("-1");
}