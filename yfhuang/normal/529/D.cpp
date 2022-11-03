#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n,M;
int T;
int cnt;
int due[100005];
int a[100005];
int ans[100005];
//priority_queue<pair<int,int> > pq;
//priority_queue<int,vector<int>,greater<int> > time;

int main(){
	cin >> n >> M;
	cnt = 0;
	int T;
	cin >> T;
	int p = 0,q = 0;
	for(int i = 1;i <= n;i++){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		a[i] = h * 3600 + m * 60 + s;
		//cout << a[i] << endl;
	}
	memset(due,0,sizeof(due));
	int mx = 0;
	int tot = 0;
	for(int i = 1;i <= n;i++){
		if(p < q && due[p] < a[i]) p++;
		//cout << q << " " << p << endl;
		if(q - p >= M){
			q--;
			due[q++] = a[i] + T - 1;
			ans[i] = tot;
		}else{
			due[q++] = a[i] + T - 1;
			ans[i] = ++tot;
		}mx = max(mx,q - p);
	}
	if(mx != M) printf("No solution\n");
	else{
		cout << tot << endl;
		for(int i = 1;i <= n;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}