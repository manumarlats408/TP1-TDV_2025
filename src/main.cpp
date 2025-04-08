#include "KP01withCGInstance.h"
#include "Solution.h"
#include "DynamicProgrammingKP01.h"
#include "BacktrackingKP01wCG.h"
#include "BruteForceKP01wCG.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <future>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <algorithm> <instance>\n";
        std::cerr << "Available algorithms: dp (Dynamic Programming), bt (Backtracking), bf (Brute Force)\n";
        return 1;
    }

    std::string algorithm = argv[1];
    std::string instance_name = argv[2];
    const int TIMEOUT_SECONDS = 900;

    KP01withCGInstance instance(0, 0);
    instance.readInstanceFromFile(instance_name);

    Solution solucion(0);
    Solution solution(instance.getNumItems());

    auto future = std::async(std::launch::async, [&]() -> Solution {
        int i = 0;
        if (algorithm == "dp") {
            DynamicProgrammingKP01 solver_dp;
            return solver_dp.solve(instance);
        } else if (algorithm == "bt") {
            BacktrackingKP01wCG solver_bt;
            return solver_bt.solve(instance, solucion, i);
        } else if (algorithm == "bf") {
            BruteForceKP01wCG solver_bf;
            return solver_bf.solve(instance, solucion, i);
        } else {
            throw std::runtime_error("Unknown algorithm");
        }
    });

    auto start = std::chrono::high_resolution_clock::now();

    std::string estado = "OK";
    double tiempo_segundos = 0.0;

    if (future.wait_for(std::chrono::seconds(TIMEOUT_SECONDS)) == std::future_status::ready) {
        solution = future.get();
        auto end = std::chrono::high_resolution_clock::now();
        tiempo_segundos = std::chrono::duration<double>(end - start).count();
    } else {
        estado = "TIMEOUT";
        tiempo_segundos = TIMEOUT_SECONDS;
    }

    // 📤 Mostrar resultados si no fue timeout
    if (estado == "OK") {
        solution.printSolution();
    } else {
        std::cout << "Instancia excedió el tiempo límite de " << TIMEOUT_SECONDS / 60 << " minutos.\n";
    }

    std::cout << "Tiempo de ejecución: " << tiempo_segundos << " segundos" << std::endl;

    // 📄 Guardar en CSV
    std::ofstream archivo_csv("resultados_bf.csv", std::ios::app); // modo append
    if (archivo_csv.tellp() == 0) {
        archivo_csv << "Archivo,Algoritmo,Peso,Beneficio,Items,Tiempo (s),Estado\n";
    }

    std::string items_str;
    if (estado == "OK") {
        for (int item : solution.returnearItems()) {
            items_str += std::to_string(item) + " ";
        }
    }

    archivo_csv << instance_name << "," << algorithm << ","
                << (estado == "OK" ? std::to_string(solution.getPesoTotal()) : "-1") << ","
                << (estado == "OK" ? std::to_string(solution.getBeneficioTotal()) : "-1") << ",\""
                << items_str << "\","
                << tiempo_segundos << ","
                << estado << "\n";

    archivo_csv.close();

    return 0;
}
