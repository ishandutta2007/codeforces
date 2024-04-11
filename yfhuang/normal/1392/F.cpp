#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

const int maxn = 1e6 + 5;
ll h[maxn];
ll a[maxn];

int st[maxn];
int top;
ll de[maxn];

int main(){
    int n;
    n = read_int();
    for(int i = 1;i <= n;i++){
        h[i] = read_int();
    }
    top = 0;
    a[1] = h[1];
    for(int i = 2;i <= n;i++){
        ll delta = h[i] - (a[i - 1] + 1); 
        a[i] = a[i - 1] + 1;
        //cout << i << " " << a[i] << " " << top << endl;
        while(top > 0){
            int pos = st[top--];
            //cout << "!!!" << i << " " << pos << endl;
            if(delta >= i - pos + 1){
                delta -= i - pos + 1;
                a[i]++;
            }else{
                st[++top] = pos + delta;
                delta = 0;
                break;
            } 
        }
        a[i] += delta / i;
        if(delta % i > 0){
            st[++top] = delta % i + 1;
        }
    }
    //for(int i = 1;i <= n;i++){
    //    cout << a[i] << " ";
    //}
    //cout << endl;
    for(int i = 1;i < n;i++){
        de[i] = 1;
    }   
    while(top > 0){
        int pos = st[top--];
        de[pos - 1] = 0;
    }
    h[n] = a[n];
    for(int i = n - 1;i >= 1;i--){
        h[i] = h[i + 1] - de[i];
    }
    for(int i = 1;i <= n;i++){
        printf("%lld%c", h[i], i == n ? '\n' : ' ');
    }
    return 0;
}