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
 * @file            ResponseEvent.h
 * @description     It is class ResponseEvent used to package response
 *                  infomation
 * @vesion          1.0
 * @author          RaWinDing
 */

#ifndef RESPONSEEVENT_H
#define RESPONSEEVENT_H

#include "Event.h"
#include <string>
#include <vector>
using namespace std;

class ResponseEvent {
public:
    void SetKeyword(vector<string> val);
    vector<string> GetKeyword();
    void SetArticle(string val);
    string GetArticle();
    void SetAnswer(double val);
    double GetAnswer();
private:
    vector<string> keyword;
    string article;
    double answer;
};

#endif // #ifndef RESPONSEEVENT_H
