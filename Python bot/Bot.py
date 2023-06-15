# -*- coding: utf-8 -*-
"""TimeChecker.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1Un_7jQPwiOc2MSBer2TODbZR9PJ61bUV

Consept: you just upload table with schedule in the program and then pandas will analyse it for useful info

upload table from your computer:
"""

from google.colab import files
uploaded_data = files.upload()

import pandas as pd

table = pd.read_excel('/content/ИИТ_2к_20-21_весна.xlsx')
table

"""Us you see this table is unreadeble. We must do something to fix it."""

!pip install python-telegram-bot

!pip install telegramcalendar

!wget https://github.com/unmonoqueteclea/calendar-telegram/blob/master/telegramcalendar.py

import logging
from telegram.ext import Updater
from telegram.ext import  CallbackQueryHandler
from telegram.ext import  CommandHandler
from telegram import  ReplyKeyboardRemove


import telegramcalendar




logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    level=logging.INFO)

logger = logging.getLogger(__name__)

def calendar_handler(bot,update):
    update.message.reply_text("Please select a date: ",
                        reply_markup=telegramcalendar.create_calendar())


def inline_handler(bot,update):
    selected,date = telegramcalendar.process_calendar_selection(bot, update)
    if selected:
        bot.send_message(chat_id=update.callback_query.from_user.id,
                        text="You selected %s" % (date.strftime("%d/%m/%Y")),
                        reply_markup=ReplyKeyboardRemove())



up = Updater(TOKEN)

up.dispatcher.add_handler(CommandHandler("calendar",calendar_handler))
up.dispatcher.add_handler(CallbackQueryHandler(inline_handler))

up.start_polling()
up.idle()

"""## Сам бот

1. Научим его понимать разные сообщения 
2. Добавим необходимые базовые функции (в режиме переписки)
3. Научим новым командам и сделаем календарь
4. Внедряем расписание
"""

!pip install telebot
!pip install PyTelegramBotAPI

import random
import telebot
import nltk
from datetime import date

bot = telebot.TeleBot(TOKEN)  

TOKEN = '1129048113:AAGpp0FPckxMzROx6pFldr5CNORkW0CXnfM'
BOT_CONFIG = {
    'intents': {
        
        'hello': {
            'examples': ['Приветик', 'Добрый день', 'Шалом', 'Привет, бот', 'Привет'],
            'responses': ['Привет, меня зовут Варфоломей', 
                          'Привет! Рад тебя видеть',
                          'Добрый день, ты как всегда выглядишь круто']
        },
        
        'bye': {
            'examples': ['Пока', 'Спокойной ночи', 'Досвидания', 'До встречи'],
            'responses': ['Удачи! Если что, пиши. Я всегда здесь','Буду тебя ждать ^^']
        },
        
        'name': {
            'examples': ['Как тебя зовут?', 'Скажи свое имя?', 'Твое имя?'],
            'responses':['Меня зовут Варфоломей','Я красная панда Варфоломей']
        },
    },

    'failure_phrases': [
                      'Ничего не понимаю. Перефразируй, пожалуйста',
                     'Скажи фразу другими словами, я тебя не понял :(',
                     'Я только учусь, спроси что-нибудь другое',
                     'Я в неведении, спроси у гугла. Передавай от меня привет',
                     'Может тебе стоит спросить у Алисы?',
                     'Не знаю, что сказать',
                     'А ты знаешь, что в Нью-Джерси все коты должны носить колокольчики, чтобы птицы всегда знали об их расположении? Так какой вопрос ты задал?'
    ]
}

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
def Send_Welcome(message):
  bot.reply_to(message, "Привет, {0}! меня зовут Варфоламей. Надеюсь, мы подружимся ^^".format(message.from_user.first_name))

@bot.message_handler(content_types=['text'])
def get_text_messages(message):
    bot.send_message(message.from_user.id, bot_ans(message.text))

bot.polling(none_stop=True)

