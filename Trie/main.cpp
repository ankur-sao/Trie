//
//  main.cpp
//  Trie
//
//  Created by ansao on 2/25/19.
//  Copyright © 2019 ansao. All rights reserved.
//

#include <iostream>
#include "TrieNode.hpp"
#include "Trie.hpp"
#include <string>
#include <vector>

using namespace std;


int main(int argc, const char * argv[])
{
    trie *ltrie = new trie();
    ltrie->insert("ankur");
    ltrie->insert("ankit");
    ltrie->insert("ankita");
   ltrie->insert("ankuri");
    ltrie->insert("ankurit");
    
    ltrie->insert("ayush");
    ltrie->insert("amit");
    ltrie->insert("vandana");
    ltrie->insert("sonali");
    ltrie->insert("shwetha");
    ltrie->insert("kavya");
    ltrie->insert("prachi");
    ltrie->insert("pratreek");
    ltrie->insert("prakhar");
    
    ltrie->insert("richa");
    ltrie->insert("arushi");
  
    ltrie->printTrie();
    
    
    return 0;
}
