data_to_process = "(000.0 00.0 218.8 59.9 0065 0015 001 374 53.20 000 089 0035 0000 000.0 00.00 00000 00010000 00 00 00000 010[\xa2"
protocol_item = ["Grid voltage", "Grid frequency", "AC output voltage", "AC output frequency", "AC output apparent power", "AC output active power", "Output load percent", "BUS voltage", "Battery voltage", "Battery charging curent", "Battery capacity", "Inverter heat sink temperture", "PV Input current for battery", "PV Input voltage 1", "Battery voltage from SCC", "Battery discharge curent", "Inverter status", "Battery voltage offset for fas on", "EEPROM version", "PV Charging power", "Inverter status"]
buff_data = []

current_word = ''
for char in data_to_process:
    if char == ' ':
        if current_word != '':
            buff_data.append(current_word)
            current_word = ''
    else:
        current_word += char

if current_word != '':
    buff_data.append(current_word)

for index, (protocol_item, item) in enumerate(zip(protocol_item, buff_data)):
    print(f"{protocol_item}: {item}")


