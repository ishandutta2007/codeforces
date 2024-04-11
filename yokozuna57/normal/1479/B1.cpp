#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
int a[100010];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	int ret=0;
	int pre=0;
	int cnt=0;
	bool ok=false;
	for(int i=0;i<n;i++){
		if(i>0&&a[i]==a[i-1]){
			cnt++;
		}
		else cnt=1;
		if(cnt>=3)continue;
		if(cnt==2){
			if(pre!=a[i]){
				ret++;
			}
			else {
				if(ok)ret++;
			}
			pre=a[i];
			ok=false;
		}
		else {
			ret++;
			if(i>0&&a[i]!=pre&&a[i-1]!=pre)ok=true;
		}
	}
	cout<<ret<<endl;
}