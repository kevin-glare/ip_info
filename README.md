# IP info
Determining your ip and geolocation in the terminal.

## Instructions

**Method without compilation:**

```
$ git@github.com:kgoryachev/ip_info.git
$ cd ip_info
$ ./ip_info
```

**You can compile program independently:**

Run the Makefile by typing make.\
This generates the ./ip_info executable. Then run the ./ip_info executable to start the program.
```
$ make
$ ./ip_info
```

**If you want to run a script from anywhere:**

```
$ sudo cp ip_info /usr/bin/
```

## Example
Run program without argument:
``` 
$ ip_info

{
    "ip":"178.71.78.46",
    "country_code":"RU",
    "country_name":"Russia",
    "region_code":"SPE",
    "region_name":"St.-Petersburg",
    "city":"St Petersburg",
    "zip_code":"190000",
    "time_zone":"Europe/Moscow",
    "latitude":59.8981,
    "longitude":30.2619,
    "metro_code":0
}
```
Run program with argument (we can send ip address or domain name):
```
$ ip_info amazon.com

{
    "ip":"176.32.103.205",
    "country_code":"US",
    "country_name":"United States",
    "region_code":"VA",
    "region_name":"Virginia",
    "city":"Ashburn",
    "zip_code":"20149",
    "time_zone":"America/New_York",
    "latitude":39.0481,
    "longitude":-77.4729,
    "metro_code":511
}
```