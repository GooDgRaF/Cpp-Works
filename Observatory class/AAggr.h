//
// Created by Антон on 23.02.2021.
//

#ifndef OBSERVATORY_CLASS_AAGGR_H
#define OBSERVATORY_CLASS_AAGGR_H


#include <vector>
#include <set>
#include "AEvent.h"
#include "AEventCart.h"
#include "Comparators.h"

class AAggr
{
public:
    void receiveAEventCart(AEventCart &aEventCart);
    void receiveAEventSph(AEventSph &aEventSph);

    void reSort(bool comp(const AEvent *, const AEvent *));

    std::vector<AEvent *> part_of_reg_time(const ATime t1, const ATime t2) const;
    std::vector<AEvent *> part_of_altitude(const ADistance z1, const ADistance z2) const;
    std::vector<AEvent *> part_of_distance(const ADistance d1, const ADistance d2) const;


    void clear();

private:

    std::vector<AEvent*> m_events = {};
    std::multiset<AEvent*, comp_reg_time> m_events_sort_by_reg_time = {};
    std::multiset<AEvent*, comp_altitude> m_events_sort_by_altitude = {};
    std::multiset<AEvent*, comp_distance> m_events_sort_by_distance = {};
    std::vector<AEvent*> m_events_sort_by_user = {};

};


#endif //OBSERVATORY_CLASS_AAGGR_H
