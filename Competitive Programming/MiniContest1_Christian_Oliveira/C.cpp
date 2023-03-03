#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001;

vector<bool> crivo(){
    long long int n = MAX;
    long long int i, j;

    vector<bool> v(n+1, true);

    v[0] = false;
    v[1] = false;
    for(i = 2; i < n; i++){

        if(v[i] && i * i <=n){
            for(j = i * i; j <= n; j+=i)
                v[j] = false;
        }
    }
    return v;
}


void verSoma(vector<bool> v, long long int n){
    long long int a = 3, b = 0, i;

    while((a + b) != n){

        if(v[n-a]){
            b = n - a;
            break;
        }

        for(i = a+1; v[i]!=1; i++);

        a = i;
    }

    cout << n << " = " << a << " + " << b << "\n";
}

int main(){
    vector<bool> v;

    v = crivo();
    long long int n;

    cin >> n;
    while(n!=0){
        verSoma(v, n);
        cin >> n;
    }
    return 0;
}