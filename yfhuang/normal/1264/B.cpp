#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int a[4];
int b[4];

int main(){
    int n = 0;
    for(int i = 0;i < 4;i++){
        cin >> a[i];
        n += a[i];
    } 
    for(int i = 0;i < 4;i++){
        b[i] = a[i];
    }
    if(abs(a[0] + a[2] - a[1] - a[3]) > 1){
        cout << "NO" << endl;
        return 0;
    }
    if(a[0] + a[2] >= a[1] + a[3]){
        if(a[0] > 0){
            int now = 0;
            vector<int> ans;
            while(ans.size() < n){
                ans.push_back(now);
                a[now]--;
                if(now - 1 >= 0 and a[now - 1] > 0){
                    now--;
                    continue;
                }
                if(now + 1 <= 3 and a[now + 1] > 0){
                    now++;
                    continue;
                }
                break;
            } 
            if(ans.size() == n){
                cout << "YES" << endl;
                for(int i = 0;i < n;i++){
                    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
                }
                return 0;
            }
            for(int i = 0;i < 4;i++){
                a[i] = b[i];
            }
        }
        if(a[2] > 0){
            int now = 2;
            vector<int> ans;
            while(ans.size() < n){
                ans.push_back(now);
                a[now]--;
                if(now - 1 >= 0 and a[now - 1] > 0){
                    now--;
                    continue;
                }
                if(now + 1 <= 3 and a[now + 1] > 0){
                    now++;
                    continue;
                }
                break;
            } 
            if(ans.size() == n){
                cout << "YES" << endl;
                for(int i = 0;i < n;i++){
                    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
                }
                return 0;
            }
            for(int i = 0;i < 4;i++){
                a[i] = b[i];
            }
        }
    }else{
        if(a[1] > 0){
            int now = 1;
            vector<int> ans;
            while(ans.size() < n){
                ans.push_back(now);
                a[now]--;
                if(now + 1 <= 3 and a[now + 1] > 0){
                    now++;
                    continue;
                }
                if(now - 1 >= 0 and a[now - 1] > 0){
                    now--;
                    continue;
                }
                break;
            } 
            if(ans.size() == n){
                cout << "YES" << endl;
                for(int i = 0;i < n;i++){
                    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
                }
                return 0;
            }
            for(int i = 0;i < 4;i++){
                a[i] = b[i];
            }
        }
        if(a[3] > 0){
            int now = 3;
            vector<int> ans;
            while(ans.size() < n){
                ans.push_back(now);
                a[now]--;
                if(now + 1 <= 3 and a[now + 1] > 0){
                    now++;
                    continue;
                }
                if(now - 1 >= 0 and a[now - 1] > 0){
                    now--;
                    continue;
                }
                break;
            } 
            if(ans.size() == n){
                cout << "YES" << endl;
                for(int i = 0;i < n;i++){
                    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
                }
                return 0;
            }
            for(int i = 0;i < 4;i++){
                a[i] = b[i];
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}