Sistema de Riego y Control Ambiental Automatizado v1.0
Solución de automatización, mitigación de vulnerabilidades e inteligencia ambiental para huertas y jardines.

Autor: Tobias Martinez Ortiz
Estado: Desarrollo Técnico / Pre-Producción
Licencia: MIT (Código Abierto)

Descripción
Sistema integral de automatización para riego y control del microclima que monitorea en tiempo real:

Temperatura ambiente (sonda digital DS18B20)
Humedad de suelo (sensor capacitivo)
Luminosidad (LDR)
Activa de forma inteligente bombas/electroválvulas e iluminación auxiliar según umbrales configurables, incorporando medidas de protección eléctrica y buenas prácticas de diseño orientadas a una futura implementación en entornos reales. 

Observaciones importantes
Matriz de componentes y comparativa simulación vs. producción
Este proyecto incluye una matriz de componentes que compara los dispositivos utilizados durante la simulación con los componentes recomendados para una implementación física en campo. El objetivo es mostrar las diferencias entre el entorno de desarrollo y una posible implementación en preproducción o producción, facilitando futuras migraciones y mejoras del sistema.

Código documentado
El código fuente contiene comentarios explicativos destinados a facilitar su comprensión, mantenimiento y aprendizaje. Se describen bloques funcionales, variables, parámetros y decisiones de diseño para que otros desarrolladores puedan comprender la lógica implementada de forma más sencilla.

Alcance y limitaciones actuales
Este proyecto se encuentra en fase de preproducción y no contempla actualmente aspectos específicos de un entorno agrícola real, tales como:

Tipos de plantas o cultivos.
Dimensiones y distribución del terreno.
Características particulares del suelo.
Requerimientos hídricos específicos por especie.
Variables climáticas avanzadas.
Optimización basada en estaciones del año.
Integración con servicios meteorológicos externos.
Los parámetros utilizados deben considerarse valores de referencia y pueden requerir calibración o adaptación según el entorno de implementación. 

Características principales
Control escalonado de riego según temperatura + humedad.
Compensación automática de fotoperíodo.
Aislamiento galvánico mediante relés optoacoplados.
Protección contra Back-EMF mediante diodos flyback.
Sensor de humedad capacitivo resistente a corrosión.
Sonda de temperatura estanca DS18B20.
Pantalla LCD 16x2 mediante bus I2C.
Manejo de fallas del sensor de temperatura.
Arquitectura preparada para migración futura a ESP32 e IoT.
Estructura del repositorio
...
