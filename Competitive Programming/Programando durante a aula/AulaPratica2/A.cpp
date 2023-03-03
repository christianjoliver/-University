#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;




int main() {
    ll X, N, y;
    int i, c=0, s=0;
    vi v;
    cin >> N >> X;

    FOR(i, 0, N){
        cin >> y;
        v.push_back(y);
    }

    sort(all(v));

    for(i=0; i<N; i++){
        s+=v[i];
        if(s>X) break;
        else c++;
    }

    cout << c;
    return 0;
}
