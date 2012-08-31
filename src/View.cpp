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
 * @file    View.cpp
 * @see     View.h      
 */

#include "View.h"

void View::Go() {
    vector<string> vec_address;

    vec_address.push_back("");
    vec_address.push_back("");
    vec_address.push_back("");

    /** GPL */
    cout << "******************************************************************************" << endl;
    cout << "* RaLike  Copyright (C) 2012  RaWinDing                                      *" << endl;
    cout << "* This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'. *" << endl;
    cout << "* This is free software, and you are welcome to redistribute it              *" << endl;
    cout << "* under certain conditions; type `show c' for details.                       *" << endl;
    cout << "******************************************************************************" << endl;
    cout << endl;

    cout << "where commands include:" << endl;
    cout << "    keyword     -input the keywords file's address." << endl;
    cout << "    first       -input the fisrt file's address." << endl;
    cout << "    second      -input the second file's address." << endl;
    cout << "    run         -begin to compete similarity between two files according the keywords." << endl;
    cout << "    quit        -quit the application." << endl;

    while (1) {
        cout << endl;
        cout << "Please input a command:" << endl;
        string command;
        cin >> command;
        if (command == "quit" || command == "") {
            cout << "Thank you for your use!" << endl;
            break;
        } else
        if (command == "keyword") {
            string address;
            cout << "Please input an address:" << endl;
            cin >> address;
            if (address == "") {
                cout << "Thank you for your use!" << endl;
                break;
            } else {
                vec_address[0] = address;
            }
        } else
        if (command == "first") {
            string address;
            cout << "Please input an address:" << endl;
            cin >> address;
            if (address == "") {
                cout << "Thank you for your use!" << endl;
                break;
            } else {
                vec_address[1] = address;
            }
        } else
        if (command == "second") {
            string address;
            cout << "Please input an address:" << endl;
            cin >> address;
            if (address == "") {
                cout << "Thank you for your use!" << endl;
                break;
            } else {
                vec_address[2] = address;
            }
        } else
        if (command == "run") {
            cout << "Examine whether all input finish..." << endl;
            bool complete = true;
            for (int i = 0; i < 2; i++) {
                if (vec_address[i] == "") {
                    cout << "Error: All input is not complete!" << endl;
                    complete = false;
                    break;
                }
            }
            if (complete) {
                cout << "Examine complete." << endl;
                RequestEvent req;
                req.SetAddress(vec_address);
                ResponseEvent res = Operation::CompeteAnswer(req);
                cout << "The result of comparision is: " << res.GetAnswer() << endl;
            }
        } else
        if (command == "show c") {
            cout << "Error: Sorry, I have not realized \"show c\" command which about GPL! Because I am lazy. =_=" << endl; 
        } else
        if (command == "show w") {
            cout << "Error: Sorry, I have not realized \"show w\" command which about GPL! Because I am lazy. =_=" << endl; 
        } else {
            cout << "Error: This command does not exist." << endl;
        }
    }
}
