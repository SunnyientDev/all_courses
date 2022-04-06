''' 
This code works as simulator.
Main values: brightness, time, date, temperature, humidity.
Users values: message.
'''
import random
import datetime
import time
import numpy as np
from datetime import datetime
import matplotlib.pyplot as plt
import matplotlib.animation as animation

################################## PLANT SETTINGS ##################################
plant_last_watering_day = "2021-01-12"
plant_watering_range_days = 7
plant_temperature = [20, 25]
plant_light_level = 700

plant_temp_limit = 5
plant_light_limit = 250
################################## SYSTEM SETTINGS ##################################
set_lamp = 0
set_pump = 0

data = []
delay = 0.1

################################## HELPER FUNCTIONS ##################################
def generate_value(value, coef, step, roundation):
    real_coef = random.uniform(coef - step, coef + step)
    current_value = value * real_coef
    return round(current_value, roundation)

def days_between(d1, d2):
    d1 = datetime.strptime(d1, "%Y-%m-%d")
    d2 = datetime.strptime(d2, "%Y-%m-%d")
    return abs((d2 - d1).days)

def switcher(current_state, new_state):
    exit_code = 1
    if current_state == 1 and new_state == 1:
        exit_code = 0
    if current_state == 0 and new_state == 0:
        exit_code = 0
    return exit_code

def check_state(current_temperature, current_brightness, current_humidity):
    ans = 1
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    
    if current_brightness < (plant_light_level - plant_light_limit) or current_brightness > (plant_light_level + plant_light_limit):
        ans *= 0
    if days_between(plant_last_watering_day, current_date) >= plant_watering_range_days or current_humidity < 20:
        ans *= 0
    if current_temperature < (plant_temperature[0] - plant_temp_limit) or current_temperature > (plant_temperature[1] + plant_temp_limit):
        ans *= 0
    return ans

def main(lamp_state, pump_state, current_temperature, current_humidity, current_brightness, plant_last_watering_day, addition):
    phrase = ""
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    current_time = now.strftime("%H:%M:%S")
    
    if(check_state(current_temperature, current_brightness, current_humidity) == 0):
        # lighting
        if current_brightness < plant_light_level and lamp_state == 0:
            print("Admin: Checking the light")
            if switcher(lamp_state, 1) != 0:
                lamp_state = 1
                print("Admin: Lamp is working")
                func = add_light(current_temperature, current_humidity, current_brightness)
                current_temperature = func[0]
                current_humidity = func[2]
                current_brightness = func[1]
                switcher(lamp_state, 0)
                lamp_state = 0
            else:
                print("Error: Lamp is not active")
        
        # watering
        if days_between(plant_last_watering_day, current_date) >= plant_watering_range_days or current_humidity < 20:
            print("Adming: Checking the water")
            if switcher(pump_state, 1) != 0:
                pump_state = 1
                print("Admin: Pump is working")
                plant_last_watering_day = current_date
                func = add_water(current_temperature, current_humidity, current_brightness)
                current_temperature = func[0]
                current_humidity = func[2]
                current_brightness = func[1]
                switcher(pump_state, 0)
                pump_state = 0
            else:
                print("Error: Pump is not active")
        
        # temperature
        if current_temperature < plant_temperature[0] - 15:
            print("It's too cold for your plant, replace it.")
            current_temperature = to_normal(10, current_temperature, current_humidity, current_brightness, 0.03)[0]
            current_humidity = to_normal(10, current_temperature, current_humidity, current_brightness, 0.03)[2]
            current_brightness = to_normal(10, current_temperature, current_humidity, current_brightness, 0.03)[1]
        elif current_temperature > plant_temperature[1] + 15:
            print("It's too hot for your plant, replace it.")
            current_temperature = to_normal(10, current_temperature, current_humidity, current_brightness, 0.01)[0]
            current_humidity = to_normal(10, current_temperature, current_humidity, current_brightness, 0.01)[2]
            current_brightness = to_normal(10, current_temperature, current_humidity, current_brightness, 0.01)[1]
    else: 
        print("Your plant is OK. Enjoy your day! =)")

    if(addition == True):
        print("Current values\n\nBrightness: {0}\nTime: {1}\nDate: {2}\nTemperature: {3}\nHumidity: {4}\n".format(current_brightness, current_time, current_date, current_temperature, current_humidity))
    return current_temperature, current_brightness, current_humidity, plant_last_watering_day, pump_state, lamp_state

def to_normal(process_time, current_temperature, current_humidity, current_brightness, coef):
    data = {}
    count = 0
    
    while(count != process_time):    
        time.sleep(delay)
        if current_humidity > 70:
            current_humidity *= (1 - coef + 0.1)
            
        if current_temperature < plant_temperature[0]:
            current_temperature *= (1 + coef)
        elif current_temperature > plant_temperature[1]:
            current_temperature *= (1 - coef + 0.1)
        
        if current_brightness < plant_light_level:
            current_brightness *= (1 + coef)
        elif current_brightness > plant_light_level:
            current_brightness *= (1 - coef + 0.1)
        
        now = datetime.now()
        current_date = now.strftime("%Y-%m-%d")
        current_time = now.strftime("%H:%M:%S")
        current_name = 'info (' + str(now.year) + '-' + str(now.month) + '-' + str(now.day) + ' ' + str(now.hour) + ':' + str(now.minute) + ':' + str(now.second) + ')'

        data[current_name] = {
                'date': current_date,
                'time': current_time,
                'brightness': current_brightness,
                'temperature': current_temperature, 
                'humidity': current_humidity, 
                'action': "normal",
        }
        f = open('data_json.txt', 'a')
        f.write(str(data[current_name]) + '\n')
        count += 1
    return current_temperature, current_brightness, current_humidity, plant_last_watering_day
    
def add_water(current_temperature, current_humidity, current_brightness):
    data = {}
    count = 0
    coef = 0.1
    process_time = 15
    
    while(count != process_time):    
        time.sleep(delay)
        if current_humidity < 70:
            current_humidity *= (1 + coef)
        current_humidity = round(current_humidity, 3)
        current_brightness = generate_value(current_brightness, 1.00001, 0.00001, 0) 
        current_temperature = generate_value(current_temperature, 1.001, 0.001, 3)
        
        now = datetime.now()
        current_date = now.strftime("%Y-%m-%d")
        current_time = now.strftime("%H:%M:%S")
        current_name = 'info (' + str(now.year) + '-' + str(now.month) + '-' + str(now.day) + ' ' + str(now.hour) + ':' + str(now.minute) + ':' + str(now.second) + ')'
        
        data[current_name] = {
                'date': current_date,
                'time': current_time,
                'brightness': current_brightness,
                'temperature': current_temperature, 
                'humidity': current_humidity, 
                'action': "adding water",
        }
        f = open('data_json.txt', 'a')
        f.write(str(data[current_name]) + '\n')
        count += 1
    return current_temperature, current_brightness, current_humidity

def add_light(current_temperature, current_humidity, current_brightness):
    data = {}
    count = 0
    coef = random.randrange(0, 100, 1) * 0.001
    process_time = 40
    
    while(count != process_time):
        time.sleep(delay)
        if current_brightness < 1000:    
            current_brightness *= (1 + coef)
        
        current_humidity -= 0.01
        current_humidity = round(current_humidity, 2)
        current_temperature = generate_value(current_temperature, 1.001, 0.001, 3)
        
        now = datetime.now()
        current_date = now.strftime("%Y-%m-%d")
        current_time = now.strftime("%H:%M:%S")
        current_name = 'info (' + str(now.year) + '-' + str(now.month) + '-' + str(now.day) + ' ' + str(now.hour) + ':' + str(now.minute) + ':' + str(now.second) + ')'

        data[current_name] = {
                'date': current_date,
                'time': current_time,
                'brightness': current_brightness,
                'temperature': current_temperature, 
                'humidity': current_humidity, 
                'action': "adding light",
        }
        f = open('data_json.txt', 'a')
        f.write(str(data[current_name]) + '\n')
        count += 1
    return current_temperature, current_brightness, current_humidity

################################## VARIABLES ##################################
default_temperature = 10
default_brightness = 500
default_humidity = 17
default_watering_day = '2021-11-10'
pump_state = 0
lamp_state = 0

#main(pump_state, lamp_state, default_temperature, default_humidity, default_brightness, default_watering_day, False)

while(check_state(default_temperature, default_brightness, default_humidity) != 1):
    res = main(pump_state, lamp_state, default_temperature, default_humidity, default_brightness, default_watering_day, False)
    default_temperature = res[0]
    default_brightness = res[1]
    default_humidity = res[2]
    default_watering_day = res[3]
    pump_state = res[4]
    lamp_state = res[5]
