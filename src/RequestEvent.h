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
 * @file            RequestEvent.h
 * @description     It is class RequestEvent used to package request infomatin.
 * @vesion          1.0
 * @author          RaWinDing
 */

#ifndef REQUESTEVENT_H
#define REQUESTEVENT_H

#include "Event.h"

#include <string>
#include <vector>
using namespace std;

class RequestEvent : public Event {
public:
    void SetAddress(vector<string> val);
    vector<string> GetAddress();
private:
    vector<string> address;
};

#endif // #ifndef REQUESTEVENT_H
