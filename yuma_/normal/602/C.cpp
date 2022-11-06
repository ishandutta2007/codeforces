//#include <stdio.h>
//#include <iostream>
//#include <math.h>
//#include <numeric>
//#include <vector>
//#include <map>
//#include <functional>
//#include <stdio.h>
//#include <array>
//#include <algorithm>
//#include <string>
//#include <assert.h>
//#include <stdio.h>
//#include <queue>
//#include<iomanip>
//using namespace std;
//
//
//using namespace std;
////
////#define N (1<<17) 
////// update(l,r,v) := [l,r]vl. k,a,b
////
////struct NODE{
////	int sum;//XVl. lQ]S.
////	int lazy;	//xl
////	NODE(){
////		sum = lazy = 0;
////	}
////};
////
////NODE seg[2 * N];
////
////// inline!(x)
////inline void lazy_evaluate_node(int k, int a, int b){
////	seg[k].sum +=seg[k].lazy;
////	if (k < N){ // 2*k(q) < 2*N (_) C[W. [m[h`.
////		seg[2 * k].lazy += seg[k].lazy;	//N`.
////		seg[2 * k + 1].lazy += seg[k].lazy;
////	}
////	seg[k].lazy = 0;
////}
////
////inline void update_node(int k){ // kq]O. [Oouifv.
////	seg[k].sum = min(seg[2 * k].sum , seg[2 * k + 1].sum);
////}
////
////// update(l,r,v) := [l,r]XV. 1-indexed.
////void update(int l, int r, int v, int k = 1, int a = 1, int b = N){
////	lazy_evaluate_node(k, a, b); 	// Hm[hs`_.
////
////	if (b < l || r < a) //[a,b][l,r]
////		return;
////	if (l <= a && b <= r){ // [l,r][a,b]S
////		seg[k].lazy += v;
////		lazy_evaluate_node(k, a, b); //x]s.
////		return;
////	}
////
////	int m = (a + b) / 2;
////	update(l, r, v, 2 * k, a, m);
////	update(l, r, v, 2 * k + 1, m + 1, b);
////	update_node(k);
////}
////
////// get(l,r) := [l,r]NG. 1-indexed.
////int get(int l, int r, int k = 1, int a = 1, int b = N){
////	lazy_evaluate_node(k, a, b); // Hm[hs`_.
////
////	if (b < l || r < a) //[a,b][l,r]
////		return 0;
////
////	if (l <= a && b <= r){ // [l,r][a,b]S
////		return seg[k].sum;
////	}
////
////	int m = (a + b) / 2;
////	int vl = get(l, r, 2 * k, a, m);
////	int vr = get(l, r, 2 * k + 1, m + 1, b);
////	update_node(k);
////	return min(vl , vr);
////}
//
//
//int main() {
//	//int n;
//	//cin >> n;
//	//vector<int> aa(n);
//	//vector<pair<int,int>>aaa;
//	//for (int i = 0; i < n; ++i){
//	//	int a, b;
//	//	cin >> a >> b;
//	//	aaa.push_back(make_pair(a, b)); 
//	//	aa[a]++;
//	//	aa[b]--;
//	//}
//	//vector<int> ans;
//	//ans.push_back(aa[0]);
//	//int amin=99999999;
//	//for(int i=0;i<n;++i){
//	//	ans.push_back(ans[i] + aa[i]);
//	//}
//
//	//RMQ r;
//	//r.init(65536);
//	//for (int i = 0; i < 65536;++i){
//	//	r.update(i, ans[i]);
//	//}
//
//	//cout << r.query(0, 7) << endl; //1
//	//cout << r.query(3, 6) << endl; //2
//	//cout << r.query(1, 5) << endl; //1
//	//cout << r.query(5, 7) << endl; //4
//	//return 0;
//
//	vector<long long int>times;
//	for (int i = 0; i < 7; ++i){
//		long long int c;
//		cin >> c;
//		times.push_back(c);
//	}
//	if (times[0] == 0)cout << "YES" << endl;
//	else{
//		times[0]--;
//	}
//
//	{
//		vector<long long int> atimes(times);
//		while (1){
//			auto zero_it = find(atimes.begin(), atimes.end(), 0);
//			if (zero_it != atimes.end()){//5 3 2 0 4 4 2 
//				const int num = zero_it - atimes.begin();
//				int from = num;
//				while (1){
//					from = (from + 1) % 7;
//					if (from == num)break;
//					int to = (from + 1) % 7;
//					if (atimes[from] != 0 && atimes[to] == 0){
//						break;
//					}
//					if (atimes[from] > atimes[to]){
//						break;
//					}
//					long long int amin = min(atimes[from], atimes[to]);
//					atimes[from] -= amin;
//					atimes[to] -= amin;
//					if (atimes[from] == 0 && atimes[to] == 0){
//						break;
//					}
//				}
//				if (all_of(atimes.begin(), atimes.end(), [](const int aaa){return aaa == 0; })){
//					cout << "YES" << endl;
//					return 0;
//				}
//				else{
//					break;
//				}
//			}
//			else{
//				long long int aamin = atimes[0];
//				for (int i = 0; i < 7; ++i){
//					aamin = min(aamin, atimes[i]);
//				}
//				for (int i = 0; i < 7; ++i){
//					atimes[i] -= aamin;
//				}
//			}
//		}
//	}
//	{
//		vector<long long int> btimes(times);
//		for (int i = 0; i < 7; ++i){//times[i]
//			btimes = times;
//			int from = (i + 6) % 7;
//			while (1){
//				from = (from + 1) % 7;
//				if (from == (i + 6) % 7)break;
//				int to = (from + 1) % 7;
//				if (btimes[from] != 0 && btimes[to] == 0){
//					break;
//				}
//				if (btimes[from] > btimes[to]){
//					break;
//				}
//				long long int amin = min(btimes[from], btimes[to]);
//				btimes[from] -= amin;
//				btimes[to] -= amin;
//				if (btimes[from] == 0 && btimes[to] == 0){
//					break;
//				}
//			}
//			if (all_of(btimes.begin(), btimes.end(), [=](int a){return a == 0; })){
//				cout << "YES" << endl;
//				return 0;
//			}
//			else{
//				continue;
//			}
//		}
//	}
//	cout << "NO" << endl;
//	return 0;
//}
////3 4 4 4 4 4 4





#include <stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
using namespace std;

//
//
//int dp[10010][51][51];
//int main(){
//	int w,n,k;
//	cin >> w>>n>>k;
//	vector<pair<int,int>> scshots;
//	for (int i = 0; i < n; ++i){
//		int a, b;
//		cin >> a >> b;
//		scshots.push_back(make_pair(a, b));
//	}
//	sort(scshots.begin(), scshots.end(), [](const pair<int, int>l, const pair<int, int>r){return (double(l.first) / double(l.second) < double(r.first) / double(r.second)); });
//	for (int ai = 0; ai < 10010; ++ai){
//		for (int an = 0; an <= 50; ++an){
//			for (int ak = 0; ak <= 50; ++ak){
//				dp[ai][an][ak] = 0;
//			}
//		}
//	}
//	for (int an = 0; an <= 50; ++an){
//		for (int ak = 0; ak < 50; ++ak){
//			dp[0][an][ak] = 0;
//		}
//	}
//	for (int ai = 0; ai < 10010; ++ai){
//		for (int ak = 0; ak <= 50; ++ak){
//			dp[ai][0][ak] = 0;
//		}
//	}
//	for (int ai = 0; ai < 10010; ++ai){
//		for (int an = 0; an <= 50; ++an){
//			dp[ai][an][0] = 0;
//		}
//	}
//	for (int an = 1; an<=scshots.size(); ++an){
//		for (int ai = scshots[an-1].first; ai < 10010; ++ai){
//			
//			for (int ak = 1; ak <= 50; ++ak){
//				dp[ai][an][ak] = max(dp[ai][an-1][ak],dp[ai - scshots[an - 1].first][an-1][ak - 1]+scshots[an-1].second);
//			}
//			for (int ak = 1; ak <= 50; ++ak){
//				dp[ai][an][ak] = max(dp[ai][an][ak - 1],dp[ai][an][ak]);
//			}
//		}
//		for (int ai = 1; ai < 10010; ++ai){
//			for (int ak = 0; ak <= 50; ++ak){
//				dp[ai][an][ak] = max(dp[ai-1][an][ak], dp[ai][an][ak]);
//			}
//		}
//	}
//	for (int an = 1; an <= scshots.size(); ++an){
//		for (int ai = 0; ai < 10010; ++ai){
//
//			for (int ak = 0; ak <= 50; ++ak){
//				dp[ai][an][ak] = max(dp[ai][an - 1][ak], dp[ai][an][ak]);
//			}
//		}
//		
//	}
//	cout << dp[w][n][k] << endl;
//	
//	return 0;
//}
class CompareDist
{
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {
		return n1.second>n2.second;
	}
};
bool train[401][401];
bool operator < (pair<int, int>l, pair<int, int>r){
	return l.second < r.second;
}
int main(){
	for (int i = 0; i < 401; ++i){
		for (int j = 0; j < 401; ++j){
			train[i][j] = false;
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		train[a][b] = true;
		train[b][a] = true;
	}


	int anst;
	int ansb;
	{
		int cantrain[401];
		for (int i = 0; i < 401; ++i){
			cantrain[i] = -1;
		}
		cantrain[1] = 0;
		priority_queue < pair<int, int>, vector<pair<int, int>>, CompareDist>a;
		a.push(make_pair(1, 0));
		while (!a.empty()){
			pair<int, int> atop = a.top();
			a.pop();
			for (int i = 1; i <= n; ++i){
				if (i == atop.first)continue;
				if (train[atop.first][i] && cantrain[i] == -1){
					a.push(make_pair(i, atop.second + 1));
					cantrain[i] = atop.second + 1;
				}
			}
		}
		if (cantrain[n] == -1){
			cout << -1 << endl;
			return 0;
		}
		anst = cantrain[n];
	}

	{
		int canbus[401];
		for (int i = 0; i < 401; ++i){
			canbus[i] = -1;
		}
		canbus[1] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist>a;
		a.push(make_pair(1, 0));
		while (!a.empty()){
			pair<int, int> atop = a.top();
			a.pop();
			for (int i = 1; i <= n; ++i){
				if (i == atop.first)continue;
				if (!train[atop.first][i] && canbus[i] == -1){
					a.push(make_pair(i, atop.second + 1));
					canbus[i] = atop.second + 1;
				}
			}
		}
		if (canbus[n] == -1){
			cout << -1 << endl;
			return 0;
		}
		ansb = canbus[n];
	}
	cout << max(anst, ansb) << endl;

	return 0;
}