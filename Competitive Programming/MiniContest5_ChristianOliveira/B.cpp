#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
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
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool inLine(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    if(x2 <= max(x1, x3) && (x2 >= min(x1, x3))
    && (y2 <= max(y1, y3) && (y2 >= min(y1, y3))))
        return true;
    return false;
}

int direction(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll res = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    if(res > 0) return 1;

    else if(res < 0) return 2;

    else return 0;
}

bool intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){

    int dir1 = direction(x1, y1, x2, y2, x3, y3);
    int dir2 = direction(x1, y1, x2, y2, x4, y4);
    int dir3 = direction(x3, y3, x4, y4, x1, y1);
    int dir4 = direction(x3, y3, x4, y4, x2, y2);

    if((dir1 != dir2) && (dir3 != dir4)) return true;

    if((dir1 == 0) && inLine(x1, y1, x3, y3, x2, y2))
        return true;
    if((dir2 == 0) && inLine(x1, y1, x4, y4, x2, y2))
        return true;
    if((dir3 == 0) && inLine(x3, y3, x1, y1, x4, y4))
        return true;
    if((dir4 == 0) && inLine(x3, y3, x2, y2, x4, y4))
        return true;
    return false;
}

int main(){
    FASTIO;

    ll t, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> t;

    for(ll i = 0; i < t; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(intersect(x1, y1, x2, y2, x3, y3, x4, y4)) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }


    return 0;
}