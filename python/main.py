import sys
import time
import csv
import os
import signal
from multiprocessing import Process, Queue
from KP01withCGInstance import KP01withCGInstance
from Solution import Solution
from DynamicProgrammingKP01 import DynamicProgrammingKP01
from BacktrackingKP01wCG import BacktrackingKP01wCG

TIMEOUT_SECONDS = 900
CSV_FILE = "resultados_pythonDP.csv"

def solve_instance(algorithm, instance_path, queue):
    instance = KP01withCGInstance()
    instance.read_instance_from_file(instance_path)
    i = 0
    initial_solution = Solution(instance.get_num_items())

    if algorithm == "dp":
        solver = DynamicProgrammingKP01()
        solution = solver.solve(instance)
    elif algorithm == "bt":
        solver = BacktrackingKP01wCG()
        solution = solver.solve(instance, initial_solution, i)
    else:
        raise ValueError("Unknown algorithm")

    items = solution.get_items()
    queue.put({
        "peso": solution.get_total_weight(),
        "beneficio": solution.get_total_profit(),
        "items": " ".join(map(str, items)),
})


def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <algorithm> <instance>")
        print("Available algorithms: dp (Dynamic Programming), bt (Backtracking)")
        return 1

    algorithm = sys.argv[1]
    instance_path = sys.argv[2]

    print(f"Procesando: {instance_path} con algoritmo '{algorithm}'")

    queue = Queue()
    process = Process(target=solve_instance, args=(algorithm, instance_path, queue))

    start = time.time()
    process.start()
    process.join(TIMEOUT_SECONDS)

    estado = "OK"
    tiempo = round(min(time.time() - start, TIMEOUT_SECONDS), 4)

    if process.is_alive():
        print("⏱️ TIMEOUT alcanzado. Finalizando proceso...")
        process.terminate()
        process.join()
        estado = "TIMEOUT"
        resultado = {
            "peso": -1,
            "beneficio": -1,
            "items": ""
        }
    else:
        resultado = queue.get()

    # Guardar en CSV
    existe = os.path.exists(CSV_FILE)
    with open(CSV_FILE, "a", newline="") as csvfile:
        writer = csv.writer(csvfile)
        if not existe:
            writer.writerow(["Archivo", "Algoritmo", "Peso", "Beneficio", "Items", "Tiempo (s)", "Estado"])
        writer.writerow([
            instance_path,
            algorithm,
            resultado["peso"],
            resultado["beneficio"],
            resultado["items"],
            tiempo,
            estado
        ])

    print(f"✅ Finalizado: {instance_path} ({estado}) en {tiempo} segundos.")

if __name__ == "__main__":
    main()