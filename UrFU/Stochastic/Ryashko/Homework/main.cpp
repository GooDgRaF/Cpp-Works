#include <iostream>
#include "Support/Random_engine.h"
#include "Distributions_test/Uniform.h"
#include "Distributions_test/Normal.h"
#include "Model_equation/Calc_model_eq.h"
#include "Model_equation/calc_trajectory_for_hist.h"
#include "KW_equation/Calc_eq.h"
#include "KW_equation/Calc_trj_for_hist.h"

int main()
    {
//        test_uniform();
//        test_normal();
//        calc_model_equation();
//       calc_for_hist();
//calc_kw_eq();
calc_for_hist_kw();
        std::cout << "Complete!" << std::endl;
        return 0;
    }
