#include<bits/stdc++.h>
using namespace std;
long long a,b,c,n,A[400100],B[400100],at,bt,ans1,ans2;
int main(){
	cin>>a>>b>>c>>n;
	for(long long i=1;i<=n;++i){
		long long x;string str;
		cin>>x>>str;
		if(str=="USB")A[++at]=x;
		else B[++bt]=x;
	}
	sort(A+1,A+at+1);
	sort(B+1,B+bt+1);
	long long p=1,q=1;
	while(p<=at&&a){ans1++;ans2+=A[p++];a--;}
	while(q<=bt&&b){ans1++;ans2+=B[q++];b--;}
	while((p<=at||q<=bt)&&c){
		ans1++,c--;
		if(q>bt)ans2+=A[p++];
		else if(p>at)ans2+=B[q++];
		else if(A[p]>B[q])ans2+=B[q++];
		else ans2+=A[p++];
	}
	cout<<ans1<<" "<<ans2;
}