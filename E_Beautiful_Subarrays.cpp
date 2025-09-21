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

struct Node{
    Node *nxt[2];
    ll cnt;
    Node(){
        cnt = 0;
        for(int i=0;i<2;i++) nxt[i] = NULL;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(ll x)
    {
        Node *curr = root;
        for(int i=31;i>=0;i--){
            ll idx = (x>>i)&1;
            if(curr->nxt[idx]==NULL) curr->nxt[idx] = new Node();

            curr = curr->nxt[idx];
            curr->cnt++;
        }
    }
    ll Query(ll pre,ll k)
    {
        Node *curr = root;
        ll ans = 0;
        for(int i=31;i>=0;i--)
        {
            if(!curr) break;

            ll pre_bit = (pre>>i)&1;
            ll k_bit = (k>>i)&1;
            if(k_bit){

                if(curr->nxt[pre_bit]) ans+=curr->nxt[pre_bit]->cnt;

                curr = curr->nxt[pre_bit^1];
            }
            else{
                curr = curr->nxt[pre_bit];
            }
        }
        return ans;
    }
};

void domain_expension()
{
    ll n,k;
    cin >> n >> k;

    Trie t;
    t.insert(0);
    ll ans = 0, xr = 0;
    ll total = n*(n+1)/2;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        xr = xr^x;
        ans+=t.Query(xr,k);
        t.insert(xr);
    }
    cout << total - ans <<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}