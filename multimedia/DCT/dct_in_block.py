import numpy as np
import matplotlib.pyplot as plt
import cv2

def apply_dct(image):
    height, width = image.shape
    transformed_image = np.zeros((height, width))

    for i in range(0, height, 16):
        for j in range(0, width, 16):
            block = image[i:i+16, j:j+16]
            dct_block = cv2.dct(block.astype(np.float32))
            transformed_image[i:i+16, j:j+16] = dct_block

    return transformed_image

def apply_idct(transformed_image):
    height, width = transformed_image.shape
    reconstructed_image = np.zeros((height, width))

    for i in range(0, height, 16):
        for j in range(0, width, 16):
            transformed_block = transformed_image[i:i+16, j:j+16]
            idct_block = cv2.idct(transformed_block.astype(np.float32))
            reconstructed_image[i:i+16, j:j+16] = idct_block

    return reconstructed_image

# Load the grayscale image
image = cv2.imread('img.jpg', cv2.IMREAD_GRAYSCALE)

# Apply DCT
transformed_image = apply_dct(image)

# Apply IDCT
reconstructed_image = apply_idct(transformed_image)
print(np.size(transformed_image),np.size(reconstructed_image))
# Plot the transformed and reconstructed images
plt.subplot(1, 2, 1)
plt.imshow(transformed_image, cmap='gray')
plt.title('Transformed Image')

plt.subplot(1, 2, 2)
plt.imshow(reconstructed_image, cmap='gray')
plt.title('Reconstructed Image')

plt.show()
