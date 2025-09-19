#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    string txt,pattern;
    cin >> txt >> pattern;
    string s = pattern+"#"+txt;

    ll n = s.size();
    ll m = pattern.size();
    vector<ll>pi(n+1);
    
    for(int i=1;i<n;i++){
        ll j = pi[i-1];

        while(j>0 && s[i]!=s[j]) j = pi[j-1];

        if(s[i]==s[j]) j++;

        pi[i] = j;
    }
    vector<ll>ans(n+1,0);

    for(int i=0;i<n;i++) ans[pi[i]]++;
    for (int i = n-1; i > 0; i--) ans[pi[i-1]] += ans[i];

    cout << ans[m] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}