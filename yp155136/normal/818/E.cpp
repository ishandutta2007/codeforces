#include <iostream>
#include <stdio.h>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int MAX_N = 1e5 +6;
const int MAGIC = 11;

int a[MAX_N];
int pre[MAGIC][MAX_N];

int main () {
    LL n,k;
    scanf("%lld %lld",&n,&k);
    vector<pii> v;
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
    }
    /*if (k==1) {
        LL ans=0;
        for (int x=0;n-1>=x;x++) {
            ans += (n-x);
        }
        printf("%lld\n",ans);
        return 0;
    }*/
    for (int i=2;50000>=i;i++) {
        if (k%i==0) {
            int cnt=0;
            while (k%i==0) {
                k/=i;
                cnt++;
            }
            v.push_back(make_pair(i,cnt));
        }
    }
    if (k!=1) v.push_back(make_pair(k,1));
    int m=v.size();
    for (int i=0;m>i;i++) {
        int p=v[i].first;
        for (int j=1;n>=j;j++) {
            int cnt=0;
            while (a[j]%p==0) {
                a[j]/=p;
                cnt++;
            }
            pre[i][j] = pre[i][j-1] + cnt;
        }
        pre[i][n+1] = 123456789;
    }
    LL ans=0;
    for (int x=0;n>x;x++) {
        int L=x,R=n+1;  //R is the answer
        while (R-L!=1) {
            int mid=(L+R)>>1;
            bool okay=true;
            for (int j=0;m>j;j++) {
                if (pre[j][mid] - pre[j][x] < v[j].second) okay=false;
            }
            if (okay) R=mid;
            else L=mid;
        }
        ans += n-R+1;
    }
    printf("%lld\n",ans);
}