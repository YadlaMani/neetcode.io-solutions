class TrieNode{//TrieNode initilization
    public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isEnd=false;
    }
};
class WordDictionary {
public:
    TrieNode* root;//Root node
    WordDictionary() {
        root=new TrieNode();//initialization
    }
    
    void addWord(string word) {
        TrieNode* curr=root;//Starting the traversal from the rootNode
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';//getting the index
            if(!curr->child[idx]) curr->child[idx]=new TrieNode();//if there is not value at that index add the new Node
            curr=curr->child[idx];//else continuing the traversal
        }
        curr->isEnd=true;//make the last node pointer end as true siginifying the end of the word
        
    }
    
    bool search(string word) {
        return helper(root,word);//calling the helper
    }
    bool helper(TrieNode* node,string word){
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch=='.'){//if the character is '.' seraching all the words from there where is the child node is not null
                for(auto chi:node->child){
                    if(chi && helper(chi,word.substr(i+1))){
                        return true;
                    }
                }
                return false;
            }
            int idx=word[i]-'a';//else checking the word
            if(!node->child[idx]) return false;//if the we reached null before traversing the whole word return null
            node=node->child[idx];
        }//if we traversed the whole word and reached the end of a valid word return true
        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
