#include "BackupManager.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

std::string BackupManager::obtenerFechaHora() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d-%H-%M-%S");
    return oss.str();
}

void BackupManager::crearBackupConFecha(const std::string& carpeta, const std::string& archivoOriginal) {
    std::string fechaHora = obtenerFechaHora();
    std::string archivoBackup = carpeta + "/" + fechaHora + "-backup.json";

    std::ifstream origen(archivoOriginal, std::ios::binary);
    std::ofstream destino(archivoBackup, std::ios::binary);

    if (!origen.is_open() || !destino.is_open()) {
        std::cout << "Error: No se pudo crear el backup de " << archivoOriginal << ".\n";
        return;
    }

    destino << origen.rdbuf();
    origen.close();
    destino.close();

    std::cout << "Backup creado correctamente: " << archivoBackup << "\n";
}

void BackupManager::restaurarBackup(const std::string& carpeta, const std::string& archivoBackup, const std::string& archivoDestino) {
    std::string rutaBackup = carpeta + "/" + archivoBackup;

    std::ifstream origen(rutaBackup, std::ios::binary);
    std::ofstream destino(archivoDestino, std::ios::binary);

    if (!origen.is_open() || !destino.is_open()) {
        std::cout << "Error: No se pudo restaurar el backup desde " << rutaBackup << ".\n";
        return;
    }

    destino << origen.rdbuf();
    origen.close();
    destino.close();

    std::cout << "Backup restaurado correctamente desde " << rutaBackup << " a " << archivoDestino << ".\n";
}
