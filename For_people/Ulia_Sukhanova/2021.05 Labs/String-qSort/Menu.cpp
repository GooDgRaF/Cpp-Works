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

size_t Menu::ask_row_size()
    {
        print_enter_number_of_rows();
        string row_size_user{};
        getline(cin, row_size_user);
        if (row_size_user.find_first_not_of("0123456789") != string::npos)
        {
            while (row_size_user.find_first_not_of("0123456789") != string::npos)
            {
                print_incorrect_input();
                print_enter_number_of_rows();
                getline(cin, row_size_user);
            }
        }
        return stoul(row_size_user);
    }

void Menu::ask_strings(v_str &v, size_t row_size)
    {
        print_enter_strings();
        v.clear();
        for (int i = 0; i < row_size; i++)
        {
            string s{};
            getline(cin, s);
            v.push_back(s);
        }
    }

void Menu::while_incorrect()
    {
        while (!isdigit(user_choice))
        {
            print_incorrect_input();
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
