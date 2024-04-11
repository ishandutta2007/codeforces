#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n,T;


const int maxn = 200000 + 5;
int a[maxn];
int t[maxn];

int main(){
	cin >> n >> T;
	double ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		ans += a[i];
	}
	long long pos = 0;
	long long neg = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&t[i]);
		t[i] -= T;
		if(t[i] > 0) pos += 1LL * a[i] * t[i];
		if(t[i] < 0) neg += 1LL * -a[i] * t[i];
	}
	if(neg > pos){
		long long dif = neg - pos;
		priority_queue<pair<int,int> > pq;
		for(int i = 1;i <= n;i++){
			if(t[i] < 0) pq.push(make_pair(-t[i],a[i]));
		}
		while(dif > 0){
			pair<int,int> Q = pq.top();pq.pop();
			if(dif >= 1LL * Q.first * Q.second){
				dif -= 1LL * Q.first * Q.second;
				ans -= Q.second;	
			}else{
				double x = 1.0 * dif / Q.first;
				dif -= x * Q.first;
				ans -= x;
			}
		}
		if(dif > 0){
			printf("%.10lf\n",0.0);
			return 0;
		}
	}else if(neg < pos){
		long long dif = pos - neg;
		priority_queue<pair<int,int> > pq;
		for(int i = 1;i <= n;i++){
			if(t[i] > 0) pq.push(make_pair(t[i],a[i]));
		}
		while(dif > 0){
			pair<int,int> Q = pq.top();pq.pop();
			if(dif >= 1LL * Q.first * Q.second){
				dif -= 1LL * Q.first * Q.second;
				ans -= Q.second;	
			}else{
				double x = 1.0 * dif / Q.first;
				dif -= x * Q.first;
				ans -= x;
			}
		}
		if(dif > 0){
			printf("%.10lf\n",0.0);
			return 0;
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}