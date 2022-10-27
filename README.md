# WebSocket
Se desea crear una aplicación distribuida de mensajería la cual consta de un servidor el cual envía mensajes a todas las aplicaciones cliente instaladas en la red local.
Las aplicaciones tienen que hacer lo siguiente:
- Servidor:
Al iniciarse la aplicación debe mostrar por pantalla un mensaje de bienvenida. A continuación debe abrir
un puerto efímero aleatorio entre el 50.000 y el 50.100 (TCP o UDP según su criterio de diseño). Luego, la
aplicación debe solicitar el ingreso de un mensaje vía teclado (de hasta 200 caracteres), enviar el mismo a
todos los hosts de la subred y quedar a la espera de la escritura de un nuevo mensaje.
- Cliente:
Al iniciarse la aplicación debe mostrar por pantalla un mensaje de bienvenida. A continuación debe abrir
el puerto registrado 2.500 (TCP o UDP según su criterio de diseño) y quedar a la espera de la recepción
de un mensaje por parte del servidor. Una vez llegado un mensaje, la aplicación debe mostrar por
pantalla la siguiente información:
    * Fecha y hora de la PC cliente.
    * IP y puerto desde la que llega el mensaje.
    * Mensaje.
    
**En ambos casos debe realizar el control de error de los ingresos de datos, funciones y las llamadas a sistema
utilizadas, mostrando mensajes informativos en caso de falla.**

Consideraciones:
- Debe usar IPv4 como protocolo de Internet.
