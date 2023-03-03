#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
    FASTIO;

    multiset<long long> ticket;
    long long m, n, h, i;

    cin >> n >> m;

    for(i = 0; i < n; i++){
        cin >> h;
        ticket.insert(h);
    }

    for(i = 0; i < m; i++){
        cin >> h;

        if(ticket.size()>0){
            auto x = ticket.lower_bound(h);
            if(h != *x) x--;

            if(x != ticket.end() && h >= *x){
                cout << *x << "\n";
                ticket.erase(x);
            }
            else cout << "-1" << "\n";
        }
        else cout << "-1" << "\n";
    }
    return 0;
}