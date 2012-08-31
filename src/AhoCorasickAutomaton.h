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
 * @file            AhoCorasickAutomaton.h
 * @description     Aho-Corasick Automaton algorithm.
 * @vesion          1.0
 * @author          RaWinDing
 */

#ifndef AHOCORASICKAUTOMATON_H
#define AHOCORASICKAUTOMATON_H

#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int TOTAL_LETTER = '~' + 1 - ' ';

class Node{
friend class AhoCorasickAutomaton;
private:
    Node();
    Node* next[TOTAL_LETTER];
    Node* fail;
    string out;
};

class AhoCorasickAutomaton {
public:
    /**
     * @param keyword - the keywords which also pattern.
     * @param article - the article which should be matched.
     * @return - the map of keywords between keywords' frequency.
     */
    map<string, int> Go(vector<string> keyword, string article);

private:
    void BuildTrie(vector<string> vec);
    void MakeFailPointer();
    map<string, int> PatternMatching(string str);
    void DestoryTrie();
    void DeleteNode(Node* node);

    Node* root;
};

#endif // #ifndef AHOCORASICKAUTOMATON_H
