#include <string>
#include <vector>
#include <iostream>
#include "hydrosheds/hydrosheds.hh"

class HydroshedsDataset {

    public:
        HydroshedsDataset();
       
};

class RiverSegment {
    private:
        int riverdata;

    public:
        int getFeature();
        int mainRiver();
        float Length();
        int hyrivID();
        virtual void out() = 0;

};