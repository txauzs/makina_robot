import serial, time #cargamos la libreria serial
import sys

arduinoPort = serial.Serial('/dev/ttyACM0', 9600,  timeout=1) #inicializamos el puerto de serie a 9600 baud


#archivo = open("pp.txt", "r")
para1 = sys.argv[1] # lee el primer parametro
archivo = open(para1, "r")

for linea in archivo.readlines():
    print linea

#variable para almacenar el mensaje
#le asignamos un valor introducido por el usuario
#print "Introduce un caracter ('s' para salir): "
#entrada = raw_input()

#while entrada != 's': #introduciendo 's' salimos del bucle
    arduinoPort.write(linea) #envia la entrada por serial
    print "He enviado: ", linea
    #print "Introduce un caracter ('s' para salir): "

    sArduino = 111
    print "Voy dentro ...", sArduino
    while ( sArduino != '1\r\n'):  #cuando el valor es <=10 continua
        print "Estoy dentro ..."
        # leemos hasta que encontarmos el final de linea
        #time.sleep(.5)
        # Se borra cualquier data que haya quedado en el buffer
        arduinoPort.flushInput()
        arduinoPort.setDTR()
        time.sleep(.3)
        sArduino = arduinoPort.readline()
        #if sArduino == '0\r\n':
        print "*Arduino %r : " % (sArduino)
        #    print float(sArduino)
        #sArduino = arduinoPort.read()
        # Mostramos el valor leido y eliminamos el salto de linea del final
        # print "Valor Arduino: " + sArduino.rstrip('\n')
        print "Valor Arduino: " + sArduino.rstrip('\n')

    print "Estoy fuera ..."
    #entrada = raw_input() #introduce otro caracter por teclado
    time.sleep(.3)
