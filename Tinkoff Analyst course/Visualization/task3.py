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

## Задание 3

Постройте диаграмму (или график), которая показывает, как скорость утилизации влияет на размер первой покупки.
В ответ пришлите изображение диаграммы (или графика) и код (SQL/Python), с помощью которого вы его получили
"""

!wget https://edu.tinkoff.ru/media/edu-files-ext-100/40efea85-f221-4233-b218-87ae35423650.xls

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import datetime

df = pd.read_excel('/content/40efea85-f221-4233-b218-87ae35423650.xls')
print(df.columns.values)

#filter
df = df.loc[(pd.isnull(df.purchase_dt)) == False]
df = df.drop('birth_dt', 1)
df = df.drop('purchase_id', 1)
df['reg_dttm'] = df['reg_dttm'].dt.strftime('%Y-%m-%d')
df['purchase_dt'] = df['purchase_dt'].dt.strftime('%Y-%m-%d')

#i = 0
#df['id_updated'] = [(lambda x: x)(x) for x in range(1239)]
data = df
data = data.reset_index()
 
def get_days(a, b):
  a = a.split('-')
  b = b.split('-')
  aa = datetime.date(int(a[0]),int(a[1]),int(a[2]))
  bb = datetime.date(int(b[0]),int(b[1]),int(b[2]))
  cc = aa-bb
  dd = str(cc)
  if dd.split()[0] == '0:00:00':
    return 0
  else:
    return int(dd.split()[0]) # only days

speed_list = []
cost_list = data['purchase_amt'].to_list()

for i in range(1239):
  temp = get_days(data['purchase_dt'][i], data['reg_dttm'][i])
  speed_list.append(temp)

final_data = pd.DataFrame({'Cost': cost_list, 'Speed': speed_list})
final_data = final_data.sort_values('Cost', kind='mergesort')

#plt.figure(figsize = (25,10))

fig, ax = plt.subplots(figsize = (25,10))
ax.plot(final_data['Cost'] , final_data['Speed'], color = 'lightgreen')
plt.xlabel('Cost')
plt.ylabel('Speed')

ax.xaxis.set_major_locator(ticker.MultipleLocator(500))
ax.xaxis.set_minor_locator(ticker.MultipleLocator(250))

ax.yaxis.set_major_locator(ticker.MultipleLocator(10))
ax.yaxis.set_minor_locator(ticker.MultipleLocator(5))

plt.minorticks_on()
plt.grid(which='minor',
        color = 'gray',
        linestyle = ':')

#plt.savefig('task3.png', dpi = 100)
plt.show()