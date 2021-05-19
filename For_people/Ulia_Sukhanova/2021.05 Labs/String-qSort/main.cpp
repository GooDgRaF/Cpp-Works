#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <ctime>
#include "Menu.h"
#include "Test.h"
#include "Mass_task.h"
#include "QSort.h"

using namespace std;


int main()
    {
        Menu menu{};
        while (true)
        {
            menu.ask_next_action();
            menu.while_incorrect();
            
            switch (menu.user_choice - '0') //ch --> int
            {
                case Menu::USER_STRINGS:
                {
                    size_t row_size = Menu::ask_row_size();
                    v_str v{row_size};
                    Menu::ask_strings(v, row_size);
                    qSort(v);
                    show_v_str(v);
                    break;
                }
                case Menu::XML_TEST:
                {
                    Menu::print_XML_start();
                    do_mass_task();
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


