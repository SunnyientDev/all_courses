import struct

# Задача 3.1. Реализовать разбор двоичного формата данных (в духе формата WAD игры Doom или
# графического формата PNG). Данные начинаются с сигнатуры 0xc9 0x50 0x51 0x4e 0x52, за которой
# следует структура A. Порядок байт: от младшего к старшему. Адреса указаны в виде смещений
# от начала данных. В решении разрешено использовать модуль struct.

B_SIZE = 6 + 8 + 4
C_SIZE = 8 + 4
D_SIZE = 2*2 + 2
A_SIZE = B_SIZE + C_SIZE + 8 + 1 + 2 + 8 + 4


def parse_b(offset, byte_string):
    b_bytes = byte_string[offset:offset + B_SIZE]
    b_parsed = struct.unpack('<6sQi', b_bytes)

    return {'B1': b_parsed[0].decode('utf-8'), 
            'B2': b_parsed[1],
            'B3': b_parsed[2]}

def parse_d(offset, byte_string):
    unpacked = struct.unpack('<HHH', byte_string[offset:offset+6])
    arr_len, arr_addr, d_2 = map(int, unpacked)
    arr = struct.unpack('<' + 'b'*arr_len, byte_string[arr_addr:arr_addr+arr_len])
    
    return {'D1': list(arr), # 0 and 1
            'D2': d_2}

def parse_c(offset, byte_string):
    c_bytes = byte_string[offset:offset + C_SIZE]
    c_parsed = struct.unpack('<IIhh', c_bytes)
    
    d_arr_len = c_parsed[0]
    d_arr_offset = c_parsed[1]
    c_2 = c_parsed[2:4]
    
    d_addr_arr = struct.unpack('<' + 'I'*d_arr_len, byte_string[d_arr_offset:d_arr_offset+4*d_arr_len])
    
    parsed_d = []
    for addr in d_addr_arr:
        parsed_d.append(parse_d(addr, byte_string))
    return {'C1': parsed_d, 
            'C2': list(c_2)}

def parse_a(offset, byte_string):
    a1_parsed = parse_b(offset, byte_string)
    a2_parsed = parse_c(offset + B_SIZE, byte_string)

    unpacked = struct.unpack('<dBHqI', byte_string[offset + B_SIZE + C_SIZE:offset + B_SIZE + C_SIZE + 8 + 1 + 2 + 8 + 4])
    return {'A1': a1_parsed, 
            'A2': a2_parsed,
            'A3': unpacked[0],
            'A4': unpacked[1],
            'A5': unpacked[2],
            'A6': unpacked[3],
            'A7': unpacked[4]}

def f31(byte_string):
    if byte_string[:5] == b'\xc9PQNR':
        return parse_a(5, byte_string)
    return False
