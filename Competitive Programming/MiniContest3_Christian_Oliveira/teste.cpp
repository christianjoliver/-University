#include "bits/stdc++.h"
using namespace std;

unsigned long long divisores(long long n) {
    unsigned long long ans;
    for(unsigned long long a = 1*1600; a*a <= n; a++) { //
        if(n % a == 0) {
            unsigned long long b = n / a;
            ans++;
            if(a != b) ans++;
        }
    }
    return ans; //
}

int main()
{
    cout << divisores(2147483648);
    return 0;
}