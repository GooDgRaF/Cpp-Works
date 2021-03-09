//
// Created by Антон on 21.02.2021.
//

#include <cmath>
#include "ADistance.h"


double ADistance::getKM() const
    {
        return m_kilometer;
    }

ADistance operator+(const ADistance &ad1, const ADistance &ad2)
    {
        return ADistance(ad1.m_kilometer + ad2.m_kilometer);
    }

ADistance operator*(const ADistance &ad1, const ADistance &ad2)
    {
        return ADistance(ad1.m_kilometer * ad2.m_kilometer);
    }

ADistance operator/(const ADistance &ad1, const ADistance &ad2)
    {
        return ADistance(ad1.m_kilometer / ad2.m_kilometer);
    }

bool operator<(const ADistance &ad1, const ADistance &ad2)
    {
        return (ad1.getKM() + ADistance::deltaKM) < ad2.getKM();
    }

bool operator==(const ADistance &ad1, const ADistance &ad2)
    {
        return std::abs(ad1.getKM() - ad2.getKM()) <= ADistance::deltaKM;
    }

bool operator<=(const ADistance &ad1, const ADistance &ad2)
    {
        return ((ad1 < ad2) || (ad1 == ad2));
    }

bool operator>=(const ADistance &ad1, const ADistance &ad2)
    {
        return !(ad1 < ad2);
    }
