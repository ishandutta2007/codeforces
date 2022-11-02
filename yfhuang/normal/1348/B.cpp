#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    int n, k;
    while(T--){
        cin >> n >> k;
        vector<int> a;
        for(int i = 1; i <= n;i++){
            int num;
            cin >> num;
            a.push_back(num);
        }
        sort(a.begin(), a.end());
        auto it = unique(a.begin(), a.end());
        a.erase(it, a.end());
        int sz = a.size();
        if(sz > k){
            cout << -1 << endl;
        }else{
            for(int i = sz;i < k;i++){
                a.push_back(1);
            }
            cout << n * k << endl;
            for(int i = 1;i <= n;i++){
                for(int j = 0;j < k;j++){
                   cout << a[j]; 
                   if(j == k - 1 and i == n)
                       cout << endl;
                   else
                       cout << " ";
                }
            }
        }
    }
    return 0;
}