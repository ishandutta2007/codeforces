#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 200005
struct Node {
	int val, id;
	bool operator < (const Node b) const {return val < b.val;}
}a[MAXN];
int n, delta[MAXN];
map < int , int > mp;
map < int , int > flag;
bool del1() {
	int del = a[3].val - a[2].val;
//	cout << del<< endl;
	For(i, 3, n-1) {
		if(a[i].val + del != a[i+1].val) {
			return 0;
		}
	}
	return 1;
}
bool deln() {
	int del = a[n-1].val - a[n-2].val;
//	cout << del<< endl;
	For(i, 1, n-2) {
		if(a[i].val + del != a[i+1].val) {
			return 0;
		}
	}
	return 1;
}
int main()
{
    n = read();
    For(i, 1, n) a[i].val = read(), a[i].id = i;
    sort(a + 1, a + 1 + n);
	For(i, 1, n-1) {
		delta[i] = a[i+1].val - a[i].val;
		mp[delta[i]]++;
	}
	int cnt = 0;
	For(i, 1, n-1) {
		if(mp[delta[i]] < n-3) cnt++;
	}
	if(cnt > 2) {
		printf("-1\n");
		return 0;
	}
	if(del1()) {
		printf("%d\n", a[1].id);
		return 0;
	}
	if(deln()) {
		printf("%d\n", a[n].id);
		return 0;
	}
	For(i, 1, n-1) {
		if(mp[delta[i]] >= n-3 && !flag[delta[i]]) {
			flag[delta[i]] = 1;
			int del = delta[i], num = 0;
			For(j, 1, n-1)
				if(a[j+1].val != a[j].val + del) {
					num++;
					if(a[j+2].val != a[j].val + del) num++;
					j++;
				}
					
			if(num >= 2) continue;
			For(j, 1, n-1)
				if(a[j+1].val != a[j].val + del) {
					cout << a[j+1].id <<endl;
					return 0;
				}
			break;
		}
	}
	cout << -1 << endl;
    return 0;
}