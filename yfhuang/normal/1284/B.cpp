#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
const int maxn = 1e6 + 5;
bool vis[maxn];

int c[maxn];

int mx[maxn], mi[maxn];
vector<int> a;
int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int l;
        scanf("%d", &l);
        a.clear();
        for(int j = 1;j <= l;j++){
            int num;
            scanf("%d", &num);
            a.push_back(num); 
        }
        for(int j = 1;j < a.size();j++){
            if(a[j] > a[j - 1]){
                vis[i] = true;
                cnt++;
                break;
            }
        }
        if(!vis[i]){
            mx[i] = a[0];
            mi[i] = a[l - 1];
            c[mx[i]]++;
        }
    }
    for(int i = 1;i <= 1e6;i++){
        c[i] += c[i - 1];
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        if(vis[i])
            ans += n;
        else{
            ans += cnt;
            ans += c[1000000] - c[mi[i]];
            //cout << cnt << " " << c[mi[i] - 1] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}