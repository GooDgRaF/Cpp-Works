//
// Created by Антон on 21.02.2021.
//

#include "AEvent.h"

AEvent::AEvent(ATime reg_st, ATime duration): m_registration_start_time(reg_st), m_duration(duration)
    {

    }

ATime AEvent::get_registration_start_time() const
    {
        return m_registration_start_time;
    }

ATime AEvent::get_duration() const
    {
        return m_duration;
    }
