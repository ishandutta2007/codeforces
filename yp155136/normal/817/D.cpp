#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e6 + 6;

LL a[MAX_N];

pii operator+(const pii &p1,const pii &p2) {
    return make_pair(p1.first+p2.first,p1.second+p2.second);
}

int main (){
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++) {
        scanf("%lld",&a[i]);
    }
    deque<pii> dq;
    LL ans=0;
    LL sum=0;
    for (int i=1;n>=i;i++) {
        LL val=a[i];
        LL cnt=1;
        while (!dq.empty() && dq.back().first < val) {
            cnt += dq.back().second;
            sum -= dq.back().first*dq.back().second;
            dq.pop_back();
        }
        sum += val*cnt;
        if (dq.empty()) {
            dq.push_back(make_pair(val,cnt));
        }
        else if (dq.back().first == val) {
            dq.back().second += cnt;
        }
        else {
            dq.push_back(make_pair(val,cnt));
        }
        ans += sum;
    }
    dq.clear();
    sum=0;
    for (int i=1;n>=i;i++) {
        LL val=a[i];
        LL cnt=1;
        while (!dq.empty() && dq.back().first > val) {
            cnt += dq.back().second;
            sum -= dq.back().first*dq.back().second;
            dq.pop_back();
        }
        sum += val*cnt;
        if (dq.empty()) {
            dq.push_back(make_pair(val,cnt));
        }
        else if (dq.back().first == val) {
            dq.back().second += cnt;
        }
        else {
            dq.push_back(make_pair(val,cnt));
        }
        ans -= sum;
    }
    printf("%lld\n",ans);
}