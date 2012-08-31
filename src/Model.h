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
 * @file            Model.h
 * @description     It provides the function used to acquire data from files.
 * @vesion          1.0
 * @author          RaWinDing
 */

#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Model {
public:

    /**
     * Get keywords from the text file that the address direct to.
     * @param address - the address where the file is located in.
     * @return - the vector<string> which stores keywords.
     */
    static vector<string> GetKeyword(string address);   

    /**
    * Get an article from the text file that the address direct to.
    * @param address - the address where the file is located in.
    * @return - the string which stores a article.
    */
    static string GetArticle(string address);
};

#endif // #ifndef MODEL_H
