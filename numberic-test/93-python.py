import requests

url = "https://10.53.77.64:443/home/login/"
#url = "https://ip:port/home/login/"
payload="encryptName='PTRXWXRKWFp3VjNj'&encryptPassword='MDVXWnNGR2Q='&pwdlen=6&devFlag='MicroTOSApi'"

headers = {
        "Content-Type": "application/x-www-form-urlencoded"

        } 

response = requests.request("post", url, headers=headers, data=payload)
