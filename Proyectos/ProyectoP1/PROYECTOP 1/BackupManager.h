#pragma once
#include <string>

class BackupManager {
public:
    static void crearBackupConFecha(const std::string& carpeta, const std::string& archivoOriginal);
    static void restaurarBackup(const std::string& carpeta, const std::string& archivoBackup, const std::string& archivoDestino);

private:
    static std::string obtenerFechaHora(); // Obtener la fecha y hora actual como string
};
