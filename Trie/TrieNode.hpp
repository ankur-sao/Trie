//
//  TrieNode.hpp
//  Trie
//
//  Created by ansao on 2/25/19.
//  Copyright © 2019 ansao. All rights reserved.
//

#ifndef TrieNode_hpp
#define TrieNode_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class TrieNode
{
private:
    
    vector<TrieNode*> links;
    const int R = 26;
    bool isEnd = false;
    
public:
    TrieNode()
    {
        links.resize(26,NULL);
        isEnd = false;
    }
    
    bool containsKey(char ch)
    {
        return links[ch -'a'];
    }
    
    TrieNode* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void put(char ch)
    {
        TrieNode *node =  new TrieNode();
        links[ch-'a'] = node;
    }
    
    void setEnd(){isEnd = true;}
    bool isEndNode(){return isEnd;}
    int totalLinks()
    {
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if (NULL != links[i]) ans++;
        }
        return ans;
    }
    
    int fromNode()
    {
        int ans = 0;
        if (isEnd) ans=1;
        for(int i=0;i<26;i++)
        {
            if (links[i]!=NULL)
            {    ans+=links[i]->fromNode();
                
            }
        }
        return ans;
    }
    
};
#endif /* TrieNode_hpp */
