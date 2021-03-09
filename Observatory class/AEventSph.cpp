//
// Created by Антон on 21.02.2021.
//
#include "AEventSph.h"
#include "cmath"

AEventSph::AEventSph(long int regSt, long int duration, ADistance radius, double inclination, double azimuth)
        : AEvent(regSt, duration), m_radius(radius), m_inclination(inclination), m_azimuth(azimuth)
    {

    }


AEventSph::operator AEventCart() const
    {
        ADistance x(m_radius.getKM() * cos(m_azimuth) * cos(m_inclination));
        ADistance y(m_radius.getKM() * sin(m_azimuth) * cos(m_inclination));
        ADistance z(m_radius.getKM() * sin(m_inclination));

        return {m_registration_start_time, m_duration, x, y, z};
    }

ADistance AEventSph::get_distance() const
    {
        return m_radius;
    }

double AEventSph::get_inclination() const
    {
        return m_inclination;
    }

double AEventSph::get_azimuth() const
    {
        return m_azimuth;
    }

ADistance AEventSph::get_altitude() const
    {
        return ADistance(m_radius.getKM() * sin(m_inclination));
    }
