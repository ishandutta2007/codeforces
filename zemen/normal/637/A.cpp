#include <bits/stdc++.h>

using namespace std;

int main()
{
int n; cin >> n;
map<int, int> cnt;
int maxCnt = -1, maxId = -1;
for (int i = 0; i < n; ++i) {
int x;
cin >> x;
if (++cnt[x] > maxCnt) maxCnt = cnt[x], maxId = x;
}
cout << maxId << endl;
   return 0;
}