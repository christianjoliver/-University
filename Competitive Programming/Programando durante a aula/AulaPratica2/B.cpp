#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;


int main(){
    int n, m, i, j, c,nota;

    cin >> n;

    for(i=0; i<n; i++){
        cin >> m;
        vpi v(m);
        c=0;
        for(j=0; j<m; j++){
            cin >> nota;
            v[j] = make_pair(nota, j);
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        for(j=0; j<m; j++)
            if(v[j].second==j) c++;

        cout << c << "\n";
    }

}