# Un problema, es que cuando mandamos la señal de movientos al Arduino, no sabemos si esta bloqueado o ha llegado a su destino

# (NOTA: Con los servos, utilizar siempre una fuente de alimentación en Arduino para no dañar los puertos USB del ordenador)

Vamos a utilizar un **shunt**

"En electrónica, un **shunt** es una carga **resistiva** a través de la cual se deriva una **corriente eléctrica**. Generalmente la **resistencia** de un **shunt** es conocida con precisión y es utilizada para determinar la intensidad de corriente eléctrica que fluye a través de esta carga, mediante la medición de la diferencia de tensión o **voltaje** a través de ella, valiéndose de ello de la **ley de Ohm (I = V/R)**."

Vamos conocer el consumo que está teniendo el motor, leyendo una entrada analógica de arduino, esta opción es válida para todo tipo de servos.

<IMG  SRC="/images/Esquemaservobloqueo_esquema_02.jpg" W ALT="Esquema Shunt Arduino">


En el directorio **makina1** dejo el sketchbook para Arduino que controla el **shunt**

El programa mueve 6 servos, recibe por el puerto serie, una letra y seguido el angulo que queremos mover de 0 a 180º, definiendo cada servo con una de las letras "**qwerty**" pines del **D9** al **D4** de arduino

Ejemplo:  **q**150  ( mueve el servo **q** 150º),
          **e**20   ( mueve el servo **e** 20º)

Y mientras el servo no llega a su destino, y tengamos una tensión en los pines de **A0** al **A5** no lee el siguiente movimiento del buffer serie

###### Este sistema de movimiento con el *shunt* he optado por el, ya que si había algún problema de movimiento con el servo, me rompe el programa Python y el puerto serie del ordenador se queda atrapado, pasando a ser otro puerto para comunicarnos con el Arduino, igual hay otro método pero lo desconozco como evitar esto ...


Si llega la letra **e** se enciende el led 13, y con la letra **a** se apaga el led 13

Fuentes sacadas de:
- http://proyectosarduinodiy.blogspot.com.es/2015/01/como-saber-si-un-servo-esta-bloqueado.html (pagina guardada en pdf dentro de documentación)
- https://es.wikipedia.org/wiki/Shunt_(electr%C3%B3nica)
