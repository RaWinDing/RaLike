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
 * @file    Model.cpp
 * @see     Model.h
 */

#include "Model.h"

vector<string> Model::GetKeyword(string address) {
    ifstream fin(address.c_str());
    vector<string> result;
    string str;
    while (getline(fin, str))
        result.push_back(str);
    fin.close();
    fin.clear();
    return result;
}

string  Model::GetArticle(string address) {
    ifstream fin(address.c_str());
    string result;
    char ch;
    while (fin.get(ch))
        result += ch;
    fin.close();
    fin.clear();
    return result;
}
