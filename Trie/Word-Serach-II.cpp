//TireNode intialization
class TrieNode{
    public: 
    TrieNode* child[26];//all lower case letters
    bool isEnd;
    
        TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isEnd=false;//specifying the word end
    }
};
class Trie{//Tire intialization
    public:
    TrieNode * root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){//inserting a word into the trie
        TrieNode *node=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';//caculating index
            if(!node->child[idx]) node->child[idx]=new TrieNode();//if the index is null add new TrieNode()
            node=node->child[idx];//move to the next child
        }
        node->isEnd=true;//mark the end of the word
        

    }
};
class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tri;
        for(auto str:words){
            tri.insert(str);//insert all the words to the trie
        }
        set<string>ans;//taking set becaue we may encounter duplicates
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){//traversing from every position of the board
                dfs(board,vis,tri.root,i,j,"",ans);
            }
        }
        return vector<string>(ans.begin(),ans.end());//making the set vector
    }
    void dfs(vector<vector<char>>&board,vector<vector<bool>>&vis,TrieNode* node,int i,int j,string currWord,set<string>&res){
        int n=board.size();
        int m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]){//boundary cases
            return;
        }
        char ch=board[i][j];//calculating the index
        if(!node->child[ch-'a']){//if no word is present reutrn
            return;
        }
        node=node->child[ch-'a'];//pointing to the next child
        currWord+=ch;//add it to the current word
        if(node->isEnd) res.insert(currWord);//if that word is the end of the word add it to the set
        vis[i][j]=true;//make it visited
        dfs(board,vis,node,i-1,j,currWord,res);//make a dfs search
        dfs(board,vis,node,i+1,j,currWord,res);
         dfs(board,vis,node,i,j-1,currWord,res);
          dfs(board,vis,node,i,j+1,currWord,res);
          vis[i][j]=false;//make it unvisited

    }
};
