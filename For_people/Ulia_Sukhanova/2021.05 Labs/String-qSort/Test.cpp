//
// Created by Антон on 17.05.2021.
//

#include "Test.h"
#include <vector>
#include <cassert>
#include <iostream>
#include "QSort.h"

using namespace std;

void test_qSort()
    {
        v_str
                zero_el{},
                one_el{"1"},
                two_el_eq{"1", "1"},
                two_el_less{"1", "23"},
                two_el_gr{"32", "1"},
                five_el{"54321", "321", "4321", "1", "21"};
        
        v_str
                answ_zero_el{},
                answ_one_el{"1"},
                answ_two_el_eq{"1", "1"},
                answ_two_el_less{"1", "23"},
                answ_two_el_gr{"1", "32"},
                answ_five_el{"1", "21", "321", "4321", "54321"};
        
        qSort(zero_el);
        qSort(one_el);
        qSort(two_el_eq);
        qSort(two_el_less);
        qSort(two_el_gr);
        qSort(five_el);
        
        
        
        
        assert(zero_el == answ_zero_el);
        assert(one_el == answ_one_el);
        assert(two_el_eq == answ_two_el_eq);
        assert(two_el_less == answ_two_el_less);
        assert(two_el_gr == answ_two_el_gr);
        assert(five_el == answ_five_el);
        
        cout << "Test for qSort successfully completed!" << endl << endl;
    }
