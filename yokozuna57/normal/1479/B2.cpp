#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
int a[100010];

int q[100010];
int nex[100010];
int d[100010];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	vector<int> b;
	int pre=0;
	for(int i=0;i<n;i++){
		if(a[i]!=pre)b.push_back(a[i]);
		pre=a[i];
	}
	n=b.size();
	for(int i=0;i<n;i++)a[i]=b[i];
	
	for(int i=1;i<=n;i++)q[i]=-1;
	for(int i=0;i<n;i++)nex[i]=-1;
	for(int i=0;i<n;i++){
		if(q[a[i]]!=-1){
			nex[q[a[i]]+1]=i;
		}
		q[a[i]]=i;
	}
	d[0]=0;
	for(int i=0;i<n;i++){
		if(nex[i]!=-1){
			d[nex[i]]=max(d[nex[i]],d[i]+1);
		}
		d[i+1]=max(d[i+1],d[i]);
	}
	cout<<n-d[n]<<endl;
}