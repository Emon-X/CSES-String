#include <bits/stdc++.h>
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

struct Node
{
    Node *nxt[2];
    ll prefix_cnt, end;
    Node()
    {
        prefix_cnt = 0;
        end = 0;
        for (int i = 0; i < 2; i++)
            nxt[i] = NULL;
    }
};

struct Trie
{
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(ll x)
    {
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            ll idx = (x >> i) & 1;

            if (curr->nxt[idx] == NULL)
                curr->nxt[idx] = new Node();

            curr = curr->nxt[idx];
            curr->prefix_cnt++;
        }
        curr->end++;
    }
    ll Query(ll pre, ll k)
    {
        Node *curr = root;
        ll ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (!curr)
                break;
            ll preBit = (pre >> i) & 1;
            ll kBit = (k >> i) & 1;
            if (kBit)
            {
                if (curr->nxt[preBit])
                    ans += curr->nxt[preBit]->prefix_cnt;
                curr = curr->nxt[preBit ^ 1];
            }
            else
            {
                curr = curr->nxt[preBit];
            }
        }
        return ans;
    }
};

void domain_expension()
{
    Trie t;
    ll n, k;
    cin >> n >> k;
    ll prefix = 0;
    ll ans = 0;
    t.insert(0);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        prefix ^= x;
        ans += t.Query(prefix, k);

        t.insert(prefix);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        domain_expension();
    return 0;
}