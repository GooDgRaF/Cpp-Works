#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "Menu.h"
#include "StringsHolder.h"
#include "Test.h"
#include "Mass_task.h"

using namespace std;


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
                case Menu::USER_STRINGS:
                    
                    Menu::print_enter_number_of_rows();
                    sh.get_size();
                    Menu::print_enter_strings();
                    sh.get_strings();
                    sh.qSort(sh.strings_to_sort, sh.strings_to_sort.begin(), sh.strings_to_sort.end() - 1);
                    sh.show_sorted();
                    break;
                case Menu::XML_TEST:
                {
                    break;
                }
                
                case Menu::TEST:
                    
                    Menu::print_test_start();
                    test_qSort();
                    break;
                case Menu::EXIT:Menu::print_goodbye();
                    return 0;
                default:Menu::print_incorrect_input();
                    break;
                
            }
        }
    }


