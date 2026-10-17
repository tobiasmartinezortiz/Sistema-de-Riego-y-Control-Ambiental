\# Lista de Materiales (BOM) - Pre-Producción



| Componente | Cantidad | Notas / Recomendación |

|-----------|----------|-----------------------|

| Arduino Uno R3 (o compatible) | 1 | Compatible con migración a ESP32 |

| Sensor DS18B20 sonda estanca | 1 | Con vaina de acero inoxidable |

| Resistencia pull-up 4,7 kΩ | 1 | Obligatoria entre DATA y VCC del DS18B20 |

| Sensor de humedad capacitivo v1.2 | 1 | No usar sensores resistivos |

| LDR + resistencia 10 kΩ | 1 | Encapsulada en resina si es posible |

| Módulo relé 4 canales optoacoplado | 1 | Con jumper JD-VCC separable |

| Diodos 1N4007 | 2 | Uno por cada carga inductiva |

| Pantalla LCD 16x2 + mochila I2C (PCF8574) | 1 | Dirección usual 0x27 |

| Gabinete estanco IP65 | 1 | Con prensaestopas |

| Fuente 5V para Arduino | 1 | - |

| Fuente 12V para bombas/válvulas | 1 | Independiente |

| Electrobombas 12V o electroválvulas | 2 | Según necesidad |

| Luminaria LED hortícola | 1 | Opcional |



\*\*Notas importantes:\*\*

\- Usar siempre fuente externa separada para los relés (quitar jumper JD-VCC).

\- Colocar diodos flyback en paralelo inverso en cada carga inductiva.

