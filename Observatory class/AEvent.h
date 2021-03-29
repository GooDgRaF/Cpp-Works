//
// Created by Антон on 21.02.2021.
//

#ifndef OBSERVATORY_CLASS_AEVENT_H
#define OBSERVATORY_CLASS_AEVENT_H
#include "ADistance.h"

using ATime = long int;

class AEvent
{
public:
  ATime get_registration_start_time() const;
  ATime get_duration() const;

  virtual ADistance get_distance() const = 0;
  virtual ADistance get_altitude() const = 0;

protected:
    AEvent(ATime reg_st, ATime duration);

    ATime m_registration_start_time = 0; // milliseconds
    ATime m_duration = 0; // milliseconds
};


#endif //OBSERVATORY_CLASS_AEVENT_H
