import glob
import sys

from calculadora import Calculadora

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

import logging

logging.basicConfig(level=logging.DEBUG)


class CalculadoraHandler:
    def __init__(self):
        self.log = {}

    def ping(self):
        print("me han hecho ping()")

    def suma(self, n1, n2):
        print("sumando " + str(n1) + " con " + str(n2))
        return n1 + n2

    def resta(self, n1, n2):
        print("restando " + str(n1) + " con " + str(n2))
        return n1 - n2

    def multiplicacion(self, n1, n2):
        print("multiplicando " + str(n1) + " por " + str(n2))
        return n1 * n2

    def division(self, n1, n2):
        print("dividiendo " + str(n1) + " entre " + str(n2))
        return n1 / n2

    def suma_vectores(self, vec1, vec2):
        result = []
        print("sumando ") + str(vec1) + " con " + str(vec2)
        for i in range(len(vec1)):
            valor = vec1[i] + vec2[i]
            result.append(valor)

        return result

    def resta_vectores(self, vec1, vec2):
        result = []
        print("resta ") + str(vec1) + " con " + str(vec2)
        for i in range(len(vec1)):
            valor = vec1[i] - vec2[i]
            result.append(valor)

        return result

    def producto_escalar(self, vec1, vec2):
        result = 0
        print("producto vectorial de ") + str(vec1) + " con " + str(vec2)
        for i in range(len(vec1)):
            result += vec1[i] * vec2[i]

        return result

    def producto_vectorial(self, vec1, vec2):
        result = []
        print("producto escalar de ") + str(vec1) + " con " + str(vec2)
        result.append( (vec1[1] * vec2[2]) - (vec1[2] * vec2[1]) )
        result.append( (vec1[2] * vec2[0]) - (vec1[0] * vec2[2]) )
        result.append( (vec1[0] * vec2[1]) - (vec1[1] * vec2[0]) )
        return result



if __name__ == "__main__":
    handler = CalculadoraHandler()
    processor = Calculadora.Processor(handler)
    transport = TSocket.TServerSocket(host="127.0.0.1", port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    print("iniciando servidor...")
    server.serve()
    print("fin")
