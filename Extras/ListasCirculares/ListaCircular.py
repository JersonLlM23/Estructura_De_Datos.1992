from nodo import Nodo
class ListaCircular:
    def __init__(self):
        self.primero = None
        self.ultimo = None

    def insertar(self, cedula, nombre, apellido):
        # Verificar si la cédula ya existe en la lista
        if not self.validar_cedula_unica(cedula):
            print("Error: La cédula ya existe en la lista.")
            return

        nuevo = Nodo(cedula, nombre, apellido)
        if self.primero is None:
            # Lista vacía, el nuevo nodo es el primero y el último
            self.primero = nuevo
            self.ultimo = nuevo
            nuevo.set_siguiente(nuevo)  # Enlazar al mismo nodo para hacerlo circular
        else:
            # Insertar al final de la lista
            self.ultimo.set_siguiente(nuevo)
            nuevo.set_siguiente(self.primero)
            self.ultimo = nuevo

        print("Persona ingresada correctamente.")

    def buscar(self, cedula):
        if self.primero is None:
            return None

        actual = self.primero
        while True:
            if actual.get_cedula() == cedula:
                return actual
            actual = actual.get_siguiente()
            if actual == self.primero:
                break

        return None

    def eliminar(self, cedula):
        if self.primero is None:
            print("La lista está vacía.")
            return False

        actual = self.primero
        anterior = None

        while True:
            if actual.get_cedula() == cedula:
                # Nodo encontrado
                if actual == self.primero:
                    # Eliminar el primer nodo
                    if self.primero == self.ultimo:
                        self.primero = None
                        self.ultimo = None
                    else:
                        self.primero = actual.get_siguiente()
                        self.ultimo.set_siguiente(self.primero)
                elif actual == self.ultimo:
                    # Eliminar el último nodo
                    anterior.set_siguiente(self.primero)
                    self.ultimo = anterior
                else:
                    # Eliminar un nodo intermedio
                    anterior.set_siguiente(actual.get_siguiente())

                print("Persona eliminada correctamente.")
                return True

            anterior = actual
            actual = actual.get_siguiente()
            if actual == self.primero:
                break

        print("Cédula no encontrada.")
        return False

    def mostrar(self):
        if self.primero is None:
            print("NULL")
            return

        actual = self.primero
        while True:
            print(
                f"<Cédula: {actual.get_cedula()}, Nombre: {actual.get_nombre()}, Apellido: {actual.get_apellido()}> ->"
            )
            actual = actual.get_siguiente()
            if actual == self.primero:
                break

        print("(Regresa al inicio)")

    def eliminar_caracter(self, cedula, caracter):
        persona = self.buscar(cedula)
        if persona is None:
            print("Cédula no encontrada.")
            return

        # Eliminar el carácter del nombre y apellido
        nuevo_nombre = persona.get_nombre().replace(caracter, "")
        nuevo_apellido = persona.get_apellido().replace(caracter, "")
        persona.set_nombre(nuevo_nombre)
        persona.set_apellido(nuevo_apellido)

        print("Carácter eliminado correctamente.")

    def validar_cedula_unica(self, cedula):
        if self.buscar(cedula) is not None:
            return False
        return True
