Sistema de Riego y Control Ambiental Automatizado v1.0
Solución de automatización, mitigación de vulnerabilidades e inteligencia ambiental para huertas y jardines.

Autor: Tobias Martinez Ortiz
Estado: Prototipo Funcional / Pre-Producción
Licencia: MIT (Código Abierto)

Descripción
Sistema integral de automatización para riego y control del microclima que monitorea en tiempo real:

Temperatura ambiente (sonda digital DS18B20)
Humedad de suelo (sensor capacitivo)
Luminosidad (LDR)
Activa de forma inteligente bombas, electroválvulas e iluminación auxiliar según umbrales configurables, incorporando medidas de protección eléctrica y criterios de diseño orientados a futuras implementaciones en entornos reales.

Características principales
Control escalonado de riego según temperatura y humedad.
Compensación automática de fotoperíodo.
Aislamiento galvánico mediante relés optoacoplados.
Protección contra Back-EMF mediante diodos flyback.
Sensor de humedad capacitivo resistente a corrosión.
Sonda de temperatura estanca DS18B20.
Pantalla LCD 16x2 mediante bus I2C.
Manejo de fallas del sensor de temperatura.
Arquitectura preparada para migración futura a ESP32 e IoT.
Observaciones importantes
Matriz de componentes y comparativa simulación vs. producción
El proyecto incluye una matriz de componentes que compara los elementos utilizados durante la simulación con los componentes recomendados para una implementación física real.

Esta información permite comprender las diferencias entre el entorno de pruebas y una futura implementación en campo, facilitando la transición hacia etapas de preproducción y producción.

Código documentado
El código fuente incluye comentarios explicativos a lo largo de su desarrollo con el objetivo de facilitar la comprensión de la lógica implementada, las decisiones de diseño adoptadas y el funcionamiento de cada bloque funcional.

La documentación interna está orientada tanto al aprendizaje como al mantenimiento futuro del sistema.

Alcance y limitaciones actuales
Este proyecto se encuentra en una etapa de preproducción y tiene fines educativos, de investigación, validación técnica y demostración conceptual.

Actualmente no contempla de forma específica:

Tipos de plantas o cultivos particulares.
Dimensiones y distribución del terreno.
Requerimientos hídricos específicos según especie.
Características físicas o químicas del suelo.
Estacionalidad y ciclos de crecimiento.
Variables climáticas avanzadas.
Integración con servicios meteorológicos externos.
Optimización basada en ubicación geográfica.
Los umbrales y parámetros utilizados deben considerarse valores de referencia y podrían requerir calibraciones, ajustes o rediseños según el cultivo, entorno y condiciones reales de implementación.

Estructura del repositorio
Sistema-de-Riego-y-Control-Ambiental/
│
├── Firmware/
│   ├── Código fuente del sistema
│   └── Firmware para Arduino
│
├── Hardware/
│   ├── Diagramas eléctricos
│   ├── Esquemas de conexiones
│   └── Componentes electrónicos
│
├── Docs/
│   ├── Documentación técnica
│   ├── Matriz de vulnerabilidades
│   ├── Matriz de componentes
│   └── Documentación de diseño
│
├── LICENCIA
└── README.md

Futuras mejoras
Migración a ESP32.
Integración IoT mediante Wi-Fi.
Monitoreo remoto mediante dashboard web.
Aplicación móvil.
Integración de pronósticos meteorológicos.
Sensores de pH, conductividad y nivel de agua.
Registro histórico de datos.
Configuración dinámica de umbrales.
Licencia
Este proyecto se distribuye bajo licencia MIT, permitiendo su uso, modificación y distribución bajo los términos establecidos en la licencia correspondiente.
