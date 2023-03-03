#include <bits/stdc++.h>

#define MAX 1299710;

using namespace std;

vector<long long int> crivo(){
    long long int n = MAX;
    long long int i, j;

    vector<bool> v(n+1, true);
    vector<long long int> x;

    v[0] = false;
    v[1] = false;
    for(i = 2; i < n; i++){
        if(v[i]) x.push_back(i);
        if(v[i] && i * i <=n){

            for(j = i * i; j <= n; j+=i)
                v[j] = false;
        }
    }
    return x;
}

int main(){

    int k, ub, lb;

    vector<long long int> v = crivo();

    cin >> k;

    while(k!=0){

        lb = lower_bound(v.begin(), v.end(), k) - v.begin() - 1;

        if(v[lb+1]==k) cout << 0 << "\n";

        else cout << (v[lb+1] - v[lb]) << "\n";

        cin >> k;
    }
    return 0;
}