//
// Created by Антон on 21.02.2021.
//

#ifndef OBSERVATORY_CLASS_ADISTANCE_H
#define OBSERVATORY_CLASS_ADISTANCE_H


class ADistance
{
public:
    explicit ADistance(double km): m_kilometer(km){};

    double getKM() const;

    friend ADistance operator+(const ADistance &ad1, const ADistance &ad2);
    friend ADistance operator*(const ADistance &ad1, const ADistance &ad2);
    friend ADistance operator/(const ADistance &ad1, const ADistance &ad2);

    //static constexpr double KMtoLY = 9460730472580.8;
    static constexpr double deltaKM = 1;

private:

    double m_kilometer;
};

    bool operator<(const ADistance &ad1, const ADistance &ad2);
    bool operator==(const ADistance &ad1, const ADistance &ad2);
    bool operator<=(const ADistance &ad1, const ADistance &ad2);
    bool operator>=(const ADistance &ad1, const ADistance &ad2);


#endif //OBSERVATORY_CLASS_ADISTANCE_H
