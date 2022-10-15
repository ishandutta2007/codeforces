#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct T{
    int d;
    T *zero, *one;
    bool b;
    T(int dd):d(dd){b=false;zero=nullptr;one=nullptr;}
    void add(int x){
        b=true;
        if (d==-1){
            return;
        }
        int tone=false;
        if (x&(1<<d))
            tone=true;
        if (one == nullptr && tone)
            one = new T(d-1);
        if (zero == nullptr && !tone)
            zero = new T(d-1);
        if (tone)
            one->add(x);
        else 
            zero->add(x);
    }
    bool check(int x, int md){
        if(d < md)
            return b;
        if (x & (1<<d)){
            if (one == nullptr)
                return false;
            return one->check(x, md);
        } else {
            if (zero == nullptr)
                return false;
            return zero->check(x, md);
        }
    }

    int ans(){
        if (one != nullptr && zero != nullptr){
            return 1 + max(one->ans(), zero->ans());
        }
        if (zero != nullptr)
            return zero -> ans();
        else if (one != nullptr)
            return one->ans();
        return b;
    }
};

void solve(int test_ind){
    int n;
    cin >> n;
    vector<int> a(n);
    T t(30);
    for(int i=0;i<n;++i){
        scanf("%d", &a[i]);
        t.add(a[i]);
    }
    cout << n - t.ans() << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}