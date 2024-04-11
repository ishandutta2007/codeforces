#include <bits/stdc++.h>
using namespace std;

bool ask(const vector <int>& v){
    cout << "? " << v.size();
    for(int x : v)
        cout << ' ' << x;
    cout << endl;

    string response;
    cin >> response;

    if(response[0] == 'Y')return true;
    else return false;
}

bool guess(int x){
    cout << "! " << x << endl;

    string response;
    cin >> response;

    if(response[1] == ')')return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> v(n);
    iota(v.begin(), v.end(), 1);

    while((int)v.size() >= 4){
        int len = (int)v.size() / 4;

        vector <int> v1, v2;
        for(int i = 0; i < (int)v.size(); i++){
            int index = min(i / len, 3);
            if(index & 1)v1.push_back(v[i]);
            if(index & 2)v2.push_back(v[i]);
        }

        int r1 = !ask(v1);
        int r2 = !ask(v2);
        
        vector <int> nv;
        for(int i = 0; i < (int)v.size(); i++){
            int index = min(i / len, 3);
            if(index != (r1 | (r2 << 1))){
                nv.push_back(v[i]);
            }
        }
        swap(v, nv);
    }

    if((int)v.size() == 3){
        if(ask({v[0]})){
            if(!guess(v[0])){
                if(ask({v[1]})){
                    guess(v[1]);
                }else{
                    guess(v[2]);
                }
            }
        }else{
            if(ask({v[0]})){
                if(!guess(v[0])){
                    if(ask({v[1]})){
                        guess(v[1]);
                    }else{
                        guess(v[2]);
                    }
                }
            }else{
                if(!guess(v[1])){
                    guess(v[2]);
                }
            }
        }
    }else if((int)v.size() == 2){
        if(!guess(v[0])){
            guess(v[1]);
        }
    }else{
        guess(v[0]);
    }

    return 0;
}