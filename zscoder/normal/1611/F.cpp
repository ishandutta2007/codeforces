#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
int main() {
	int times;
	cin>>times;
	for (int i = 0; i < times; i++) {
		int N, S;
		cin>>N>>S;
		ll cost[N];
		for (int j = 0; j < N; j++) {
			cin>>cost[j];
		}
		ll currsum = 0;
		ll left = 0;
		ll right = -1;
		int maximum = 0;
		int ansl = -1;
		int ansr = -1;
		while (left < N) {
			while (right < N - 1) {
				if (currsum + cost[right + 1] >= -S)
				{
					right++;
					currsum+=cost[right];
				}
				else
					break;
			}
			if (right - left + 1 >= maximum) {
				maximum = right - left + 1;
				ansl = left;
				ansr = right;
			}
			currsum-=cost[left];
			left++;
		}
		if (maximum == 0)
			cout<<-1<<endl;
		else
			cout<<(ansl + 1)<<" "<<(ansr + 1)<<endl;
	}
}