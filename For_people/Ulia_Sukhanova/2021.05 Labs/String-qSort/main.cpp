#include <iostream>
#include <cctype>
#include "Menu.h"
#include "Test.h"
#include "Mass_task.h"

using namespace std;
using namespace Menu;

int main()
    {
        while (true)
        {
            switch (ask_next_action())
            {
                case USER_STRINGS:
                {
                    size_t row_size = ask_row_size();
                    v_str v{row_size};
                    ask_strings(v, row_size);
                    qSort(v);
                    print_sort_str();
                    show_v_str(v);
                    break;
                }
                case XML_TEST:
                {
                    print_XML_start();
                    do_mass_task();
                    break;
                }
                
                case TEST:
                    
                    print_test_start();
                    test_qSort();
                    break;
                
                
                case EXIT:print_goodbye();
                    return 0;
                default:print_incorrect_input();
                    break;
            }
        }
    }


