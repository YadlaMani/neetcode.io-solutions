class TrieNode{
    public:
        TrieNode *child[26];//26 sized pointer array for lower case alphabet
        bool isEnd;//to indicate the end of the words
        TrieNode(){//initialization
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
            isEnd=false;
        }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
        
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';//calculating the index
            if(!curr->child[idx]) curr->child[idx]=new TrieNode();//checking if the index is full if yeas adding the new trieNode to the index
            curr=curr->child[idx];//traversal
        }
        curr->isEnd=true;//at the end of the word making the end true
    }
    
    bool search(string word,bool prefix=false) {
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';//caculating the index
            if(!curr->child[idx]) return  false;//if the idx is null then the word is not presnt in the tree
            curr=curr->child[idx];
        }
        if(prefix) return true;//if prefix search the word doesn't need to be ended
        return curr->isEnd;//if not the word should have a end
        
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
