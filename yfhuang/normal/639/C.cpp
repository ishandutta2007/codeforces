#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 5;

typedef long long ll;

const ll INF = (1LL<<60);

ll c[maxn],c1[maxn],c2[maxn];
ll n,k;
int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        scanf("%I64d",&c[i]);
    }
    for(int i = 0; i <= n; i++){
        c1[i] = c[i];
    }
    for(int i = 0; i <= n; i++){
        c2[i] = c[i];
    }
    //for(int i = 0; i <= n; i++){
      //  cout<<c1[i]<<endl;
//    }
    int r = n;
    for(int i = 0; i < n; i++){
        if(c1[i]%2==0){
            c1[i + 1]+=c1[i]/2;
        }
        else{
            r = i;
            break;
        }
    }
    int l = 0;
    for(int i = n; i > 0; i--){
        if(abs(c2[i]) < INF){
            c2[i-1] += 2 * c2[i];
        }else{
            l = i;
            break;
        }
    }
    //for(int i = 0; i <= n; i++){
      //  cout<<c1[i]<<endl;
        //cout<<c2[i]<<endl;
//    }
    //cout<<l<<' '<<r<<endl;
    ll cnt = 0;
    for(int i = l; i <= r; i++){
        if(abs(c2[i] + c1[i] - 2 * c[i]) <= k) cnt++;
        if(i == n && c2[i] + c1[i] - 2 * c[i] == 0) cnt--;
    }
    cout<<cnt<<endl;
    return 0;
}