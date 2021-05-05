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
    # (c) Массив char, размер 6 - 1 * 6 байт
    # (L) uint64 - 8 байт
    # (i) int32 - 4 байта

    b_bytes = byte_string[offset:offset + B_SIZE]
    b_parsed = struct.unpack('<cLi', b_bytes)

    return {'B1': b_parsed[0], 
            'B2': b_parsed[1],
            'B3': b_parsed[2]}

def parse_d(offset, byte_string):
    # (H) Размер (uint16) и адрес (uint16) массива (b) int8 - 2 байта + 2 байта + 1 байт = 5 байт
    # (H) uint16 - 2 байта

    d_bytes = byte_string[offset:offset + D_SIZE]
    d_parsed = struct.unpack('<HHH', d_bytes)

    d1_bytes = byte_string[d_parsed[1]:d_parsed[1] + d_parsed[0]]
    d1_parsed = struct.unpack('<' + 'b' * d_parsed[0], d1_bytes)
    
    return {'D1': list(d1_parsed), # 0 and 1
            'D2': d_parsed[2]}

def parse_c(offset, byte_string):
    # Размер I(uint32) и адрес I(uint32) массива адресов (uint32) структур D
    # Массив (h)int16, размер 2 - 2 * 2 байт

    c_bytes = byte_string[offset:offset + C_SIZE]
    c_parsed = struct.unpack('<IIb', c_bytes)

    c1_parsed = struct.unpack('<'+'H'*c_parsed[1], byte_string[c_parsed[2]:c_parsed[2] + c_parsed[1]*4])
    c1_list = [parse_d(addr, byte_string) for addr in c1_parsed]
    
    return {'C1': c1_list, 
            'C2': c1_parsed[0]}

def parse_a(offset, byte_string):
    # Структура B
    # Структура C
    # (d) double - 8 байт
    # (b) uint8 - 1 байт
    # (H) uint16 - 2 байта
    # (B) int64 - 8 байт
    # (I) uint32 - 4 байта
    a1_parsed = parse_b(offset, byte_string)
    a2_parsed = parse_c(offset + B_SIZE, byte_string)

    a34567_bytes = byte_string[offset + B_SIZE + C_SIZE: offset + B_SIZE + C_SIZE + 8 + 1 + 2 + 8 + 4]
    a34567_parsed = struct.unpack('<dbHBI', a34567_bytes)

    return {'A1': a1_parsed, 
            'A2': a2_parsed,
            'A3': a34567_parsed[0],
            'A4': a34567_parsed[1],
            'A5': a34567_parsed[2],
            'A6': a34567_parsed[3],
            'A7': a34567_parsed[4]}

def f31(byte_string):
    return parse_a(5, byte_string)

print(f31(b'\xc9PQNReurwba\xc3=?\xac\x07\xab\xee\x0f3\xae\xd8\x1c\x07\x00\x00\x00{'
b'\x00\x00\x00c\xb7\xf5~F\xce6\x80#\x9e\xeb\xbf\x98\xb4\x1aI\xe7'
b'\xd9\x84\xc2\xf1J\xff\xba\xc8b2\x88\xd7\x02\x00:\x00\x0f\x88\x0f\x93'
b'(T\x04\x00B\x00\x9dN\xca~\x8c_\x04\x00L\x00\xf5<\xa3%\x02\x00V\x00\x85:\x8ct'
b'\xf0\xff\x04\x00^\x00w\x90\xa2\xa6\xb9\x03\x00h\x00\xf4\x97~\x15\xeb'
b'\x05\x04\x00q\x00\xa6\x11<\x00\x00\x00F\x00\x00\x00P\x00\x00\x00X'
b'\x00\x00\x00b\x00\x00\x00k\x00\x00\x00u\x00\x00\x00'))