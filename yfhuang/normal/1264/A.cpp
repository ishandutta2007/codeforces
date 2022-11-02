#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 4e5 + 5;
int t;
int n;
int p[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%d", &p[i]);
        }
        int gsb = 0;
        for(int i = 1;i <= n / 2;i++){
            if(p[i] > p[i + 1]){
                gsb = i;
            }
        }
        if(gsb < 3){
            cout << 0 << " " << 0 << " " << 0 << endl;
            continue;
        }
        int g = 0;
        for(int i = 1;i <= gsb;i++){
            if(p[i] > p[i + 1]){
                g = i;
                break;
            }
        }
        if(g == gsb){
            cout << 0 << " " << 0 << " " << 0 << endl;
            continue;
        }
        bool flag = false;
        for(int i = g + 1;i <= gsb;i++){
            if(p[i] > p[i + 1] and i - g > g and gsb - i > g){
                cout << g << " " << i - g << " " << gsb - i << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << 0 << " " << 0 << " " << 0 << endl;
        }
    }
    return 0;
}