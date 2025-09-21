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
    Node *nxt[26];
    ll prefix_cnt, end;
    Node()
    {
        prefix_cnt = 0;
        end = 0;
        for (int i = 0; i < 26; i++)
            nxt[i] = NULL;
    }
};

struct Trie
{
    Node *root;
    vector<multiset<ll>> depth;
    ll sz = 1e5 + 4;
    Trie()
    {
        root = new Node();
        depth.resize(sz);
    }
    void insert(const string &s)
    {
        Node *curr = root;
        ll d = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ll idx = s[i] - 'a';

            if (curr->nxt[idx] == NULL)
                curr->nxt[idx] = new Node();

            curr = curr->nxt[idx];

            if(curr->prefix_cnt){
                depth[d].erase(depth[d].find(curr->prefix_cnt));
            }
            curr->prefix_cnt++;
            depth[d].insert(curr->prefix_cnt);
            d++;
        }
        curr->end++;
    }
    bool common_prefix(ll k, ll L)
    {
        if(L>=depth.size()) return false;

        return (!depth[L].empty() && *depth[L].rbegin()>=k);
    }

    void erase(const string &s)
    {
        Node *curr = root;
        ll d = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            curr = curr->nxt[s[i] - 'a'];
            depth[d].erase(depth[d].find(curr->prefix_cnt));
    
            curr->prefix_cnt--;
            if(curr->prefix_cnt)
            depth[d].insert(curr->prefix_cnt);
            d++;
        }
        curr->end--;
    }
};

void domain_expension()
{
    ll n;
    cin >> n;
    map<ll, string> mp;
    Trie t;
    for (int i = 0; i < n; i++)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            string s;
            cin >> s;
            mp[i + 1] = s;
            t.insert(s);
        }
        else if (type == 2)
        {
            ll k, l;
            cin >> k >> l;
            if (t.common_prefix(k, l))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            ll idx;
            cin >> idx;
            if (mp.count(idx))
            {
                t.erase(mp[idx]);
                mp.erase(idx);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}