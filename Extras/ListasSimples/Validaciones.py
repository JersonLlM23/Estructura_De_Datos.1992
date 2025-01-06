class Validaciones:
    @staticmethod
    def validar_cedula_real(cedula):
        if len(cedula) != 10 or not cedula.isdigit():
            print("Error: La cédula debe contener exactamente 10 dígitos.")
            return False

        provincia = int(cedula[:2])
        if provincia < 1 or provincia > 24:
            print("Error: La cédula tiene un código de provincia inválido.")
            return False

        suma = 0
        for i, digit in enumerate(map(int, cedula[:9])):
            if i % 2 == 0:
                suma += digit * 2 if digit * 2 < 10 else digit * 2 - 9
            else:
                suma += digit

        digito_verificador = (10 - suma % 10) % 10
        if digito_verificador != int(cedula[9]):
            print("Error: La cédula no es válida.")
            return False

        return True

    @staticmethod
    def validar_solo_letras(texto):
        if not all(c.isalpha() or c.isspace() for c in texto):
            print("Error: El texto debe contener solo letras.")
            return False
        return True

    @staticmethod
    def normalizar_nombre(nombre):
        return nombre.capitalize() if nombre else ""

    @staticmethod
    def capturar_cedula():
        while True:
            cedula = input("Ingrese la cédula: ").strip()
            if Validaciones.validar_cedula_real(cedula):
                return cedula

    @staticmethod
    def capturar_una_letra():
        while True:
            letra = input("Ingrese una letra: ").strip()
            if len(letra) == 1 and letra.isalpha():
                return letra
            print("Error: Debe ingresar solo una letra.")

    @staticmethod
    def capturar_solo_letras():
        while True:
            texto = input("Ingrese texto: ").strip()
            if Validaciones.validar_solo_letras(texto):
                return texto

    @staticmethod
    def validar_numero_1_a_25():
        while True:
            try:
                numero = int(input("Ingrese un número entre 1 y 25: "))
                if 1 <= numero <= 25:
                    return numero
                print("Error: Número fuera del rango permitido.")
            except ValueError:
                print("Error: Debe ingresar un número válido.")

    @staticmethod
    def leer_solo_numeros():
        import msvcrt
        input_val = ""
        while True:
            ch = msvcrt.getch()
            if ch.isdigit():
                print(ch.decode("utf-8"), end="", flush=True)
                input_val += ch.decode("utf-8")
            elif ch == b'\r':  # Enter
                print()
                break
            elif ch == b'\x08' and input_val:  # Backspace
                print("\b \b", end="", flush=True)
                input_val = input_val[:-1]
        return input_val
