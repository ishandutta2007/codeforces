#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;

using ll=long long;
using ld =long double;

#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}


map<string,int>say(int l,int r){
    cout<<"? "<<l+1<<' '<<r<<endl;
    int cnt=(r-l+1)*(r-l)/2;
    string sts;
    map<string,int>mp;
    for(int i=0;i<cnt;++i){
        string st;cin>>st;
        sort(st.begin(),st.end());
        mp[st]++;
    }
    return mp;
}

string solve(int N){
    map<string,int>all_sts=say(0,N);
    if(N==1){
        cout<<"! "<<all_sts.begin()->first<<endl;
        return 0;
    }
    map<string,int>one_sts=say(1,N);

    for(auto os:one_sts){
        auto it=all_sts.find(os.first);
        it->second-=os.second;
        if(it->second==0){
            all_sts.erase(it);
        }
    }
    

    vector<string>lefts(N+1);
    for(auto as:all_sts){
        lefts[as.first.size()]=as.first;
        assert(as.second==1);
    
    }
    string answer;
    //WHATS(lefts)
    for(int i=0;i<N;++i){
        string k=lefts[i+1];
        for(auto c:lefts[i]){
           // WHATS(k)
           // WHATS(k.find(c))
            k.erase(k.find(c),1);
        }
        answer.push_back(k[0]);
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int N;cin>>N;
    if(N<=3){
        string ans_st;
        for(int x=0;x<N;++x){
            cout<<"? "<<x+1<<' '<<x+1<<endl;
            char ch;
            cin>>ch;
            ans_st.push_back(ch);
        }
        cout<<"! "<<ans_st<<endl;
        return 0;
    }
    auto mp=say(0,N);

    vector<int>minuss(26);
    vector<vector<int>>sums(N+1,vector<int>(26));
    for(auto m:mp){
        for(auto c:m.first){
            sums[m.first.size()][c-'a']+=m.second;
        }
    }
    vector<pair<int,int>>pairs;
    vector<int>totals(26);
    totals=sums[N];
    vector<vector<int>>nums(N/2+1,vector<int>(26));
    nums[0]=totals;
    for(int i=1;i<=N/2;++i){
        for(int j=0;j<26;++j){
            nums[i][j]=sums[N-i][j]-sums[N-i+1][j];
        }
    }
    //WHATS(nums)
    for(int i=1;i<=N/2;++i){
        vector<int>v;
        for(int j=0;j<26;++j){
            int rest=nums[i-1][j]-nums[i][j];
            for(int k=0;k<rest;++k){
                v.push_back(j);
            }
        }
        
        assert(v.size()==2);
        {
            pairs.push_back(make_pair(v[0],v[1]));
        }
    }
   // WHATS(pairs)
    string l_st=solve(N/2);
    //WHATS(l_st)
    string answer(N,'X');
    for(int i=0;i<l_st.size();++i){
        answer[i]=l_st[i];
        if(l_st[i]=='a'+pairs[i].first){
            answer[N-i-1]='a'+pairs[i].second;
        }else{
            answer[N-i-1]='a'+pairs[i].first;
        }
    }
    if(N%2){
        for(auto p:pairs){
            totals[p.first]--;
            totals[p.second]--;
        }
        answer[N/2]='a'+(find(totals.begin(),totals.end(),1)-totals.begin());
    }
    cout<<"! "<<answer<<endl;
    return 0;
}