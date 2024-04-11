    #include <bits/stdc++.h>
    using namespace std;
     
    #define fi first
    #define se second
    #define mp make_pair
    #define pb push_back
    #define eb emplace_back
     
    typedef long long ll;
    typedef pair<int, int> pi;
     
    int T;
    int n, p;
    const int maxn = 1e6 + 5;
    int k[5 * maxn];
    int cnt[5 * maxn];
    int cnt1[5 * maxn];
     
    const int mod = 1e9 + 7;
     
    int qpow(int a, int power){
        int ret = 1;
        while(power > 0){
            if(power & 1){
                ret = 1LL * ret * a % mod;
            }
            a = 1LL * a * a % mod;
            power >>= 1;
        }
        return ret;
    }
     
    void add(int &a, int b){
        a += b;
        if(a >= mod)
            a -= mod;
    }
     
    void sub(int &a, int b){
        a -= b;
        if(a < 0){
            a += mod;
        }
    }
     
    int compute(queue<pi> q){
        int ret = 0;
        while(!q.empty()){
            pi f = q.front(); q.pop();
            add(ret, 1LL * qpow(p, f.fi) * f.se % mod);
        }
        return ret;
    }
     
     
     
    int main(){
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cin >> T;
        while(T--){
            cin >> n >> p;
            if(p == 1){
                for(int i = 1;i <= n;i++){
                    cin >> k[i];
                }
                cout << (n & 1) << endl;
                continue;
            }
            for(int i = 1;i <= n;i++){
                cin >> k[i];
                cnt[k[i]]++;
            }
            sort(k + 1, k + 1 + n);
            for(int i = 1;i <= n;i++){
                cnt1[k[i]] = cnt[k[i]];
            }
            queue<pi> q;
            for(int i = n, j = n;i >= 1;i = j - 1, j = i){
                while(j - 1 >= 1 and k[j - 1] == k[i]){
                    j--;
                }
                q.push(mp(k[i], cnt1[k[i]]));
            }
            ll diff = 0;
            int pre = 0;
            bool flag = false;
            while(!q.empty()){
                if(diff == 0){
                    pi f = q.front(); q.pop(); 
                    int val = f.fi;
                    int num = f.se; 
                    if(num & 1){
                        diff = 1;
                        pre = val;
                    }
                }else{
                    pi f = q.front();
                    int val = f.fi;
                    int num = f.se;
                    for(int i = pre - 1;i >= val;i--){
                        diff *= p;
                        if(diff > n){
                            pre = i;
                            break;
                        }
                    }
                    if(diff > n){
                        int a1 = 1LL * qpow(p, pre) * (diff % mod) % mod;
                        int a2 = compute(q);
                        sub(a1, a2);
                        cout << a1 << endl;
                        flag = true;
                        break;
                    }else{
                        q.pop();
                        if(diff > num){
                            diff -= num;
                            pre = val;
                        }else{
                            num -= diff;
                            if(num & 1){
                                diff = 1;
                                pre = val;
                            }else{
                                diff = 0;
                                pre = 0;
                            }
                        } 
                    }
                }     
            }
            if(!flag){
                cout << 1LL * qpow(p, pre) * (diff % mod) % mod << endl;
            }
            for(int i = 1;i <= n;i++){
                cnt[k[i]]--;
            }
        } 
        return 0;
    }