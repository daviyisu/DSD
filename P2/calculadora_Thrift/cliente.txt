#!/usr/bin/env python
# -*- coding: utf-8 -*-
from calculadora import Calculadora
import sys

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol


def inputVector():
    result = []
    print("Introduce la coordenada x:\n")
    result.append(input())

    print("Introduce la coordenada y:\n")
    result.append(input())

    print("Introduce la coordenada z:\n")
    result.append(input())
    return result


transport = TSocket.TSocket("localhost", 9090)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)

client = Calculadora.Client(protocol)

transport.open()

print("hacemos ping al server")
client.ping()

print("Elija un modo:\n"
      "1 - Operaciones con enteros\n"
      "2 - Operaciones con vectores\n"
      "3 - Salir\n")
modo = input()
if modo == 1:
    print("Elija una operacion:\n"
          "1 - Sumar\n"
          "2 - Resta\n"
          "3 - Multiplicación\n"
          "4 - División\n")
    opcion_menu = input()
    if opcion_menu < 1 or opcion_menu > 4:
        print("Opción incorrecta\n")
        transport.close()
        exit(-1)
    else:
        print("Introduzca primer parámetro")
        arg1 = input()
        print("Introduzca segundo parámetro")
        arg2 = input()

        if opcion_menu == 1:
            resultado = client.suma(arg1, arg2)
            print("El resultado es " + str(resultado))
        elif opcion_menu == 2:
            resultado = client.resta(arg1, arg2)
            print("El resultado es " + str(resultado))
        elif opcion_menu == 3:
            resultado = client.multiplicacion(arg1, arg2)
            print("El resultado es " + str(resultado))
        elif opcion_menu == 4:
            if arg2 == 0:
                print("No se puede dividir entre 0")
                transport.close()
                exit(-1)
            else:
                resultado = client.division(arg1, arg2)
                print("El resultado es " + str(resultado))

elif modo == 2:
    print("Elija una operacion:\n"
          "1 - Sumar vectores\n"
          "2 - Restar vectores\n"
          "3 - Producto escalar de vectores\n"
          "4 - Producto vectorial de vectores\n")
    opcion_vectores = input()

    if opcion_vectores == 1:
        print("Primer vector:\n")
        vec1 = inputVector()

        print("Segundo vector:\n")
        vec2 = inputVector()

        resultado = client.suma_vectores(vec1, vec2)
        print("El resultado es " + str(resultado))

    elif opcion_vectores == 2:
        print("Primer vector:\n")
        vec1 = inputVector()

        print("Segundo vector:\n")
        vec2 = inputVector()

        resultado = client.resta_vectores(vec1, vec2)
        print("El resultado es " + str(resultado))

    elif opcion_vectores == 3:
        print("Primer vector:\n")
        vec1 = inputVector()

        print("Segundo vector:\n")
        vec2 = inputVector()

        resultado = client.producto_escalar(vec1, vec2)
        print("El resultado es " + str(resultado))


    elif opcion_vectores == 4:
        print("Primer vector:\n")
        vec1 = inputVector()

        print("Segundo vector:\n")
        vec2 = inputVector()

        resultado = client.producto_vectorial(vec1, vec2)
        print("El resultado es " + str(resultado))

    else:
        print("Opción incorrecta\n")
        transport.close()
        exit(-1)
elif modo == 3:
    print("¡Hasta luego!\n")
    transport.close()
    exit(0)



