//
// Created by Антон on 21.02.2021.
//

#ifndef OBSERVATORY_CLASS_AEVENT_H
#define OBSERVATORY_CLASS_AEVENT_H
#include "ADistance.h"


class AEvent
{
public:
  long int get_registration_start_time() const;
  long int get_duration() const;

  virtual ADistance get_distance() const = 0;
  virtual ADistance get_altitude() const = 0;

protected:
    AEvent(long int reg_st, long int duration);

    long int m_registration_start_time; // milliseconds
    long int m_duration; // milliseconds
};


#endif //OBSERVATORY_CLASS_AEVENT_H
