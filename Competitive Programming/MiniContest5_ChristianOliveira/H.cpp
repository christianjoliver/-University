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

int dp[1001][1001];
ll isPalindrome(string &s, ll i, ll j) {
    
    if (i == j){
        dp[i][j] = 1;
        return 1;
    }
        
    if(i+1 == j){
        if(s[i] == s[j])
            return dp[i][j] = 2;
        else
            return dp[i][j] = 1;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = 2 + isPalindrome(s, i+1, j-1);

    else
        return dp[i][j] = max(isPalindrome(s, i, j-1), isPalindrome(s, i+1, j));
}

int main(){
    FASTIO;
    ll t;
    cin >> t;
    cin.ignore();
    for(ll i = 0; i < t; i++){
        string s;
        memset(dp, -1, sizeof(dp));
        getline(cin, s);
        cout << isPalindrome(s, 0, (ll)s.size()-1) << endl;
    }
    return 0;
}