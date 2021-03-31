//
// Created by Антон on 29.03.2021.
//

#ifndef OBSERVATORY_CLASS_COMPARATORS_H
#define OBSERVATORY_CLASS_COMPARATORS_H


struct comp_reg_time
{
    bool operator()(const AEvent *e1, const AEvent *e2) const
        {
            return e1->get_registration_start_time()
                   <
                   e2->get_registration_start_time();
        }
};

struct comp_altitude
{
    bool operator()(const AEvent *e1, const AEvent *e2) const
        {
            return e1->get_altitude()
                   <
                   e2->get_altitude();
        }
};

struct comp_distance
{
    bool operator()(const AEvent *e1, const AEvent *e2) const
        {
            return e1->get_distance()
                   <
                   e2->get_distance();
        }
};

#endif //OBSERVATORY_CLASS_COMPARATORS_H
