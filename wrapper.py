import os
import shutil
import subprocess
from colorama import Fore


def prepare_first(kernels_list, level):
    flag = 0
    for suite in kernels_list.keys():
        for bench, k_list in kernels_list[suite].items():
            model_path = path + suite + "/" + bench + "/ring/NVLink4/4chiplet/data/"
            for kernel in k_list:
                synthetic_path = model_path + str(kernel) + "/synthetic/" + level
                if os.path.exists(synthetic_path):
                    if flag == 0:
                        out = input("Are you sure you want to delete this directory (y/n)? It is " + level + "\n")
                        if out == "y" or out == "yes" or out == "Y":
                            flag = 1
                        else:
                            print("don't worry. Files are still there!")
                            exit(1)
                    elif flag == 1:
                        shutil.rmtree(synthetic_path)
                        os.mkdir(synthetic_path)
                else:
                    os.mkdir(synthetic_path)


if __name__ == "__main__":
    level = "level3"
    path =   "/home/ben/Desktop/benchmarks/"
    kernels_list = {"SDK": {"conjugate-gradient": [2, 3]},
                    "pannotia": {"color-max": [1],
                                 "color-maxmin": [2, 3, 4, 5, 7, 8, 9, 10],
                                 "pagerank-spmv": [2, 3, 5, 7, 9],
                                 "sssp": [3, 6, 9]},
                    "polybench": {"syr2k": [1]},
                    "parboil": {"spmv": [1],
                                "mri-gridding": [1]},
                    "cutlass": {"splitk-gemm": [2],
                                "gemm": [1, 2, 3]},
                    "deepbench": {"rnn": [4, 8, 10],
                                  "gemm": [3, 6]}
                    }
    #kernels_list = {"cutlass": {"gemm": [1]}}
    try:
        prepare_first(kernels_list, level)
    except:
        pass
    for suite in kernels_list.keys():
        for bench, k_list in kernels_list[suite].items():
            model_path = path + suite + "/" + bench + "/ring/NVLink4/4chiplet/model/"
            for kernel in k_list:
                model_file = model_path + str(kernel) + "/burst_model_" + level + ".json"
                save_path = path + suite + "/" + bench + "/ring/NVLink4/4chiplet/data/" + str(kernel) + "/synthetic/" + level
                command = "./"+ level + "/model.exe " + model_file + " " + save_path
                os.system(command)