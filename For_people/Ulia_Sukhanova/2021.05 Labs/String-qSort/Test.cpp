//
// Created by Антон on 17.05.2021.
//

#include "Test.h"
#include "StringsHolder.h"
#include <vector>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

void test_qSort()
    {
        vector<string>
                zero_el{},
                one_el{"1"},
                two_el_eq{"1", "1"},
                two_el_less{"1", "23"},
                two_el_gr{"32", "1"},
                five_el{"54321", "321", "4321", "1", "21"};
        
        vector<string>
                answ_zero_el{},
                answ_one_el{"1"},
                answ_two_el_eq{"1", "1"},
                answ_two_el_less{"1", "23"},
                answ_two_el_gr{"1", "32"},
                answ_five_el{"1", "21", "321", "4321", "54321"};
        
        Strings_holder sh;
        
        sh.qSort(zero_el, zero_el.begin(), zero_el.end() - 1);
        sh.qSort(one_el, one_el.begin(), one_el.end() - 1);
        sh.qSort(two_el_eq, two_el_eq.begin(), two_el_eq.end() - 1);
        sh.qSort(two_el_less, two_el_less.begin(), two_el_less.end() - 1);
        sh.qSort(two_el_gr, two_el_gr.begin(), two_el_gr.end() - 1);
        sh.qSort(five_el, five_el.begin(), five_el.end() - 1);
        
        
        assert(zero_el == answ_zero_el);
        assert(one_el == answ_one_el);
        assert(two_el_eq == answ_two_el_eq);
        assert(two_el_less == answ_two_el_less);
        assert(two_el_gr == answ_two_el_gr);
        assert(five_el == answ_five_el);
        
        cout << "Test for qSort successfully completed!" << endl << endl;
    }
