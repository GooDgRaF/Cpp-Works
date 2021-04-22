#include <iostream>
#include "Support/Random_engine.h"
#include "Distributions_test/Uniform.h"
#include "Distributions_test/Normal.h"
#include "Model_equation/Calc_model_eq.h"


int main()
    {
//        test_uniform();
//        test_normal();
        calc_model_equation();

        std::cout << "Complete!" << std::endl;
        return 0;
    }
