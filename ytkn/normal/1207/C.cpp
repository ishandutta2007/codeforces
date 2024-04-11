#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int s[200000];

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll n, a, b;
        cin >> n >> a >> b;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '0') s[j] = 0;
            else s[j] = 1;
            if(s[j] == 1) cnt++;
        }
        ll ans = 0;
        if(cnt == 0){
            ans = (n+1)*b+a*n;
        }else{
            vector<ll> v;
            ll cnt1 = 0;
            ll cnt0 = 0;
            for(int j = 0; j < n; j++){
                if(s[j] == 0){
                    if(cnt0 == 0 && j != 0) {
                        ans += cnt1*a+(cnt1+1)*b*2; 
                        //cout << ans << endl;
                    }
                    cnt0++;
                    cnt1 = 0;
                } 
                else{
                    if(cnt1 == 0){
                        v.push_back(cnt0);
                    }
                    cnt0 = 0;
                    cnt1++;
                }
            }
            v.push_back(cnt0);
            //cout << ans << endl;
            for(int j = 0; j < v.size(); j++){
                //cout << v[j] << ' ';
                if(j == 0 || j+1 == v.size()){ 
                    ans += v[j]*(a+b)+a;
                }else{
                    ans += min((v[j]-1)*(2*b+a)+a, (v[j]-1)*(a+b)+3*a);
                }
                //cout << ans << endl;
            }
        }
        //cout << endl;
        cout << ans << endl;
    }
}