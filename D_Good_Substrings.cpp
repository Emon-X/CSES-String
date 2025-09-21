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
ll ans ;

struct Node{
    Node *nxt[26];
    ll prefix_cnt, end;

    Node() {
        prefix_cnt = 0;
        end = 0;
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

struct Trie
{
    Node *root;
    Trie(){
        root = new Node();
    }
};

void domain_expension()
{
    string s,bit;
    cin >> s >> bit;
    ll k;
    cin >> k;
    vector<ll>freq(26,0);
    for(int i=0;i<26;i++) if(bit[i]=='0') freq[i]++;

    ans = 0;
    Trie t;
    for(int i=0;i<s.size();i++)
    {
        Node *curr = t.root;
        ll bad = 0;
        for(int j=i;j<s.size();j++)
        {
            ll idx = s[j] - 'a';
            bad +=freq[idx];
            if(bad>k) break;

            if(curr->nxt[idx]==NULL){
                curr->nxt[idx] = new Node();
                ans++;
            }
            curr = curr->nxt[idx];
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}