//
// Created by ben on 3/21/24.
//

#ifndef NUMBERGENERATOR_TEMPORAL_LOCALITY_H
#define NUMBERGENERATOR_TEMPORAL_LOCALITY_H


#include "MarkovChain.h"
#include "RandomGenerator.h"
#include <map>

class Temporal_Locality {
private:
    MarkovChain *iat;
    RandomGenerator::CustomDistribution *burst_duration;
    std::map<int, RandomGenerator::CustomDistribution *>burst_volume;
public:
    Temporal_Locality();
    ~Temporal_Locality();
    void set_iat(MarkovChain*);
    int generate_iat();
    void set_burst_duration(RandomGenerator::CustomDistribution*);
    int generate_burst_duration();
    void set_burst_volume(std::map<int, RandomGenerator::CustomDistribution *>);
    int generate_burst_volume(int);
    void show_model();
};


#endif //NUMBERGENERATOR_TEMPORAL_LOCALITY_H
