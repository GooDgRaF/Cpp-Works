//
// Created by Антон on 21.02.2021.
//

#include "AEvent.h"

AEvent::AEvent(long int reg_st, long int duration): m_registration_start_time(reg_st), m_duration(duration)
    {

    }

long int AEvent::get_registration_start_time() const
    {
        return m_registration_start_time;
    }

long int AEvent::get_duration() const
    {
        return m_duration;
    }
