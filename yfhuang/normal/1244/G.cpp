#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int n;
typedef long long LL;

LL k;
const int maxn = 1e6 + 6;
int deque[maxn * 2];
int front, rear;

LL check(int x){
    for(int i = 1;i <= x;i++){
        deque[n + 1 - i] = i;
    }
    for(int i = 1;i <= n - x;i++){
        deque[i] = x + i;
    }
    LL sum = 0;
    for(int i = 1;i <= n;i++){
        sum += max(deque[i], i);
    }
    return sum;
}

int main(){
    cin >> n >> k;
    LL lb = 1LL * (n + 1) * n / 2;
    LL ub = 0;
    for(int i = 1;i <= n;i++){
        ub += max(i, n + 1 - i);
    }
    if(k < lb){
        cout << -1 << endl;
    }else{
        k = min(ub, k);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(check(mid) <= k)
                l = mid;
            else
                r = mid - 1;
        }
        LL now = check(l);
       // cout << now << endl;
        for(int i = 1;i <= l;i++){
            deque[n + 1 - i] = i;
        }
        for(int i = 1;i <= n - l;i++){
            deque[i] = l + i;
        }
        front = 1, rear = n;
        for(int i = front;i < rear;i++){
            if(now < k){
                now -= max(i - front + 1, deque[i]) + max(i - front + 2, deque[i + 1]);
                now += max(i - front + 1, deque[i + 1]) + max(i - front + 2, deque[i]);
                swap(deque[i], deque[i + 1]);
            }else{
                break;
            }
        }
        //cout << now << endl;
        cout << k << endl;
        for(int i = 1;i <= n;i++){
            printf("%d%c", i, i == n ? '\n' : ' ');
        }
        for(int i = 1;i <= n;i++){
            printf("%d%c", deque[i], i == rear ? '\n' : ' ');
        }
    }
    return 0;
}