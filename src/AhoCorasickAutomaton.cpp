/* 
 * RaLike - a software used for compete similarity between two text files.
 * Copyright (C) 2012 RaWinDing 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file    AhoCorasickAutomaton.cpp
 * @see     AhoCorasickAutomaton.h      
 */

#include "AhoCorasickAutomaton.h"

Node::Node() {
    for (int i = 0; i < TOTAL_LETTER; i++) {
        this->next[i] = NULL;
    }
    this->fail = NULL;
}

map<string, int> AhoCorasickAutomaton::Go(
    vector<string> keyword, string article)
{
    BuildTrie(keyword);
    MakeFailPointer();
    map<string, int> answer = PatternMatching(article);
    DestoryTrie();
    return answer;
}

void AhoCorasickAutomaton::BuildTrie(vector<string> vec) {
    this->root = new Node;
    for (vector<string>::iterator iter = vec.begin();
        iter != vec.end();
        iter++)
    {
        string str = *iter;
        Node* p = root;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] < ' ' || str[i] > '~') break;
            int letter = str[i] - ' ';
            if (p->next[letter] == NULL) p->next[letter] = new Node;
            p = p->next[letter];
        }
        p->out = str;     
    }
}

void AhoCorasickAutomaton::MakeFailPointer(){                 
    root->fail = NULL;                                       
    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        Node* temp = que.front();
        que.pop();
        Node* p = NULL;
        for(int i = 0; i < TOTAL_LETTER; i++){
            if(temp->next[i] != NULL){
                if(temp == root) {
                    temp->next[i]->fail = root;             
                } else {
                    p = temp->fail;
                    while (p != NULL){                    
                        if (p->next[i] != NULL){           
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;                        
                    }
                    if (p == NULL) temp->next[i]->fail = root;
                }
                que.push(temp->next[i]);
            }
        }
    }
}

map<string, int> AhoCorasickAutomaton::PatternMatching(string str){
    map<string, int> answer;
    int i = 0;
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (str[i] < ' ' || str[i] > '~') continue;
        int letter = str[i] - ' ';
        while(p->next[letter] == NULL && p != root) p = p->fail;
        p = p->next[letter];
        if (p == NULL) p = root;
        Node* node = p;
        while(node != root){                   
            if (node->out.length() > 0) {
                if (answer.find(node->out) != answer.end())
                    answer[node->out]++;
                else
                    answer[node->out] = 1;
            }
            node = node->fail;
        }
    }
    return answer;
}

void AhoCorasickAutomaton::DestoryTrie() {
    this->DeleteNode(this->root);
}

void AhoCorasickAutomaton::DeleteNode(Node* node) {
    if (node != NULL) {
        for (int i = 0; i < TOTAL_LETTER; i++)
            this->DeleteNode(node->next[i]);
        delete node;
    }
}
