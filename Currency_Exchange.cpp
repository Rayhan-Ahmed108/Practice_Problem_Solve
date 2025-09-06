#include<bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie *child[26];
    bool wordend;
    Trie()
    {
        wordend = false;
        for(int i = 0; i < 26; i++)
        child[i] = nullptr;
    }
    ~Trie() {for(int i = 0; i < 26; i++)
              if (child[i]) delete child[i]; }
};
void Trinsert(Trie *root, string &key)
{
    Trie *curr = root;
    for (auto ch : key)
    {
        if (!curr->child[ch - 'a'])
            curr->child[ch - 'a'] = new Trie();
        curr = curr->child[ch - 'a'];
    }
    curr->wordend = true;
}
bool Triesearch(Trie *root, string &st)
{
    if (!root)
        return false;
    Trie *cur = root;
    for (auto &ch : st)
    {
        if (!cur->child[ch - 'a'])
            return false;
        cur = cur->child[ch - 'a'];
    }
    return cur->wordend;
}
int main() {

}