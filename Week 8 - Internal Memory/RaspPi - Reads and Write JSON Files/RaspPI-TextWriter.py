import json         #imports JSON Library
file_path = 'C:/Users/raspiUser/Desktop/ESD/Memory/' #path

totalDevices = 2;   #to later loop for each device
deviceObj = {};     #variable to store read files

for x in range(totalDevices):
    file_name = 'device-%s.json' %(x+1)     #format the file_name for each device JSON file
    fullpath = file_path + file_name        #create its respective path, and reads & stores it to a dictionary
    with open(fullpath,'r') as data_file:   #opens in read mode
        data = json.load(data_file)
        ids = data["device"]                #looks for device key
        deviceObj['device%s'%(x+1)] = ids   #adds new dictionary key:value pairs
        data_file.close();  


main_server = {"All_Devices": deviceObj}     #json for main JSON file that contains all the information

file_path = 'C:/Users/raspiUser/Desktop/ESD/Memory/allDevices.json'   #file path doesn't change so its constant
with open(file_path,'w') as data_file:                  #opens in write mode
    jsonObject = json.dumps(main_server, indent = 5)    #formats it properly
    data_file.write(jsonObject)                         #writes it

data_file.close();  



    

