#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, v;
    set<long long> bal;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v;
        bal.insert(v);
    }
    cout << bal.size() << "\n";
    return 0;
}