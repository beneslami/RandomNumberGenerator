//
// Created by ben on 3/15/24.
//

#ifndef NUMBERGENERATOR_TRAFFIC_MODEL_H
#define NUMBERGENERATOR_TRAFFIC_MODEL_H

#include "RandomGenerator.h"
#include "Temporal_Locality.h"

class Traffic_Model {
private:
    int cycle;
    std::string traffic_model_path;
    class Temporal_Locality *request_temporal_locality;
    class Temporal_Locality *reply_temporal_locality;
public:
    Traffic_Model(std::string);
    ~Traffic_Model();
    void read_model_file();
    int generate_off_cycle(std::string);
    int generate_burst_duration(std::string);
    int generate_burst_volume(std::string, int);
    void show_model(std::string);
    int get_cycle();
};


#endif
