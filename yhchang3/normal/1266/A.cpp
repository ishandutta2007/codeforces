#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int cnt=0,cnt2=0,cnt0=0;
		for(int i=0;i<s.size();i++){
			int x=s[i]-'0';
			cnt+=x;
			if(x%2==0)
				cnt2++;
			if(x==0)
				cnt0++;
		}
		if(cnt==0||((cnt%3==0)&&cnt0&&(cnt2>=2)))
			cout<<"red\n";
		else
			cout<<"cyan\n";
	}
}