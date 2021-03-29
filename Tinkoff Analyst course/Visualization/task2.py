# -*- coding: utf-8 -*-
"""
# Визуализация данных

Поговорим о проекте Тинькофф Квест.
Рассматриваем следующий процесс: заявители регистрируются на сайте Тинькофф Квест, где указывают свой возраст. Всех зарегистрированных называем клиентами.

В дальнейшем кто-то из них совершает с созданного аккаунта покупки сертификатов на квест. Будем называть это утилизацией. Число дней от регистрации на сайте до первой покупки будем называть скоростью утилизации.

В приложенном файле таблица со следующими полями:

* client_id -- id клиента, зарегистрированного на сайте
* birth_dt -- дата его рождения
* reg_dttm -- дата и время регистрации на сайте данного клиента
* purchase_id -- id покупки
* purchase_dt -- дата покупки
* purchase_amt -- сумма покупки

Если данные по покупке пустые -- клиент не совершил утилизации.

## Задание 2

Постройте диаграмму (или график), которая показывает, как по возрастным сегментам отличается конверсия в утилизацию.
В ответ пришлите изображение диаграммы (или графика) и код (SQL/Python), с помощью которого вы его получили
"""

!wget https://edu.tinkoff.ru/media/edu-files-ext-100/40efea85-f221-4233-b218-87ae35423650.xls

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_excel('/content/40efea85-f221-4233-b218-87ae35423650.xls')
print(df.columns.values)

df

#data transformation
df['birth_dt'] = df['birth_dt'].dt.strftime('%Y')
df['reg_dttm'] = df['reg_dttm'].dt.strftime('%Y-%m')

#add new columns
df['age'] = 2019 - df['birth_dt'].astype(int)
df['util'] = ((pd.isnull(df.purchase_id)) == False).astype(int) # we choose int type to simplify the summation
df

"""Оставим только нужные для построения данные"""

df_upt = df.groupby(['client_id','age', 'util'], as_index=False)[['reg_dttm']].count()
data = df_upt.groupby(['age', 'util'], as_index=False)[['client_id']].count()

data.rename(columns={'client_id': 'count'}, inplace=True)
data

age_data = ['18-25', '26-35', '36-45', '46-54', '55+'] #change the range for correct summation
count = []

def add_func(result, mydf, column):
  temp = mydf[(column >= 18)&(column <= 25)&(mydf.util == 1)]['count'].sum()
  temp /= mydf[(column >= 18)&(column <= 25)]['count'].sum()
  result.append(round(temp*100))
  
  temp = mydf[(column >= 26)&(column <= 35)&(mydf.util == 1)]['count'].sum()
  temp /= mydf[(column >= 26)&(column <= 35)]['count'].sum()
  result.append(round(temp*100))

  temp = mydf[(column >= 36)&(column <= 45)&(mydf.util == 1)]['count'].sum()
  temp /= mydf[(column >= 36)&(column <= 45)]['count'].sum()
  result.append(round(temp*100))

  temp = mydf[(column >= 46)&(column < 55)&(mydf.util == 1)]['count'].sum()
  temp /= mydf[(column >= 46)&(column < 55)]['count'].sum()
  result.append(round(temp*100))

  temp = mydf[(column >= 55)&(mydf.util == 1)]['count'].sum()
  temp /= mydf[column >= 55]['count'].sum()
  result.append(round(temp*100))
  return result

count = add_func(count, data, data.age)
data = pd.DataFrame({'Age': age_data, 'Util percentage': count})
data

plt.figure(figsize = (25,10))

plt.bar(data['Age'] , data['Util percentage'], color = 'lightgreen', width=0.5, align='center')

plt.ylim(data['Util percentage'].min() - 2, data['Util percentage'].max() + 2)
plt.xlabel('Age range')
plt.ylabel('Util percentage')

plt.savefig('task2.png', dpi = 100)
plt.show()