//
//  Trie.hpp
//  Trie
//
//  Created by ansao on 2/25/19.
//  Copyright © 2019 ansao. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "TrieNode.hpp"

using namespace std;

class trie
{
private:
    TrieNode *root;
public:
    trie()
    {
        root = new TrieNode();
    }
    
    void insert(string A)
    {
        TrieNode *node = root;
        for(int i =0;i<A.size();i++)
        {
            if (!node->containsKey(A[i]))
            {
                node->put(A[i]);
            }
            node = node->get(A[i]);
        }
        node->setEnd();
    }
    
    TrieNode* searchPrefix(string A)
    {
        TrieNode *node = root;
        for(int i=0;i<A.size();i++)
        {
            if (node->containsKey(A[i]))
            {
                node = node->get(A[i]);
            }
            else return NULL;
        }
        return node;
    }
    
    bool search(string A)
    {
        TrieNode *node = searchPrefix(A);
        return NULL!=node && node->isEndNode();
    }
    
    void printStrings(TrieNode *node, string prefix)
    {
        if (node->isEndNode())
        {
            cout<<prefix << ", ";
        }
            for(int i=0;i<26;i++)
            {
                char ch = 'a' + i;
                if (node->containsKey(ch))
                {
                    string temp = prefix;
                    temp.push_back(ch);
                    printStrings(node->get(ch), temp);
                }
            }
    }
    void printTrie()
    {
        printStrings(root, "");
    }
    
    int stringsWithPrefix(string A)
    {
        int strings =0;
        TrieNode *node = searchPrefix(A);
        if (node != NULL)
        {
            strings += node->fromNode();
        }
        return strings;
    }
};



#endif /* Trie_hpp */
