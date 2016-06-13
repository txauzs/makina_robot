# Un problema que me he encontrado, es que cuando mandamos la señal de movientos al Arduino, no sabemos si esta bloqueado o ha llegado a su destino

Por lo que vamos a utilizar un **shunt**

"En electrónica, un **shunt** es una carga **resistiva** a través de la cual se deriva una **corriente eléctrica**. Generalmente la **resistencia** de un shunt es conocida con precisión y es utilizada para determinar la intensidad de corriente eléctrica que fluye a través de esta carga, mediante la medición de la diferencia de tensión o **voltaje** a través de ella, valiéndose de ello de la **ley de Ohm (I = V/R)**."

vamos conocer el consumo que está teniendo el motor, a continuación leerlo con una entrada analógica de arduino, esta opción es válida para todo tipo de servos.

<IMG  SRC="/images/Esquemaservobloqueo_esquema_02.jpg" W ALT="Esquema Shunt Arduino">


En el directorio **makina1** dejo el sketchbook para Arduino que controla el **shunt**

Fuentes sacadas de:
- http://proyectosarduinodiy.blogspot.com.es/2015/01/como-saber-si-un-servo-esta-bloqueado.html
- https://es.wikipedia.org/wiki/Shunt_(electr%C3%B3nica)
