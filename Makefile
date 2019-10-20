all: ip_info

ip_info:
	g++ main.cpp -lcurl -o ip_info
