# matrix on matrix

import numpy as np

x_shape = tuple(map(int, input().split()))
X = np.fromiter(map(int, input().split()), np.int).reshape(x_shape)
y_shape = tuple(map(int, input().split()))
Y = np.fromiter(map(int, input().split()), np.int).reshape(y_shape)
U = Y.T

if x_shape[1]!=y_shape[1]:
    print("Shapes don't match")
else:
    result = X.dot(U)
    print(result)
