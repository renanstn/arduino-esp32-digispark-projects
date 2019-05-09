import serial

conexao = serial.Serial('COM4', 9600)
while True:
	angulo = raw_input('Digite o angulo: ')
	if int(angulo) >=0 and int(angulo) <= 180:
		conexao.write(angulo)
	else:
		print "O valor deve ser entre 0 e 180"
conexao.close()