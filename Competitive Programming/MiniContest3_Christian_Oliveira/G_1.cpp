#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



vector<ll> coins;
vector<bool> used;
ll n;
ll val;

void solve(){

    vector<vector<bool>> subset(n+1, vector<bool>(val+1));
  
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
  
    for (int i = 1; i <= val; i++)
        subset[0][i] = false;
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= val; j++) {
            if (j < coins[i - 1]) 
                subset[i][j] = subset[i - 1][j];
            
            else
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - coins[i - 1]];
        }
    }
    
    if(subset[n][val]) cout << "S" << endl;
    else cout << "N" << endl;
}

int main() {
    FASTIO;

    cin >> val >> n;
    coins.resize(n);
    used.resize(n, true);
    for(int i = 0; i < n; i++) cin >> coins[i];
    
    solve();

    return 0;
}