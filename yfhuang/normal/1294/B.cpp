#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int t;
int n;
const int maxn = 1005;
pair<int, int> coord[maxn];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &coord[i].first, &coord[i].second);
        }
        sort(coord + 1, coord + n + 1);
        bool flag = true;
        for(int i = 1; i < n;i++){
            if(coord[i + 1].second < coord[i].second)
                flag = false;
        }
        if(flag){
            string s = "";
            coord[0] = make_pair(0, 0);
            for(int i = 0;i < n;i++){
                for(int j = 1;j <= coord[i + 1].first - coord[i].first;j++){
                    s.push_back('R');
                }
                for(int j = 1;j <= coord[i + 1].second - coord[i].second;j++){
                    s.push_back('U');
                }
            }
            cout << "YES" << endl;
            cout << s << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}