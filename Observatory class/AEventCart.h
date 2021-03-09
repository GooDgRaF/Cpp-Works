//
// Created by Антон on 21.02.2021.
//

#ifndef OBSERVATORY_CLASS_AEVENTCART_H
#define OBSERVATORY_CLASS_AEVENTCART_H

class AEventSph;
#include "AEvent.h"
#include "AEventSph.h"

class AEventCart : public AEvent
{
public:
    AEventCart(long int reg_st, long int duration, ADistance x, ADistance y, ADistance z);

    ADistance get_distance() const override;
    ADistance get_altitude() const final;
    ADistance getX() const;
    ADistance getY() const;
    ADistance getZ() const;

    explicit operator AEventSph() const;

private:
    ADistance m_x;
    ADistance m_y;
    ADistance m_z;
};


#endif //OBSERVATORY_CLASS_AEVENTCART_H
