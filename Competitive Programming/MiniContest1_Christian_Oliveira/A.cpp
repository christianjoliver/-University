#include <bits/stdc++.h>

using namespace std;

bool verSoma(long long int x, long long int y){

    int s10 = 0,  s12 = 0, s16 = 0, ini = x;

    while(1){
        if(ini<10){
            s10 += ini;
            break;
        }
        s10 += ini%10;
        ini = ini/10;
    }

    ini = x;

    while(1){
        if(ini<12){
            s12 += ini;
            break;
        }
        s12 += ini%12;
        ini = ini/12;
    }

    ini = x;

    if(s10 != s12) return 0;

    while(1){
        if(ini<16){
            s16 += ini;
            break;
        }
        s16 += ini%16;
        ini = ini/16;
    }

    if(s12 != s16) return 0;

    return 1;
}

int main(){

    long int x, y;

    cin >> x >> y;

    for(long int i = x; i <= y; i++)
        if(verSoma(i, y)) cout << i << "\n";


    return 0;
}