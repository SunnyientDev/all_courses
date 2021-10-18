import seaborn
import matplotlib.pyplot as plt
import numpy as np

def line(x1, x2):
  return -3*x1 - 5*x2 - 2

def line_x1(x1):
  return (-3*x1-2)/5

#generate random points
np.random.seed(0)
points = np.random.randn(200, 2) * 2 #200 points on two-dimensional plane

for x1, x2 in points:
  value = line(x1, x2)

  if(value == 0):
    plt.plot(x1, x2, "ro", color = "blue")
  elif (value > 0):
    plt.plot(x1, x2, "ro", color = "green")
  elif (value < 0):
    plt.plot(x1, x2, "ro", color = "red")

plt.gca().set_aspect('equal', adjustable = "box")
x1_range = np.arange(-5.0, 5.0, 0.5)
plt.plot(x1_range, line_x1(x1_range), color='blue')
plt.xlabel('x1')
plt.ylabel('x2')
