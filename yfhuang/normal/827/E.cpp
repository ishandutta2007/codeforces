#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const int maxn = 5e5 + 5;
void FFT(complex<double> *a,int len,int inv){
    for(int i=0, n1=0, n2=0; i < len; ++i, n2 ^= (len /(i & -i) >> 1),n1 ^= (i & -i))
        if(n1 > n2)
            swap(a[n1],a[n2]);
    for(int m = 1;m <= len >> 1;m <<= 1){
        complex<double> w0(cos(PI/m),sin(PI / (inv * m))),w = 1,t;
        for(int k = 0;k < len;k += (m << 1),w = 1)
            for(int j = 0;j < m;++j,w *= w0) {
                t = w * a[k + j + m];
                a[k + j + m] = a[k + j] - t;
                a[k + j] += t;
            }
    }
    if(inv == -1)
        for(int i = 0;i < len;++i){
            a[i] /= len;
        }
}
complex<double> a[maxn << 2],b[maxn << 2];
long long c[maxn << 2];
int A[maxn],B[maxn];
int solve(int n){
    int len = 1;
    while(len < 2 * n - 1) len <<= 1;
    for(int i = 0;i <= len;i++){
        if(i < n) a[i] = complex<double>(1.0 * A[i],0);
        else a[i] = complex<double>(0,0);
        if(i < n) b[i] = complex<double>(1.0 * B[i],0);
        else b[i] = complex<double>(0,0);
    }
    FFT(a,len,1);FFT(b,len,1);
    for(int i = 0;i <= len;i++){
        a[i] = a[i] * b[i];
    }
    FFT(a,len,-1);
    for(int i = 0;i <= len;i++){
        c[i] = round(a[i].real());
    }
    return len;
}
char s[maxn];
bool vis[maxn << 2];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        scanf("%s",s);
        for(int i = 0;i < n;i++){
            A[i] = s[i] == 'V';
            B[(n - 1 - i)] = s[i] == 'K';
        }
        int len = solve(n);
        fill(vis,vis + 1 + n,0);
        for(int i = 0;i <= len;i++){
            if(c[i] > 0) vis[abs(i - (n - 1))] = 1;
        }
        for(int i = 1;i <= n;i++){
            if(vis[i] == 0){
                for(int j = i + i;j <= n;j += i){
                    vis[i] |= vis[j];
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) ans += vis[i] == 0;
        cout << ans << endl;

        for(int i =1 ;i <= n;i++){
            if(vis[i] == 0){
                printf("%d ",i);
            }
        }
        puts("");
    }
    return 0;
}