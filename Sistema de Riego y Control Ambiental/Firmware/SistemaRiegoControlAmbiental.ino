/*
 * Sistema de Riego y Control Ambiental Automatizado v1.0
 * Autor: Tobias Martinez Ortiz
 * Licencia: MIT
 *
 * Descripción:
 * Sistema de automatización para riego y control microclimático
 * con sensores de temperatura (DS18B20), humedad de suelo capacitiva
 * y luminosidad (LDR). Incluye protecciones eléctricas y manejo de fallas.
 */

#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// ==================== CONFIGURACIÓN ====================

// Pantalla LCD 16x2 vía I2C (dirección más común 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Bus OneWire - Sensor DS18B20
// IMPORTANTE: Resistencia pull-up de 4.7 kΩ entre DATA y 5V
const int PIN_TEMP_ONEWIRE = 5;
OneWire oneWire(PIN_TEMP_ONEWIRE);
DallasTemperature sensorTemp(&oneWire);

// Entradas analógicas
const int PIN_HUMEDAD = A0;   // Sensor capacitivo de humedad de suelo
const int PIN_LDR     = A2;   // Fotorresistencia (LDR)

// Salidas hacia módulo de relés optoacoplado
const int PIN_RIEGO_1 = 2;    // Relé 1 - Bomba / Válvula 1
const int PIN_RIEGO_2 = 3;    // Relé 2 - Bomba / Válvula 2
const int PIN_LUZ     = 4;    // Relé 3 - Iluminación auxiliar

// Lógica de los relés (cambiar según el módulo que uses)
const int RELE_ON  = HIGH;    // Usar LOW si tu módulo es activo en bajo
const int RELE_OFF = LOW;

// Umbrales (ajustables según cultivo y clima)
const int  UMBRAL_HUMEDAD     = 65;     // %
const float UMBRAL_TEMPERATURA = 28.0;  // °C
const int  UMBRAL_LUZ         = 150;    // Valor analógico LDR

// ==================== SETUP ====================

void setup() {
  Serial.begin(9600);

  // Configurar pines de salida
  pinMode(PIN_RIEGO_1, OUTPUT);
  pinMode(PIN_RIEGO_2, OUTPUT);
  pinMode(PIN_LUZ, OUTPUT);

  // Apagar todo al inicio (estado seguro)
  digitalWrite(PIN_RIEGO_1, RELE_OFF);
  digitalWrite(PIN_RIEGO_2, RELE_OFF);
  digitalWrite(PIN_LUZ, RELE_OFF);

  // Inicializar sensor de temperatura
  sensorTemp.begin();

  // Inicializar pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistema Riego");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(1500);
  lcd.clear();
}

// ==================== LOOP ====================

void loop() {
  // ----- 1. Lectura de sensores -----
  int rawHumedad = analogRead(PIN_HUMEDAD);
  int humedad = map(rawHumedad, 1023, 0, 0, 100);
  humedad = constrain(humedad, 0, 100);

  sensorTemp.requestTemperatures();
  float tempC = sensorTemp.getTempCByIndex(0);
  bool errorSensorTemp = (tempC == DEVICE_DISCONNECTED_C);

  // Valor de resguardo ante falla del sensor
  if (errorSensorTemp) {
    tempC = 0.0;
  }

  int luzLDR = analogRead(PIN_LDR);

  // ----- 2. Lógica de riego -----
  if ((humedad < UMBRAL_HUMEDAD) && (tempC >= UMBRAL_TEMPERATURA)) {
    // Caso 1: Riego máximo
    digitalWrite(PIN_RIEGO_1, RELE_ON);
    digitalWrite(PIN_RIEGO_2, RELE_ON);
  } 
  else if ((humedad < UMBRAL_HUMEDAD) && (tempC < UMBRAL_TEMPERATURA)) {
    // Caso 2: Riego moderado
    digitalWrite(PIN_RIEGO_1, RELE_ON);
    digitalWrite(PIN_RIEGO_2, RELE_OFF);
  } 
  else if ((humedad >= UMBRAL_HUMEDAD) && (tempC >= UMBRAL_TEMPERATURA)) {
    // Caso 3: Refrigeración / nebulización
    digitalWrite(PIN_RIEGO_1, RELE_OFF);
    digitalWrite(PIN_RIEGO_2, RELE_ON);
  } 
  else {
    // Caso 4: Reposo
    digitalWrite(PIN_RIEGO_1, RELE_OFF);
    digitalWrite(PIN_RIEGO_2, RELE_OFF);
  }

  // ----- 3. Control de fotoperíodo -----
  if (luzLDR < UMBRAL_LUZ) {
    digitalWrite(PIN_LUZ, RELE_ON);
  } else {
    digitalWrite(PIN_LUZ, RELE_OFF);
  }

  // ----- 4. Mostrar información en LCD -----
  lcd.setCursor(0, 0);
  if (errorSensorTemp) {
    lcd.print("Error sensor T  ");
  } else {
    lcd.print("T:");
    lcd.print(tempC, 1);
    lcd.print((char)223);   // Símbolo de grados °
    lcd.print("C L:");
    lcd.print(luzLDR);
    lcd.print("   ");
  }

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humedad);
  lcd.print("% R:");

  if (digitalRead(PIN_RIEGO_1) == RELE_ON && digitalRead(PIN_RIEGO_2) == RELE_ON) {
    lcd.print("B1+B2");
  } else if (digitalRead(PIN_RIEGO_1) == RELE_ON) {
    lcd.print("B1   ");
  } else if (digitalRead(PIN_RIEGO_2) == RELE_ON) {
    lcd.print("B2   ");
  } else {
    lcd.print("OFF  ");
  }

  // El DS18B20 necesita al menos 750 ms para la conversión a 12 bits
  delay(1000);
}