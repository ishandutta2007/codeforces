//
//  main.cpp
//  D
//
//  Created by  on 16/7/7.
//  Copyright  2016 . All rights reserved.
//
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int mm[MAXN];
struct ST
{
    int dp[MAXN][20],ty;
    void build(int n,int b[],int _ty)
    {
        ty=_ty;
        for(int i=1;i<=n;i++)
            dp[i][0]=ty*b[i];
        for(int j=1;j<=mm[n];j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
    int query(int x,int y)
    {
        int k=mm[y-x+1];
        return ty*max(dp[x][k],dp[y-(1<<k)+1][k]);
    }
}rmq_a,rmq_b;
int a[MAXN],b[MAXN];
int main()
{
    for(int i=-(mm[0]=-1);i<MAXN;i++)
        mm[i]=mm[i-1]+((i&(i-1))==0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    rmq_a.build(n,a,1);
    rmq_b.build(n,b,-1);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n+1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(rmq_a.query(i,m)>=rmq_b.query(i,m))r=m;
            else l=m+1;
        }
        res-=l;
        l=i,r=n+1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(rmq_a.query(i,m)>rmq_b.query(i,m))r=m;
            else l=m+1;
        }
        res+=l;
    }
    return 0*printf("%I64d",res);
}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int maxn = 200000 + 5;
//
//int d[maxn][20];
//int d1[maxn][20];
//
//int A[maxn];
//int B[maxn];
//
//int n;
//
//void RMQ_init1(int n){
//    for(int i = 0;i < n;i++) d1[i][0] = B[i];
//    for(int j = 1;(1 << j) <= n;j++){
//        for(int i = 0;i + (1 << j) - 1 < n;i++){
//            d1[i][j] = min(d1[i][j - 1],d1[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//}
//
//void RMQ_init(int n){
//    for(int i = 0;i < n;i++) d[i][0] = A[i];
//    for(int j = 1;(1 << j) <= n;j++){
//        for(int i = 0;i + (1 << j) - 1 < n;i++){
//            d[i][j] = max(d[i][j - 1],d[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//    
//}
//int RMQ(int L,int R){
//    int k = 0;
//    while((1 << (k + 1)) <= R - L + 1) k++;
//    return max(d[L][k],d[R - (1<<k)+1][k]);
//}
//
//int RMQ1(int L,int R){
//    int k = 0;
//    while((1 << (k + 1)) <= R - L + 1) k++;
//    return min(d1[L][k],d1[R - (1<<k)+1][k]);
//}
//
//int main(){
//    cin >> n;
//    for(int i = 0;i < n;i++){
//        scanf("%d",A + i);
//    }
//    RMQ_init(n);
//    for(int i = 0;i < n;i++){
//        scanf("%d",B + i);
//    }
//    RMQ_init1(n);
//    long long ans = 0;
//    for(int i = 0;i < n;i++){
//        int l = i , r = n - 1;
//        while(l < r)
//        {
//            int m = (l + r) / 2;
//            if(RMQ(i,m) >= RMQ1(i,m))r = m;
//            else l = m + 1;
//        }
//        ans -= l;
//        //cout << l << endl;
//        l = i,r = n - 1;
//        while(l<r)
//        {
//            int m=l+(r-l)/2;
//            if(RMQ(i,m)>RMQ1(i,m))r=m;
//            else l=m+1;
//        }
//        ans+=l;
//        //cout << l << endl;
//    }
//    cout << ans << endl;
//    return 0;
//}

//const int INF = 1e9 + 5;
//
//
//int a[maxn];
//int b[maxn];
//int q[maxn];
//
//int n;
//
//struct interval{
//    int l,r;
//    int key;
//    int m;
//    bool operator < (const interval & rhs) const{
//        return key < rhs.key || (key == rhs.key && l < rhs.l);
//    }
//}A[maxn],B[maxn];
//
//int main(int argc, const char * argv[]) {
//    cin >> n;
//    for(int i = 1;i <= n;i++){
//        scanf("%d",a + i);
//        A[i].m = i;
//        A[i].key = a[i];
//    }
//    for(int i = 1;i <= n;i++){
//        scanf("%d",b + i);
//        B[i].m = i;
//        B[i].key = b[i];
//    }
//    a[0] = INF,a[n + 1] = INF;
//    int cur = 0;
//    q[++cur] = 0;
//    for(int i = 1;i <= n;i++){
//        while(cur > 0 && a[i] > a[q[cur]]) cur--;
//        A[i].l = q[cur] + 1;
//        q[++cur] = i;
//    }
//    cur = 0;
//    q[++cur] = n + 1;
//    for(int i = n;i >= 1;i--){
//        while(cur > 0 && a[i] > a[q[cur]]) cur--;
//        A[i].r = q[cur] - 1;
//        q[++cur] = i;
//    }
//    b[0] = -INF,b[n + 1] = -INF;
//    cur = 0;
//    q[++cur] = 0;
//    for(int i = 1;i <= n;i++){
//        while(cur > 0 && b[i] < b[q[cur]]) cur--;
//        B[i].l = q[cur] + 1;
//        q[++cur] = i;
//    }
//    cur = 0;
//    q[++cur] = n + 1;
//    for(int i = n;i >= 1;i--){
//        while(cur > 0 && b[i] < b[q[cur]]) cur--;
//        B[i].r = q[cur] - 1;
//        q[++cur] = i;
//    }
//    sort(A + 1,A + 1 + n);
//    sort(B + 1,B + 1 + n);
////    for(int i = 1;i <= n;i++){
////        cout << A[i].l << ' ' << A[i].m << ' ' << A[i].r << ' ' << A[i].key<<endl;
////        
////    }
////    for(int i = 1;i <= n;i++){
////        cout << B[i].l << ' ' << B[i].m << ' ' << B[i].r << ' ' << B[i].key<<endl;
////    }
//    cur = 1;
//    long long ans = 0;
//    for(int i = 1;i <= n;i++)if(cur <= n){
//        if(A[i].key < B[cur].key) continue;
//        while(cur <= n && A[i].key > B[cur].key) cur++;
//        while(cur <= n && A[i].key == B[cur].key){
//            if(A[i].m <= B[cur].m){
//                if(A[i].r < B[cur].m || A[i].m < B[cur].l) break;
//                ans += (A[i].m - B[cur].l + 1) * ( -B[cur].m + A[i].r + 1);
//                if(A[i].r <= B[cur].r){
//                    break;
//                }else{
//                    cur++;
//                }
//            }else if(A[i].m > B[cur].m){
//                if(A[i].m > B[cur].r || A[i].l > B[cur].m) break;
//                ans += (B[cur].r - A[i].m + 1) * (B[cur].m - A[i].l + 1);
//                if(A[i].r <= B[cur].r){
//                    break;
//                }else{
//                    cur++;
//                }
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}