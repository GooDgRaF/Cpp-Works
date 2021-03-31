//
// Created by Антон on 23.02.2021.
//

#include "AAggr.h"
#include <algorithm>

void AAggr::receiveAEventCart(AEventCart &aEventCart)
    {
        AEvent *aEvent = new AEventCart(aEventCart);
        m_events.push_back(aEvent);
        m_events_sort_by_reg_time.insert(aEvent);
        m_events_sort_by_altitude.insert(aEvent);
        m_events_sort_by_distance.insert(aEvent);
        m_events_sort_by_user.push_back(aEvent);
    }

void AAggr::receiveAEventSph(AEventSph &aEventSph)
    {
        AEvent *aEvent = new AEventSph(aEventSph);
        m_events.push_back(aEvent);
        m_events_sort_by_reg_time.insert(aEvent);
        m_events_sort_by_altitude.insert(aEvent);
        m_events_sort_by_distance.insert(aEvent);
        m_events_sort_by_user.push_back(aEvent);
    }

void AAggr::reSort(bool comp(const AEvent *, const AEvent *))
    {
        std::sort(m_events_sort_by_user.begin(), m_events_sort_by_user.end(), comp);
    }

std::vector<AEvent *> AAggr::part_of_reg_time(const ATime t1, const ATime t2) const
    {
        std::vector<AEvent *> res;

        for (const auto i: m_events_sort_by_reg_time)
        {
            if ((i->get_registration_start_time() >= t1)
                &&
                (i->get_registration_start_time() <= t2))
            {
                res.push_back(i);
            }
        }
        return res;
    }

std::vector<AEvent *> AAggr::part_of_altitude(const ADistance z1, const ADistance z2) const
    {
        std::vector<AEvent*> res;

        for (const auto i: m_events_sort_by_altitude)
        {
            if ((i->get_altitude() >= z1)
                &&
                (i->get_altitude() <= z2))
            {
                res.push_back(i);
            }
        }
        return res;
    }

std::vector<AEvent *> AAggr::part_of_distance(const ADistance d1, const ADistance d2) const
    {
        std::vector<AEvent*> res;

        for (const auto i: m_events_sort_by_distance)
        {
            if ((i->get_distance() >= d1)
                &&
                (i->get_distance() <= d2))
            {
                res.push_back(i);
            }
        }
        return res;
    }

void AAggr::clear()
    {
        for (auto el : m_events)
        {
            delete el;
        }

    }


