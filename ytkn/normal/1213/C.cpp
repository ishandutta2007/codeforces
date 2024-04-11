#include <iostream>

using namespace std;

typedef long long ll;

ll sum[10];

int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll n, m;
        cin >> n >> m;
        int k = m%10;
        int tmp = k;
        int cnt = 0;
        sum[0] = tmp;
        while(true){
            tmp += k;
            tmp %= 10;
            cnt++;
            if(tmp == k)break;
            sum[cnt] = sum[cnt-1]+tmp;
        }
        ll d = n/m;
        ll ans = (d/cnt)*sum[cnt-1]+sum[d%cnt-1];
        cout << ans << endl;
    }
}