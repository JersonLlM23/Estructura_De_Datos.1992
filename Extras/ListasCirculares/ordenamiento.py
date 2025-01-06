import os

class Ordenamiento:
    @staticmethod
    def ordenar_por_cubetas(lista, archivo_ordenado="personas_ordenadas.txt"):
        """
        Ordena una lista circular por nombre usando el método de cubetas.
        """

        if lista.primero is None:
            print("La lista está vacía. No hay nada que ordenar.")
            return

        # Crear 26 cubetas (una por cada letra del alfabeto)
        cubetas = {chr(i): [] for i in range(ord('A'), ord('Z') + 1)}

        # Distribuir los nodos en las cubetas
        actual = lista.primero
        while True:
            nombre = actual.get_nombre()
            if nombre:  # Validar que el nombre no esté vacío
                primera_letra = nombre[0].upper()
                if primera_letra in cubetas:
                    cubetas[primera_letra].append(
                        (actual.get_cedula(), actual.get_nombre(), actual.get_apellido())
                    )
            actual = actual.get_siguiente()
            if actual == lista.primero:
                break

        # Ordenar las cubetas internamente y reconstruir la lista
        lista.primero = None
        lista.ultimo = None

        with open(archivo_ordenado, "w") as archivo:
            for letra in sorted(cubetas.keys()):  # Iterar en orden alfabético
                for cedula, nombre, apellido in cubetas[letra]:
                    archivo.write(f"{cedula},{nombre},{apellido}\n")
                    lista.insertar(cedula, nombre, apellido)

        print("Lista ordenada y guardada en archivo:", archivo_ordenado)
