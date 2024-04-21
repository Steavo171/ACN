def get_ip_class(binary_ip):
    octet = int(binary_ip[:8], 2)

    if octet >= 1 and octet <= 126:
        return 'Class A'
    elif octet >= 128 and octet <= 191:
        return 'Class B'
    elif octet >= 192 and octet <= 223:
        return 'Class C'
    elif octet >= 224 and octet <= 239:
        return 'Class D'
    elif octet >= 240 and octet <= 255:
        return 'Class E'
    else:
        return 'Invalid IP Address'


binary_ip = input("Enter IP address in binary format ")
print(binary_ip)
if(len(binary_ip)==32):
    ip_class = get_ip_class(binary_ip)
    print("IP Class:", ip_class)
else:
    print("Invalid ip")

oc1 = int(binary_ip[:8],2)
oc2 = int(binary_ip[8:16],2)
oc3 = int(binary_ip[16:24],2)
oc4 = int(binary_ip[24:32],2)

inp = f'''{oc1}.{oc2}.{oc3}.{oc4}'''

x = inp.split('.')

if(int(x[0])>=1 and int(x[0])<=126):
    print("Network address : ", x[0] + ".0.0.0")
    print("Net id : ",x[0])
    print("Host address : 0."+x[1]+"."+x[2]+"."+x[3])
    print("Host ID : ", x[1]+"."+x[2]+"."+x[3])
    print("First address : ",x[0] + ".0.0.0")
    print("Last address : ",x[0]+"."+"255.255.255")
    print("Total number of address : ", 255*255*255)

elif (int(x[0])>=128 and int(x[0])<=191):
    print("Network address : ", x[0] +"."+ x[1]+".0.0")
    print("Net id : ",x[0]+"."+x[1])
    print("Host address : 0.0"+"."+x[2]+"."+x[3])
    print("Host ID : " +x[2]+"."+x[3])
    print("First address : ",x[0] +"."+ x[1]+".0.0")
    print("Last address : ",x[0]+"."+x[1]+"."+"255.255")
    print("Total number of address : ", 255*255)

elif(int(x[0])>=192 and int(x[0])<=223):
    print("Network address : ", x[0] +"."+ x[1]+"."+ x[2]+"."+"0")
    print("Net id : ",x[0]+"."+x[1]+"."+x[2])
    print("Host address : 0.0.0"+"."+x[3])
    print("Host ID : ", x[3])
    print("First address : ",x[0] +"."+ x[1]+"."+ x[2]+"."+"0")
    print("Last address : ",x[0]+"."+x[1]+"."+x[2]+"."+"255")
    print("Total number of address : ", 255)

elif(int(x[0])>=224 and int(x[0])<=239):
    print("No network address available for class D")
    print("No net ID available")
    print("No host address available for class D")
    print("No host ID available")
    print("No first address and last address available")
    
elif(int(x[0])>=240 and int(x[0])<=255):
    print("No network address available for class E")
    print("No net ID available")
    print("No host address available for class D")
    print("No host ID available")
    print("No first address and last address available")


def cusmask(num):
    i = 0
    byte = 0

    if(num>=24):
        i=num-24
        for idx in range(i):
            byte = byte +pow(2,7-idx)
        return"255.255.255"+str(byte)

    elif(num>=16):
        i=num-16
        for idx in range(i):
            byte = byte+pow(2,7-idx)
        return "255.255."+ str(byte)+".0"

    elif(num>=8):
        i=num-8
        for idx in range(i):
            byte = byte + pow(2,7-idx)
        return "255."+str(byte)+".0.0"

num = int(input("Enter the custom masking value : "))
res=cusmask(num)
print(res)