#include <iostream>
#include "AEvent.h"
#include "AEventCart.h"
#include "AAggr.h"
#include <cmath>

#include <random>
#include <ctime>
#include <algorithm>

bool comp(const AEvent *e1, const AEvent *e2)
    { //По азимуту
        if (dynamic_cast<const AEventSph *>(e1) == nullptr)
        {
            auto e1_cart = dynamic_cast<const AEventCart *>(e1);
            auto e1_sph = static_cast<const AEventSph>(*e1_cart);
            e1 = &e1_sph;
        }
        if (dynamic_cast<const AEventSph *>(e2) == nullptr)
        {
            auto e2_cart = dynamic_cast<const AEventCart *>(e2);
            auto e2_sph = static_cast<const AEventSph>(*e2_cart);
            e2 = &e2_sph;
        }
        return
                dynamic_cast<const AEventSph *>(e1)->get_azimuth()
                <
                dynamic_cast<const AEventSph *>(e2)->get_azimuth();

    }

int main()
    {

        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> uid(0, 100);
        std::uniform_int_distribution<> uid_time(0, 10000);
        std::uniform_int_distribution<> uid_duration(10, 500);

        std::uniform_real_distribution<> urd_inclination(-M_PI / 2, M_PI / 2);
        std::uniform_real_distribution<> urd_azimuth(-M_PI + 0.00001, M_PI);


        AAggr aggregator;

        for (int l = 0; l < 15; l++)
        {
            ADistance x(uid(gen));
            ADistance y(uid(gen));
            ADistance z(uid(gen));
            int t = uid_time(gen);
            int d = uid_duration(gen);

            AEventCart aEventCart(t, d, x, y, z);
            aggregator.receiveAEventCart(aEventCart);
        }


        for (int l = 0; l < 15; l++)
        {
            ADistance r(uid(gen));
            double inclination(urd_inclination(gen));
            double azimuth(urd_azimuth(gen));
            int t = uid_time(gen);
            int d = uid_duration(gen);

            AEventSph aEventSph(t, d, r, inclination, azimuth);
            aggregator.receiveAEventSph(aEventSph);
        }

        std::vector<AEvent*> time_cut = aggregator.part_of_reg_time(3000, 7000);
        std::vector<AEvent*> altitude_cut = aggregator.part_of_altitude(ADistance(30), ADistance(70));
        std::vector<AEvent*> distance_cut = aggregator.part_of_distance(ADistance(120), ADistance(170));

        aggregator.reSort(comp);

        aggregator.clear();


        return 0;
    }
