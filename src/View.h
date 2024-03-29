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
 * @file            View.h
 * @description     It is the class used to user interaction.
 * @vesion          1.0
 * @author          RaWinDing
 */

#include "Operation.h"
#include "RequestEvent.h"
#include "ResponseEvent.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class View {
public:

    /**
     * It is the terminal interaction.
     */
    void Go();
};
