#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
#include <vector>
using namespace std;

const int maxn = 1005;

struct Point{
    int a[5];
    void read(){
        for(int i = 0;i < 5;i++){
            cin >> a[i];
        }
    }
    Point(){}
}p[maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        p[i].read();
    }
    if(n > 100){
        printf("0\n");
    }else{
        vector<int> ans;
        for(int i = 1;i <= n;i++){
            bool flag = true;
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    if(j == i) continue;
                    if(k == i || k == j) continue;
                    int b[5],c[5];
                    int ret = 0;
                    for(int l = 0;l < 5;l++){
                        b[l] = p[j].a[l] - p[i].a[l];
                        c[l] = p[k].a[l] - p[i].a[l];
                        ret += b[l] * c[l];
                    }
                    if(ret > 0) flag = false;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            cout << ans[i] << " ";
        }
    }
    return 0;
}