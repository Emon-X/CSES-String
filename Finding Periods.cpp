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
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll>z(n+1);

    ll l = 0, r = 0;
    for(int i=1;i<n;i++){
        if(i<r) z[i] = min(r-i,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;

        if(i+z[i]>r){
            l = i;
            r = i + z[i];
        }
    }
    //for(auto u:pi) cout << u << " ";cout << endl;
    for(int i=0;i<n;i++){
        if(i+z[i]==n) cout << i << " ";
    }
    cout << n << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}