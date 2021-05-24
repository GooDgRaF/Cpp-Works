//
// Created by Антон on 24.05.2021.
//

#include "Menu.h"
#include <iostream>
#include <functional>

using namespace std;

size_t Menu::ask_next_action()
    {
        cout << endl;
        cout << "Choose the next action: " << endl;
        cout << "[1] Calculate determinant. " << endl;
        cout << "[2] Calculate Redheffer-det. " << endl;
        cout << "[3] Calculate system of linear equations. " << endl;
        cout << "[4] Start in-program tests." << endl;
        cout << "[7] Reload XML-file." << endl;
        cout << endl << "[0] Exit. " << endl;
        
        char user_choice{-1};
        cin >> user_choice;
        cin.ignore();
        
        while (!isdigit(user_choice))
        {
            print_incorrect_input();
            ask_next_action();
        }
        return user_choice - '0';
    }

void Menu::print_goodbye()
    {
        cout << "Have a nice day!" << endl;
    }

void Menu::print_incorrect_input()
    {
        cout << "Incorrect input. Try again." << endl;
    }

void Menu::print_test_start()
    {
        cout << "The tests have started:" << endl;
    }

void Menu::print_det_value(double d)
    {
        cout << "The value of the determinant = " << d << endl;
    }

void Menu::print_Redheffer_det_value(double d, size_t det_size)
    {
        cout << "The value of the Redheffer determinant = " << d << endl;
        cout << "The theoretical value = " << value_det_Redheffer[det_size - 1] << endl;
        
    }

void Menu::print_sle_solution(vector<double> &solution)
    {
        if (solution.empty())
        {
            cerr << "Main determinant of the system = 0!" << endl;
        }
        else
        {
            for (int i = 0; i < solution.size(); ++i)
            {
                cout << "x_" << i << " = " << solution[i] << endl;
            }
        }
    }

