from validaciones import Validaciones
from ListaCircular import ListaCircular
from ordenamiento import Ordenamiento

# Crear la lista circular
lista = ListaCircular()

def main():
    while True:
        print("\n*** Menu de opciones ***")
        print("1. Insertar persona")
        print("2. Buscar persona")
        print("3. Eliminar persona")
        print("4. Mostrar lista")
        print("5. Eliminar carácter de nombre")
        print("6. Cifrar un carácter")
        print("7. Mostrar lista auxiliar")
        print("8. Ordenar nombres (Distribution Sort)")
        print("9. Mostrar archivo de distribución ordenado")
        print("10. Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == "1":  # Insertar persona
            print("Ingrese su cédula: ")
            cedula = Validaciones.leer_solo_numeros()

            if len(cedula) != 10 or not Validaciones.validar_cedula(cedula):
                print("Cédula inválida. Debe contener exactamente 10 dígitos.")
                continue

            if not Validaciones.validar_cedula_real(cedula):
                print("Cédula no válida según validación real.")
                continue

            nombre = input("Ingrese el nombre: ").strip()
            if not Validaciones.validar_nombre(nombre):
                continue

            apellido = input("Ingrese el apellido: ").strip()
            if not Validaciones.validar_nombre(apellido):
                continue

            lista.insertar(cedula, nombre, apellido)

        elif opcion == "2":  # Buscar persona
            print("Ingrese la cédula a buscar: ")
            cedula = Validaciones.leer_solo_numeros()
            persona = lista.buscar(cedula)

            if persona:
                print(f"Persona encontrada: <Cédula: {persona.get_cedula()}, "
                      f"Nombre: {persona.get_nombre()}, "
                      f"Apellido: {persona.get_apellido()}>")
            else:
                print("Persona no encontrada.")

        elif opcion == "3":  # Eliminar persona
            print("Ingrese la cédula a eliminar: ")
            cedula = Validaciones.leer_solo_numeros()
            if lista.eliminar(cedula):
                print("Persona eliminada correctamente.")
            else:
                print("Persona no encontrada.")

        elif opcion == "4":  # Mostrar lista
            print("\nLista de personas:")
            lista.mostrar()

        elif opcion == "5":  # Eliminar un carácter de un nombre
            print("Ingrese la cédula de la persona: ")
            cedula = Validaciones.leer_solo_numeros()
            caracter = input("Ingrese el carácter a eliminar: ")
            lista.eliminar_caracter(cedula, caracter)

        elif opcion == "6":  # Cifrar un carácter
            print("Ingrese la cédula para cifrar: ")
            cedula = Validaciones.leer_solo_numeros()
            persona = lista.buscar(cedula)

            if not persona:
                print("Persona no encontrada.")
                continue

            print(f"--Persona encontrada--\nCédula: {persona.get_cedula()}\n"
                  f"Nombre: {persona.get_nombre()}\nApellido: {persona.get_apellido()}")

            caracter = input("Ingrese el carácter a cifrar: ")
            if not caracter.isalpha():
                print("El carácter debe ser una letra.")
                continue

            desplazamiento = int(Validaciones.leer_solo_numeros())
            lista.cifrar_caracter(cedula, caracter, desplazamiento)

        elif opcion == "7":  # Mostrar lista auxiliar
            print("\nLista auxiliar:")
            lista.mostrar_auxiliar()

        elif opcion == "8":  # Ordenar nombres
            Ordenamiento.ordenar_por_cubetas(lista)

        elif opcion == "9":  # Mostrar archivo de distribución ordenado
            archivo = "personas_ordenadas.txt"
            try:
                with open(archivo, "r") as file:
                    print("\nArchivo de distribución ordenado:")
                    for linea in file:
                        print(linea.strip() + " ->")
                    print("NULL")
            except FileNotFoundError:
                print(f"No se encontró el archivo {archivo}.")

        elif opcion == "10":  # Salir
            print("Saliendo del programa...")
            break

        else:
            print("Opción no válida. Por favor, seleccione una opción del menú.")

if __name__ == "__main__":
    main()
