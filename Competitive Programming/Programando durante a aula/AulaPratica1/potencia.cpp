#include <bits/stdc++.h>

using namespace std;

long long int m = 1000000007;


long long int expon(long long a, long long b){

    if(b==0) return 1;

    long long result = expon(a, b/2) ;

    if(b%2)
        return (result * result) % m * a % m;
    else
        return result * result % m;
}


int main(){

    int ent, a, b;

    cin >> ent;

    for(int i = 0; i<ent; i++){
        cin >> a >> b;
        cout << expon(a, b) << "\n";
    }
}