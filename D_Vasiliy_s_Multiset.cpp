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
    ll prefix_cnt, end;

    Node() {
        prefix_cnt = 0;
        end = 0;
        for (int i = 0; i < 2; i++) nxt[i] = NULL;
    }
};

struct Trie
{
    Node *root;
    Trie(){
        root = new Node();
    }

    void insert(const string &word)
    {
        Node *curr = root;
        for (auto ch : word)
        {
            ll idx = ch - '0';
            if (curr->nxt[idx] == NULL) curr->nxt[idx] = new Node();
            curr = curr->nxt[idx];
            curr->prefix_cnt++;
        }
        curr->end++;
    }
    ll search_Word(const string &word){
        Node *curr = root;
        ll ans = 0;
        ll p = word.size() - 1;
        for(auto ch : word){
            ll idx = ch - '0';
            ll need = idx ^ 1;

            if(curr->nxt[need]!=NULL && curr->nxt[need]->prefix_cnt>0){
                ans |= (1LL << p);
                curr = curr->nxt[need];
            }
            else curr = curr->nxt[1^need];
            p--;
        }
        return ans;
    }
    ll search_prefix(const string &word)
    {
        Node *curr = root;
        for(auto ch : word){
            ll idx = ch - 'a';
            if(!curr->nxt[idx]) return curr->prefix_cnt;
            curr = curr->nxt[idx];
        }
        return curr->prefix_cnt;
    }
    void erase(const string &word)
    {
        //if (!search_Word(word)) return;

        Node* cur = root;
        for (char c : word) {
            int idx = c - '0';
            cur = cur->nxt[idx];
            cur->prefix_cnt--;
        }
        cur->end--;
    }
    ll longest_prefix(const string &word)
    {
        Node *curr = root;
        ll len = 0;
        for(auto ch : word)
        {
            ll idx = ch - 'a';
            if(curr->nxt[idx]==NULL || curr->nxt[idx]->prefix_cnt == 0) break;
            curr = curr->nxt[idx];
            len++;
        }
        return len;
    }

};

void domain_expension()
{
    ll n;
    cin >> n;
    Trie t;
    const ll MX = 32;
    bitset<MX> bit(0);
    t.insert(bit.to_string());

    while(n--)
    {
        char ch;
        ll d;
        cin >> ch >> d;
        bitset<MX>bit1(d);
        string r = (bit1.to_string());
        if(ch=='+'){
            t.insert(r);
        }
        else if(ch=='-'){
            t.erase(r);
        }
        else{
            cout << t.search_Word(r) << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}