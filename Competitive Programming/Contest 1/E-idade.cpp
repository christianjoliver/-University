#include <bits/stdc++.h>

using namespace std;

int main(){
    long long m;
    valarray<long long> f = {0, 0, 0};

    cin >> m >> f[0] >> f[1];
    f[2] = m-f[0]-f[1];

    cout << f.max() << "\n";
    return 0;
}