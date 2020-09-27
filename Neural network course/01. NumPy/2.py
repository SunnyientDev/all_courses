import numpy as np

a = np.eye(3,4,k = 1)
b = 2 * np.eye(3,4,k = 0)
mat = a + b
print(np.reshape(mat, (12,1)))
