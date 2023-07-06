# your code goes here
import numpy as np
import matplotlib.pyplot as plt
import cv2
import os
# total of 256 different character to keep
# here 254 will be used for lineBreak 255 for planeBreak
# other will be used for counting purpose
path = "IMG_20220206_150748.jpg"
img_file_size = os.path.getsize(path)/(1024*1024)
img = plt.imread(path)
img = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
plt.imsave("gray_"+path,img,cmap='gray')
# img = np.array([[3,0,3],[0,4,4]]).astype(np.uint8)
MAX_COUNT, NEWLINE, NEWPLANE = 253,chr(254),chr(255)
START = 3
# plt.imshow(img)
# plt.savefig("grayFlower.jpeg")
def imgToText(img):
    ss = ""

    for bitPos in range(START,8):
        sliced = (img&(1<<bitPos))>>bitPos
        m,n = img.shape
       
        for i in range(m):
            '''First count zero then one then zero
            for the entire row and so on bit will be flipped
            at the beginning of the loop'''
            
            bit = 1
            cnt = 0
            j = 0
            temTotal = 0
            while(j<n):
                bit ^=1
                if(bit!=sliced[i][j]):
                    ss+=chr(0)
                    continue
                else:
                    while(j<n and bit==sliced[i][j]):
                        j+=1
                        cnt+=1
                    temTotal+=cnt
                    while(cnt>MAX_COUNT):
                        ss+=chr(MAX_COUNT)
                        ss+=chr(0)
                        cnt-=MAX_COUNT

                    if(cnt>0):
                        ss+=chr(cnt)
                        cnt=0
            
            ss+= NEWLINE
            
        ss+= NEWPLANE
        
    
    return ss[:-1]


def textToImg(bitPlane):
    x,y = img.shape
    image = np.array([[0]*y for i in range(x)])
    for bitPos in range(8-START):
        rows = bitPlane[bitPos].rstrip(NEWLINE).split(NEWLINE)
        assert len(rows)==x
        for i in range(x):
            j = 0
            bitVal = 0
            for byte in rows[i]:
                
                num = ord(byte)
                
                while num:
                    image[i][j] |= bitVal<<(bitPos+START)
                    j+=1
                    num-=1
                
                bitVal^=1
            
            assert j==y
            
    return image
            


if __name__=="__main__":
    encode_path = "RLEEncodedV2.txt"
    # compress the data
    compressed = imgToText(img)
    print("compressed")
    with open(encode_path,'wb') as wf:
        wf.write(compressed.encode('utf-8'))

    # # Done Compression Now decompress
    with open(encode_path,"rb") as rb:
        file = rb.read().decode()
    bitPlane = file.split(NEWPLANE)
    

    decompressed = textToImg(bitPlane)
    
    print("decompressed")

    plt.subplot(1,2,1)
    plt.title(f"Original size {img_file_size} MB")
    plt.imshow(img,cmap='gray')

    plt.subplot(1,2,2)
    plt.title(f"RLECompressed size {os.stat(file).st_size/(1024*1024)} MB")
    plt.imshow(decompressed,cmap='gray')
    plt.show()

        
