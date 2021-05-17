//
// Created by Антон on 17.05.2021.
//

#include "Menu.h"
#include <iostream>
#include <functional>

using namespace std;

void Menu::ask_next_action()
    {
        cout << "Choose the next action: " << endl;
        cout << "[1] Sorting the strings entered by the user. " << endl;
        cout << "[2] Start XML-test. " << endl;
        cout << "[3] Start in-program tests." << endl;
        cout << "[0] Exit. " << endl;
        cin >> user_choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

void Menu::while_incorrect()
    {
        while (!isdigit(user_choice))
        {
            Menu::print_incorrect_input();
            ask_next_action();
        }
    }

void Menu::print_goodbye()
    {
        cout << "Good luck! " << endl;
    }

void Menu::print_incorrect_input()
    {
        cout << "Incorrect input. Try again. " << endl;
    }

void Menu::print_enter_number_of_rows()
    {
        cout << "Enter number of strings to sort: " << endl;
        
    }

void Menu::print_enter_strings()
    {
        cout << "Enter strings row by row: " << endl;
    }

void Menu::print_test_start()
    {
        cout << "Tests started " << endl;
    }
