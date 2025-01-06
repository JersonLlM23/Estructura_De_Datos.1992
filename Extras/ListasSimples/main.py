from Lista_Simple import ListaSimple
from MetodoOrdenamientoExterno import MetodoOrdenamientoExterno
from Validaciones import Validaciones

if __name__ == "__main__":
    lista_principal = ListaSimple()
    lista_auxiliar = ListaSimple()
    metodo_ordenamiento = MetodoOrdenamientoExterno()

    # Limpiar duplicados al inicio usando ListaSimple
    ListaSimple.limpiar_duplicados()

    try:
        with open("personas.txt", "r") as archivo:
            for linea in archivo:
                partes = linea.strip().split(",")
                if len(partes) == 3:  # Verificar que la línea tenga exactamente 3 elementos
                    cedula, nombre, apellido = partes
                    lista_principal.insertar_a_cola(cedula, nombre, apellido)
                else:
                    print(f"Línea inválida en el archivo: {linea.strip()}")
    except FileNotFoundError:
        print("Archivo personas.txt no encontrado. Se iniciará con una lista vacía.")

    while True:
        print("\n** Menú de opciones **")
        print("1. Insertar persona")
        print("2. Buscar persona")
        print("3. Eliminar persona")
        print("4. Mostrar lista")
        print("5. Eliminar carácter de nombre")
        print("6. Cifrar un carácter")
        print("7. Mostrar lista auxiliar")
        print("8. Ordenar lista por nombre (Distribution Sort)")
        print("9. Mostrar archivo de distribución ordenado")
        print("10. Salir")

        opcion = input("Seleccione una opción: ")

        if opcion == "1":
            print("Ingrese la cédula (solo números): ", end="")
            cedula = Validaciones.leer_solo_numeros()
            nombre = Validaciones.capturar_solo_letras()
            apellido = Validaciones.capturar_solo_letras()

            # Verificar si la cédula ya existe en el archivo
            with open("personas.txt", "r") as archivo:
                if any(linea.split(",")[0] == cedula for linea in archivo):
                    print(f"Error: La cédula {cedula} ya existe en el archivo.")
                    continue

            # Si no existe, agregar a la lista y archivo
            lista_principal.insertar_a_cola(cedula, nombre, apellido)
            with open("personas.txt", "a") as archivo:
                archivo.write(f"{cedula},{nombre},{apellido}\n")

        elif opcion == "2":
            print("Ingrese la cédula a buscar (solo números): ", end="")
            cedula = Validaciones.leer_solo_numeros()
            lista_principal.buscar(cedula)

        elif opcion == "3":
            print("Ingrese la cédula a eliminar (solo números): ", end="")
            cedula = Validaciones.leer_solo_numeros()
            if lista_principal.eliminar(cedula):
                # Regenerar el archivo sin el registro eliminado
                with open("personas.txt", "w") as archivo:
                    temp = lista_principal.cabeza
                    while temp:
                        archivo.write(f"{temp.cedula},{temp.nombre},{temp.apellido}\n")
                        temp = temp.siguiente

        elif opcion == "4":
            # Mostrar lista ordenada
            lista_principal.mostrar_ordenado()

        elif opcion == "5":
            print("Ingrese la cédula (solo números): ", end="")
            cedula = Validaciones.leer_solo_numeros()
            caracter = Validaciones.capturar_una_letra()
            lista_principal.eliminar_caracter(cedula, caracter, lista_auxiliar)

        elif opcion == "6":
            print("Ingrese la cédula (solo números): ", end="")
            cedula = Validaciones.leer_solo_numeros()
            caracter = Validaciones.capturar_una_letra()
            print("Ingrese el desplazamiento (número entre 1 y 25): ", end="")
            desplazamiento = Validaciones.validar_numero_1_a_25()
            lista_principal.cifrar_caracter(cedula, caracter, desplazamiento, lista_auxiliar)

        elif opcion == "7":
            lista_auxiliar.mostrar()

        elif opcion == "8":
            # Generar nombres de las cubetas
            archivos_cubetas = [f"cubeta_{chr(i)}.txt" for i in range(65, 91)]
            
            # Distribuir los datos en las cubetas
            metodo_ordenamiento.distribuir_datos("personas.txt", archivos_cubetas)

            # Ordenar cada cubeta
            for archivo in archivos_cubetas:
                metodo_ordenamiento.ordenar_archivo(archivo)

            # Fusionar las cubetas en un archivo final
            metodo_ordenamiento.fusionar_archivos(archivos_cubetas, "personas_ordenadas.txt")

            print("Datos ordenados y guardados en personas_ordenadas.txt.")

            # Actualizar la lista principal con los datos ordenados
            lista_principal = ListaSimple()  # Reiniciar la lista
            try:
                with open("personas_ordenadas.txt", "r") as archivo:
                    for linea in archivo:
                        partes = linea.strip().split(",")
                        if len(partes) == 3:
                            cedula, nombre, apellido = partes
                            lista_principal.insertar_a_cola(cedula, nombre, apellido)
            except FileNotFoundError:
                print("Archivo personas_ordenadas.txt no encontrado.")

        elif opcion == "9":
            metodo_ordenamiento.mostrar_archivo("personas_ordenadas.txt")

        elif opcion == "10":
            print("Saliendo del programa.")
            break

        else:
            print("Opción inválida. Intente nuevamente.")
