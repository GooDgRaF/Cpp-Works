#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "Menu.h"

using namespace std;

struct Strings_holder
{
    vector<string> strings_to_sort{};
    int k{};
    
    void get_size()
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
    
    void get_strings()
        {
            strings_to_sort.clear();
            for (int i = 0; i < k; i++)
            {
                string s{};
                getline(cin, s);
                strings_to_sort.push_back(s);
            }
        }
    
    void show_sorted()
        {
            cout << "Sorted strings: " << endl;
            for (const auto &el : strings_to_sort)
            {
                cout << el << endl;
            }
            cout << endl << endl;
        }
    
    void qSort(vector<string> &v, vector<string>::iterator begin, vector<string>::iterator end)
        {
            auto first = begin;
            auto last = end;
            size_t sup_element = (begin->size() + end->size())/2;
            
            while (first <= last)
            {
                while (first->size() < sup_element)
                {
                    first++;
                }
                while (last->size() > sup_element)
                {
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
    
};


int main()
    {
        Menu menu{};
        Strings_holder sh{};
        while (true)
        {
            menu.ask_next_action();
            menu.while_incorrect();
            
            switch (menu.user_choice - '0') //ch --> int
            {
                case Menu::USER_STRINGS:Menu::print_enter_number_of_rows();
                    sh.get_size();
                    Menu::print_enter_strings();
                    sh.get_strings();
                    sh.qSort(sh.strings_to_sort, sh.strings_to_sort.begin(), sh.strings_to_sort.end() - 1);
                    sh.show_sorted();
                    break;
                case Menu::XML_TEST:break;
                case Menu::EXIT:Menu::print_goodbye();
                    return 0;
                default:Menu::print_incorrect_input();
                    break;
                
            }
        }
    }


