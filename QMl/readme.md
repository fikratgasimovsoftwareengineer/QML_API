### QT6-QML & FLASH SERVER-CLIENT COMMUNICATION 
```
Here, i desribe json file creation and filling, with random informations,tecnical components as the followings

1. create Json file, and Fill it with random Information
2. Read Json file
3. Send Json File
4. Front End Components on Qml file have been supplied
------------------------------------------------------

In order to send json with following GET AND POST request, i need to create custom API, in this case, i prefered Flash 
library in pyhton, creating Get and Post request on the url : http://127.0.0.1:5000/test

In order to run application follow these steps:

1. run first API serrver
	$ python3 pyhon_flash.py
2. then enter to jsonData folder with Qt creator, and run application , you will see three corresponding buttons
	- write (Write data to json)
	- read (Read data from json)
	- send (Send Json to EndPoint API Server)

3. results could be seen with tools mentions below
	1. from terminal
		$ curl http://127.0.0.1:5000/test (this is get request)
		$ alternatively, use postman of GET functionality 
```

Thank you!
