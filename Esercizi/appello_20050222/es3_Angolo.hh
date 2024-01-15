#ifndef ANGOLO_HH
#define ANGOLO_HH 1
#include<vector>

template<typename T>
T average(std::vector<double> vd){return static_cast<double>(std::accumulate(vd.begin(), vd.enc(), 0,0))/vd.size();}

class Angolo{
public:
    virtual double angolo()=0;

};

#endif // ANGOLO_HH