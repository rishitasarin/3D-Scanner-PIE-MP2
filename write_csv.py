import serial

# Setting Arduino parameters
arduinoComPort="/dev/cu.usbmodem101" # fill out later
baudRate = 9600
serialPort = serial.Serial(arduinoComPort, baudRate, timeout=1)

with open('data.csv', 'a') as f:
    f.write('tilt,pitch,depth\n')
    while(True):
        lineOfData = serialPort.readline().decode()
        if len(lineOfData)>0:
            try:    
                tilt, pitch, depth = [x for x in lineOfData.split(' ')]
                f.write(f'{tilt},{pitch},{depth}')
            except:
                f.close()
                break
