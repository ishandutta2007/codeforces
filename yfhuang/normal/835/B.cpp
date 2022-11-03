#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

char s[100005];
long long k;
int num[100005];
priority_queue<int> q;
int main(){
    cin >> k;

    scanf("%s",s + 1);
    int len = strlen(s + 1);
    int ans = 0;
    long long sum = 0;
    for(int i = 1;i <= len;i++){
        num[i] = s[i] - '0';
        sum += num[i];
        if(num[i] < 9) q.push(9 - num[i]);
    }
    while(sum < k){
        ans++;
        int p = q.top();q.pop();
        sum += p;
    }

    cout << ans << endl;
    return 0;
}