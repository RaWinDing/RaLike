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
 * @file            Operation.h
 * @description     It provides the function used for class View to obtain
 *                  data.
 * @vesion          1.0
 * @author          RaWinDing
 */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "AhoCorasickAutomaton.h"
#include "ResponseEvent.h"
#include "RequestEvent.h"
#include "Model.h"

#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Operation {
public: 

    /**
     * Obtain keywords.
     * @param req_event - the RequestEvent which contains the needed
     *                    infomation.
     * @return - the ResponseEvent which contains the keywords.
     */
    static ResponseEvent ObtainKeyword(RequestEvent req_event);   

    /**
     * Obtain an article.
     * @param req_event - the RequestEvent which contains the needed
     *                    infomation.
     * @return - the ResponseEvent which contains the an article.
     */
    static ResponseEvent ObtainArticle(RequestEvent req_event);

    /**
     * Compete the answer.
     * @param req_event - the RequestEvent which contains the needed
     *                    infomation.
     * @return - the ResponseEvent which contains the answer.
     */
    static ResponseEvent CompeteAnswer(RequestEvent req_event);
};

#endif // #ifndef OPERATOR_H
