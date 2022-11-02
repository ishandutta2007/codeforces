#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int n;

int query(int x1, int y1, int x2, int y2){
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    fflush(stdout);
    int num;
    cin >> num;
    return num;
}

pair<int, int> solve(int x1, int y1, int x2, int y2){
    if(x1 == x2){
        while(y1 < y2){
            int mid = (y1 + y2) / 2;
            int ans = query(x1, y1, x2, mid); 
            if(ans & 1) y2 = mid;
            else y1 = mid + 1;
        }
        return make_pair(x1, y1);
    }else{
        while(x1 < x2){
            int mid = (x1 + x2) / 2;
            int ans = query(x1, y1, mid, y2);
            if(ans & 1) x2 = mid;
            else x1 = mid + 1;
        }
        return make_pair(x1, y1);
    }
}

int main(){
    cin >> n;
    set<pair<int, int> > s;
    for(int i = 1;i <= n;i++){
        int ans = query(i, 1, i, n);
        if(s.size() < 2 && (ans & 1)){
            s.insert(solve(i, 1, i, n));
        } 
    }
    for(int i = 1;i < n;i++){
        int ans = query(1, i, n, i);
        if(s.size() < 2 && (ans & 1)){
            s.insert(solve(1, i, n, i));
        }
    }
    if(s.size() < 2){
        s.insert(solve(1, n, n, n));
    }
    cout << "!";
    for(auto v : s){
        cout << " " << v.first << " " << v.second;
    }
    cout << endl;
    fflush(stdout);
    return 0;
}