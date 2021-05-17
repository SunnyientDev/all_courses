def f23(str6):
  #remove empty strings
  for i in range(len(str6)-1):
    if(str(None in str6[i]) == 'True'):
      del str6[i]

  #1st row separation
  for i in range(len(str6)):
    temp = str6[i][0].split(':')
    str6[i][0] = temp[0]
    str6[i].append(temp[1])  
  
  #remove duplicates
  id = []

  for i in range(len(str6[0])-1):
    if(str6[0][i] == str6[0][i+1]):
      id.append(i)

  for i in range(len(id)):
    for j in range(len(str6)):
      if(str6[j][id[i]] != str6[j][id[i]+1]):
        del id[i]

  for i in range(len(id)):
    for j in range(len(str6)):
      del str6[j][id[i]]

  #new array
  res = []
  for i in str6:
    if i not in res:
      res.append(i)

  #data format
  for i in range(len(res)):
    res[i][len(res[i])-1] = str(round(float(res[i][len(res[i])-1]) * 100)) + "%"
    res[i][0] = res[i][0].split('@')[1]
    res[i][1] = res[i][1].split(',')[0]
    res[i][len(res[i])-2] = res[i][len(res[i])-2].replace(".", "-")
  
  
  #output
  for i in range(len(res[0])):
    if("%" in res[0][i]):
      for j in range(len(res)):
        res[j][i], res[j][0] = res[j][0], res[j][i]

    if("." in res[0][i]):
      for j in range(len(res)):
        res[j][i], res[j][2] = res[j][2], res[j][i]
    
    if("-" in res[0][i]):
      for j in range(len(res)):
        res[j][i], res[j][3] = res[j][3], res[j][i]
  return res