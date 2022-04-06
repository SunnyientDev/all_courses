import paho.mqtt.client as mqtt
import json 
import datetime 
import time

# WirenBoard settings
WB_address = "192.168.1."
WB_num = 15
WB_port = 1883

channel_1 = "/devices/wb-msw-v3_21/controls/Current Motion"
channel_2 = "/devices/wb-msw-v3_21/controls/Sound Level"
channel_3 = "/devices/wb-ms_11/controls/Illuminance"
channel_4 = "/devices/wb-ms_11/controls/Temperature"

data = {}
current_motion = []
sound_level = []
illuminance = []
temperature = []

f = open('data_json.txt', 'a')
f.write('[\n')

f = open('data_xml.txt', 'a')
f.write('<root>\n')

# Subscriber's lines
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

    client.subscribe(channel_1)
    client.subscribe(channel_2)
    client.subscribe(channel_3)
    client.subscribe(channel_4)

def on_message(client, userdata, msg):
    #print(msg.topic + " " + str(msg.payload))
    if str(msg.topic) == "/devices/wb-msw-v3_21/controls/Current Motion":
        current_motion.append(int(msg.payload))
        #print(current_motion)
    
    if str(msg.topic) == "/devices/wb-msw-v3_21/controls/Sound Level":
        sound_level.append(float(msg.payload))
        #print(sound_level)

    if str(msg.topic) == "/devices/wb-ms_11/controls/Illuminance":
        illuminance.append(int(msg.payload))
        #print(illuminance)
    
    if str(msg.topic) == "/devices/wb-ms_11/controls/Temperature":
        temperature.append(float(msg.payload))
        #print(temperature)

    if len(current_motion) != 0 and len(sound_level) != 0 and len(illuminance) != 0 and len(temperature) != 0:
        now = datetime.datetime.now()
        time = str(now.year) + '-' + str(now.month) + '-' + str(now.day) + ' ' + str(now.hour) + ':' + str(now.minute) + ':' + str(now.second)
        current_name = 'info (' + time + ')'
        data = {}
        data[current_name] = {
            'id': WB_num,
            'current motion': current_motion[-1], 
            'sound level': sound_level[-1], 
            'illuminance': illuminance[-1],
            'temperature': temperature[-1]
        }
        print(data)

        try:
            while True:
                f = open('data_json.txt', 'a')
                f.write('{')
                f.write('id' + str(WB_num) + '\n'
                        + '\"current_motion\":\"' + str(current_motion[-1]) + '\",\n' 
                        + '\"sound_level\":\"' + str(sound_level[-1]) + '\",\n'  
                        + '\"illuminance\":\"' + str(illuminance[-1]) + '\",\n'  
                        + '\"temperature\":\"' + str(temperature[-1]) + '\",\n'  
                        + '\"time\":\"' + time + '\"\n')
                f.write('},')
                
                f = open('data_xml.txt', 'a')
                f.write('<id>' + str(WB_num) + '</id>\n'
                        + '<current_motion>' + str(current_motion[-1]) + '</current_motion>\n' 
                        + '<sound_level>' + str(sound_level[-1]) + '</sound_level>\n' 
                        + '<illuminance>' + str(illuminance[-1]) + '</illuminance>\n' 
                        + '<temperature>' + str(temperature[-1]) + '</temperature>\n' 
                        + '<time>' + time + '</time>\n')
        except:
            print("Time error")
        data = {}

f = open('data_json.txt', 'a')
f.write('{')
f.write('id' + str(WB_num) + '\n'
                        + '\"current_motion\":\"' + str(current_motion[-1]) + '\",\n' 
                        + '\"sound_level\":\"' + str(sound_level[-1]) + '\",\n'  
                        + '\"illuminance\":\"' + str(illuminance[-1]) + '\",\n'  
                        + '\"temperature\":\"' + str(temperature[-1]) + '\",\n'  
                        + '\"time\":\"' + time + '\"\n')
f.write('}\n]')

f = open('data_xml.txt', 'a')
f.write('<id>' + str(WB_num) + '</id>\n'
                        + '<current_motion>' + str(current_motion[-1]) + '</current_motion>\n' 
                        + '<sound_level>' + str(sound_level[-1]) + '</sound_level>\n' 
                        + '<illuminance>' + str(illuminance[-1]) + '</illuminance>\n' 
                        + '<temperature>' + str(temperature[-1]) + '</temperature>\n' 
                        + '<time>' + time + '</time>\n')
f = open('data_xml.txt', 'a')
f.write('</root>')

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(WB_address + str(WB_num), WB_port, 5) #18883
client.loop_forever(max_packets=5)
client.disconnect()
print(data)