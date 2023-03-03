#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, i, j, k, n, x, s;

    vector<int> v;

    cin >> n;

    for(k=0; k<n; k++){
        cin >> x;
        v.push_back(x);
    }

    cin >> x;

    i = 0;
    j = v.size()-1;

    while(true){
        s = v[i] + v[j];
        if(s == x) break;
        else if(s > x) j--;
        else i++;
    }

    cout << v[i] << " " << v[j] << "\n";

    return 0;
}