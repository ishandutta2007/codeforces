#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int r;
	int cnt_ = 0;
	for(int i = s.size()-1; i>= 0 ; i--){
		if(s[i] == '#'){
			r = i;
			break;
		}
		if(s[i] == ')'){
			cnt_++;
		}
		if(s[i] == '('){
			cnt_--;
			if(cnt_ < 0){
				puts("-1");
				return 0;
			}
		}
	}

	vector<int> ans;
	int cnt = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '(')cnt++;
		else if(s[i] == ')'){
			cnt--;
			if(cnt < 0){
				puts("-1");
				return 0;
			}
		}
		else {
			if(i != r){
				ans.push_back(1);
				cnt--;
				if(cnt < 0){
					puts("-1");
					return 0;
				}
			}
			else{
				if(cnt - cnt_ <= 0){
					puts("-1");
					return 0;
				}
				ans.push_back(cnt - cnt_);
			}
		}
	}

	for(int i = 0 ; i < ans.size() ; i++){
		printf("%d\n",ans[i]);
	}
}