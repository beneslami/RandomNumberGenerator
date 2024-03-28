//
// Created by ben on 3/15/24.
//

#include "Traffic_Model.h"
#include <list>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv){
    std::string model = std::string(argv[1]);
    std::string directory = std::string(argv[2]);
    Traffic_Model *traffic = new Traffic_Model(model);
    traffic->read_model_file();
    int i = 1;
    bool flag = 0;
    std::list<int>iat_list;
    std::list<double>intensity;
    std::list<double>temporal;

    while(i <= 10000000) {
        if(flag == 0){
            int dur = traffic->generate_burst_duration("req");
            if(dur == -1) break;
            int vol = traffic->generate_burst_volume("req", dur);
            intensity.push_back((double)vol/dur);
            temporal.push_back((double)vol/dur);
            flag = !flag;
            i += dur;
        }
        else if(flag == 1) {
            int iat = traffic->generate_off_cycle("req");
            if(iat == -1) break;
            iat_list.push_back(iat);
            temporal.push_back(iat);
            flag = !flag;
            i += iat;
        }
    }

    int output = 0;
    std::string temp_dir = directory;
    struct stat sb;
    if(stat(temp_dir.c_str(), &sb) != 0){
        std::cout << "The output directory does not exist\n";
        output = -1;
    }
    else {
        std::fstream iatFile(temp_dir.append("/iat_sequence.txt"), std::ios::out);
        while (!iat_list.empty()) {
            iatFile << iat_list.front() << "\n";
            iat_list.pop_front();
        }
        iatFile.close();
        temp_dir = directory;
        std::fstream intensityFile(temp_dir.append("/intensity_sequence.txt"), std::ios::out);
        while (!intensity.empty()) {
            intensityFile << intensity.front() << "\n";
            intensity.pop_front();
        }
        intensityFile.close();
        temp_dir = directory;
        std::fstream temporalFile(temp_dir.append("/temporal_sequence.txt"), std::ios::out);
        while (!temporal.empty()) {
            temporalFile << temporal.front() << "\n";
            temporal.pop_front();
        }
        temporalFile.close();
        output = 1;
    }
    delete traffic;

    return output;
}