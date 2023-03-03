#include <bits/stdc++.h>


using namespace std;


int main(){
    long long n, i, x, y, soma = 0, cred = 0;

    vector<pair<int, int>> v;
    cin >> n;

    for(i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    for(auto i:v){
        soma += i.first;
        cred += i.second - soma;
    }

    cout << cred << "\n";

    return 0;
}