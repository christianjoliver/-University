#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;

    cin >> n;

    vector<long long int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    n = 1;

    for(auto m: v){
        if(m > n) break;
        n+=m;
    }

    cout << n << "\n";
    return 0;
}