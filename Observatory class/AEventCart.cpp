//
// Created by Антон on 21.02.2021.
//
#include "AEventCart.h"
#include "cmath"

AEventCart::AEventCart(ATime reg_st, ATime duration, ADistance x, ADistance y, ADistance z)
        : AEvent(reg_st, duration), m_x(x), m_y(y), m_z(z)
    {

    }

AEventCart::operator AEventSph() const
    {
        ADistance radius = this->get_distance();
        const double inclination = asin((m_z / radius).getKM());
        const double azimuth = atan2(m_y.getKM(),m_x.getKM());


        return {m_registration_start_time, m_duration, radius, inclination, azimuth};
    }

ADistance AEventCart::getZ() const
    {
        return m_z;
    }

ADistance AEventCart::getX() const
    {
        return m_x;
    }

ADistance AEventCart::getY() const
    {
        return m_y;
    }

ADistance AEventCart::get_distance() const
    {
        return ADistance(sqrt((m_x * m_x + m_y * m_y + m_z * m_z).getKM()));
    }

ADistance AEventCart::get_altitude() const
    {
        return m_z;
    }
