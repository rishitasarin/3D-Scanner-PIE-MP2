import serial
import math

# Setting Arduino parameters
arduinoComPort="/dev/cu.usbmodem101" # fill out later
baudRate = 9600
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

with open('data.csv', 'w') as f:
    s = np.array([0,0,0])
    while(True):
        lineOfData = serialPort.readline().decode()
        if len(lineOfData)>0 and lineOfData!='finished\r\n':
            tilt, pitch, depth = [x for x in lineOfData.split(' ')]
            print(tilt, pitch, depth)
            # x,y,z = convert_to_vector(tilt, pitch, depth)
            calib_depth = 91.9 - .214*int(depth) + 0.000134*(int(depth)**2)
            f.write(f'{tilt},{pitch},{calib_depth}\n')
        if lineOfData=='finished\r\n':
            f.close()
            break
            