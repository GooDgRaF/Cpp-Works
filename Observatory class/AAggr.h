//
// Created by Антон on 23.02.2021.
//

#ifndef OBSERVATORY_CLASS_AAGGR_H
#define OBSERVATORY_CLASS_AAGGR_H


#include <vector>
#include "AEvent.h"
#include "AEventCart.h"

class AAggr
{
public:
    void receiveAEventCart(AEventCart &aEventCart);
    void receiveAEventSph(AEventSph &aEventSph);

    void reSort();
    void reSort(bool comp(const AEvent *, const AEvent *));

    std::vector<AEvent *> part_of_reg_time(const ATime t1, const ATime t2) const;
    std::vector<AEvent *> part_of_altitude(const ADistance z1, const ADistance z2) const;
    std::vector<AEvent *> part_of_distance(const ADistance d1, const ADistance d2) const;


    void clear();

private:

    std::vector<AEvent*> m_events;
    std::vector<AEvent*> m_events_sort_by_reg_time;
    std::vector<AEvent*> m_events_sort_by_altitude;
    std::vector<AEvent*> m_events_sort_by_distance;
    std::vector<AEvent*> m_events_sort_by_user;

    void reSort_reg_time();
    void reSort_altitude();
    void reSort_distance();
};


#endif //OBSERVATORY_CLASS_AAGGR_H
