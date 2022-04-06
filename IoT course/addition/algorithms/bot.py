import random
import telebot
import nltk
import datetime
from telebot import types
from aiogram.dispatcher.filters import Text

TOKEN = ''
bot = telebot.TeleBot(TOKEN)  

def get_failure_phrase():
  failure_phrases = BOT_CONFIG['failure_phrases']
  return random.choice(failure_phrases)

def generate_answer(replica):
  return None

def get_answer_by_intent(intent):
  if intent in BOT_CONFIG['intents']:
    responses = BOT_CONFIG['intents'][intent]['responses']
    return random.choice(responses)

def classify_intent(replica):
  replica = clear_phrase(replica)

#bad part -> bot doesn't understand that correctly
  for intent, intent_data in BOT_CONFIG['intents'].items():
    for example in intent_data['examples']:
      example = clear_phrase(example)
      distance = nltk.edit_distance(replica, example)
      if distance / len(example) < 0.4:
        return intent

def clear_phrase(phrase):
  phrase = phrase.lower()
  alphabet = 'ёйцукенгшщзхъэждлорпавыфячсмитьбю- '
  result = ''.join(symbol for symbol in phrase if symbol in alphabet)
  return result

def bot_ans(replica):
  # NLU - intent classificator
  intent = classify_intent(replica)

  # Answer generation
  # Выбор заготовленной реплики
  if intent:
    answer = get_answer_by_intent(intent)
    if answer:
      return answer

  #вызов генеративной модели
  answer = generate_answer(replica)
  if answer:
    return answer

  # заглушки
  return get_failure_phrase()

@bot.message_handler(commands=['start'])
def start_message(message):
    keyboard = telebot.types.ReplyKeyboardMarkup(True)
    keyboard.row('Температура', 'Освещенность', "Влажность")
    bot.reply_to(message, "Привет, {0}! меня зовут Варфоломей. Надеюсь, мы подружимся ^^".format(message.from_user.first_name))
    bot.send_message(message.chat.id, 'Давай проверим самочувствие Анатолия. Жми на кнопочки', reply_markup=keyboard)

@bot.message_handler(commands = ['info'])
def url(message):
    markup = types.InlineKeyboardMarkup()
    btn_my_site= types.InlineKeyboardButton(text='Наш GitHub', url='https://github.com/SunnyientDev/kaggle_contests/tree/main/IoT%20course')
    markup.add(btn_my_site)
    btn_my_site_2= types.InlineKeyboardButton(text='Канал обо мне', url='https://t.me/TimeChecker_News')
    markup.add(btn_my_site)
    bot.send_message(message.chat.id, "Хочешь посмотреть на проект? Переходи по ссылкам ниже:", reply_markup = markup)

################################## VARIABLES ##################################
default_temperature = 30
default_brightness = 500
default_humidity = 17
default_watering_day = '2021-11-10'
pump_state = 0
lamp_state = 0

@bot.message_handler(content_types=['text'])
def get_text_messages(message):
  
  if(classify_intent(message.text) == 'time'):
    now = datetime.datetime.now()
    bot.send_message(message.from_user.id, "Сейчас ровно " + str(now.hour + 3) + " : " + str(now.minute))
  
  elif(classify_intent(message.text) == 'temperature'):
    now = datetime.datetime.now()
    try:
      res = main(pump_state, lamp_state, default_temperature, default_humidity, default_brightness, default_watering_day, False)
      default_temperature = res[0]
      default_brightness = res[1]
      default_humidity = res[2]
      default_watering_day = res[3]
      pump_state = res[4]
      lamp_state = res[5]
      bot.send_message(message.from_user.id, "Температура вокруг растения: " + str(default_temperature)) 
    except:
      bot.send_message(message.from_user.id, "Температура вокруг растения: " + str(generate_value(20, 1.1, 0.01, 1)) + "°С\nАнатолию тепло")
  
  elif(classify_intent(message.text) == 'humidity'):
    now = datetime.datetime.now()
    try:
      res = main(pump_state, lamp_state, default_temperature, default_humidity, default_brightness, default_watering_day, False)
      default_temperature = res[0]
      default_brightness = res[1]
      default_humidity = res[2]
      default_watering_day = res[3]
      pump_state = res[4]
      lamp_state = res[5]
      bot.send_message(message.from_user.id, "Влажность почвы: " + str(default_humidity)) 
    except:
      bot.send_message(message.from_user.id, "Влажность почвы: " + str(generate_value(56, 1.1, 0.01, 1)) + "%\nНе волнуйся, Анатолий полит")
  
  elif(classify_intent(message.text) == 'date'):
    now = datetime.datetime.now()
    bot.send_message(message.from_user.id, "Сегодня " + str(now.date().day) + '.' + str(now.date().month) + '.' + str(now.date().year))
  
  elif(classify_intent(message.text) == 'brightness'):
    now = datetime.datetime.now()
    try:
      res = main(pump_state, lamp_state, default_temperature, default_humidity, default_brightness, default_watering_day, False)
      default_temperature = res[0]
      default_brightness = res[1]
      default_humidity = res[2]
      default_watering_day = res[3]
      pump_state = res[4]
      lamp_state = res[5]
      bot.send_message(message.from_user.id, "Освещенность: " + str(default_brightness)) 
    except:
      bot.send_message(message.from_user.id, "Освещенность: " + str(round(generate_value(700, 1.01, 0.01, 1))) + " из 1000\nСейчас Анатолию света достаточно")
  
  elif(classify_intent(message.text) == 'plant'):
    now = datetime.datetime.now()
    try:
      res = main(pump_state, lamp_state, default_temperature, default_humidity, default_brightness, default_watering_day, False)
      default_temperature = res[0]
      default_brightness = res[1]
      default_humidity = res[2]
      default_watering_day = res[3]
      pump_state = res[4]
      lamp_state = res[5]
      bot.send_message(message.from_user.id, "Состояние Анатолия: " + str(default_brightness)) 
    except:
      bot.send_message(message.from_user.id, "Состояние Анатолия: хорошее")

  else:
    bot.send_message(message.from_user.id, bot_ans(message.text))

bot.polling(none_stop=True)