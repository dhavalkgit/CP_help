#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26];
    bool flag;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
        flag = false;  // Initially not the end of any word
    }
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void putKey(char ch, Node *node){
        links[ch-'a']=node;
    }

    Node* getNext(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node();
        }

        void insert(string s){
            Node* node = root;
            for(int i=0;i<s.length();i++){
                if(!node->containsKey(s[i])){
                    node->putKey(s[i], new Node);
                }
                node=node->getNext(s[i]);
            }
            node->flag=true;
        }

        bool searchWord(string s){
            Node* node = root;

            for(int i=0;i<s.length();i++){
                if(node->containsKey(s[i])){
                    node=node->getNext(s[i]);
                }
                else{
                    return false;
                }
            }

            return node->flag;
        }

        bool prefixExist(string s){
            Node* node = root;

            for(int i=0;i<s.length();i++){
                if(node->containsKey(s[i])){
                    node=node->getNext(s[i]);
                }
                else{
                    return false;
                }
            }

            return node->flag==false;
        }
};
int main()
{
    Trie trie ;
    trie.insert("hello");
    trie.insert("helloword");
    if(trie.prefixExist("hell")){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}