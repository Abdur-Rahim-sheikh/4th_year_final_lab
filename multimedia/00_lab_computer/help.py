import numpy as np
import matplotlib.pyplot as plt
import cv2

path = "blackAndWhite.jpeg"
img = plt.imread(path)
img = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)

def imgToText(img):
    x = np.uint8(0)
    ss = ""

    for bitPos in range(8):
        sliced = (img&(1<<bitPos))>>bitPos
        m,n = img.shape
       
        for i in range(m):
            bit = 0
            cnt = 0
            j = 0
            
            while(j<n):
                while(j<n and bit==sliced[i][j]):
                    j+=1
                    cnt+=1

                while(cnt>255):
                    ss+=chr(255)
                    ss+=chr(0)
                    cnt-=255
                if(cnt>0):
                    ss+=chr(cnt)
                    cnt=0

                bit ^=1
            
            ss+='\n'
        ss+='\n'
    
    return ss

                


# compress the data
compressed = imgToText(img)

with open("compressed.txt","wb") as fw:
    fw.write(compressed)