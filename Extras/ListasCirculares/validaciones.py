import re
import msvcrt

class Validaciones:
    @staticmethod
    def validar_cedula(cedula):
        """
        Valida que la cédula tenga exactamente 10 dígitos.
        """
        return bool(re.fullmatch(r"\d{10}", cedula))  # Debe tener exactamente 10 dígitos

    @staticmethod
    def validar_solo_letras(texto):
        """
        Valida que un texto solo contenga letras y espacios.
        """
        return bool(re.fullmatch(r"[A-Za-z ]+", texto))  # Solo letras y espacios permitidos

    @staticmethod
    def validar_cedula_real(cedula):
        """
        Valida si una cédula es real según un cálculo específico.
        """
        if len(cedula) != 10 or not cedula.isdigit():
            return False

        coeficientes = [2, 1, 2, 1, 2, 1, 2, 1, 2]
        suma = 0

        for i in range(9):  # Los primeros 9 dígitos
            valor = int(cedula[i]) * coeficientes[i]
            if valor > 9:
                valor -= 9
            suma += valor

        digito_verificador = 10 - (suma % 10)
        if digito_verificador == 10:
            digito_verificador = 0

        return digito_verificador == int(cedula[9])

    @staticmethod
    def leer_solo_numeros():
        """
        Permite ingresar solo números bloqueando letras y otros caracteres.
        Compatible con Windows (usa msvcrt).
        """
        input_str = ""
        while True:
            ch = msvcrt.getch()  # Lee un carácter del teclado
            if ch.isdigit():  # Solo aceptar números
                print(ch.decode(), end="", flush=True)  # Mostrar el carácter
                input_str += ch.decode()
            elif ch == b'\r':  # Enter
                print()  # Salto de línea
                break
            elif ch == b'\b' and input_str:  # Backspace
                print("\b \b", end="", flush=True)  # Borra el carácter en pantalla
                input_str = input_str[:-1]

        return input_str

    @staticmethod
    def validar_nombre(nombre):
        """
        Valida que un nombre no esté vacío, contenga solo letras,
        y no tenga múltiples palabras.
        """
        if not nombre or not Validaciones.validar_solo_letras(nombre) or " " in nombre.strip():
            print("Error: El nombre debe contener solo una palabra con letras.")
            return False
        return True
