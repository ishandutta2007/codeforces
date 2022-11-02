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
int n;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        if(n & 1){
            cout << "NO" << endl;
        }else{
            sort(a + 1, a + 1 + n);
            for(int i = 1;i <= n / 2;i++){
                b[2*(i-1)] = a[i]; 
                b[2*(i-1) + 1] = a[i + n / 2];
            }
            bool flag = true;
            for(int i = 0;i < n;i++){
                int l = i - 1;
                int r = i + 1;
                if(l < 0)
                    l += n;
                if(r >= n)
                    r -= n;
                if(i & 1){
                    if(b[i] > b[l] and b[i] > b[r]){

                    }else
                        flag = false;
                }else{
                    if(b[i] < b[l] and b[i] < b[r]){

                    }else
                        flag = false;
                }
            }
            if(flag){
                cout << "YES" << endl;
                for(int i = 0;i < n;i++){
                    cout << b[i] << ((i == n - 1) ? '\n' : ' ');
                }
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}