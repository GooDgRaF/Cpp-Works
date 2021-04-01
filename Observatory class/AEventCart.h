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
    AEventCart(ATime reg_st, ATime duration, ADistance x, ADistance y, ADistance z);

    ADistance get_distance() const override;
    ADistance get_altitude() const final;
    ADistance getX() const;
    ADistance getY() const;
    ADistance getZ() const;

    explicit operator AEventSph() const;

    ~AEventCart(){std::cout << "AEventCart" << std::endl; };

private:
    ADistance m_x{0};
    ADistance m_y{0};
    ADistance m_z{0};
};


#endif //OBSERVATORY_CLASS_AEVENTCART_H
