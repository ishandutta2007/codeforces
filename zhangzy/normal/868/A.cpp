#include<bits/stdc++.h>
using namespace std;

string s,ss[110];
int n;

int main(){
	cin>>s;cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ss[i];
		if (ss[i]==s){
			return 0*printf("YES");
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (s[0]==ss[i][1]&&s[1]==ss[j][0]){
				return 0*printf("YES");
			}
		}
	}
	printf("NO");
}