import numpy as np
import matplotlib.pyplot as plt
import cv2
from scipy.fftpack import dct, idct

def dct_2d(image):
    return dct(dct(image.T, norm='ortho').T, norm='ortho')

def idct_2d(image):
    return idct(idct(image.T, norm='ortho').T, norm='ortho')

# Define a grayscale image of size 16x16
image = plt.imread("img.jpg", format='gray')
image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
img2 = np.copy(image)

# img2.resize((16,16))
plt.imshow(img2, cmap='gray')
plt.title("Original Image")
plt.show()
# Apply DCT on the image
dct_image = dct_2d(img2)

# Plot the transformed image
plt.imshow(dct_image, cmap='gray')
plt.title("DCT Transformed Image")
plt.show()

# Apply IDCT on the transformed image
idct_image = idct_2d(dct_image)

# Plot the resulting image
plt.imshow(idct_image, cmap='gray')
plt.title("IDCT Transformed Image")
plt.show()
