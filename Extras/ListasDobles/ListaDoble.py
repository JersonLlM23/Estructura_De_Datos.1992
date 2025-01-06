import os
from Nodo import Nodo

class ListaDoble:
    def __init__(self):
        self.cabeza = None
        self.cola = None

    def eliminar_caracter(self, cedula, caracter, lista_auxiliar):
        nodo = self.buscar(cedula)
        if nodo:
            nuevo_nombre = nodo.nombre.replace(caracter, '')
            nuevo_apellido = nodo.apellido.replace(caracter, '')
            nodo.set_nombre(nuevo_nombre)
            nodo.set_apellido(nuevo_apellido)
            lista_auxiliar.insertar_o_actualizar(nodo.cedula, nuevo_nombre, nuevo_apellido)
            self.guardar_lista_en_archivo("personas.txt")
            print(f"Caracter '{caracter}' eliminado de la persona con cedula {cedula}.")
        else:
            print(f"No se encontró la persona con cedula {cedula}.")

    def cifrar_caracter(self, cedula, caracter, desplazamiento, lista_auxiliar):
        try:
            temp = self.buscar(cedula)
            if temp is None:
                print("Cedula no encontrada.")
                return

            def cifrar(c):
                if c == caracter:
                    base = 'a' if c.islower() else 'A'
                    return chr((ord(c) - ord(base) + desplazamiento) % 26 + ord(base))
                return c

            nuevo_nombre = ''.join(cifrar(c) for c in temp.get_nombre())
            nuevo_apellido = ''.join(cifrar(c) for c in temp.get_apellido())

            temp.set_nombre(nuevo_nombre)
            temp.set_apellido(nuevo_apellido)

            lista_auxiliar.insertar_o_actualizar(temp.get_cedula(), nuevo_nombre, nuevo_apellido)

            with open("personas.txt", "r") as archivo_entrada, open("personas_temp.txt", "w") as archivo_temporal:
                for linea in archivo_entrada:
                    datos = linea.strip().split(',')
                    if datos[0] == cedula:
                        archivo_temporal.write(f"{datos[0]},{nuevo_nombre},{nuevo_apellido}\n")
                    else:
                        archivo_temporal.write(linea)

            os.remove("personas.txt")
            os.rename("personas_temp.txt", "personas.txt")

            print(f"Caracter cifrado correctamente con desplazamiento {desplazamiento}. Archivo actualizado y lista auxiliar actualizada.")
        except Exception as e:
            print(f"Error al cifrar caracter: {e}")

    def mostrar(self):
        temp = self.cabeza
        if temp is None:
            print("\nNULL\n")
            return
        while temp is not None:
            print(f"\nCedula: {temp.get_cedula()}\nNombre: {temp.get_nombre()}\nApellido: {temp.get_apellido()} -> ", end="")
            temp = temp.get_siguiente()
        print("\nNULL\n")

    def insertar(self, cedula, nombre, apellido):
        nuevo_nodo = Nodo(cedula, nombre, apellido)
        if self.cabeza is None:
            self.cabeza = nuevo_nodo
            self.cola = nuevo_nodo
        else:
            self.cola.set_siguiente(nuevo_nodo)
            nuevo_nodo.set_anterior(self.cola)
            self.cola = nuevo_nodo

    def insertar_o_actualizar(self, cedula, nombre, apellido):
        nodo = self.buscar(cedula)
        if nodo:
            nodo.set_nombre(nombre)
            nodo.set_apellido(apellido)
        else:
            self.insertar(cedula, nombre, apellido)

    def buscar(self, cedula):
        temp = self.cabeza
        while temp is not None:
            if temp.get_cedula() == cedula:
                return temp
            temp = temp.get_siguiente()
        return None

    def eliminar(self, cedula):
        temp = self.cabeza
        while temp is not None and temp.get_cedula() != cedula:
            temp = temp.get_siguiente()

        if temp is None:
            print(f"Persona con cedula {cedula} no encontrada.")
            return False

        if temp == self.cabeza:
            self.cabeza = temp.get_siguiente()
            if self.cabeza is not None:
                self.cabeza.set_anterior(None)
            else:
                self.cola = None
        elif temp == self.cola:
            self.cola = temp.get_anterior()
            if self.cola is not None:
                self.cola.set_siguiente(None)
            else:
                self.cabeza = None
        else:
            temp.get_anterior().set_siguiente(temp.get_siguiente())
            temp.get_siguiente().set_anterior(temp.get_anterior())

        del temp
        return True

    def guardar_en_archivo(self, cedula, nombre, apellido, nombre_archivo):
        try:
            with open(nombre_archivo, "a") as archivo:
                archivo.write(f"{cedula},{nombre},{apellido}\n")
        except Exception as e:
            print(f"Error al guardar en archivo: {e}")

    def cargar_desde_archivo(self, nombre_archivo):
        try:
            if not self.archivo_existe(nombre_archivo):
                print("No se pudo abrir el archivo.")
                return

            with open(nombre_archivo, "r") as archivo:
                for linea in archivo:
                    datos = linea.strip().split(',')
                    if len(datos) == 3:
                        self.insertar(datos[0], datos[1], datos[2])
        except Exception as e:
            print(f"Error al cargar desde archivo: {e}")

    @staticmethod
    def archivo_existe(nombre_archivo):
        return os.path.isfile(nombre_archivo)

    def guardar_lista_en_archivo(self, filename):
        with open(filename, 'w') as file:
            current = self.cabeza
            while current:
                file.write(f"{current.get_cedula()},{current.get_nombre()},{current.get_apellido()}\n")
                current = current.get_siguiente()
