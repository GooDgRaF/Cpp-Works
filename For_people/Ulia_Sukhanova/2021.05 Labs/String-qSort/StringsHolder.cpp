//
// Created by Антон on 17.05.2021.
//

#include "Menu.h"
#include "StringsHolder.h"
#include <iostream>

using namespace std;

void Strings_holder::get_size()
    {
        char k_user{};
        cin >> k_user;
        while (!isdigit(k_user))
        {
            Menu::print_incorrect_input();
            Menu::print_enter_number_of_rows();
            cin >> k_user;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        k = k_user - '0';
        strings_to_sort.reserve(k);
    }

void Strings_holder::get_strings()
    {
        strings_to_sort.clear();
        for (int i = 0; i < k; i++)
        {
            string s{};
            getline(cin, s);
            strings_to_sort.push_back(s);
        }
    }

void Strings_holder::show_sorted()
    {
        cout << "Sorted strings: " << endl;
        for (const auto &el : strings_to_sort)
        {
            cout << el << endl;
        }
        cout << endl << endl;
    }

void Strings_holder::qSort(vector<string> &v, vector<string>::iterator begin, vector<string>::iterator end)
    {
        if (v.empty())
        {
            return;
        }
        number_of_operations = 0;
        
        auto first = begin;
        auto last = end;
        size_t sup_element = (begin->size() + end->size())/2;
        
        while (first <= last)
        {
            while (first->size() < sup_element)
            {
                number_of_operations++;
                first++;
            }
            while (last->size() > sup_element)
            {
                number_of_operations++;
                last--;
            }
            
            if (first <= last)
            {
                string tmp = *first;
                *first = *last;
                *last = tmp;
                first++;
                last--;
            }
        }
        if (begin < last) qSort(v, begin, last);
        if (end > first) qSort(v, first, end);
    }