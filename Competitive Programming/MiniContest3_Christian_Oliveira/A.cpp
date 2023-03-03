#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll solve(vpll atv, ll n){
    ll i, count = 0, t = 0;
    for(i = 0; i < n; i++)
        if(atv[i].S >= t) {count++; t = atv[i].F;}
    return count;
}

int main() {
    FASTIO;
	ll i, n, a, b;
    vpll atv;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a >> b;
        atv.PB(MP(b, a));
    }
    sort(all(atv));
    cout << solve(atv, n) << "\n"; 
	return 0;
}