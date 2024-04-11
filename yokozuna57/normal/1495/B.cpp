#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
int p[100010];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	
	int ret=0;
	
	int MAX=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(i>=2&&p[i-1]<p[i])continue;
		if(i<=n-1&&p[i+1]<p[i])continue;
		int k=0;
		while(i-k-1>=1&&p[i-k-1]>p[i-k])k++;
		int l=0;
		while(i+l+1<=n&&p[i+l+1]>p[i+l])l++;
		if(MAX<k){
			MAX=k;
			cnt=1;
		}
		else if(MAX==k)cnt++;
		if(MAX<l){
			MAX=l;
			cnt=1;
		}
		else if(MAX==l)cnt++;
	}
	if(cnt>=3){
		puts("0");
		return 0;
	}
	
	for(int i=2;i<=n-1;i++){
		if(p[i-1]>p[i]||p[i]<p[i+1])continue;
		int k=0;
		while(i-k-1>=1&&p[i-k-1]<p[i-k])k++;
		int l=0;
		while(i+l+1<=n&&p[i+l+1]<p[i+l])l++;
		if(k==l&&k%2==0&&k==MAX)ret++;
	}
	cout<<ret<<endl;
}