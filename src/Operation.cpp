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
 * @file    Operation.cpp
 * @see     Operation.h      
 */

#include "Operation.h"

ResponseEvent Operation::ObtainKeyword(RequestEvent req_event) {
    string address = req_event.GetAddress()[0];
    vector<string> result = Model::GetKeyword(address);
    ResponseEvent res_event;
    res_event.SetKeyword(result);
    return res_event;
}

ResponseEvent  Operation::ObtainArticle(RequestEvent req_event) {
    string address = req_event.GetAddress()[0];
    string result = Model::GetArticle(address);
    ResponseEvent res_event;
    res_event.SetArticle(result);
    return res_event;
}

ResponseEvent Operation::CompeteAnswer(RequestEvent req_event) {
    RequestEvent req;
    ResponseEvent res;

    vector<string> original_address = req_event.GetAddress();

    // original_address[0] is the string, an address of keywords.
    vector<string> address;
    address.push_back(original_address[0]);
    req.SetAddress(address);
    res = Operation::ObtainKeyword(req);
    vector<string> keyword = res.GetKeyword();

    // original_address[1] is the string, an address of the first article.
    address.clear();
    address.push_back(original_address[1]);
    req.SetAddress(address);
    res = Operation::ObtainArticle(req);
    string article1 = res.GetArticle();
    
    // original_address[2] is the string, an address of the second article.
    address.clear();
    address.push_back(original_address[2]);
    req.SetAddress(address);
    res = Operation::ObtainArticle(req);
    string article2 = res.GetArticle();
    
    AhoCorasickAutomaton ac_automaton;
    map<string, int> first_map = ac_automaton.Go(keyword, article1);
    map<string, int> second_map = ac_automaton.Go(keyword, article2);
   
    double result = 0;
    for (vector<string>::iterator iter = keyword.begin();
        iter != keyword.end();
        iter++)
    {
        int num1 = first_map.find(*iter) != first_map.end() ?
            first_map[*iter] : 0;
        int num2 = second_map.find(*iter) != second_map.end() ?
            second_map[*iter] : 0;
        result += pow((num1 - num2), 2);
    }
    result = sqrt(result);
    res.SetAnswer(result);

    return res;
}
