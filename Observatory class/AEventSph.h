//
// Created by Антон on 21.02.2021.
//

#ifndef OBSERVATORY_CLASS_AEVENTSPH_H
#define OBSERVATORY_CLASS_AEVENTSPH_H

class AEventCart;
#include "AEvent.h"
#include "AEventCart.h"

class AEventSph : public AEvent
{
public:
    AEventSph(long int regSt, long int duration, ADistance radius, double inclination, double azimuth);
    
    explicit operator AEventCart() const;

    ADistance get_distance() const override;
    ADistance get_altitude() const final;
    double get_inclination() const;
    double get_azimuth() const;

private:
    ADistance m_radius;
    double m_inclination; // [-Pi/2, Pi/2]
    double m_azimuth; // In X-Y plane. (-Pi, Pi]
};



#endif //OBSERVATORY_CLASS_AEVENTSPH_H
