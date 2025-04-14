import requests
import json
import datetime
import serial

# Configura el puerto serial (ajusta 'COM3' y baudrate según tu configuración)
ser = serial.Serial('COM11', 9600)

# URL de la API
url = "https://api.n2yo.com/rest/v1/satellite/visualpasses/25338/41.702/-76.014/0/2/300/&apiKey=TV43BH-4XXWCB-H2M26M-58DX"
response = requests.get(url)

if response.status_code == 200:
    data = response.json()

    # Asumimos que la estructura de datos tiene los siguientes campos
    # Puedes ajustar esto según la estructura real de la respuesta de la API
    info = data.get('info', {})
    passes = data.get('passes', [])

    # Extraer información específica y almacenarla en variables
    sat_name = info.get('satname', '')
    transaction_count = info.get('transactionscount', 0)
    satellite_id = info.get('satid', 0)

    if passes:
        # Procesar solo el primer pase
        pass_info = passes[0]
        startAz = int(pass_info.get('startAz', 0)) 
        midAz = int(pass_info.get('maxAz', 0))
        endAz = int(pass_info.get('endAz', 0))
        maxEl = int(pass_info.get('maxEl', 0))
        tiempo_in = int(pass_info.get('startUTC', 0))
        tiempo_mi = int(pass_info.get('maxUTC', 0))
        tiempo_fi = int(pass_info.get('endUTC', 0))

        tiempo1 = datetime.datetime.fromtimestamp(tiempo_in)
        tiempo2 = datetime.datetime.fromtimestamp(tiempo_mi)
        tiempo3 = datetime.datetime.fromtimestamp(tiempo_fi)

        hora1 = tiempo1.hour
        minutos1 = tiempo1.minute

        hora2 = tiempo2.hour
        minutos2 = tiempo2.minute

        hora3 = tiempo3.hour
        minutos3 = tiempo3.minute

        # Imprimir la información del primer pase
        print(f"Pase 1:")
        print(f"  Azimuth Inicial: {startAz}")
        print(f"  Azimuth Medio: {midAz}")
        print(f"  Azimuth Final: {endAz}")
        print(f"  Elevación Medio: {maxEl}")
        print(f"  Hora Inicial: {hora1}")
        print(f"  Minutos Inicial: {minutos1}")
        print(f"  Hora Media: {hora2}")
        print(f"  Minutos Media: {minutos2}")
        print(f"  Hora Final: {hora3}")
        print(f"  Minutos Final: {minutos3} \n")

        # Convertir el Azimuth Inicial a string y enviar cada dígito como ASCII por el puerto serial
        for digit in str(startAz):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(midAz):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(endAz):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(maxEl):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(hora1):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(minutos1):
           ser.write(digit.encode('ascii'))

        for digit in str(hora2):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(minutos2):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(hora3):
           ser.write(digit.encode('ascii'))

        ser.write(b',')

        for digit in str(minutos3):
           ser.write(digit.encode('ascii'))


    # Imprimir la información del satélite
    print(f"Nombre del Satélite: {sat_name}")
    print(f"ID del Satélite: {satellite_id}")
    print(f"Conteo de Transacciones: {transaction_count}")

else:
    print("Error al obtener los datos:", response.status_code)

# Cerrar el puerto serial
ser.close()