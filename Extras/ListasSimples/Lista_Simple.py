import msvcrt
from Nodo import Nodo
import tkinter as tk
from tkinter import scrolledtext
from threading import Thread

class ListaSimple:
    def __init__(self):
        self.cabeza = None

    def insertar_a_cola(self, cedula, nombre, apellido):
        if not self.validar_cedula_unica(cedula):
            print("Error: La cédula ya existe en la lista.")
            return

        nuevo = Nodo(cedula, nombre, apellido)
        if self.cabeza is None:
            self.cabeza = nuevo
        else:
            temp = self.cabeza
            while temp.siguiente is not None:
                temp = temp.siguiente
            temp.siguiente = nuevo

    def validar_cedula_unica(self, cedula):
        temp = self.cabeza
        while temp is not None:
            if temp.cedula == cedula:
                return False
            temp = temp.siguiente
        return True

    def buscar(self, cedula):
        temp = self.cabeza
        while temp is not None:
            if temp.cedula == cedula:
                print(f"--Persona encontrada--\nCédula: {temp.cedula}\nNombre: {temp.nombre}\nApellido: {temp.apellido}")
                return temp
            temp = temp.siguiente
        print(f"La cédula {cedula} no existe en la lista.")
        return None

    def eliminar(self, cedula):
        temp = self.cabeza
        anterior = None

        while temp is not None:
            if temp.cedula == cedula:
                if anterior is None:
                    self.cabeza = temp.siguiente
                else:
                    anterior.siguiente = temp.siguiente
                print(f"Persona con cédula {cedula} eliminada exitosamente.")
                return True
            anterior = temp
            temp = temp.siguiente

        print(f"Persona con cédula {cedula} no encontrada.")
        return False

    def mostrar(self):
        temp = self.cabeza
        if temp is None:
            print("La lista está vacía.")
            return

        while temp is not None:
            print(f"Cédula: {temp.cedula}\nNombre: {temp.nombre}\nApellido: {temp.apellido}\n{'-' * 30}")
            temp = temp.siguiente

    def eliminar_caracter(self, cedula, caracter, lista_auxiliar):
        temp = self.buscar(cedula)
        if temp is None:
            return

        nuevo_nombre = temp.nombre.replace(caracter, "")
        nuevo_apellido = temp.apellido.replace(caracter, "")

        temp.set_nombre(nuevo_nombre)
        temp.set_apellido(nuevo_apellido)

        lista_auxiliar.insertar_a_cola(temp.cedula, nuevo_nombre, nuevo_apellido)

    def cifrar_caracter(self, cedula, caracter, desplazamiento, lista_auxiliar):
        temp = self.buscar(cedula)
        if temp is None:
            print("Cédula no encontrada.")
            return

        def cifrar(c):
            if c == caracter and c.isalpha():
                base = ord('a') if c.islower() else ord('A')
                return chr((ord(c) - base + desplazamiento) % 26 + base)
            return c

        nuevo_nombre = ''.join(cifrar(c) for c in temp.nombre)
        nuevo_apellido = ''.join(cifrar(c) for c in temp.apellido)

        temp.set_nombre(nuevo_nombre)
        temp.set_apellido(nuevo_apellido)

        lista_auxiliar.insertar_a_cola(temp.cedula, nuevo_nombre, nuevo_apellido)

    @staticmethod
    def limpiar_duplicados(nombre_archivo="personas.txt"):
        try:
            with open(nombre_archivo, "r") as archivo:
                lineas = archivo.readlines()

            # Usar un conjunto para mantener unicidad
            unicos = set()
            lineas_limpias = []
            for linea in lineas:
                cedula = linea.split(",")[0]
                if cedula not in unicos:
                    unicos.add(cedula)
                    lineas_limpias.append(linea)

            # Reescribir el archivo sin duplicados
            with open(nombre_archivo, "w") as archivo:
                archivo.writelines(lineas_limpias)

        except FileNotFoundError:
            print(f"Archivo {nombre_archivo} no encontrado. Se iniciará vacío.")

    def mostrar_ordenado(self):
        # Crear una lista temporal con los datos actuales
        elementos = []
        temp = self.cabeza
        while temp is not None:
            elementos.append((temp.cedula, temp.nombre, temp.apellido))
            temp = temp.siguiente

        # Ordenar por nombre y apellido
        elementos.sort(key=lambda x: (x[1], x[2]))

        # Mostrar los elementos ordenados
        for cedula, nombre, apellido in elementos:
            print(f"Cédula: {cedula}, Nombre: {nombre}, Apellido: {apellido}")

    