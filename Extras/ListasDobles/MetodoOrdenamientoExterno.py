import os

class MetodoOrdenamientoExterno:
    def distribuir_datos(self, archivo_entrada, archivos_salida):
        try:
            if not os.path.isfile(archivo_entrada):
                print("Error al abrir el archivo de entrada.")
                return

            cubetas = {}
            with open(archivo_entrada, "r") as archivo:
                for linea in archivo:
                    datos = linea.strip().split(',')
                    if datos[1]:
                        indice = ord(datos[1][0].lower()) - ord('a')
                        if 0 <= indice < 26:
                            cubeta_nombre = f"cubeta_{chr(65 + indice)}.txt"
                            if cubeta_nombre not in cubetas:
                                cubetas[cubeta_nombre] = open(cubeta_nombre, "w")
                                archivos_salida.append(cubeta_nombre)
                            cubetas[cubeta_nombre].write(linea)

            for cubeta in cubetas.values():
                cubeta.close()

            print("Datos distribuidos correctamente en las cubetas.")
        except Exception as e:
            print(f"Error al distribuir datos: {e}")

    def ordenar_archivo(self, nombre_archivo):
        try:
            if not os.path.isfile(nombre_archivo):
                print(f"Error al abrir el archivo {nombre_archivo} para lectura.")
                return

            with open(nombre_archivo, "r") as archivo:
                datos = [linea.strip() for linea in archivo]

            datos.sort(key=lambda x: (x.split(',')[1], x.split(',')[2]))

            with open(nombre_archivo, "w") as archivo:
                for dato in datos:
                    archivo.write(dato + "\n")
        except Exception as e:
            print(f"Error al ordenar archivo: {e}")

    def fusionar_archivos(self, archivos_cubetas, archivo_final):
        try:
            with open(archivo_final, "w") as archivo_salida:
                for archivo_cubeta in archivos_cubetas:
                    if os.path.isfile(archivo_cubeta):
                        with open(archivo_cubeta, "r") as archivo:
                            for linea in archivo:
                                archivo_salida.write(linea)
            print(f"Archivos fusionados en {archivo_final}.")
        except Exception as e:
            print(f"Error al fusionar archivos: {e}")

    def mostrar_archivo(self, nombre_archivo):
        try:
            if not os.path.isfile(nombre_archivo):
                print("No se pudo abrir el archivo.")
                return

            print("Lista ordenada:")
            with open(nombre_archivo, "r") as archivo:
                for linea in archivo:
                    print(linea.strip())
        except Exception as e:
            print(f"Error al mostrar archivo: {e}")

    def eliminar_archivos_temporales(self):
        try:
            # Delete all bucket files
            for archivo in os.listdir():
                if archivo.startswith("cubeta_") and archivo.endswith(".txt"):
                    os.remove(archivo)
            # Delete personas_ordenadas.txt if it exists
            if os.path.exists("personas_ordenadas.txt"):
                os.remove("personas_ordenadas.txt")
            print("Archivos temporales eliminados correctamente.")
        except Exception as e:
            print(f"Error al eliminar archivos temporales: {e}")
