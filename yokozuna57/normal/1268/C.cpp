#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

struct BIT{
	int a[1<<19];
	void init(){
		for(int i = 0 ; i < (1<<19) ; i ++){
			a[i] = 0;
		}
	}
	void add(int x){
		while(x > 0){
			a[x] ++;
			x -= x&-x;
		}
	}
	int sum(int x){
		int ret = 0;
		while(x <= (1<<18)){
			ret += a[x];
			x += x&-x;
		}
		return ret;
	}
}bit;

int main(){
	static ll n;
	static ll p[200010];
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld",&p[i]);
	}
	
	static ll q[200010];
	for(int i = 1 ; i <= n ; i ++){
		q[p[i]] = i;
	}
	
	printf("0");
	ll ret = 0;
	set<int> S;
	S.insert(q[1]);
	set<int>::iterator x = S.begin();
	set<int>::iterator y = S.end();
	bit.init();
	bit.add(q[1]);
	for(int k = 2 ; k <= n ; k ++){
		/*puts("=====");
		for(int s: S){
			cout << s << " ";
		}
		cout << endl;
		cout << *x << " " << *y << endl;
		puts("=====");*/
		S.insert(q[k]);
		bit.add(q[k]);
		if(k%2 == 1){
			//cout << "k=" << k << ":" << ret << endl;
			if(q[k] < *x){
				ret += (*x-q[k]-1) - (bit.sum(q[k]+1)-bit.sum(*x));
			}
			else if(q[k] < *y){
				x ++;
			}
			else {
				ret += (q[k]-*y-1) - (bit.sum(*y+1)-bit.sum(q[k]));
				x ++;
				y ++;
			}
			//cout << "k=" << k << ":" << ret << endl;
			ret += bit.sum(q[k])-1;
			ret -= min( bit.sum(q[k])-1 , k-bit.sum(q[k]) );
		}
		else {
			if(q[k] < *x){
				ret += (*x-q[k]-1) - (bit.sum(q[k]+1)-bit.sum(*x));
				x --;
				y --;
			}
			else if(k == 2 || q[k] < *y){
				ret += (q[k]-*x-1) - (bit.sum(*x+1)-bit.sum(q[k]));
				y --;
			}
			else {
				ret += (q[k]-*x-1) - (bit.sum(*x+1)-bit.sum(q[k]));
			}
			ret += bit.sum(q[k])-1;
			ret -= min( bit.sum(q[k])-1 , k-bit.sum(q[k]) );
		}
		printf(" %lld",ret);
	}
	printf("\n");
}