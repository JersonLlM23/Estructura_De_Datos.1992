# MetodoOrdenamientoExterno.py
class MetodoOrdenamientoExterno:
    def distribuir_datos(self, archivo_entrada, archivos_salida=None):
        try:
            with open(archivo_entrada, 'r') as archivo:
                # Crear las cubetas como archivos separados
                cubetas = {chr(i): open(f"cubeta_{chr(i)}.txt", 'w') for i in range(65, 91)}

                for linea in archivo:
                    partes = linea.strip().split(',')
                    if len(partes) >= 2:
                        nombre = partes[1].strip()
                        if nombre:
                            letra = nombre[0].upper()
                            if letra in cubetas:
                                cubetas[letra].write(linea.strip() + '\n')

                # Cerrar todos los archivos de cubetas
                for cubeta in cubetas.values():
                    cubeta.close()
        except FileNotFoundError:
            print("Error: El archivo de entrada no existe.")

    def ordenar_archivo(self, nombre_archivo):
        try:
            with open(nombre_archivo, 'r') as archivo:
                datos = archivo.readlines()

            # Ordenar por nombre (índice 1) y apellido (índice 2)
            datos.sort(key=lambda linea: (linea.split(',')[1].strip(), linea.split(',')[2].strip()))

            with open(nombre_archivo, 'w') as archivo:
                archivo.writelines(datos)
        except FileNotFoundError:
            print(f"Error: El archivo {nombre_archivo} no se encontró.")

    def fusionar_archivos(self, archivos_cubetas, archivo_final):
        try:
            with open(archivo_final, 'w') as archivo_salida:
                for nombre_cubeta in archivos_cubetas:
                    try:
                        with open(nombre_cubeta, 'r') as cubeta:
                            datos = cubeta.readlines()
                            if datos:
                                archivo_salida.writelines(datos)
                    except FileNotFoundError:
                        pass  # No mostramos el error de cubeta faltante
        except FileNotFoundError:
            print("Error al crear el archivo de salida.")

    def mostrar_archivo(self, nombre_archivo):
        try:
            with open(nombre_archivo, 'r') as archivo:
                contenido = archivo.read()
                if contenido.strip():  # Verificar que no esté vacío
                    print(contenido)
                else:
                    print(f"El archivo {nombre_archivo} está vacío.")
        except FileNotFoundError:
            print(f"Error: El archivo {nombre_archivo} no se pudo abrir.")
