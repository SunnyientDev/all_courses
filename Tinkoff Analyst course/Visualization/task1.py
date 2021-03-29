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

## Задание 1

Постройте диаграмму (или график), которая показывает, как менялось множество клиентов по возрасту с течением времени.
"""
"""Будем ориентироваться по столбцам reg_dttm, birth_dt"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_excel('/content/40efea85-f221-4233-b218-87ae35423650.xls')
print(df.columns.values)

df

#data transformation
df['birth_dt'] = df['birth_dt'].dt.strftime('%Y')
df['reg_dttm'] = df['reg_dttm'].dt.strftime('%Y-%m')

#add new column
df['age'] = 2019 - df['birth_dt'].astype(int)
df

#define the limits
print('min: ', df['reg_dttm'].min())
print('max: ', df['reg_dttm'].max())
print('---------------------------')
print('min: ', df['age'].min())
print('max: ', df['age'].max())

"""Заметим, что по факту у нас 3 временных периода: январь-февраль, февраль-март, март-апрель"""

january_data = df[df.reg_dttm == '2019-01']
february_data = df[df.reg_dttm <= '2019-02']
march_data = df[df.reg_dttm <= '2019-03']

january_data_updated = january_data.groupby(['client_id','age'], as_index=False)[['reg_dttm']].count()
january_final = january_data_updated.groupby(['age'], as_index=False)[['client_id']].count()
january_final.rename(columns={'client_id': 'count'}, inplace=True)

february_data_updated = february_data.groupby(['client_id','age'], as_index=False)[['reg_dttm']].count()
february_final = february_data_updated.groupby(['age'], as_index=False)[['client_id']].count()
february_final.rename(columns={'client_id': 'count'}, inplace=True)

march_data_updated = march_data.groupby(['client_id','age'], as_index=False)[['reg_dttm']].count()
march_final = march_data_updated.groupby(['age'], as_index=False)[['client_id']].count()
march_final.rename(columns={'client_id': 'count'}, inplace=True)

age_data = ['18-25', '26-35', '36-45', '46-55', '56-65', '66+']
count_data_012 = []
count_data_023 = []
count_data_034 = []

def add_func(result, mydf):
  result.append(mydf[(mydf.age >= 18)&(mydf.age <= 25)]['count'].sum())
  result.append(mydf[(mydf.age >= 26)&(mydf.age <= 35)]['count'].sum())
  result.append(mydf[(mydf.age >= 36)&(mydf.age <= 45)]['count'].sum())
  result.append(mydf[(mydf.age >= 46)&(mydf.age <= 55)]['count'].sum())
  result.append(mydf[(mydf.age >= 56)&(mydf.age <= 65)]['count'].sum())
  result.append(mydf[(mydf.age > 65)]['count'].sum())
  return result

count_data_012 = add_func(count_data_012, january_final)
info = pd.DataFrame({'Age': age_data, 'clients num. January': count_data_012})
count_data_023 = add_func(count_data_023, february_final)
info['clients num. February'] = count_data_023

count_data_034 = add_func(count_data_034, march_final)
info['clients num. March'] = count_data_034
info

plt.figure(figsize = (25,10))
plt.xlabel('Age range')
plt.ylabel('Count of clients')

plt.bar(info['Age'] , info['clients num. March'], color = 'coral', label = 'March', width=0.4, align='center')
plt.bar(info['Age'] , info['clients num. February'], color = 'lightgreen', label = 'February', width=0.4, align='center')
plt.bar(info['Age'] , info['clients num. January'], color = 'skyblue', label = 'January', width=0.4, align='center')
plt.savefig('task1.png', dpi = 100)
plt.show()