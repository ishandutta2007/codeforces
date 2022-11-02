#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n;
const int maxn = 2005;

int a[maxn];

int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            scanf("%d", a + i);
        }
        int ans = n;
        set<int> s;
        for(int i = 0;i <= n;i++){
            if(i > 0){
                if(s.find(a[i]) != s.end()){
                    break;
                }
                s.insert(a[i]);
            }
            set<int> s1;
            ans = min(ans, n - i);
            for(int j = n;j >= i + 1;j--){
                if(s.find(a[j]) != s.end()){
                    break;
                }
                if(s1.find(a[j]) != s1.end()){
                    break;
                }
                s1.insert(a[j]);
                ans = min(ans, j - i - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}