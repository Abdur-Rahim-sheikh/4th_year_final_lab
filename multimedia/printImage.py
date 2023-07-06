import matplotlib.pyplot as plt
import cv2

path = "lili.jpg"
img = plt.imread(path)
img = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)

plt.imshow(img,cmap='gray')
plt.show()