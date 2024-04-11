#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int MAX_N = 100003;
const int MAX_P = 3;
LL a[MAX_N];
LL p[MAX_P];
LL c[MAX_N];
LL num[MAX_P];
vector<LL> primes;

LL to_int(string s) {
	LL ret=0;
	int len=s.size();
	bool check=false;
	for (int x=0;len>x;x++) {
		if (s[x]=='-') check=true;
		else {
			ret*=10;
			ret+=(s[x]-'0');
		}
	}
	if (check) ret = -ret;
	return ret;
}

void build_p() {
	p[0]=1e9+7;
	p[1]=1e9+9;
	memset(c,-1,sizeof(c));
	for (LL x=2;MAX_N>x;x++) {
		if (c[x]==-1) {
			primes.push_back(x);
			for (LL i=x;i*x<MAX_N;i++) {
				c[i*x]=1;
			}
		}
//		cout<<"x="<<x<<endl;
	}
	int len=primes.size();
	int che[len];
	memset(che,0,sizeof(che));
	int cnt=2;
	while (cnt<MAX_P) {
		while (true) {
			int x=rand()%len;
			if (che[x]==0) {
				che[x]=1;
				p[cnt++]=primes[x];
				break;
			}
		}
	}
}

LL fast_pow(LL a,LL n,LL p) {
	LL ret=1;
	LL tmp[30];
	tmp[0]=a%p;
	for (int x=1;30>x;x++) {
		tmp[x]=tmp[x-1]*tmp[x-1];
		tmp[x]%=p;
	}
	for (int x=0;30>x;x++) {
		if ((n|(LL(1<<x))) == n) {
			ret*=tmp[x];
			ret%=p;
		}
	}
	if (n==0) return 1;
	else if (a==0) return 0;
	else return ret;
}

int main () {
	//ios::sync_with_stdio(0);cin.tie(0);
	srand(time(NULL));
	int n,k;
//	build_p();
//	for (int x=0;11>x;x++) cout<<p[x]<<endl;
	while (cin >> n >> k) {
		int cnt=0;
		string t;
		for (int x=0;n>=x;x++) {
			string s;
			cin >> s;
			if (s=="?") cnt++;
			if (cnt==0) a[x]=to_int(s);
//			cout<<"a["<<x<<"] = "<<a[x]<<endl;
//			cout<<"cnt="<<cnt<<endl;
			if (x==0) t=s;
		}
		if (cnt!=0) {
			if (k==0) {
				if (t!="0" && t!="?") {
					puts("No");
				}
				else if (t=="0") puts("Yes");
				else if ((n+1-cnt)%2==1) puts("Yes");
				else puts("No");
			}
			else if (n%2==1) puts("Yes");
			else puts("No");
		}
		else {
			build_p();
			memset(num,0,sizeof(num));
			for (int x=0;n>=x;x++) {
//				cout<<"x="<<x<<endl;
				for (int i=0;MAX_P>i;i++) {
					LL tmp;
					if (a[x]<0) {
						tmp=a[x] + p[i]*(-a[x]) ;
						tmp%=p[i];
					}
					else {
						tmp=a[x]%p[i];
					}
//					cout<<"tmp="<<tmp<<endl;
//					cout<<tmp*fast_pow(k,x,p[i])<<endl;
					num[i] += (tmp*fast_pow(k,x,p[i])) % p[i];
					num[i] %= p[i];
//					cout<<"num["<<i<<"] = "<<num[i]<<endl;
				}
			}
			string ans="Yes";
			int cnt=0;
			for (int x=0;MAX_P>x;x++) {
				if (num[x]%p[x]!=0)  {
					ans="No";
				}
			}
			if (k==0 && a[0]==0) ans="Yes";
			else if (k==0 && a[0]!=0) ans="No";
			cout<<ans<<endl;
		}
	}
}